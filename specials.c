/*
#endif
 *******************************************************************
 *** This software is copyright 1985-2014 by Michael H Riley     ***
 *** You have permission to use, modify, copy, and distribute    ***
 *** this software so long as this copyright notice is retained. ***
 *** This software may not be used in commercial applications    ***
 *** without express written permission from the author.         ***
 *******************************************************************
*/

#include "header.h"

int gacha[2500];
int num_gacha;

void display_scroll() {
#ifdef ASCII
  int i;
  gotoxy(12,5); textcolor(14);
  txt_write("+------+                                      +------+");
  gotoxy(12,6); textcolor(14);
  txt_write("|      +");
  textcolor(7); txt_write("--------------------------------------");
  textcolor(14); txt_write("+      |");
  gotoxy(12,7); textcolor(14);
  txt_write("|      +");
  textcolor(7); txt_write("+------------------------------------+");
  textcolor(14); txt_write("+      |");
  gotoxy(12,8); textcolor(14);
  txt_write("+------+                                      +------+");
  gotoxy(12,18); textcolor(14);
  txt_write("+------+                                      +------+");
  gotoxy(12,19); textcolor(14);
  txt_write("|      +");
  textcolor(7); txt_write("+------------------------------------+");
  textcolor(14); txt_write("+      |");
  gotoxy(12,20); textcolor(14);
  txt_write("|      +");
  textcolor(7); txt_write("--------------------------------------");
  textcolor(14); txt_write("+      |");
  gotoxy(12,21); textcolor(14);
  txt_write("+------+                                      +------+");
  for (i=8; i<19; i++) {
    gotoxy(20,i); textcolor(7);
    textcolor(7); txt_write("|                                    |");
    }
#else
  graphmode();
  setfillstyle(1,15);
  bar(50,50,450,430);
  setfillstyle(1,7);
  bar(50,10,450,49);
  bar(50,431,450,471);
  setfillstyle(1,14);
  bar(10,10,39,49);
  bar(461,10,491,49);
  bar(10,431,39,471);
  bar(461,431,491,471);
  setfillstyle(1,6);
  bar(40,20,49,40);
  bar(451,20,460,40);
  bar(40,440,49,460);
  bar(451,440,460,460);
  settextstyle(4,0,3);
#endif
  }

void display_msg(int msg,char ext) {
  int i;
  int x,y;
//  int space;
  int size;
  char last;
  MESSAGE general;
  general = (ext == 'L') ? lore[msg] : gen[msg];
  graphmode();
  display_scroll();
  x = 160; y = 160; size = 30;
//  space = 25;
  setcolor(0);
  while (strlen(general.message) != 0) {
    if (strlen(general.message) < size) {
      outtextxy(x,y,general.message);
      strcpy(general.message,"");
      }
    else {
      i = size;
      while (i > 0 && general.message[i] != ' ') i--;
      last = general.message[i];
      general.message[i] = 0;
      outtextxy(x,y,general.message);
      general.message[i] = last;
      i++;
      y += 19;
      strcpy(general.message,general.message+i);
      }
    }
  inkey();
  show_screen();
  }

void special1() {
  int x,y;
  for (x=1; x<=100; x++)
    for (y=1; y<=100; y++)
      if (player.map[x][y] < 0) show_sprite(x-player.map_x,y-player.map_y,37);
  clair = '*';
  add_skill(SK_ORACLE,1);
  }

void special2() {
  int x,y;
  int sx,sy,ex,ey;
  sx = player.x - 20;
  sy = player.y - 20;
  ex = player.x + 20;
  ey = player.y + 20;
  if (sx < 0) sx = 0;
  if (sy < 0) sy = 0;
  if (ex > 99) ex = 99;
  if (ey > 99) ey = 99;
  for (x=1; x<=100; x++)
    for (y=1; y<=100; y++)
      if (player.map[x][y] < 0) {
        if (player.known[x][y] == 0) player.known[x][y] = 1;
        show_spot(x,y);
      }
  add_skill(SK_ORACLE,1);
  }

void special3() {
  int i;
  i = player.diff * 5 + get_skill(8) * 5;
  player.effect[PE_HASTE] += u_random(i + i + 1) + 25;
  }

void special4() {
  int i;
  i = player.diff * 5 + get_skill(8) * 5;
  player.effect[PE_GIANT] += u_random(i + i + 1) + 25;
  }

void special5() {
  int i;
  i = player.diff * 3 + get_skill(8) * 3;
  player.effect[PE_ETHER] += u_random(i) + 10;
  if (player.effect[PE_ETHER] > 100) player.effect[PE_ETHER] = 100;
  }

void special6() {
  player.effect[PE_LIGHT] += 5000;
  if (player.effect[PE_LIGHT] > 10000) player.effect[PE_LIGHT] = 10000;
  }

void special8();
void special9();
void special22();
void special37();

void special7() {
  special8();
  special9();
  special22();
  special37();
  }

void special8() {
  int x,y;
  for (x=1; x<=100; x++)
    for (y=1; y<=100; y++)
        if (player.map[x][y] >=24 && player.map[x][y] <=25) {
          player.known[x][y] = 1;
          show_spot(x,y);
          }
  show_sm_map();
  add_skill(SK_ORACLE,1);
  }

void special9() {
  int x,y;
  for (x=1; x<=100; x++)
    for (y=1; y<=100; y++)
      if (player.map[x][y] < 0) {
        player.known[x][y] = 1;
        show_spot(x,y);
        }
  add_skill(SK_ORACLE,1);
  delay(1000);
  }

void special10() {
  int i;
//  int x,y;
//  int space;
//  int size;
  MESSAGE general;
  i = u_random(NO_OF_LORE) + 1;
  general = lore[i];
  add_skill(SK_LORE,1);
  while (general.region != player.region && general.region != 0 &&
         general.region >= 90) {
    i = u_random(NO_OF_LORE) + 1;
    general = lore[i];
    }
  if (u_random(100) < (25 + get_skill(6) * 5) || player.effect[PE_READLORE] != 0) {
    player.lore[i] = -1;
    add_skill(SK_LORE,4);
    } else {
    for (i=0; i<=strlen(general.message); i++)
      if ((general.message[i] >= 'A' && general.message[i] <= 'Z') ||
          (general.message[i] >= 'a' && general.message[i] <= 'z'))
#ifdef ASCII
        {
          if (general.message[i] >= 'A' && general.message[i] <= 'Z') general.message[i] = 'A' + 'Z'-general.message[i];
          if (general.message[i] >= 'a' && general.message[i] <= 'z') general.message[i] = 'a' + 'z'-general.message[i];
	}
#else
        general.message[i] += 128;
#endif
    }
  saveScreen();
  display_scroll();
//  x = 120; y = 160; space = 25; size = 30;
  setcolor(0);
  show_message(general.message);
/*
  while (strlen(general.message) != 0) {
    if (strlen(general.message) < size) {
      write_font(x,y,0,general.message);
      strcpy(general.message,"");
      }
    else {
      i = size;
      while (i > 0 && general.message[i] != ' ') i--;
      last = general.message[i];
      general.message[i] = 0;
      write_font(x,y,0,general.message);
      general.message[i] = last;
      i++;
      y += 19;
      strcpy(general.message,general.message+i);
      }
    }
*/
  inkey();
  restoreScreen();
  }

void special11() {
  int i;
//  int x,y;
//  int space;
//  int size;
  MESSAGE general;
  i = u_random(NO_OF_GENS) + 1;
  general = gen[i];
  while (general.region != player.region && general.region != 0) {
    i = u_random(NO_OF_GENS) + 1;
    general = gen[i];
    }
  if (u_random(100) < (50 + get_skill(6) * 5) || player.effect[PE_READLANG] != 0) {
    player.gen[i] = -1;
    add_skill(SK_LANG,1);
    } else {
    for (i=0; i<=strlen(general.message); i++)
      if ((general.message[i] >= 'A' && general.message[i] <= 'Z') ||
          (general.message[i] >= 'a' && general.message[i] <= 'z'))
#ifdef ASCII
        {
          if (general.message[i] >= 'A' && general.message[i] <= 'Z') general.message[i] = 'A' + 'Z'-general.message[i];
          if (general.message[i] >= 'a' && general.message[i] <= 'z') general.message[i] = 'a' + 'z'-general.message[i];
	}
#else
        general.message[i] += 128;
#endif
    }
  saveScreen();
  display_scroll();
//  x = 120; y = 160; space = 25; size = 30;
  setcolor(0);
  show_message(general.message);
/*
  while (strlen(general.message) != 0) {
    if (strlen(general.message) < size) {
      write_font(x,y,0,general.message);
      strcpy(general.message,"");
      }
    else {
      i = size;
      while (i > 0 && general.message[i] != ' ') i--;
      last = general.message[i];
      general.message[i] = 0;
      write_font(x,y,0,general.message);
      general.message[i] = last;
      i++;
      y += 19;
      strcpy(general.message,general.message+i);
      }
    }
*/
  inkey();
/*  show_screen(); */
  restoreScreen();
  }

void special12() {
  OBJECT_REC* i;
  i = inventory(NULL);
  if (i != NULL) {
    if (i->control2 == E_MUTA) mutable_set_name(i);
    i->level = -1;
    stats.counts[STAT_ITEMS_IDENTED]++;
    gotoxy(25,inv_item+3);
    txt_write(get_name(i));
    msg(get_name(i),14);
    delay(1000);
    }
  graphmode();
  show_map();
  show_sm_map();
  show_side();
  show_player();
  }

void special13() {
  int i;
  i = player.diff * 5 + get_skill(8) * 5;
  player.effect[PE_PROT] += u_random(i+i+1) + 25;
  player.effect[PE_APROT] = 10;
  }

void special14() {
  int x,y;
  for (x=1; x<=100; x++)
    for (y=1; y<=100; y++)
      if (player.known[x][y] == 0) player.known[x][y] = 1;
  add_skill(SK_ORACLE,1);
  }

void special15() {
  if (player.d_level > 0 && player.in_city != 'Y') save_level();
  player.d_level = 0;
  }

void special16() {
  player.stat[1]++;
  if (player.stat[1] > 99) player.stat[1] = 99;
  adjust_abilities();
  }

void special17() {
  player.stat[2]++;
  if (player.stat[2] > 99) player.stat[2] = 99;
  adjust_abilities();
  }

void special18() {
  player.stat[4]++;
  if (player.stat[4] > 99) player.stat[4] = 99;
  adjust_abilities();
  }

void special19() {
  player.cmana *= 2;
  }

void special20() {
  int i;
//  int x,y;
//  int space;
//  int size;
  MESSAGE general;
  i = u_random(NO_OF_GENS) + 1;
  general = gen[i];
  while (general.region != player.region && general.region != 0) {
    i = u_random(NO_OF_GENS) + 1;
    general = gen[i];
    }
  player.gen[i] = -1;
  add_skill(SK_LANG,1);
  saveScreen();
#ifndef ASCII
  graphmode();
#endif
  display_scroll();
//  x = 160; y = 160; space = 25; size = 30;
  setcolor(0);
  show_message(general.message);
  inkey();
  restoreScreen();
  }

void special21() {
  player.effect[PE_READLANG] = 20;
  }

void special22() {
  int x,y;
  for (x=player.map_x; x<=player.map_x+15; x++)
    for (y=player.map_y; y<=player.map_y+15; y++)
      if (player.known[x][y] == 0) {
        if (player.map[x][y] >= 1088 && player.map[x][y] <= 1156)
          player.known[x][y] = 1;
        if (player.map[x][y] >= 1168 && player.map[x][y] <= 9999)
          player.known[x][y] = 1;
        }
  show_screen();
  }

void special23() {
  char mflag;
  int  x,y;
  int  xdir,ydir;
  int  mon;
  get_dir(&xdir,&ydir);
  mflag = ' ';
  x = player.x;
  y = player.y;
  while (mflag == ' ') {
    x += xdir;
    y += ydir;
    if (player.map[x][y] < 0) mflag = '*';
    if (player.map[x][y] == 21) mflag = '*';
    if (player.map[x][y] > 400 && player.map[x][y] <500) mflag = '*';
    }
  if (player.map[x][y] < 0 ||
      (player.map[x][y] >400 && player.map[x][y] <500)) {
    if (in_arena == 'Y') mon = player.map[x][y] - 400;
      else mon = 0-player.map[x][y];
    if (in_arena == 'Y') prompt(player.monster[mon][a_mon].name);
      else prompt(player.monster[1][mon].name);
    delay(1000);
    }
  else {
    clear_prompt();
    prompt("Fizzle. . .");
    }
  }

void special24() {
  player.effect[PE_POISON] /= 2;
  }

void special25() {
  player.effect[PE_POISON] = 0;
  }

void special26() {
  player.effect[PE_LIGHT] = -1;
  }

void special27(int level) {
  int slot;
  int  i;
  char buffer[80];
  slot = 0;
  for (i=1; i<=5; i++)
    if (slot == 0 && player.party[i].hp == 0) slot = i;
  if (slot != 0) {
    player.party[slot] = monsters[u_random(NO_OF_MONSTERS)];
    while (player.party[slot].level > level ||
           player.party[slot].level < (level - 4)) {
      player.party[slot] = monsters[u_random(NO_OF_MONSTERS)];
      }
    player.party[slot].hp = u_random(player.party[slot].hp) + 1;
    player.party[slot].time = (player.level * 10) + (get_skill(SK_MAGIC) * 25);
    player.party[slot].exp = needed(player.party[slot].level) * 10;
    clear_prompt();
    sprintf(buffer,"Called a %s",player.party[slot].name);
    prompt(buffer);
    }
  }

void special28() {
  player.effect[PE_READLORE] = 20;
  }

void special29() {
  int x,y;
  for (x=player.x-1; x<=player.x+1; x++)
    for (y=player.y-1; y<=player.y+1; y++)
      if (player.map[x][y] == 41) player.map[x][y] = currentFloor;
  }

void special30() {
  int x,y;
  int xdir,ydir;
  get_dir(&xdir,&ydir);
  x = player.x + xdir;
  y = player.y + ydir;
  if (player.map[x][y] == currentFloor) {
    player.map[x][y] = 600 + (player.level * 2);
    show_map();
    show_player();
    }
  else {
    clear_prompt();
    prompt("Fizzle. . .");
    }
  }

void special31(int max) {
  int i;
  int n;
  clear_prompt();
  n = u_random(25);
  while (n > max) n = u_random(25);
  switch (n) {
    case 0:prompt("STR increased");
           if (player.stat[1] < 99) player.stat[1] += 2;
           adjust_abilities();
           break;
    case 1:prompt("DEX increased");
           if (player.stat[2] < 99) player.stat[2] += 2;
           adjust_abilities();
           break;
    case 2:prompt("CON increased");
           if (player.stat[3] < 99) player.stat[3] += 2;
           adjust_abilities();
           break;
    case 3:prompt("HP increased");
           i = u_random(10);
           player.chp += i;
           player.mhp += i;
           break;
    case 4:prompt("Mana increased");
           i = u_random(10);
           player.cmana += i;
           player.mmana += i;
           break;
    case 5:prompt("Skill increased");
           i = u_random(16) + 1;
           player.skill[i] += 200000;
           break;
    case 6:prompt("CHR increased");
           if (player.stat[6] < 99) player.stat[6] += 2;
           adjust_abilities();
           break;
    default:prompt("Fizzle...");
    }
  }

void special34() {
  int x,y;
  int xdir,ydir;
  int mon;
  get_dir(&xdir,&ydir);
  x = player.x + xdir;
  y = player.y + ydir;
  mon = 0;
  while (player.map[x][y] == 21 && mon == 0) {
    player.map[x][y] = 42;
    x += xdir;
    y += ydir;
    if (x<2 || x>98 || y<2 || y>98) mon = 1;
    player.phase = player.level;
    }
  show_map();
  }

void special36() {
  player.effect[PE_FEAR] = 0;
  }

void special37() {
  int x,y;
  for (x=1; x<=100; x++)
    for (y=1; y<=100; y++)
     if (player.map[x][y] >= 800 && player.map[x][y] < 900) {
       player.known[x][y] = 1;
       player.map[x][y] = 40;
       }
  show_screen();
  add_skill(SK_ORACLE,1);
  }

void special38() {
  player.effect[PE_FIRE] += u_random(player.diff * 5 + player.d_level / 3);
  }

void special40() {
  OBJECT_REC item;
  OBJECT_REC* pItem;
  pItem = find_linked_item(ITEM_SRATIONS);
  if (pItem != NULL) {
    item = *pItem;
    inventory(&item);
    }
  show_screen();
  }

void special41() {
  int x,y,i;
  int count;
  count = 2 + (get_skill(SK_MAGIC) / 10);
  if (in_arena == 'Y')
    for (i=1; i<=count; i++) {
      x = u_random(15) + offset_x;
      y = u_random(15) + offset_y;
      while (player.map[x][y] > 30) {
        x = u_random(15) + offset_x;
        y = u_random(15) + offset_y;
        }
      player.map[x][y] = 143;
      show_spot(x,y);
      snakes++;
      }
  }

void special42(int mon) {
  int slot;
  int x,y;
  int  i;
  slot = 0;
  for (i=1; i<=5; i++)
    if (slot == 0 && player.party[i].hp == 0) slot = i;
  if (slot != 0) {
    player.party[slot] = monsters[mon];
    player.party[slot].hp = u_random(player.party[slot].hp) + 1;
    player.party[slot].time = (player.level * 10) + (get_skill(SK_MAGIC) * 25);
    player.party[slot].exp = needed(player.party[slot].level) * 10;
    clear_prompt();
    if (in_arena == 'Y') {
      x = 11 + u_random(14); y = 11 + u_random(14);
      while (player.map[x][y] < 0 || player.map[x][y] > 200) {
        x = 11 + u_random(14); y = 11 + u_random(14);
        }
      player.map[x][y] = 300 + slot;
      show_spot(x,y);
      }
    }
  }

void special43() {
  int l;
  int x,y;
  special37();
  for (l=0; l<10; l++) 
    for (x=1; x<=100; x++)
      for (y=1; y<=100; y++)
       if (current_dungeon.level[l].map[x][y] >= 800 && current_dungeon.level[l].map[x][y] < 900) {
         current_dungeon.level[l].known[x][y] = 1;
         current_dungeon.level[l].map[x][y] = 40;
         }
//  show_screen();
  }

void special46() {
  char invoke[33];
  char buffer[80];
  char key;
  strcpy(invoke,"");
  prompt("Function ? _");
  key = 0;
  while (key != 13) {
    key = inkey();
    if (key > 31) {
      invoke[strlen(invoke) + 1] = 0;
      invoke[strlen(invoke)] = key;
      sprintf(buffer,"Function ? %s_",invoke);
      clear_prompt();
      promptNS(buffer);
      }
    if (key == 8 && strlen(invoke) > 1) {
      invoke[strlen(invoke) - 1] = 0;
      sprintf(buffer,"Function ? %s_",invoke);
      clear_prompt();
      promptNS(buffer);
      }
    }
  if (strcasecmp(invoke,"auralal") == 0) special1();
  if (strcasecmp(invoke,"litraal") == 0) special6();
  if (strcasecmp(invoke,"suraal") == 0) special15();
  if (strcasecmp(invoke,"reahl") == 0) special21();
  if (strcasecmp(invoke,"mala") == 0) special22();
  if (strcasecmp(invoke,"loeer") == 0) special28();
  if (strcasecmp(invoke,"detral") == 0) special43();
  if (strcasecmp(invoke,"idahl") == 0) special23();
  }

void special47() {
  textmode(3); textcolor(14); gotoxy(29,1);
  txt_writeln("TARDIS Operators Guide");
  txt_writeln("");
  textcolor(2);
  txt_writeln("TARDIS units only work in the Upland areas.  They do not work in dungeons");
  txt_writeln("or towns");
  txt_writeln("");
  txt_writeln("The TARDIS can be programmed for up to 10 destination points");
  txt_writeln("To program a TARDIS, manually go to the destination to be programmed, then");
  txt_writeln("press the F-key you wish to store that destination under.  You will be");
  txt_writeln("prompted for a description so you can later identify the destinations");
  txt_writeln("");
  txt_writeln("To go to a pre-programmed destination press <SHIFT> and the F-key holding");
  txt_writeln("the destination that you wish to go to.");
  txt_writeln("");
  txt_writeln("The <T>ardis log command will give you a list of all programmed destinations");
  textcolor(11);
  gotoxy(28,24); txt_write("Press any key to continue");
  inkey();
  }

void special48() {
  if (player.d_level == bottom) special(14,NULL);
  }

void special49() {
  char flag;
  char key;
  char search[33];
  int  msg;
  flag = ' ';
  while (flag == ' ') {
    textmode(3);
    gotoxy(27,1); textcolor(11);
    txt_write("Halkanar Computer IBM Clone");
    textcolor(14);
    gotoxy(10,5);
    txt_write("Search for <L>ore, or <G>eneral Information ? (Q to quit)");
    key = inkey();
    if (key == 'q' || key == 'Q') flag = '*';
    if (key == 'l' || key == 'L') {
      strcpy(search,"");
      while (strlen(search) < 5) {
        gotoxy(10,9); textcolor(9);
        txt_write("Enter Search String (5 chars min.) ? ");
        strcpy(search,"");
        readln(search);
        }
      msg = find_lore(search);
      if (msg == 0) {
        gotoxy(10,9); textcolor(12);
        txt_write("You have all the knowledge on that subject         ");
        delay(1000);
        }
      else {
        player.lore[msg] = -1;
        display_msg(msg,'L');
        }
      }
    if (key == 'g' || key == 'G') {
      strcpy(search,"");
      while (strlen(search) < 5) {
        gotoxy(10,9); textcolor(9);
        txt_write("Enter Search String (5 chars min.) ? ");
        strcpy(search,"");
        readln(search);
        }
      msg = find_gen(search);
      if (msg == 0) {
        gotoxy(10,9); textcolor(12);
        txt_write("You have all the knowledge on that subject         ");
        delay(1000);
        }
      else {
        player.gen[msg] = -1;
        display_msg(msg,'G');
        }
      }
    }
  }

void special50() {
  clear_prompt();
  if (player.quests[37] == 'Y' && player.quests[51] == 'Y' &&
      player.quests[24] == 'Y') {
    clair = '*';
    special8();
    special9();
    special22();
    special25();
    special43();
    special4();
    }
  else
    prompt("The Triad is Incomplete");
  }

void special51() {
  int i;
  int x,y;
//  int space;
  int size;
  char last;
  MESSAGE general;
  i = u_random(NO_OF_LORE) + 1;
  general = lore[i];
  while (general.region != player.region && general.region != 0) {
    i = u_random(NO_OF_LORE) + 1;
    general = lore[i];
    }
  player.lore[i] = -1;
  add_skill(SK_LORE,1);
  graphmode();
  display_scroll();
  x = 160; y = 160; size = 30;
//  space = 25;
  setcolor(0);
  while (strlen(general.message) != 0) {
    if (strlen(general.message) < size) {
      outtextxy(x,y,general.message);
      strcpy(general.message,"");
      }
    else {
      i = size;
      while (i > 0 && general.message[i] != ' ') i--;
      last = general.message[i];
      general.message[i] = 0;
      outtextxy(x,y,general.message);
      general.message[i] = last;
      i++;
      y += 19;
      strcpy(general.message,general.message+i);
      }
    }
  inkey();
  }

void special52() {
  int i;
  int x,y;
  int m_file;
  for (x=1; x<=100; x++)
    for (y=1; y<=100; y++)
      player.known[x][y] = 1;
#ifdef MINGW
  m_file = open("temp01.$$$",O_WRONLY | O_BINARY);
#else
  m_file = open("temp01.$$$",O_WRONLY);
#endif
  if (m_file < 0) {
    printf("Fatal Error: Could not open temp file\n");
    exit(1);
    }
  for (i = 0; i<NO_OF_MAPS; i++) {
    lseek(m_file,sizeof(KNOW_TYPE) * i,SEEK_SET);
    write(m_file,player.known,sizeof(KNOW_TYPE));
    }
  close(m_file);
  }

void special53() {
  int i;
  for (i=1; i<=NO_OF_GENS; i++) player.gen[i] = -1;
  for (i=1; i<=NO_OF_LORE; i++) player.lore[i] = -1;
  msg("You feel enlightened",15);
  }

void special54() {
  player.cmana = player.mmana;
  }

void special55() {
  player.mmana *= 2;
  player.cmana = player.mmana;
  msg("You feel more energized",15);
  }

void special56() {
  player.exp *= 1.05;
  if (player.exp >= player.exp_next) {
    advancement();
    show_side();
    }
  }

void special57() {
  player.exp *= 1.07;
  if (player.exp >= player.exp_next) {
    advancement();
    show_side();
    }
  }

void special58() {
  player.exp *= 1.10;
  if (player.exp >= player.exp_next) {
    advancement();
    show_side();
    }
  }

void special59() {
  player.exp *= 1.15;
  if (player.exp >= player.exp_next) {
    advancement();
    show_side();
    }
  }

void special60(OBJECT_REC* item) {
  int amt;
  if (has_intrinsic(A_NOSL) == 0) {
    if (item == NULL) {
      amt =  player.diff + (player.d_level / 3);
      } else {
      amt = (item->damage < 0) ? -item->damage : (item->damage / 2) + u_random(item->damage/2) +1;
      }
    if (has_intrinsic(A_RSSL)) amt /= 2;
    if (amt < 1) amt = 1;
    player.effect[PE_SLEEP] = amt;
    }
  }

void special61(OBJECT_REC* item) {
  int amt;
  if (has_intrinsic(A_NOFR) == 0) {
    if (item == NULL) {
      amt =  player.diff + (player.d_level / 3);
      } else {
      amt = (item->damage < 0) ? -item->damage : (item->damage / 2) + u_random(item->damage/2) +1;
      }
    if (has_intrinsic(A_RSFR)) amt /= 2;
    if (amt < 1) amt = 1;
    player.effect[PE_FEAR] += amt;
    msg("You feel fearful",15);
    }
  }

void special62(OBJECT_REC* item) {
  int amt;
  if (item == NULL) {
    amt =  u_random((player.diff * 5) + (player.d_level / 3));
    } else {
    amt = (item->damage < 0) ? -item->damage : (item->damage / 2) + u_random(item->damage/2) +1;
    }
  player.effect[PE_BLIND] = amt;
  msg("Hmmmm, who turned off the lights?",14);
  }

void special63(OBJECT_REC* item) {
  int amt;
  if (item == NULL) {
    amt =  u_random((player.diff * 5) + (player.d_level / 3));
    } else {
    amt = (item->damage < 0) ? -item->damage : (item->damage / 2) + u_random(item->damage/2) +1;
    }
  player.effect[PE_CONFUSED] = amt;
  msg("A fog clouds your mind",14);
  }

void special64() {
  player.effect[PE_CONFUSED] = 0;
  msg("You seem to think clearly again",14);
  }

void special65() {
  player.effect[PE_FEAR] = 0;
  msg("You seem much braver",14);
  }

void special66() {
  player.effect[PE_BLIND] = 0;
  show_map();
  }

void special67() {
  player.effect[PE_CONFUSED] = 0;
  player.effect[PE_FEAR] = 0;
  player.effect[PE_POISON] = 0;
  player.effect[PE_BLIND] = 0;
  show_map();
  }

void special68() {
  if (player.invent[I_RHND].otype == O_DAGR ||
      player.invent[I_RHND].otype == O_EDGE ||
      player.invent[I_RHND].otype == O_BLNT ||
      player.invent[I_RHND].otype == O_POLE ||
      player.invent[I_RHND].otype == O_BOW) {
    player.invent[I_RHND].plus++;
    player.weapon+=5;
    msg("Your weapon glows briefly",15);
    }
  }

void special69() {
  if (player.invent[I_ARMR].otype == O_ARMR) {
    player.invent[I_ARMR].plus++;
    player.armour+=5;
    msg("Your armor glows briefly",15);
    }
  }

void special70() {
  if (player.invent[I_RHND].otype == O_DAGR ||
      player.invent[I_RHND].otype == O_EDGE ||
      player.invent[I_RHND].otype == O_BLNT ||
      player.invent[I_RHND].otype == O_POLE ||
      player.invent[I_RHND].otype == O_BOW) {
    player.invent[I_RHND].plus--;
    player.weapon-=5;
    msg("Your weapon turns black",4);
    }
  }

void special71() {
  if (player.invent[I_ARMR].otype == O_ARMR) {
    player.invent[I_ARMR].plus--;
    player.armour-=5;
    msg("Your armor turns black",4);
    }
  }

void special72() {
  OBJECT_REC* i;
  i = inventory(NULL);
  if (i != NULL) {
    if (i->plus < 0) {
      i->plus = 0;
      msg("Item glows briefly",15);
      }
    }
  }

void special73() {
  int i;
  OBJECT_REC* o;
  o = inventory(NULL);
  if (o != NULL) {
    i = 1;
    while (objects[i].otype != 255) {
      if (strcmp(objects[i].name,o->name) == 0) {
        o->charges = objects[i].charges;
        msg("Item glows briefly",15);
        return;
        }
      }
    msg("Fizzle",9);
    }
  }

void special74() {
  int i;
  for (i=1; i<=19; i++)
    if (player.invent[i].otype != O_NONE &&
        player.invent[i].plus < 0) player.invent[i].plus = 0;
  for (i=1; i<=32; i++)
    if (player.pack[i].otype != O_NONE &&
        player.pack[i].plus < 0) player.pack[i].plus = 0;
  msg("Entire inventory  glows briefly",15);
  }

void special75() {
  player.torch += 10;
  msg("10 Torches added to inventory",15);
  }

void special76() {
  int i;
  i = player.diff * 5 + get_skill(8) * 5;
  player.effect[PE_LEV] += u_random(i + i + 1) + 25;
  }

void special77() {
  player.sex = (player.sex == 'F') ? 'M' : 'F';
  msg("Your body feels different",15);
  if (player.sex == 'F') {
    player.stat[1]--;
    player.stat[6]++;
    } else {
    player.stat[1]++;
    player.stat[6]--;
    }
  }

void special78() {
  player.effect[PE_CONFUSED] = 5 + u_random(25);
  msg("A fog clouds your mind",14);
  stats.counts[STAT_ALCOHOL_DRANK]++;
  }

void special79() {
  int i;
  char buffer[1000];
  i = u_random(recipe_count);
  recipe_string(i,buffer);
  saveScreen();
  display_scroll();
  show_message(buffer);
  player.lore[RECIPE_BASE+i] = 1;
  inkey();
  restoreScreen();
  }

void special80() {
  OBJECT_REC* i;
  i = inventory(NULL);
  if (i != NULL) {
    if (i->otype == O_ARMR ||
        i->otype == O_SHLD ||
        i->otype == O_HELM ||
        i->otype == O_BOOT ||
        i->otype == O_RING ||
        i->otype == O_NECK ||
        i->otype == O_DAGR ||
        i->otype == O_EDGE ||
        i->otype == O_BLNT ||
        i->otype == O_POLE ||
        i->otype == O_BOW) {
      if (i->num_sockets < 3 && i->effect != E_LGCY) {
        i->num_sockets++;
        stats.counts[STAT_SOCKETS_ADDED]++;
        }
      }
    }
  graphmode();
  show_map();
  show_sm_map();
  show_side();
  show_player();
  }

void special81() {
  OBJECT_REC* i;
  i = inventory(NULL);
  if (i != NULL) {
    if (i->otype == O_ARMR ||
        i->otype == O_SHLD ||
        i->otype == O_HELM ||
        i->otype == O_BOOT ||
        i->otype == O_ROBE ||
        i->otype == O_RING ||
        i->otype == O_NECK ||
        i->otype == O_DAGR ||
        i->otype == O_EDGE ||
        i->otype == O_BLNT ||
        i->otype == O_POLE ||
        i->otype == O_BOW) {
      if (i->effect != E_LGCY) {
        i->num_enchantments = 0;
        i->enchantments[0] = 0;
        i->enchantments[1] = 0;
        i->enchantments[2] = 0;
        }
      }
    }
  graphmode();
  show_map();
  show_sm_map();
  show_side();
  show_player();
  }

void special82() {
  OBJECT_REC* i;
  i = inventory(NULL);
  if (i != NULL) {
    if (i->otype == O_ARMR ||
        i->otype == O_SHLD ||
        i->otype == O_HELM ||
        i->otype == O_BOOT ||
        i->otype == O_RING ||
        i->otype == O_NECK ||
        i->otype == O_DAGR ||
        i->otype == O_EDGE ||
        i->otype == O_BLNT ||
        i->otype == O_POLE ||
        i->otype == O_BOW) {
      if (i->effect != E_LGCY) {
        i->sockets[0] = 0;
        i->sockets[1] = 0;
        i->sockets[2] = 0;
        }
      }
    }
  graphmode();
  show_map();
  show_sm_map();
  show_side();
  show_player();
  }

void special83() {
  int i;
  int o;
  OBJECT_REC item;
  OBJECT_REC* pItem;
  o = -1;
  while (o < 0) {
    i = u_random(20);
    if (u_random(20) >= i) o = i;
    }
  pItem = find_linked_item(300+o);
  if (pItem != NULL) {
    item = *pItem;
    inventory(&item);
    }
  show_screen();
  }

void special84() {
  int i;
  int o;
  OBJECT_REC item;
  OBJECT_REC* pItem;
  o = -1;
  while (o < 0) {
    i = u_random(20);
    if (u_random(20) >= i) o = i;
    }
  pItem = find_linked_item(360+o);
  if (pItem != NULL) {
    item = *pItem;
    inventory(&item);
    }
  show_screen();
  }

void special85() {
  OBJECT_REC item;
  int j;
  j = u_random(NO_OF_OBJECTS) + 1;
  while ( objects[j].level == 0 ||
          objects[j].control2 < 0 ||
          objects[j].rarity == 0 ||
         u_random(2500) >= objects[j].rarity) {
     j = u_random(NO_OF_OBJECTS) + 1;
     }
  item = objects[j];
  item.level = -1;
  inventory(&item);
  show_screen();
  }

void special86() {
  charmmonster();
  }

void special87() {
  player.effect[PE_ROOT] = 0;
  }

void special88() {
  int i;
  char buffer[20];
  i = get_skill(SK_HEAL);
  if (i < 1) i = 1;
  if (player.effect[PE_HEROIC] == 2) i *= 1.5;
  if (player.effect[PE_HEROIC] == 4) i *= 2;
  if (player.chp < get_mhp()) add_skill(SK_HEAL,1);
  player.chp += i;
  if (player.chp > get_mhp()) player.chp = get_mhp();
  sprintf(buffer,"Healed %d",i);
  msg(buffer,15);
  }

void special89(int control) {
  int i;
  char buffer[64];
  i = 0;
  if (player.effect[PE_POLYTIME] > 0) {
    player.chp -= monsters[player.effect[PE_POLYMORPH]].hp;
    player.mhp -= monsters[player.effect[PE_POLYMORPH]].hp;
    }
  while (monsters[i].speed < 999) {
    if (monsters[i].number == control) {
      player.effect[PE_POLYMORPH] = i;
      player.effect[PE_POLYTIME] = player.level * 25;
      player.chp += monsters[i].hp;
      player.mhp += monsters[i].hp;
      sprintf(buffer,"Became %s",monsters[i].name);
      msg(buffer,15);
      return;
      }
    i++;
    }
  msg("Fizzle...",15);
  }

void special90(int mtype) {
  int x,y;
  int r;
  NPC_REC* monster;
  r = 1;
  r += (get_skill(SK_MAGIC) / 15);
  for (y=player.y-r; y<=player.y+r;y++)
    for (x=player.x-r; x<=player.x+r;x++) {
      monster = get_monster(x,y);
      if (monster != NULL && (mtype == 0 || monster->mtype == mtype)) {
        monster->special2 |= M2_PACIFIED;
        }
      }
  }

void special91(int range) {
  int x,y;
  int lx,ly;
  target(100,1,-1);
  x = target_x;
  y = target_y;
  for (ly=y-range; ly <=y+range; ly++)
    for (lx=x-range; lx <=x+range; lx++)
      if (lx > 1 && lx < 100 && ly > 1 && ly < 100)
         if (los(x,y,lx,ly,'Y')) {
           player.known[lx][ly] = 1;
           show_spot(lx,ly);
           }
  }

void special92() {
  player.effect[PE_COLD] += u_random(player.diff * 5 + player.d_level / 3);
  }

void special93() {
  player.effect[PE_ELEC] += u_random(player.diff * 5 + player.d_level / 3);
  }

void special94() {
  player.effect[PE_ARCN] += u_random(player.diff * 5 + player.d_level / 3);
  }

void special95(int amount) {
  player.mhp += amount;
  player.chp += amount;
  }

void special96() {               /* crown */
  if (triad_equipped()) {
    special8();
    special9();
    special21();
    special28();
    }
  else
    prompt("The Triad is Incomplete");
  }

void special97() {               /* scepter */
  if (triad_equipped()) {
    special43();
    special4();
    special36();
    special87();
    }
  else
    prompt("The Triad is Incomplete");
  }

void special98() {               /* orb */
  if (triad_equipped()) {
    special25();
    special6();
    special67();
    }
  else
    prompt("The Triad is Incomplete");
  }

void attempt_move(int x,int y,int xdir,int ydir) {
  int i;
  int can_move;
  int mx[2];
  int my[2];
  can_move = 0;
  if (player.map[x][y] < 0) can_move = -1;
  if (player.map[x][y] >= 1000) can_move = -1;
  if (player.map[x][y] >=300 && player.map[x][y] <= 500) can_move = -1;
sprintf(buffer,"dir=%d,%d",xdir,ydir);
msg(buffer,15);
if (can_move == 0) msg("Cannot move",15);
  if (can_move == 0) return;
  if (player.map[x+xdir][y+ydir] == currentFloor) {
msg("Move base",15);
    player.map[x+xdir][y+ydir] = player.map[x][y];
    player.map[x][y] = currentFloor;
    return;
    }
  for (i=0; i<2; i++) {
    mx[i] = 0;
    my[i] = 0;
    }
  if (xdir == 0) {
    mx[0] = -1; my[0] = ydir;
    mx[1] = 1; my[0] = ydir;
    }
  else if (ydir == 0) {
    mx[0] = xdir; my[0] = -1;
    mx[1] = xdir; my[0] = 1;
    }
  else {
    mx[0] = xdir; my[0] = 0;
    mx[1] = 0; my[1] = ydir;
    }
  for (i=0; i<2; i++) {
    if (player.map[x+mx[i]][y+my[i]] == currentFloor) {
      player.map[x+mx[i]][y+my[i]] = player.map[x][y];
      player.map[x][y] = currentFloor;
      return;
      }
    }
  }

void special99() {
  int x,y;
  int str;
  str = (player.level * 4);
  if (str > 90) str = 90;
  for (y=player.y-1; y<=player.y+1; y++)
    for (x=player.x-1; x<=player.x+1; x++)
      if (x != player.x || y != player.y) {
        if (player.map[x][y] != currentFloor) attempt_move(x,y,x-player.x,y-player.y);
        if (player.map[x][y] == currentFloor) player.map[x][y] = 600 + str;
        }
  show_map();
  show_player();
  }

void special100() {
  int cores;
  int shards;
  int i;
  OBJECT_REC item;
  OBJECT_REC* pItem;
  cores = 0;
  shards = 0;
  for (i=1; i<20; i++) {
    if (player.invent[i].otype == O_MISC && strcasecmp(player.invent[i].name,"sun core") == 0) cores++;
    if (player.invent[i].otype == O_MISC && strcasecmp(player.invent[i].name,"sun shard") == 0) shards++;
    }
  for (i=0; i<33; i++) {
    if (player.pack[i].otype == O_MISC && strcasecmp(player.pack[i].name,"sun core") == 0) cores++;
    if (player.pack[i].otype == O_MISC && strcasecmp(player.pack[i].name,"sun shard") == 0) shards++;
    }
  if (cores < 1 || shards < 8) return;
  cores = 1;
  shards = 8;
  for (i=1; i<20; i++) {
    if (player.invent[i].otype == O_MISC && strcasecmp(player.invent[i].name,"sun core") == 0 && cores > 0) {
      cores--;
      player.invent[i].otype = O_NONE;
      }
    if (player.invent[i].otype == O_MISC && strcasecmp(player.invent[i].name,"sun shard") == 0 && shards > 0) {
      shards--;
      player.invent[i].otype = O_NONE;
      }
    }
  for (i=0; i<33; i++) {
    if (player.pack[i].otype == O_MISC && strcasecmp(player.pack[i].name,"sun core") == 0 && cores > 0) {
      cores--;
      player.pack[i].otype = O_NONE;
      }
    if (player.pack[i].otype == O_MISC && strcasecmp(player.pack[i].name,"sun shard") == 0 && shards > 0) {
      shards--;
      player.pack[i].otype = O_NONE;
      }
    }
  pItem = find_linked_item(ITEM_SUNSTONE);
  if (pItem != NULL) {
    item = *pItem;
    item.level = -1;
    inventory(&item);
    }
  show_screen();
  }

void special101() {
  if (player.in_city == 'Y') {
    exitf = 10;
    player.in_city = 'N';
    player.d_level = player.effect[PE_DLEVEL];
    player.dungeon_number = player.effect[PE_DUNGEON];
    strcpy(player.d_name,links[player.dungeon_number].name);
    player.diff = links[player.dungeon_number].diff;
    player.land_x = links[player.dungeon_number].x;
    player.land_y = links[player.dungeon_number].y;
    player.region = links[player.dungeon_number].region;
    used_sunstone = 'Y';
    }
  else {
    player.effect[PE_DLEVEL] = player.d_level;
    player.effect[PE_DUNGEON] = player.dungeon_number;
    player.d_level = 0;
    }
  }

void special102() {
  int  x,y;
  int  xdir,ydir;
  if (player.in_city != 'N') return;
  if (player.gateway == '*') return;
  get_dir(&xdir,&ydir);
  x = player.x + xdir;
  y = player.y + ydir;
  if (x > 1 && x < 99 && y > 1 && y < 99)
    if (player.map[x][y] == 21) {
      player.map[x][y] = currentFloor;
      show_spot(x,y);
      }
  }

void generic_gacha() {
  int i;
  int flag;
  i = 0;
  while (objects[i].link != 999) {
    flag = -1;
    if ((objects[i].align & 0x20000000) != 0) flag = 0;
    if (objects[i].otype == O_JEWL) flag = 0;
    if (objects[i].effect == E_SPCL &&
        objects[i].control >= 89000 &&
        objects[i].control <90000) flag = 0;
    if (objects[i].effect == E_SPCL && objects[i].control == 103) flag = 0;
    if (objects[i].control2 < 0 && -objects[i].control2 != date.tm_mon) flag = 0;
    if (flag) gacha[num_gacha++] = i;
    i++;
    }
  }

void jewel_gacha() {
  int i;
  i = 0;
  while (objects[i].link != 999) {
    if (objects[i].otype == O_JEWL) {
      gacha[num_gacha++] = i;
      }
    i++;
    }
  }

void figurine_gacha() {
  int i;
  i = 0;
  while (objects[i].link != 999) {
    if (objects[i].effect == E_SPCL &&
        objects[i].control >= 89000 &&
        objects[i].control <90000) {
      gacha[num_gacha++] = i;
      }
    i++;
    }
  }

void card_gacha() {
  int i;
  i = 0;
  while (objects[i].link != 999) {
    if (objects[i].otype == O_CARD) {
      gacha[num_gacha++] = i;
      }
    i++;
    }
  }

void special103(int whichone) {
  int i;
  OBJECT_REC item;
  int flag;
  num_gacha = 0;
  switch (whichone) {
    case 1:generic_gacha(); break;
    case 2:jewel_gacha(); break;
    case 3:figurine_gacha(); break;
    case 4:card_gacha(); break;
    }
  if (num_gacha == 0) return;
  flag = 0;
  while (flag == 0) {
    i = u_random(num_gacha);
    if (u_random(10000) <= objects[gacha[i]].rarity) flag = -1;
    }
  item = objects[gacha[i]];
  if (item.level > 0) item.level = -item.level; else item.level = -1;
  inventory(&item);
  show_screen();
  }

/* armor deck */
void special104() {
  int p;
  int i;
  OBJECT_REC item;
  i = 0;
  p = -1;
  while (objects[i].link != 999) {
    if (objects[i].otype == O_ARMR && objects[i].effect == E_LGCY) {
      if ((objects[i].align & (1 << player.class)) != 0)  {
        if (p < 0 || objects[i].damage > objects[p].damage) p = i;
        }
      }
    i++;
    }
  if (p > 0) {
    item = objects[p];
    if (item.level > 0) item.level = -item.level;
    if (item.level == 0) item.level = -1;
    inventory(&item);
    show_screen();
    }
  }

/* item deck */
void special105() {
  int i;
  char flag;
  OBJECT_REC item;
  flag = ' ';
  while (flag == ' ') {
    flag = '*';
    i = u_random(NO_OF_OBJECTS) + 1;
    if (objects[i].align & 0x10000000) flag = ' ';
    if (objects[i].rarity > 100) flag = ' ';
    if (objects[i].effect == E_MUTA) flag = ' ';
    if (objects[i].effect == E_LGND) flag = ' ';
    if (objects[i].effect == E_RSPL) flag = ' ';
    if (objects[i].otype == O_CARD) flag = ' ';
    if (objects[i].otype == O_GACH) flag = ' ';
    if (objects[i].otype == O_FOOD) flag = ' ';
    if (objects[i].control2 < 0) flag = ' ';
    }
  item = objects[i];
  if (item.level > 0) item.level = -item.level;
  if (item.level == 0) item.level = -1;
  inventory(&item);
  show_screen();
  }

/* weapon deck */
void special106() {
  int p;
  int i;
  OBJECT_REC item;
  i = 0;
  p = -1;
  while (objects[i].link != 999) {
    if (objects[i].otype == classes[player.class-1].weapon_affinity)
      if (objects[i].effect == E_LGCY)
        if ((objects[i].align & (1 << player.class)) != 0)  {
          if (p < 0 || objects[i].damage > objects[p].damage) p = i;
          }
    i++;
    }
  if (p > 0) {
    item = objects[p];
    if (item.level > 0) item.level = -item.level;
    if (item.level == 0) item.level = -1;
    inventory(&item);
    show_screen();
    }
  }

/* class deck */
void special107() {
  int i;
  for (i=0; i<5; i++) {
    if (player.level < 95) {
      player.exp = player.exp_next;
      advancement();
      }
    }
  show_screen();
  }

/* monster deck */
void special108() {
  }

void showCard(char* title,char* message) {
  msg(title,15);
  msg(message,14);
  }

void socketItem(OBJECT_REC* item,int dir) {
  if (dir > 0) {
    if (item->num_sockets == 3) return;
    item->num_sockets++;
    item->sockets[item->num_sockets-1] = 0;
    }
  else {
    if (item->num_sockets == 0) return;
    item->sockets[item->num_sockets-1] = 0;
    item->num_sockets--;
    }
  }

/* deck of many things */
void special109(OBJECT_REC* item) {
  int i;
  int j;
  int max;
  int card;
  if (item == NULL) return;
  if (item->control2 == 0) return;
  card = u_random(30);
  while ((item->control2 & (1 << card)) == 0) card = u_random(30);
  item->control2 ^= (1 << card);
  switch (card+1) {
    case 1: 
            showCard("Life","Double your life");
            player.chp += player.mhp;
            player.mhp *= 2;
            break;
    case 2:
            showCard("Rich","Gain 1,000,000 gold");
            player.bank += 1000000;
            break;
    case 3:
            showCard("Offense","Weapon gains +1");
            if (is_weapon(&(player.invent[I_RHND]))) player.invent[I_RHND].plus++;
            break;
    case 4:
            showCard("Defense","Armor gains +1");
            if (player.invent[I_ARMR].otype != O_NONE) player.invent[I_ARMR].plus++;
            break;
    case 5:
            showCard("Experience","Gain 1 level");
            player.exp = player.exp_next;
            advancement();
            player.exp += ((player.exp_next - player.exp) / 2);
            break;
    case 6:
            showCard("Skilled","Gain +5 in all skills");
            for (i=1; i<=24; i++) {
              player.skill[i] += 500000;
              if (player.skill[i] > 9900000) player.skill[i] = 9900000;
              }
            break;
    case 7:
            showCard("Buffed","Gain +5 to all stats");
            for (i=1; i<7; i++) {
              player.stat[i] += 5;
              if (player.stat[i] > 99) player.stat[i] = 99;
              }
            break;
    case 8:
            showCard("Enhanced","Gain 1 socket on equipment");
            if (is_weapon(&(player.invent[I_RHND]))) socketItem(&(player.invent[I_RHND]),1);
            if (is_weapon(&(player.invent[I_LHND]))) socketItem(&(player.invent[I_LHND]),1);
            if (player.invent[I_SHLD].otype != O_NONE) socketItem(&(player.invent[I_SHLD]),1);
            if (player.invent[I_ARMR].otype != O_NONE) socketItem(&(player.invent[I_ARMR]),1);
            if (player.invent[I_ROBE].otype != O_NONE) socketItem(&(player.invent[I_ROBE]),1);
            if (player.invent[I_BOOT].otype != O_NONE) socketItem(&(player.invent[I_BOOT]),1);
            if (player.invent[I_HELM].otype != O_NONE) socketItem(&(player.invent[I_HELM]),1);
            if (player.invent[I_NCK1].otype != O_NONE) socketItem(&(player.invent[I_NCK1]),1);
            if (player.invent[I_NCK2].otype != O_NONE) socketItem(&(player.invent[I_NCK2]),1);
            if (player.invent[I_RNG1].otype != O_NONE) socketItem(&(player.invent[I_RNG1]),1);
            if (player.invent[I_RNG2].otype != O_NONE) socketItem(&(player.invent[I_RNG2]),1);
            if (player.invent[I_RNG3].otype != O_NONE) socketItem(&(player.invent[I_RNG3]),1);
            if (player.invent[I_RNG4].otype != O_NONE) socketItem(&(player.invent[I_RNG4]),1);
            break;
    case 9:
            if (player.level < 35) showCard("Elevated","Instant level 35");
              else showCard("Elevated", "Gain 5 levels");
            max = 35;
            if (player.level >= 35) max = player.level + 5;
            if (max > 99) max = 99;
            while (player.level < max) {
              player.exp = player.exp_next;
              advancement();
              }
            break;
    case 10:
             showCard("Spellcraft","Learn all class spells");
             i = 0;
             while (spells[i].effect != 999) {
               if (spells[i].allign == classes[player.class-1].spell_group) {
                 j = 1;
                 while (j > 0 && spellbook[j] != 0) {
                   if (spellbook[j] == i) j = -1;
                   else j++;
                   }
                 if (j > 0) spellbook[j] = i;
                 }
               i++;
               }
             break;
    case 11:
             showCard("Enlightened","Learn all message/lore");
             for (i=0; i<4000; i++) {
               player.gen[i] = 1;
               player.lore[i] = 1;
               }
             break;
    case 12:
            showCard("Survival","Gain +1 on all equipment");
            if (is_weapon(&(player.invent[I_RHND]))) player.invent[I_RHND].plus++;
            if (is_weapon(&(player.invent[I_LHND]))) player.invent[I_LHND].plus++;
            if (player.invent[I_SHLD].otype != O_NONE) player.invent[I_SHLD].plus++;
            if (player.invent[I_ARMR].otype != O_NONE) player.invent[I_ARMR].plus++;
            if (player.invent[I_ROBE].otype != O_NONE) player.invent[I_ROBE].plus++;
            if (player.invent[I_BOOT].otype != O_NONE) player.invent[I_BOOT].plus++;
            if (player.invent[I_HELM].otype != O_NONE) player.invent[I_HELM].plus++;
            if (player.invent[I_NCK1].otype != O_NONE) player.invent[I_NCK1].plus++;
            if (player.invent[I_NCK2].otype != O_NONE) player.invent[I_NCK2].plus++;
            if (player.invent[I_RNG1].otype != O_NONE) player.invent[I_RNG1].plus++;
            if (player.invent[I_RNG2].otype != O_NONE) player.invent[I_RNG2].plus++;
            if (player.invent[I_RNG3].otype != O_NONE) player.invent[I_RNG3].plus++;
            if (player.invent[I_RNG4].otype != O_NONE) player.invent[I_RNG4].plus++;
            break;
    case 13:
             showCard("Craftsman","Learn all recipes");
             for (i=4000; i<5000; i++) {
               player.lore[i] = 1;
               }
             break;
    case 16:
             showCard("Death","Death!!!");
             player.chp = -1000;
             break;
    case 17:
             showCard("Poverty","Lose all wordly possessions");
             for (i=0; i<20; i++) player.invent[i].otype = O_NONE;
             for (i=0; i<33; i++) player.pack[i].otype = O_NONE;
             player.gold_coins = 0;
             player.mithril_coins = 0;
             player.adamantite_coins = 0;
             player.bank = 0;
             for (i=0; i<1000; i++) player.hole[i].otype = O_NONE;
             for (i=0; i<5; i++)
               for (j=0; j<500; j++) player.houses[i].inventory[j].otype = O_NONE;
             break;
    case 18:
            showCard("Dullness","Weapon loses -1");
            if (is_weapon(&(player.invent[I_RHND]))) player.invent[I_RHND].plus--;
            break;
    case 19:
            showCard("Rusty","Armor loses -1");
            if (player.invent[I_ARMR].otype != O_NONE) player.invent[I_ARMR].plus--;
            break;
    case 20:
            showCard("Tripped","Lose 1 level");
            player.level--;
            player.chp -= classes[player.class].hitdie;
            player.mhp -= classes[player.class].hitdie;
            if (player.level <= 0) player.chp = -1000;
            break;
    case 21:
            showCard("Unskilled","Lose -5 in all skills");
            for (i=1; i<=24; i++) {
              player.skill[i] -= 500000;
              if (player.skill[i] < 0) player.skill[i] = 0;
              }
            break;
    case 22:
            showCard("Unbuffed","Lose -5 to all stats");
            for (i=1; i<7; i++) {
              player.stat[i] -= 5;
              if (player.stat[i] < 1) player.chp = -1000;
              }
            break;
    case 23:
            showCard("Disenhanted","Lose 1 socket on equipment");
            if (is_weapon(&(player.invent[I_RHND]))) socketItem(&(player.invent[I_RHND]),-1);
            if (is_weapon(&(player.invent[I_LHND]))) socketItem(&(player.invent[I_LHND]),-1);
            if (player.invent[I_SHLD].otype != O_NONE) socketItem(&(player.invent[I_SHLD]),-1);
            if (player.invent[I_ARMR].otype != O_NONE) socketItem(&(player.invent[I_ARMR]),-1);
            if (player.invent[I_ROBE].otype != O_NONE) socketItem(&(player.invent[I_ROBE]),-1);
            if (player.invent[I_BOOT].otype != O_NONE) socketItem(&(player.invent[I_BOOT]),-1);
            if (player.invent[I_HELM].otype != O_NONE) socketItem(&(player.invent[I_HELM]),-1);
            if (player.invent[I_NCK1].otype != O_NONE) socketItem(&(player.invent[I_NCK1]),-1);
            if (player.invent[I_NCK2].otype != O_NONE) socketItem(&(player.invent[I_NCK2]),-1);
            if (player.invent[I_RNG1].otype != O_NONE) socketItem(&(player.invent[I_RNG1]),-1);
            if (player.invent[I_RNG2].otype != O_NONE) socketItem(&(player.invent[I_RNG2]),-1);
            if (player.invent[I_RNG3].otype != O_NONE) socketItem(&(player.invent[I_RNG3]),-1);
            if (player.invent[I_RNG4].otype != O_NONE) socketItem(&(player.invent[I_RNG4]),-1);
            break;
    case 24:
            showCard("Knockback","Reduced to level 1");
            player.level = 1;
            player.mhp = classes[player.class-1].hitdie;
            player.chp = player.mhp;
            player.exp = 0;
            player.exp_next = classes[player.class-1].first_exp;
            player.mmana = 0;
            if (player.level >= classes[player.class-1].becomes_caster) player.mmana = classes[player.class-1].mana;
            player.cmana = player.mmana;
            break;
    case 25:
            showCard("Forgetfull","Forget all known spells");
            for (i=0; i<1000; i++) spellbook[i] = 0;
            break;
    case 26:
             showCard("Senility","Forget all message/lore");
             for (i=0; i<4000; i++) {
               player.gen[i] = 0;
               player.lore[i] = 0;
               }
             break;
    case 27:
            showCard("Archaic","Lose -1 on all equipment");
            if (is_weapon(&(player.invent[I_RHND]))) player.invent[I_RHND].plus--;
            if (is_weapon(&(player.invent[I_LHND]))) player.invent[I_LHND].plus--;
            if (player.invent[I_SHLD].otype != O_NONE) player.invent[I_SHLD].plus--;
            if (player.invent[I_ARMR].otype != O_NONE) player.invent[I_ARMR].plus--;
            if (player.invent[I_ROBE].otype != O_NONE) player.invent[I_ROBE].plus--;
            if (player.invent[I_BOOT].otype != O_NONE) player.invent[I_BOOT].plus--;
            if (player.invent[I_HELM].otype != O_NONE) player.invent[I_HELM].plus--;
            if (player.invent[I_NCK1].otype != O_NONE) player.invent[I_NCK1].plus--;
            if (player.invent[I_NCK2].otype != O_NONE) player.invent[I_NCK2].plus--;
            if (player.invent[I_RNG1].otype != O_NONE) player.invent[I_RNG1].plus--;
            if (player.invent[I_RNG2].otype != O_NONE) player.invent[I_RNG2].plus--;
            if (player.invent[I_RNG3].otype != O_NONE) player.invent[I_RNG3].plus--;
            if (player.invent[I_RNG4].otype != O_NONE) player.invent[I_RNG4].plus--;
            break;
    case 28:
             showCard("Babbling","Forget all recipes");
             for (i=4000; i<5000; i++) {
               player.lore[i] = 0;
               }
             break;
    default:
             showCard("Blank","Blank card");
             break;
    }
  show_screen();
  }

void special110(OBJECT_REC* item) {
  int i;
  char buffer[1000];
  if (item == NULL) return;
  i = item->control2;
  recipe_string(i,buffer);
  saveScreen();
  display_scroll();
  show_message(buffer);
  player.lore[RECIPE_BASE+i] = 1;
  inkey();
  restoreScreen();

  }

void special(int whichone,OBJECT_REC* item) {
  int control;
  control = 0;
  if (whichone > 1000) {
    control = whichone % 1000;
    whichone = whichone / 1000;
    }
  switch (whichone) {
    case  1: if (in_arena != 'Y') special1(); break;
    case  2: if (in_arena != 'Y') if (player.gateway != '*') special2(); break;
    case  3:special3(); break;
    case  4:special4(); break;
    case  5: if (in_arena != 'Y') special5(); break;
    case  6: if (in_arena != 'Y') special6(); break;
    case  7: if (in_arena != 'Y') special7(); break;
    case  8: if (in_arena != 'Y') special8(); break;
    case  9: if (in_arena != 'Y') special9(); break;
    case 10:special10(); break;
    case 11:special11(); break;
    case 12:special12(); break;
    case 13:special13(); break;
    case 14: if (in_arena != 'Y') if (player.gateway != '*') special14(); break;
    case 15: if (in_arena != 'Y') if (player.gateway != '*') special15(); break;
    case 16:special16(); break;
    case 17:special17(); break;
    case 18:special18(); break;
    case 19:special19(); break;
    case 20:special20(); break;
    case 21:special21(); break;
    case 22:special22(); break;
    case 23:special23(); break;
    case 24:special24(); break;
    case 25:special25(); break;
    case 26: if (in_arena != 'Y') special26(); break;
    case 27:special27(5); break;
    case 28:special28(); break;
    case 29: if (in_arena != 'Y') special29(); break;
    case 30: if (in_arena != 'Y') special30(); break;
    case 32:special27(10); break;
    case 33:special27(15); break;
    case 34: if (in_arena != 'Y') special34(); break;
    case 36:special36(); break;
    case 37: if (in_arena != 'Y') special37(); break;
    case 38:special38(); break;
    case 39:special42(78); break;
    case 40:special40(); break;
    case 41: if (in_arena == 'Y') special41(); break;
    case 42:special42(1); break;
    case 43: if (in_arena != 'Y') special43(); break;
    case 44:special42(11); break;
    case 45:special42(13); break;
    case 46: if (in_arena != 'Y') special46(); break;
    case 47: if (in_arena != 'Y') special47(); break;
    case 48: if (in_arena != 'Y') special48(); break;
    case 49: if (in_arena != 'Y') special49(); break;
    case 50: if (in_arena != 'Y') special50(); break;
    case 51: if (in_arena != 'Y') special51(); break;
    case 52: if (in_arena != 'Y') special52(); break;
    case 53: if (in_arena != 'Y') special53(); break;
    case 54:special54(); break;
    case 55:special55(); break;
    case 56:special56(); break;
    case 57:special57(); break;
    case 58:special58(); break;
    case 59:special59(); break;
    case 60:special60(item); break;
    case 61:special61(item); break;
    case 62:special62(item); break;
    case 63:special63(item); break;
    case 64:special64(); break;
    case 65:special65(); break;
    case 66:special66(); break;
    case 67:special67(); break;
    case 68:special68(); break;
    case 69:special69(); break;
    case 70:special70(); break;
    case 71:special71(); break;
    case 72:special72(); break;
    case 73:special73(); break;
    case 74:special74(); break;
    case 75:special75(); break;
    case 76:special76(); break;
    case 77:special77(); break;
    case 78:special78(); break;
    case 79:special79(); break;
    case 80:special80(); break;
    case 81:special81(); break;
    case 82:special82(); break;
    case 83:special83(); break;
    case 84:special84(); break;
    case 85:special85(); break;
    case 86:special86(); break;
    case 87:special87(); break;
    case 88:special88(); break;
    case 89:special89(control); break;
    case 90: if (in_arena != 'Y') special90(control); break;
    case 91: if (in_arena != 'Y') special91(control); break;
    case 92:special92(); break;
    case 93:special93(); break;
    case 94:special94(); break;
    case 95:special95(item->control2);
    case 96:special96(); break;
    case 97:special97(); break;
    case 98:special98(); break;
    case 99:special99(); break;
    case 100:special100(); break;
    case 101:special101(); break;
    case 102:special102(); break;
    case 103:special103(item->control2); break;
    case 104:special104(); break;
    case 105:special105(); break;
    case 106:special106(); break;
    case 107:special107(); break;
    case 108:special108(); break;
    case 109:special109(item); break;
    case 110:special110(item); break;
    }
  }

void socket_item(OBJECT_REC* obj) {
  int slot;
  OBJECT_REC* item;
  item = inventory(NULL);
  slot = -1;
  if (item != NULL) {
    if (item->effect == E_LGCY) return;
    if (item->num_sockets >= 1 && item->sockets[0] == 0) slot = 0;
    else if (item->num_sockets >= 2 && item->sockets[1] == 0) slot = 1;
    else if (item->num_sockets >= 3 && item->sockets[2] == 0) slot = 2;
    if (slot >= 0) {
      obj->otype = O_NONE;
      item->sockets[slot] = obj->control;
      adjust_abilities();
      }
    }
  }

void enchant(int ench,int limit) {
  OBJECT_REC* i;
  char success;
  success = ' ';
  i = inventory(NULL);
  if (i != NULL) {
    if (i->otype == O_ARMR ||
        i->otype == O_SHLD ||
        i->otype == O_HELM ||
        i->otype == O_BOOT ||
        i->otype == O_ROBE ||
        i->otype == O_RING ||
        i->otype == O_NECK ||
        i->otype == O_DAGR ||
        i->otype == O_EDGE ||
        i->otype == O_BLNT ||
        i->otype == O_POLE ||
        i->otype == O_BOW) {
      if (i->effect == E_LGCY) success = 'N';
      else if (i->num_enchantments < 3 && i->num_enchantments < limit) {
        i->num_enchantments++;
        i->enchantments[i->num_enchantments-1] = ench;
        stats.counts[STAT_ENCHANTMENTS]++;
        }
      else success = 'N';
      }
    }
  graphmode();
  show_map();
  show_sm_map();
  show_side();
  show_player();
  if (success == 'N') msg("Fizzle. . .",4);
  show_messages();
  }

void perform_effect(OBJECT_REC* obj) {
  int i;
  int d;
  char buffer[40];
  OBJECT_REC* item;
  int amt;
  i = 0;
  while (trophies[i].criteria_type < 999) {
    if (trophies[i].criteria_type == TC_TYPE) {
/*
      if (obj->otype == O_SCRL) stats.counts[STAT_SCROLLS_READ]++;
      else if (obj->otype == O_POTN) stats.counts[STAT_POTIONS_DRUNK]++;
      else if (obj->otype == O_FOOD) stats.counts[STAT_MEALS_EATEN]++;
*/
      if (obj->otype == trophies[i].control[0])
        stats.counts[trophies[i].control[2]]++;
      }
    if (trophies[i].criteria_type == TC_ITEM) {
      if (obj->link == trophies[i].control[0]) stats.counts[trophies[i].control[2]]++;
      if (trophies[i].control[3] > 0)
        if (obj->link == trophies[i].control[3]) stats.counts[trophies[i].control[5]]++;
      }
    if (trophies[i].criteria_type == TC_ITEMR) {
      if (obj->link >= trophies[i].control[0] && obj->link <= trophies[i].control[1]) {
        stats.counts[trophies[i].control[2]] |= (1 << (obj->link - trophies[i].control[0]));
        }
      }
    i++;
    }

  if (obj->effect == E_POSN) stats.counts[STAT_POISONED]++;

  if (obj->charges == 0) obj->otype = O_NONE;
  if (obj->user_hp != 0 && player.chp < get_mhp()) {
    d = (obj->user_hp > 0) ? (obj->user_hp / 2) + u_random(obj->user_hp / 2) : -obj->user_hp;
    if (obj->otype == O_POTN) d *= (1.0 + get_skill(SK_MED) / 100.0);
    do_heal(d,0);
    if (obj->otype == O_POTN) add_skill(SK_MED,1);
    }
  if (obj->user_health > 0 && player.health < 100) {
    player.health += (obj->user_health / 2) + u_random(obj->user_health /2);
    }
  if (obj->user_health < 0 && player.health < 100) {
    player.health -= obj->user_health;
    }
  if (obj->effect == E_MANA) {
    if (obj->control < 0) player.cmana -= obj->control;
      else player.cmana += (obj->control / 2) + u_random(obj->control / 2);
    if (player.cmana > get_mmana()) player.cmana = get_mmana();
    }
  if (obj->effect == E_ITEM) {
    item = find_linked_item(obj->control);
    if (item != NULL) {
      saveScreen();
      inventory(item);
      restoreScreen();
      }
    }
  if (obj->effect == E_DAMG) {
    i = u_random(obj->control);
    sprintf(buffer,"Took %d damage",i);
    msg(buffer,12);
    stats_take_damage(i);
    player.chp -= i;
    }
  if (obj->effect == E_SOCK) socket_item(obj);
  if (obj->effect == E_ATCK)
    switch (obj->control) {
      case 1:touch(obj->damage,0); break;
      case 2:missile(obj->damage,0,0); break;
      case 3:area9(obj->damage,0,player.x,player.y); break;
      case 4:area25(obj->damage,0,player.x,player.y); break;
      case 5:missile(obj->damage,0,1); break;
      }
  if (obj->effect == E_ARMR) {
    player.effect[PE_PROT] = player.level * 8;
    player.effect[PE_APROT] = obj->control * player.level;
    }
  if (obj->effect == E_FEAR) fear(obj->control);
  if (obj->effect == E_SLEP) do_sleep();
  if (obj->effect == E_TELE) teleport();
  if (obj->effect == E_SPCL) special(obj->control,obj);
  if (obj->effect == E_POSN) {
    amt = u_random(player.diff*5+player.d_level /3);
    if (has_intrinsic(A_NOPS)) amt = 0;
    if (has_intrinsic(A_RSPS) && u_random(100) < 50) amt = amt / 2;
    player.effect[PE_POISON] += amt;
    if (amt > 0) msg("Poisoned!",13);
    }
  if (obj->effect == E_BLES) {
    player.effect[PE_PROT] = obj->control * 8;
    player.effect[PE_APROT] = obj->control;
    }
  if (obj->effect == E_ENCH) {
    enchant(obj->control,3);
    }
  if (obj->effect == E_TEMP) {
    player.effect[obj->control] = obj->damage;
    }
  if (obj->effect == E_TRAP) {
    if (set_trap(obj->control) == 0) {
      obj->otype = O_TRAP;
      msg("Could not set",7);
      } else obj->otype = O_NONE;
    }
  if (obj->effect == E_INTR && obj->control == A_COMP) {
    use_compass();
    }
  if (obj->effect == E_SPEL) {
    if (spells[obj->control].user_hp > 0 && player.chp < get_mhp()) {
      do_heal((spells[obj->control].user_hp / 2) + u_random(spells[obj->control].user_hp / 2),0);
      }
    if (spells[obj->control].user_hp < 0 && player.chp < get_mhp()) {
      player.chp -= spells[obj->control].user_hp;
      if (player.chp > get_mhp()) player.chp = get_mhp();
      }
    switch (spells[obj->control].effect) {
      case 1:do_blink();
      case 2:player.effect[PE_PROT] = player.level * 8;
             player.effect[PE_APROT] = spells[obj->control].control;
             break;
      case 3:touch(spells[obj->control].control,spells[obj->control].special); break;
      case 4:missile(spells[obj->control].control,spells[obj->control].special,0); break;
      case 6:do_sleep(); break;
      case 7:special(spells[obj->control].control,obj); break;
      case 8:fear(0); break;
      case 9:missile(spells[obj->control].control,spells[obj->control].special,1); break;
      case 10:blind(); break;
      case 11:area25(spells[obj->control].control,spells[obj->control].special,player.x,player.y); break;
      case 12:drain(spells[obj->control].control,spells[obj->control].special); break;
      case 13:area49(spells[obj->control].control,spells[obj->control].special,player.x,player.y); break;
      case 14:super(spells[obj->control].control,spells[obj->control].special); break;
      case SP_ENCH:
           if (player.level < 15) enchant(spells[obj->control].control,1);
           else if (player.level < 20) enchant(spells[obj->control].control,2);
           else enchant(spells[obj->control].control,3);
           break;
        }
 
    }
  }

int triad_equipped() {
  int count;
  count = 0;
  if (player.invent[I_LHND].effect == E_SPCL && player.invent[I_LHND].control >= 96 && player.invent[I_LHND].control <= 98)  {
    if (is_weapon(&(player.invent[I_LHND]))) count++;
    else if (player.invent[I_LHND].otype == O_HAND) count++;
    }
  if (player.invent[I_RHND].effect == E_SPCL && player.invent[I_RHND].control >= 96 && player.invent[I_RHND].control <= 98)  {
    if (is_weapon(&(player.invent[I_RHND]))) count++;
    else if (player.invent[I_RHND].otype == O_HAND) count++;
    }
  if (player.invent[I_SHLD].effect == E_SPCL && player.invent[I_SHLD].control >= 96 && player.invent[I_SHLD].control <= 98)  {
    if (player.invent[I_SHLD].otype != O_SHLD) count++;
    }
  if (player.invent[I_ARMR].effect == E_SPCL && player.invent[I_ARMR].control >= 96 && player.invent[I_ARMR].control <= 98)  {
    if (player.invent[I_ARMR].otype != O_ARMR) count++;
    }
  if (player.invent[I_HELM].effect == E_SPCL && player.invent[I_HELM].control >= 96 && player.invent[I_HELM].control <= 98)  {
    if (player.invent[I_HELM].otype == O_HELM) count++;
    }
  if (player.invent[I_BOOT].effect == E_SPCL && player.invent[I_BOOT].control >= 96 && player.invent[I_BOOT].control <= 98)  {
    if (player.invent[I_BOOT].otype != O_BOOT) count++;
    }
  if (player.invent[I_ROBE].effect == E_SPCL && player.invent[I_ROBE].control >= 96 && player.invent[I_ROBE].control <= 98)  {
    if (player.invent[I_ROBE].otype != O_ROBE) count++;
    }
  return (count >= 3) ? -1 : 0;
  }

int fighting_final_boss(NPC_REC* mon) {
  if (strcmp(mon->name,FINAL_BOSS) == 0) return -1;
  return 0;
  }

