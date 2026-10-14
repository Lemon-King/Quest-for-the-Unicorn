/*
 *******************************************************************
 *** This software is copyright 1985-2007 by Michael H Riley     ***
 *** You have permission to use, modify, copy, and distribute    ***
 *** this software so long as this copyright notice is retained. ***
 *** This software may not be used in commercial applications    ***
 *** without express written permission from the author.         ***
 *******************************************************************
*/

#include "header.h"

OBJECT_REC* inventory(OBJECT_REC* it) {
  OBJECT_REC item;
  OBJECT_REC in_air;
  OBJECT_REC* treasure;
  OBJECT_REC* pItem;
  char key;
  int  line;
  char flag;
  int  i;

  void show_screen() {
    int i;
    int ct;
    char buffer[40];
    textmode(3);
    textcolor(6);
    gotoxy(1,1);
    txt_write("<");
    textcolor(14); txt_write("ESC");
    textcolor(6); txt_write(">quit, <");
    textcolor(14); txt_write("P");
    textcolor(6); txt_write(">ack, <");
    textcolor(14); txt_write("T");
    textcolor(6); txt_write(">ake from pack, e<");
    textcolor(14); txt_write("X");
    textcolor(6); txt_write(">change, <");
    textcolor(14); txt_write("ENTER");
    textcolor(6); txt_write("> select");
    textcolor(2);
    gotoxy(1,3);
    txt_writeln("       Up in air      :");
    txt_writeln("    a) Left Hand      :");
    txt_writeln("    b) Right Hand     :");
    txt_writeln("    c) Left Shoulder  :");
    txt_writeln("    d) Right Shoulder :");
    txt_writeln("    e) Neck 1         :");
    txt_writeln("    f) Neck 2         :");
    txt_writeln("    g) Belt Left      :");
    txt_writeln("    h) Belt Right     :");
    txt_writeln("    i) Belt Front     :");
    txt_writeln("    j) Belt Back      :");
    txt_writeln("    k) Shield         :");
    txt_writeln("    l) Armour         :");
    txt_writeln("    m) Ring Left 1    :");
    txt_writeln("    n) Ring Left 2    :");
    txt_writeln("    o) Ring Right 1   :");
    txt_writeln("    p) Ring Right 2   :");
    txt_writeln("    q) Robe           :");
    txt_writeln("    r) Boots          :");
    txt_writeln("    s) Helm           :");
    show_inventory(&item);
    ct = 0;
    for (i=1; i<=32; i++)
      if (player.pack[i].otype != O_NONE) ct++;
    textcolor(14); gotoxy(5,24);
    sprintf(buffer,"Pack holds %d items",ct);
    txt_write(buffer);
    }

  in_air.otype = O_NONE;
  if (it != NULL) item = *it;
    else item.otype = O_NONE;
  if (player.d_level == bottom && it != NULL) {
    treasure = find_linked_item(links[player.dungeon_number].treasure);
    if (treasure != NULL && strcmp(it->name,treasure->name) == 0) {
      player.quests[player.dungeon_number] = 'Y';
      }
    }
  it = NULL;

  show_screen();
  line = 3;
  flag = ' ';
  textcolor(14);
  gotoxy(1,line); txt_write("->");
  while (flag == ' ') {
    key = inkey();
    if (key == '2' || key == '.' || key == '>') {
      textcolor(14);
      gotoxy(1,line); txt_write("  ");
      line++;
      if (line > 22) line = 3;
      gotoxy(1,line); txt_write("->");
      }
    if (key == '8' || key == ',' || key == '<') {
      textcolor(14);
      gotoxy(1,line); txt_write("  ");
      line--;
      if (line < 3) line = 22;
      gotoxy(1,line); txt_write("->");
      }
    if (key == 'P') pack_item(&item,line);
    if (key == 'T') {
      pItem = unpack();
      if (pItem != NULL && inv_valid(pItem,line-3) == 'Y') {
        if (line > 3) player.invent[line - 3] = *pItem;
          else item = *pItem;
        pItem->otype = O_NONE;
        }
      show_screen();
      textcolor(14);
      gotoxy(1,line); txt_write("->");
      }
    if (key == 13) {
      if (line > 3) {
        inv_item = line - 3;
        it = &(player.invent[line - 3]);
        item = player.invent[line - 3];
        }
      else {
        inv_item = 0;
        in_air = item;
        it = &in_air;
        }
      flag = '$';
      }
    if (key >= 'a' && key <= 's') {
      textcolor(14);
      gotoxy(1,line); txt_write("  ");
      line = key - 93;
      gotoxy(1,line); txt_write("->");
      }
    if (key == 'x' || key == 'X') do_exchange(&item,line);
    if (key == 'Q') flag = '*';
    if (key == 27) {
      in_air = item;
      flag = '*';
      }
    }
  player.armour = 0;
  if (player.invent[I_SHLD].otype == O_SHLD)
     player.armour = player.invent[I_SHLD].damage +
                     player.invent[I_SHLD].plus * 3;
  if (player.invent[I_ARMR].otype == O_ARMR)
     player.armour += player.invent[I_ARMR].damage +
                      player.invent[I_ARMR].plus * 5;
  if (player.invent[I_BOOT].otype == O_BOOT)
     player.armour += player.invent[I_BOOT].damage +
                      player.invent[I_BOOT].plus * 2;
  if (player.invent[I_HELM].otype == O_HELM) 
      player.armour += player.invent[I_HELM].damage +
                       player.invent[I_HELM].plus * 2;
  if (player.invent[I_ROBE].otype == O_ROBE) 
      player.armour += player.invent[I_ROBE].damage +
                       player.invent[I_ROBE].plus * 2;
  if (player.invent[I_RHND].otype == O_EDGE ||
      player.invent[I_RHND].otype == O_POLE ||
      player.invent[I_RHND].otype == O_DAGR ||
      player.invent[I_RHND].otype == O_BOW)
    player.weapon = player.invent[I_RHND].damage +
                    player.invent[I_RHND].plus * 5;
    else player.weapon = 0;
  for (i=I_RNG1; i<=I_RNG4; i++)
    if (player.invent[i].otype != O_NONE)
      player.weapon += player.invent[i].damage;
  if (player.class == C_MONK) check_monk_weapon();
  if (in_air.otype != O_NONE && player.map[player.x][player.y]) {
    i = find_item_slot();
    if (i != -1) {
      player.map_objects[i] = in_air;
      player.map[player.x][player.y] = i+1000;
      if (it == &in_air) it = &(player.map_objects[i]);
      }
    }
  return it;
  }
