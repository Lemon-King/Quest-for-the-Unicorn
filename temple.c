/*
 *******************************************************************
 *** This software is copyright 1985-2014 by Michael H Riley     ***
 *** You have permission to use, modify, copy, and distribute    ***
 *** this software so long as this copyright notice is retained. ***
 *** This software may not be used in commercial applications    ***
 *** without express written permission from the author.         ***
 *******************************************************************
*/

#include "header.h"

void rebirth() {
  char key;
  clrscr();
  textcolor(15);
  gotoxy(10,10); txt_write("The Ritual of Rebirth has begun.  The druids begin to chant");
  gotoxy(10,11); txt_write("and your world grows dark.  You hear a voice in the void, ");
  gotoxy(10,12); txt_write("\"You are reborn, your journey begins anew.\"");
  textcolor(7);
  gotoxy(10,16); txt_write("Select game mode: <N>ormal, <H>eroic, <E>pic: ");
  key = ' ';
  while (key != 'N' && key != 'H' && key != 'E') {
    key = inkey();
    if (key == 'n') key = 'N';
    if (key == 'h') key = 'H';
    if (key == 'e') key = 'E';
    }
  if (key == 'N') heroicMode = 0;
  if (key == 'H') heroicMode = 2;
  if (key == 'E') heroicMode = 4;
  }

void temple(char* name) {
  double cost;
  char   buffer[80];
  char   key;
  OBJECT_REC* item;
  int    hier;
  int    i;
  char   allowed;

  void show_top() {
    int line;
    textmode(3); gotoxy(27,1); textcolor(11);
    sprintf(buffer,"Welcome to %s",name);
    txt_write(buffer);
    textcolor(14);
    line = 3;
    gotoxy(27,line++); txt_write("1> Healing"); gotoxy(51,3); txt_write("  100");
    gotoxy(27,line++); txt_write("2> Prayer");  gotoxy(51,4); txt_write("  500");
    gotoxy(27,line); txt_write("3> Restore allignment");
    cost = player.align;
    cost = 500*(100-cost);
    sprintf(buffer,"%5.0f",cost);
    gotoxy(51,line++); txt_write(buffer);
    gotoxy(27,line++); txt_write("4> Remove Curse");
    if (allowed == 'Y') {
      gotoxy(27,line++); txt_write("5> Become a Hierophant");
      }
    if (player.gateway == 'F' && player.effect[PE_HEROIC] >= 0) {
      gotoxy(27,line++); txt_write("6> Rebirth");
      }
    if (player.effect[PE_HEROIC] >= 0) {
      gotoxy(27,line++); txt_write("7> One with Nature");
      }
    gotoxy(27,line++); txt_write("<ESC> Leave");
    line++;
    gotoxy(30,line); txt_write("Option ?");
    textcolor(15); gotoxy(35,24);
    sprintf(buffer,"Gold = %d",get_gold());
    txt_write(buffer);
    }

  hier = -1;
  allowed = 'N';
  for (i=0; i<NUM_CLASSES; i++)
    if (classes[i].flags & CF_HIER) hier = i + 1;
  if (hier >= 0) allowed = (check_class_change(hier)) ? 'Y' : 'N';
  show_top();
  key = ' ';
  while (key != '0') {
    key = inkey();
    if (key == 27) key = '0';
    if (key == '1' && get_gold()>=100) {
      player.chp = (classes[player.class-1].flags & CF_DRUID) ? player.mhp * 2 : player.mhp;
      sub_gold(100);
      textcolor(11);
      gotoxy(27,12); txt_write("Healed");
      delay(1000);
      }
    if (key == '2' && get_gold()>=500) {
      player.cmana = (classes[player.class-1].flags & CF_DRUID) ? player.mmana * 2 : player.mmana;
      if (classes[player.class-1].flags & CF_HIER) player.cmana = player.mmana * 2;
      sub_gold(500);
      if (player.mmana != 0) {
        textcolor(11);
        gotoxy(27,12); txt_write("Mana Increased");
        delay(1000);
        }
      }
    if (key == '3' && get_gold()>cost) {
      sub_gold(cost);
      player.align = 100;
      textcolor(11);
      gotoxy(27,12); txt_write("Alignment Restored");
      delay(1000);
      }
    if (key == '4') {
      item = inventory(NULL);
      show_top();
      if (item->plus >= 0) {
        gotoxy(27,13); textcolor(9); txt_write("That Item is not cursed");
        delay(1000);
        } else {
        cost = abs(item->plus) * 1000;
        sprintf(buffer,"Item will cost %.0f gold to uncurse",cost);
        gotoxy(27,13); textcolor(15); txt_write(buffer);
        if (cost > get_gold()) {
          gotoxy(27,14); textcolor(12); txt_write("You do not have enough gold!!!");
          } else {
          gotoxy(27,15); textcolor(11); txt_write("Do you wish to uncurse it? (Y/N)");
          while (key != 'Y' && key != 'N') {
            key = inkey();
            if (key == 'n') key = 'N';
            if (key == 'y') key = 'Y';
            }
          if (key == 'Y') {
            item->plus = 0;
            sub_gold(cost);
            gotoxy(27,16); textcolor(9); txt_write("Curse has been removed.");
            } else {
            gotoxy(27,16); textcolor(15); txt_write("Maybe next time.");
            }
          }
        delay(2500);
        }
      }
    if (allowed == 'Y' && key == '5') {
      make_h();
      textcolor(11);
      gotoxy(27,12); txt_write("Now a Hierophant");
      delay(1000);
      }
    if (player.gateway == 'F' && player.effect[PE_HEROIC] >=0 && key == '6') {
      textcolor(12); gotoxy(22,14); txt_write("WARNING! Rebirth will clear your game!");
      textcolor(15); gotoxy(18,16); txt_write("Do you wish to perform the Ritual of Rebirth?");
      key = ' ';
      while (key != 'Y' && key != 'N') {
        key = inkey();
        if (key == 'n') key = 'N';
        if (key == 'y') key = 'Y';
        }
      if (key == 'Y') { rebirth(); exitf = 7; key = '0'; }
      }
    if (player.effect[PE_HEROIC] >=0 && key == '7') {
      if (player.effect[PE_HEROIC] == 0) { textcolor(12); gotoxy(22,14); txt_write("WARNING! This will downgrade your game to Casual!"); }
      if (player.effect[PE_HEROIC] == 2) { textcolor(12); gotoxy(22,14); txt_write("WARNING! This will downgrade your game to Normal!"); }
      if (player.effect[PE_HEROIC] == 4) { textcolor(12); gotoxy(22,14); txt_write("WARNING! This will downgrade your game to Heroic!"); }
      textcolor(15); gotoxy(18,16); txt_write("Do you wish to become one with nature?");
      while (key != 'Y' && key != 'N') {
        key = inkey();
        if (key == 'n') key = 'N';
        if (key == 'y') key = 'Y';
        }
      if (key == 'Y') {
        if (player.effect[PE_HEROIC] == 0) player.effect[PE_HEROIC] = -1;
        if (player.effect[PE_HEROIC] == 2) player.effect[PE_HEROIC] = 0;
        if (player.effect[PE_HEROIC] == 4) player.effect[PE_HEROIC] = 2;
        }
      }
    show_top();
    }
  } /* void temple(char* name) */
