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

void disp_char() {
  int i;
  char key;
  clrscr();
  textmode(3); textcolor(2);
  gotoxy(1,1); txt_write("Name   :");
  gotoxy(1,2); txt_write("Age    :");
  gotoxy(1,3); txt_write("Sex    :");
  gotoxy(1,4); txt_write("Race   :");
  gotoxy(1,5); txt_write("Level  :");
  gotoxy(1,6); txt_write("Exp    :");
  gotoxy(1,7); txt_write("Class  :");
  gotoxy(1,8); txt_write("Title  :");
  gotoxy(1,9); txt_write("Health :");
  gotoxy(1,10); txt_write("Align. :");
  gotoxy(35,1); txt_write("Str:");
  gotoxy(35,2); txt_write("Dex:");
  gotoxy(35,3); txt_write("Con:");
  gotoxy(35,4); txt_write("Int:");
  gotoxy(35,5); txt_write("Wis:");
  gotoxy(35,6); txt_write("Chr:");
  gotoxy(34,7); txt_write("C Hp:");
  gotoxy(34,8); txt_write("M Hp:");
  gotoxy(32,9); txt_write("C Mana:");
  gotoxy(32,10); txt_write("M Mana:");
  gotoxy(55,1); txt_write("Attack :");
  gotoxy(55,2); txt_write("Defense:");
  gotoxy(55,3); txt_write("Damage :");
  gotoxy(55,4); txt_write("N.Save :");
  gotoxy(55,5); txt_write("M.Save :");
  gotoxy(55,6); txt_write("Missile:");
  gotoxy(55,7); txt_write("Stealth:");
  gotoxy(55,8); txt_write("Disarm :");
  gotoxy(55,9); txt_write("Search :");
  gotoxy(55,10); txt_write("Magic  :");
  gotoxy(1,12); txt_write("Torches:");
  gotoxy(1,13); txt_write("Gold   :");
  gotoxy(31,12); txt_write("Mount  :");
  gotoxy(31,13); txt_write("Winged :");
  gotoxy(55,12); txt_write("Armour :");
  gotoxy(55,13); txt_write("Weapon :");
  textcolor(14);
  gotoxy(10,1); txt_write(player.name);
  gotoxy(10,2); txt_write(show_int(player.age));
  gotoxy(10,3);
  if (player.sex == 'F') txt_write("Female"); else txt_write("Male");
  show_health();
  show_align();
  gotoxy(10,4);
  switch(player.race) {
    case 1:txt_write("Human"); break;
    case 2:txt_write("Elf"); break;
    case 3:txt_write("Half-Elf"); break;
    case 4:txt_write("Dwarf"); break;
    case 5:txt_write("Hobbit"); break;
    }
  gotoxy(10,5); txt_write(show_int(player.level));
  gotoxy(10,6); txt_write(show_flt(player.exp));
  txt_write(" ("); txt_write(show_flt(player.exp_next)); txt_write(")");
  gotoxy(10,7);
  switch(player.class) {
    case 1:txt_write("Fighter"); break;
    case 2:txt_write("Paladin"); break;
    case 3:txt_write("Ranger"); break;
    case 4:txt_write("Cleric"); break;
    case 5:txt_write("Druid"); break;
    case 6:txt_write("Mage"); break;
    case 7:txt_write("Assassin"); break;
    case 8:txt_write("Hierophant"); break;
    case 9:txt_write("Cavalier"); break;
    case 10:txt_write("Monk"); break;
    case 11:txt_write("Noble"); break;
    }
  gotoxy(10,8); txt_write(player.title);
  for (i=1; i<7; i++) {
    gotoxy(40,i);
    txt_write(show_int(player.stat[i]));
    }
  gotoxy(40,7); txt_write(show_int(player.chp));
  gotoxy(40,8); txt_write(show_int(player.mhp));
  gotoxy(40,9); txt_write(show_int(player.cmana));
  gotoxy(40,10); txt_write(show_int(player.mmana));
  display_abilities();
  textcolor(14);
  gotoxy(10,12); txt_write(show_int(player.torch));
  gotoxy(10,13); txt_write(show_flt(player.gold));
  gotoxy(40,12);
  if (player.mount == 0) txt_write("No"); else txt_write("Yes");
  gotoxy(40,13);
  if (player.peg == 0) txt_write("No"); else txt_write("Yes");
  gotoxy(64,12); txt_write(show_int(player.armour));
  gotoxy(64,13); txt_write(show_int(player.weapon));
  gotoxy(1,15); textcolor((player.skill[1]>4)?15:8);
  txt_write(show_int(player.skill[1])); gotoxy(4,15); txt_write("Missile");
  gotoxy(1,16); textcolor((player.skill[2]>4)?15:8);
  txt_write(show_int(player.skill[2])); gotoxy(4,16); txt_write("Edge Weapons");
  gotoxy(1,17); textcolor((player.skill[3]>4)?15:8);
  txt_write(show_int(player.skill[3])); gotoxy(4,17); txt_write("Pole Weapons");
  gotoxy(1,18); textcolor((player.skill[4]>4)?15:8);
  txt_write(show_int(player.skill[4])); gotoxy(4,18); txt_write("Hunting");
  gotoxy(20,15); textcolor((player.skill[5]>4)?15:8);
  txt_write(show_int(player.skill[5])); gotoxy(23,15); txt_write("Scouting");
  gotoxy(20,16); textcolor((player.skill[6]>4)?15:8);
  txt_write(show_int(player.skill[6])); gotoxy(23,16); txt_write("Language");
  gotoxy(20,17); textcolor((player.skill[7]>4)?15:8);
  txt_write(show_int(player.skill[7])); gotoxy(23,17); txt_write("Lore");
  gotoxy(20,18); textcolor((player.skill[8]>4)?15:8);
  txt_write(show_int(player.skill[8])); gotoxy(23,18); txt_write("Magic");
  gotoxy(40,15); textcolor((player.skill[9]>4)?15:8);
  txt_write(show_int(player.skill[9])); gotoxy(43,15); txt_write("Healing");
  gotoxy(40,16); textcolor((player.skill[10]>4)?15:8);
  txt_write(show_int(player.skill[10])); gotoxy(43,16); txt_write("Medicine");
  gotoxy(40,17); textcolor((player.skill[11]>4)?15:8);
  txt_write(show_int(player.skill[11])); gotoxy(43,17); txt_write("Riding");
  gotoxy(40,18); textcolor((player.skill[12]>4)?15:8);
  txt_write(show_int(player.skill[12])); gotoxy(43,18); txt_write("Boating");
  gotoxy(60,15); textcolor((player.skill[13]>4)?15:8);
  txt_write(show_int(player.skill[13])); gotoxy(63,15); txt_write("Oracle");
  gotoxy(60,16); textcolor((player.skill[14]>4)?15:8);
  txt_write(show_int(player.skill[14])); gotoxy(63,16); txt_write("Charm");
  gotoxy(60,17); textcolor((player.skill[15]>4)?15:8);
  txt_write(show_int(player.skill[15])); gotoxy(63,17); txt_write("Survival");
  gotoxy(60,18); textcolor((player.skill[16]>4)?15:8);
  txt_write(show_int(player.skill[16])); gotoxy(63,18); txt_write("Combat");
  textcolor(9);
  gotoxy(1,19); txt_write("F1 - "); txt_write(player.fspell[1]);
  gotoxy(1,20); txt_write("F3 - "); txt_write(player.fspell[3]);
  gotoxy(1,21); txt_write("F5 - "); txt_write(player.fspell[5]);
  gotoxy(1,22); txt_write("F7 - "); txt_write(player.fspell[7]);
  gotoxy(1,23); txt_write("F9 - "); txt_write(player.fspell[9]);
  gotoxy(40,19); txt_write("F2 - "); txt_write(player.fspell[2]);
  gotoxy(40,20); txt_write("F4 - "); txt_write(player.fspell[4]);
  gotoxy(40,21); txt_write("F6 - "); txt_write(player.fspell[6]);
  gotoxy(40,22); txt_write("F8 - "); txt_write(player.fspell[8]);
  gotoxy(39,23); txt_write("F10 - "); txt_write(player.fspell[10]);
  textcolor(14);
  gotoxy(19,24); txt_write("Press <ENTER> to continue");
  key = ' ';
  while (key != 13) {
    key = inkey();
    }
  }

