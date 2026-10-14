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

void display_scroll() {
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
  }

void display_msg(int msg,char ext) {
  int i;
  int x,y;
  int space;
  int size;
  char key;
  char last;
  MESSAGE general;
  general = (ext == 'L') ? lore[msg] : gen[msg];
  graphmode();
  display_scroll();
  x = 160; y = 160; space = 25; size = 30;
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
  key = inkey();
  show_screen();
  }

void special1() {
  int x,y;
  for (x=player.map_x; x<=player.map_x+15; x++)
    for (y=player.map_y; y<=player.map_y+15; y++)
      if (player.map[x][y] < 0) show_sprite(x-player.map_x,y-player.map_y,37);
  clair = '*';
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
  for (x=sx; x<=ex; x++)
    for (y=sy; y<=ey; y++)
      if (player.known[x][y] == 0) player.known[x][y] = 1;
  }

void special3() {
  int i;
  i = player.diff * 5 + player.skill[8] * 5;
  player.effect[PE_HASTE] += u_random(i + i + 1) + 25;
  }

void special4() {
  int i;
  i = player.diff * 5 + player.skill[8] * 5;
  player.effect[PE_GIANT] += u_random(i + i + 1) + 25;
  }

void special5() {
  int i;
  i = player.diff * 3 + player.skill[8] * 3;
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
      if (player.known[x][y] == 0) {
        if (player.map[x][y] >=24 && player.map[x][y] <=25) {
          player.known[x][y] = 1;
          show_spot(x,y);
          }
        if (player.map[x][y] >=1000 && player.map[x][y] <=1088) {
          player.known[x][y] = 1;
          show_spot(x,y);
          }
        if (player.map[x][y] >=1163 && player.map[x][y] <=1167) {
          player.known[x][y] = 1;
          show_spot(x,y);
          }
        }
  show_sm_map();
  }

void special9() {
  int x,y;
  for (x=player.map_x; x<=player.map_x+15; x++)
    for (y=player.map_y; y<=player.map_y+15; y++)
      if (player.known[x][y] == 0 && player.map[x][y] < 0)
        player.known[x][y] = 1;
  delay(1000);
  }

void special10() {
  int i;
  int x,y;
  int space;
  int size;
  char key;
  MESSAGE general;
  i = u_random(NO_OF_LORE) + 1;
  general = lore[i];
  while (general.region != player.region && general.region != 0 &&
         general.region >= 90) {
    i = u_random(NO_OF_LORE) + 1;
    general = lore[i];
    }
  if (u_random(100) < (25 + player.skill[6] * 5) || player.effect[PE_READLORE] != 0) {
    player.lore[i] = -1;
    } else {
    for (i=0; i<=strlen(general.message); i++)
      if ((general.message[i] >= 'A' && general.message[i] <= 'Z') ||
          (general.message[i] >= 'a' && general.message[i] <= 'z'))
        general.message[i] += 128;
    }
  saveScreen();
  display_scroll();
  x = 120; y = 160; space = 25; size = 30;
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
  key = inkey();
  restoreScreen();
  }

void special11() {
  int i;
  int x,y;
  int space;
  int size;
  char key;
  MESSAGE general;
  i = u_random(NO_OF_GENS) + 1;
  general = gen[i];
  while (general.region != player.region && general.region != 0) {
    i = u_random(NO_OF_GENS) + 1;
    general = gen[i];
    }
  if (u_random(100) < (50 + player.skill[6] * 5) || player.effect[PE_READLANG] != 0) {
    player.gen[i] = -1;
    } else {
    for (i=0; i<=strlen(general.message); i++)
      if ((general.message[i] >= 'A' && general.message[i] <= 'Z') ||
          (general.message[i] >= 'a' && general.message[i] <= 'z'))
        general.message[i] += 128;
    }
  saveScreen();
  display_scroll();
  x = 120; y = 160; space = 25; size = 30;
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
  key = inkey();
/*  show_screen(); */
  restoreScreen();
  }

void special12() {
  OBJECT_REC* i;
  i = inventory(NULL);
  if (i != NULL) {
    i->level = -1;
    gotoxy(25,inv_item+3);
    txt_write(get_name(i));
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
  i = player.diff * 5 + player.skill[8] * 5;
  player.effect[PE_PROT] += u_random(i+i+1) + 25;
  player.effect[PE_APROT] = 10;
  }

void special14() {
  int x,y;
  for (x=1; x<=100; x++)
    for (y=1; y<=100; y++)
      if (player.known[x][y] == 0) player.known[x][y] = 1;
  }

void special15() {
  player.d_level = 0;
  }

void special16() {
  player.stat[1]++;
  if (player.stat[1] > 30) player.stat[1] = 30;
  adjust_abilities();
  }

void special17() {
  player.stat[2]++;
  if (player.stat[2] > 30) player.stat[2] = 30;
  adjust_abilities();
  }

void special18() {
  player.stat[4]++;
  if (player.stat[4] > 30) player.stat[4] = 30;
  adjust_abilities();
  }

void special19() {
  player.cmana *= 2;
  }

void special20() {
  int i;
  int x,y;
  int space;
  int size;
  char key;
  MESSAGE general;
  i = u_random(NO_OF_GENS) + 1;
  general = gen[i];
  while (general.region != player.region && general.region != 0) {
    i = u_random(NO_OF_GENS) + 1;
    general = gen[i];
    }
  player.gen[i] = -1;
  saveScreen();
  graphmode();
  display_scroll();
  x = 160; y = 160; space = 25; size = 30;
  setcolor(0);
  show_message(general.message);
  key = inkey();
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
  char key;
  key = get_dir(&xdir,&ydir);
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
    player.party[slot].time = u_random(player.level * 5) + 1;
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
      if (player.map[x][y] == 41) player.map[x][y] = 7;
  }

void special30() {
  int x,y;
  int xdir,ydir;
  char key;
  key = get_dir(&xdir,&ydir);
  x = player.x + xdir;
  y = player.y + ydir;
  if (player.map[x][y] == 7) {
    player.map[x][y] = 600 + player.level;
    show_map();
    show_player();
    }
  else {
    clear_prompt();
    prompt("Fizzle. . .");
    }
  }

void special31() {
  int i;
  clear_prompt();
  switch (u_random(25)) {
    case 0:prompt("STR increased");
           if (player.stat[1] < 26) player.stat[1] += 2;
           adjust_abilities();
           break;
    case 1:prompt("DEX increased");
           if (player.stat[2] < 26) player.stat[2] += 2;
           adjust_abilities();
           break;
    case 2:prompt("CON increased");
           if (player.stat[3] < 26) player.stat[3] += 2;
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
           player.skill[i] += 2;
           break;
    case 6:prompt("CHR increased");
           if (player.stat[6] < 26) player.stat[6] += 2;
           adjust_abilities();
           break;
    default:prompt("Fizzle...");
    }
  }

void special34() {
  char key;
  int x,y;
  int xdir,ydir;
  int mon;
  key = get_dir(&xdir,&ydir);
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
  for (x=player.map_x; x<=player.map_x+15; x++)
    for (y=player.map_y; y<=player.map_y+15; y++)
      if (player.map[x][y] >= 800 && player.map[x][y] < 900) {
        player.known[x][y] = 1;
        player.map[x][y] = 40;
        }
  show_screen();
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
  if (in_arena == 'Y')
    for (i=1; i<=5; i++) {
      x = u_random(15) + 10;
      y = u_random(15) + 10;
      while (player.map[x][y] > 30) {
        x = u_random(15) + 10;
        y = u_random(15) + 10;
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
    player.party[slot].time = u_random(player.level * 5) + 1;
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
  int x,y;
  for (x=1; x<=100; x++)
    for (y=1; y<=100; y++)
     if (player.map[x][y] >= 800 && player.map[x][y] < 900) {
       player.known[x][y] = 1;
       player.map[x][y] = 40;
       }
  show_screen();
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
      prompt(buffer);
      }
    if (key == 8 && strlen(invoke) > 1) {
      invoke[strlen(invoke) - 1] = 0;
      sprintf(buffer,"Function ? %s_",invoke);
      clear_prompt();
      prompt(buffer);
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
  char key;
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
  key = inkey();
  }

void special48() {
  if (player.d_level == bottom) special(14);
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
  int space;
  int size;
  char key;
  char last;
  MESSAGE general;
  i = u_random(NO_OF_LORE) + 1;
  general = lore[i];
  while (general.region != player.region && general.region != 0) {
    i = u_random(NO_OF_LORE) + 1;
    general = lore[i];
    }
  player.lore[i] = -1;
  graphmode();
  display_scroll();
  x = 160; y = 160; space = 25; size = 30;
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
  key = inkey();
  }

void special52() {
  int i;
  int x,y;
  int m_file;
  for (x=1; x<=100; x++)
    for (y=1; y<=100; y++)
      player.known[x][y] = 1;
  m_file = open("temp01.$$$",O_WRONLY);
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
  }

void special54() {
  player.cmana = player.mmana;
  }

void special55() {
  player.mmana *= 2;
  player.cmana = player.mmana;
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

void special60() {
  if (has_intrinsic(A_NOSL) == 0) player.effect[PE_SLEEP] = u_random(1024);
  }

void special61() {
  if (has_intrinsic(A_NOFR) == 0) {
    if (has_intrinsic(A_RSFR)) player.effect[PE_FEAR] = u_random(1024) / 4;
      else player.effect[PE_FEAR] = u_random(1024);
    }
  }

void special62() {
  player.effect[PE_BLIND] = u_random(1024);
  msg("Hmmmm, who turned off the lights?",14);
  }

void special63() {
  player.effect[PE_CONFUSED] = u_random(1024);
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
    msg("Your armour glows briefly",15);
    }
  }

void special70() {
  if (player.invent[I_RHND].otype == O_DAGR ||
      player.invent[I_RHND].otype == O_EDGE ||
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
    msg("Your armour turns black",4);
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
  i = player.diff * 5 + player.skill[8] * 5;
  player.effect[PE_LEV] += u_random(i + i + 1) + 25;
  }

void special(byte whichone) {
  if (in_arena != 'Y')
    switch (whichone) {
      case  1:special1(); break;
      case  2:if (player.gateway != '*') special2(); break;
      case  3:special3(); break;
      case  4:special4(); break;
      case  5:special5(); break;
      case  6:special6(); break;
      case  7:special7(); break;
      case  8:special8(); break;
      case  9:special9(); break;
      case 10:special10(); break;
      case 11:special11(); break;
      case 12:special12(); break;
      case 13:special13(); break;
      case 14:if (player.gateway != '*') special14(); break;
      case 15:if (player.gateway != '*') special15(); break;
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
      case 26:special26(); break;
      case 27:special27(5); break;
      case 28:special28(); break;
      case 29:special29(); break;
      case 30:special30(); break;
      case 32:special27(10); break;
      case 33:special27(15); break;
      case 34:special34(); break;
      case 36:special36(); break;
      case 37:special37(); break;
      case 38:special38(); break;
      case 39:special42(78); break;
      case 40:special40(); break;
      case 42:special42(1); break;
      case 43:special43(); break;
      case 44:special42(11); break;
      case 45:special42(13); break;
      case 46:special46(); break;
      case 47:special47(); break;
      case 48:special48(); break;
      case 49:special49(); break;
      case 50:special50(); break;
      case 51:special51(); break;
      case 52:special52(); break;
      case 53:special53(); break;
      case 54:special54(); break;
      case 55:special55(); break;
      case 56:special56(); break;
      case 57:special57(); break;
      case 58:special58(); break;
      case 59:special59(); break;
      case 60:special60(); break;
      case 61:special61(); break;
      case 62:special62(); break;
      case 63:special63(); break;
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
      }
  if (in_arena == 'Y')
    switch (whichone) {
      case  3:special3(); break;
      case  4:special4(); break;
      case 10:special10(); break;
      case 11:special11(); break;
      case 12:special12(); break;
      case 13:special13(); break;
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
      case 27:special27(5); break;
      case 28:special28(); break;
      case 32:special27(10); break;
      case 33:special27(15); break;
      case 36:special36(); break;
      case 38:special38(); break;
      case 39:special42(78); break;
      case 40:special40(); break;
      case 41:special41(); break;
      case 42:special42(1); break;
      case 44:special42(11); break;
      case 45:special42(13); break;
      case 54:special54(); break;
      case 55:special55(); break;
      case 56:special56(); break;
      case 57:special57(); break;
      case 58:special58(); break;
      case 59:special59(); break;
      case 60:special60(); break;
      case 61:special61(); break;
      case 62:special62(); break;
      case 63:special63(); break;
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
      }
  }

void perform_effect(OBJECT_REC* obj) {
  int i;
  char buffer[40];
  OBJECT_REC* item;
  if (obj->user_hp > 0 && player.chp < player.mhp) {
    player.chp += (obj->user_hp / 2) + u_random(obj->user_hp / 2);
    }
  if (obj->user_hp < 0 && player.chp < player.mhp) {
    player.chp -= obj->user_hp;
    }
  if (obj->user_health > 0 && player.health < 100) {
    player.health += (obj->user_health / 2) + u_random(obj->user_health /2);
    }
  if (obj->user_health < 0 && player.health < 100) {
    player.health -= obj->user_health;
    }
  if (obj->effect == E_MANA && player.cmana < player.mmana) {
    if (obj->control < 0) player.cmana -= obj->control;
      else player.cmana += (obj->control / 2) + u_random(obj->control / 2);
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
    player.chp -= i;
    }
  if (obj->effect == 3)
    switch (obj->control) {
      case 1:touch(obj->damage); break;
      case 2:missile(obj->damage); break;
      case 3:area9(obj->damage); break;
      case 4:area25(obj->damage); break;
      case 5:missile9(obj->damage); break;
      }
  if (obj->effect == 4) fear();
  if (obj->effect == 5) do_sleep();
  if (obj->effect == 6) teleport();
  if (obj->effect == 7) special(obj->control);
  if (obj->effect == 8)
          player.effect[PE_POISON] += u_random(player.diff*5+player.d_level /3);
  if (obj->effect == 9) {
    player.effect[PE_PROT] = obj->control * 8;
    player.effect[PE_APROT] = obj->control;
    }
  }

