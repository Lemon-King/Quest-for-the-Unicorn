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

void make_char() {
  int pool;
  int i,j;
  int x,y;
  int m_file;
  char buffer[80];
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
  textcolor(14);
  gotoxy(10,1); p_read(player.name);
  player.age = u_random(10)+18;
  gotoxy(10,2);
  sprintf(buffer,"%d",player.age);
  txt_write(buffer);
  textcolor(2); gotoxy(10,3); textcolor(14); txt_write("_");
  key = inkey();
  if (key == 'f' || key == 'F') player.sex = 'F';
    else player.sex = 'M';
  gotoxy(10,3); if (player.sex == 'F') txt_write("Female");
    else txt_write("Male");
  textcolor(9);
  player.health = 100;
  player.align = 100;
  show_health();
  show_align();
  gotoxy(5,15); txt_write("Character Race:");
  textcolor(15);
  gotoxy(5,16); txt_write("1> Human");
  gotoxy(5,17); txt_write("2> Elf");
  gotoxy(5,18); txt_write("3> Half-Elf");
  gotoxy(5,19); txt_write("4> Dwarf");
  gotoxy(5,20); txt_write("5> Hobbit");
  textcolor(14);
  gotoxy(10,4); txt_write("_");
  key = '0';
  while (key<'1' || key>'5') key = inkey();
  gotoxy(10,4);
  switch (key) {
    case '1':
         player.race = 1;
         txt_write("Human");
         break;
    case '2':
         player.race = 2;
         txt_write("Elf");
         break;
    case '3':
         player.race = 3;
         txt_write("Half-Elf");
         break;
    case '4':
         player.race = 4;
         txt_write("Dwarf");
         break;
    case '5':
         player.race = 5;
         txt_write("Hobbit");
         break;
    }
  gotoxy(5,15); txt_write("               ");
  gotoxy(5,16); txt_write("        ");
  gotoxy(5,17); txt_write("      ");
  gotoxy(5,18); txt_write("           ");
  gotoxy(5,19); txt_write("        ");
  gotoxy(5,20); txt_write("         ");
  player.level = 1; gotoxy(10,5);
  sprintf(buffer,"%d",player.level);
  txt_write(buffer);
  player.exp = 0; gotoxy(10,6);
  sprintf(buffer,"%9.0f",player.exp);
  txt_write(buffer);
  textcolor(9);
  gotoxy(5,15); txt_write("Character classes:");
  textcolor(15);
  gotoxy(5,16); txt_write("1> Fighter");
  gotoxy(5,17); txt_write("2> Paladin");
  gotoxy(5,18); txt_write("3> Ranger");
  gotoxy(5,19); txt_write("4> Cleric");
  gotoxy(5,20); txt_write("5> Druid");
  gotoxy(5,21); txt_write("6> Mage");
  gotoxy(5,22); txt_write("7> Monk");
  gotoxy(10,7);
  textcolor(14);
  txt_write("_");
  gotoxy(10,7);
  key = '0';
  while (key<'1' || key>'7') key = inkey();
  switch (key) {
    case '1':
         player.class = 1;
         strcpy(player.title,"Veteran");
         txt_write("Fighter");
         player.exp_next = 100;
         break;
    case '2':
         player.class = 2;
         strcpy(player.title,"Gallant");
         txt_write("Paladin");
         player.exp_next = 175;
         break;
    case '3':
         player.class = 3;
         strcpy(player.title,"Runner");
         txt_write("Ranger");
         player.exp_next = 150;
         break;
    case '4':
         player.class = 4;
         strcpy(player.title,"Acolyte");
         txt_write("Cleric");
         player.exp_next = 125;
         break;
    case '5':
         player.class = 5;
         strcpy(player.title,"Aspirant");
         txt_write("Druid");
         player.exp_next = 115;
         break;
    case '6':
         player.class = 6;
         strcpy(player.title,"Prestidigitator");
         txt_write("Mage");
         player.exp_next = 200;
         break;
    case '7':
         player.class = 10;
         strcpy(player.title,"Novice");
         txt_write("Monk");
         player.exp_next = 150;
         break;
    }
  gotoxy(5,15); txt_write("                  ");
  gotoxy(5,16); txt_write("          ");
  gotoxy(5,17); txt_write("          ");
  gotoxy(5,18); txt_write("         ");
  gotoxy(5,19); txt_write("         ");
  gotoxy(5,20); txt_write("        ");
  gotoxy(5,21); txt_write("       ");
  gotoxy(5,22); txt_write("       ");
  gotoxy(10,8); txt_write(player.title);
  for (i=1; i<=6; i++) {
    player.stat[i] = 10;
    gotoxy(40,i);
    sprintf(buffer,"%2d",player.stat[i]);
    txt_write(buffer);
    }
  i = 1; pool = 18;
  gotoxy(43,i);
  sprintf(buffer,"<-%2d",pool);
  txt_write(buffer);
  key = 0;
  while (key != 13) {
    key = inkey();
    switch (key) {
      case '8':if (i>1) {
                 gotoxy(43,i); txt_write("     ");
                 i = i-1;
                 gotoxy(43,i);
                 sprintf(buffer,"<-%2d",pool);
                 txt_write(buffer);
                 }
               break;
      case '2':if (i<6) {
                 gotoxy(43,i); txt_write("     ");
                 i = i+1;
                 gotoxy(43,i);
                 sprintf(buffer,"<-%2d",pool);
                 txt_write(buffer);
                 }
               break;
      case '4':if (pool>0) {
                 player.stat[i] = player.stat[i]+1;
                 pool = pool-1;
                 gotoxy(40,i);
                 sprintf(buffer,"%2d",player.stat[i]);
                 txt_write(buffer);
                 gotoxy(43,i);
                 sprintf(buffer,"<-%2d",pool);
                 txt_write(buffer);
                 }
               break;
      case '6':if (player.stat[i]>3) {
                 player.stat[i] = player.stat[i]-1;
                 pool = pool+1;
                 gotoxy(40,i);
                 sprintf(buffer,"%2d",player.stat[i]);
                 txt_write(buffer);
                 gotoxy(43,i);
                 sprintf(buffer,"<-%2d",pool);
                 txt_write(buffer);
                 }
        }
      if (key == 13 && pool != 0) key = 0;
    }
  gotoxy(43,i); txt_write("     ");
  if (player.sex == 'F') {
    player.stat[1] = player.stat[1]-1;
    player.stat[6] = player.stat[6]+1;
    player.stat[2] = player.stat[2]+1;
    }
  switch (player.race) {
    case 1:
         player.stat[1] = player.stat[1]+1;
         player.stat[2] = player.stat[2]-1;
        break;
    case 2:
         player.stat[1] = player.stat[1]-1;
         player.stat[2] = player.stat[2]+1;
         player.stat[5] = player.stat[5]+1;
         player.stat[6] = player.stat[6]+1;
         player.stat[3] = player.stat[3]-1;
        break;
    case 3:
         player.stat[5] = player.stat[5]+1;
         player.stat[6] = player.stat[6]-1;
        break;
    case 4:
         player.stat[1] = player.stat[1]+1;
         player.stat[2] = player.stat[2]+1;
         player.stat[3] = player.stat[3]+1;
         player.stat[4] = player.stat[4]-1;
         player.stat[5] = player.stat[5]-1;
         player.stat[6] = player.stat[6]-1;
        break;
    case 5:
         player.stat[1] = player.stat[1]-1;
         player.stat[2] = player.stat[2]+2;
         player.stat[3] = player.stat[3]+1;
         player.stat[4] = player.stat[4]-1;
         player.stat[5] = player.stat[5]-1;
        break;
    }
  for (i=1; i<=5; i++) player.party[i].hp = 0;
  for (i=1; i<=6; i++) {
    gotoxy(40,i);
    sprintf(buffer,"%2d",player.stat[i]);
    txt_write(buffer);
    }
  for (i=1; i<=16; i++) player.skill[i] = 0;
  switch (player.class) {
    case 1:
        player.mhp = 10;
        if (player.stat[3]>14) player.mhp = player.mhp+1;
        if (player.stat[3]>17) player.mhp = player.mhp+1;
        if (player.stat[3]>20) player.mhp = player.mhp+2;
        player.chp = player.mhp;
        player.mmana = 0;
        player.cmana = 0;
        switch (u_random(3)) {
          case 0:player.skill[1] = u_random(5); break;
          case 1:player.skill[2] = u_random(5); break;
          case 2:player.skill[3] = u_random(5); break;
          }
        break;
    case 2:
        player.mhp = 10;
        if (player.stat[3]>14) player.mhp = player.mhp+1;
        if (player.stat[3]>17) player.mhp = player.mhp+1;
        if (player.stat[3]>20) player.mhp = player.mhp+2;
        player.chp = player.mhp;
        player.mmana = 0;
        player.cmana = 0;
        switch (u_random(3)) {
          case 0:player.skill[1] = u_random(3); break;
          case 1:player.skill[2] = u_random(3); break;
          case 2:player.skill[3] = u_random(3); break;
          }
        player.skill[9] = u_random(3);
        player.skill[10] = u_random(3);
        break;
    case 3:
        player.mhp = 8;
        if (player.stat[3]>14) player.mhp = player.mhp+1;
        if (player.stat[3]>17) player.mhp = player.mhp+1;
        if (player.stat[3]>20) player.mhp = player.mhp+2;
        player.chp = player.mhp;
        player.mmana = 0;
        player.cmana = 0;
        switch (u_random(3)) {
          case 0:player.skill[1] = u_random(5); break;
          case 1:player.skill[2] = u_random(5); break;
          case 2:player.skill[3] = u_random(5); break;
          }
        player.skill[4] = u_random(3);
        player.skill[5] = u_random(3);
        player.skill[11] = u_random(3);
        player.skill[15] = u_random(3);
        break;
    case 4:
        player.mhp = 6;
        if (player.stat[3]>14) player.mhp = player.mhp+1;
        if (player.stat[3]>17) player.mhp = player.mhp+1;
        if (player.stat[3]>20) player.mhp = player.mhp+2;
        player.chp = player.mhp;
        player.mmana = 6;
        player.cmana = 6;
        break;
    case 5:
        player.mhp = 6;
        if (player.stat[3]>14) player.mhp = player.mhp+1;
        if (player.stat[3]>17) player.mhp = player.mhp+1;
        if (player.stat[3]>20) player.mhp = player.mhp+2;
        player.chp = player.mhp;
        player.mmana = 6;
        player.cmana = 6;
        player.skill[4] = u_random(3);
        player.skill[5] = u_random(3);
        player.skill[11] = u_random(5);
        break;
    case 6:
        player.mhp = 4;
        if (player.stat[3]>14) player.mhp = player.mhp+1;
        if (player.stat[3]>17) player.mhp = player.mhp+1;
        if (player.stat[3]>20) player.mhp = player.mhp+2;
        player.chp = player.mhp;
        player.mmana = 6;
        player.cmana = 6;
        break;
    case 10:
        player.mhp = 4;
        if (player.stat[3]>14) player.mhp = player.mhp+1;
        if (player.stat[3]>17) player.mhp = player.mhp+1;
        if (player.stat[3]>20) player.mhp = player.mhp+2;
        player.chp = player.mhp;
        player.mmana = 0;
        player.cmana = 0;
        check_monk_weapon();
        switch (u_random(3)) {
          case 0:player.skill[1] = u_random(5); break;
          case 1:player.skill[2] = u_random(5); break;
          case 2:player.skill[3] = u_random(5); break;
          }
        break;
    }
  player.mhp = player.mhp+(player.stat[3] / 4);
  player.chp = player.mhp;
  gotoxy(40,7);
  sprintf(buffer,"%4d",player.chp);
  txt_write(buffer);
  gotoxy(40,8);
  sprintf(buffer,"%4d",player.mhp);
  txt_write(buffer);
  gotoxy(40,9);
  sprintf(buffer,"%4d",player.cmana);
  txt_write(buffer);
  gotoxy(40,10);
  sprintf(buffer,"%4d",player.mmana);
  txt_write(buffer);
  adjust_abilities();
  display_abilities();
  player.torch = 10;
  player.food = 5;
  player.armour = 0;
  player.weapon = 0;
  if (player.class == 10) check_monk_weapon();
  player.mount = 0;
  player.peg = 0;
  for (i=0; i<255; i++) player.effect[i] = 0;
  player.effect[PE_FIRE] = 0;
  player.effect[PE_ETHER] = 0;
  player.effect[PE_GIANT] = 0;
  player.effect[PE_HASTE] = 0;
  player.effect[PE_POISON] = 0;
  player.effect[PE_PROT] = 0;
  player.effect[PE_LIGHT] = 0;
  player.in_city = 'N';
  player.hp_count = 15;
  player.mana_count = 20;
  player.effect[PE_READLANG] = 0;
  player.effect[PE_READLORE] = 0;
  player.phase = 0;
  player.effect[PE_SLEEP] = 0;
  player.effect[PE_BLIND] = 0;
  player.effect[PE_CONFUSED] = 0;
  player.effect[PE_FEAR] = 0;
  player.ship_x = 0;
  player.ship_y = 0;
  player.ship_r = 0;
  player.inship = ' ';
  player.gateway = ' ';
  player.gold = 250;
  player.bank = 0;
  player.interest = 0;
  textcolor(2);
  gotoxy(1,12); txt_write("Torches:");
  gotoxy(1,13); txt_write("Gold   :");
  gotoxy(31,12); txt_write("Mount  :");
  gotoxy(31,13); txt_write("Winged :");
  gotoxy(55,12); txt_write("Armour :");
  gotoxy(55,13); txt_write("Weapon :");
  textcolor(14);
  gotoxy(10,12); 
  sprintf(buffer,"%d",player.torch);
  txt_write(buffer);
  gotoxy(10,13);
  sprintf(buffer,"%6.0f",player.gold);
  txt_write(buffer);
  gotoxy(40,12); if (player.mount == 0) txt_write("No"); else txt_write("Yes");
  gotoxy(40,13); if (player.peg == 0) txt_write("No"); else txt_write("Yes");
  gotoxy(64,12);
  sprintf(buffer,"%d",player.armour);
  txt_write(buffer);
  gotoxy(64,13);
  sprintf(buffer,"%d",player.weapon);
  txt_write(buffer);
  gotoxy(1,16); if (player.skill[1]>4) textcolor(14); else textcolor(8);
  sprintf(buffer,"%2d Arrow",player.skill[1]); txt_write(buffer);
  gotoxy(1,17); if (player.skill[2]>4) textcolor(14); else textcolor(8);
  sprintf(buffer,"%2d Edge Weapons",player.skill[2]); txt_write(buffer);
  gotoxy(1,18); if (player.skill[3]>4) textcolor(14); else textcolor(8);
  sprintf(buffer,"%2d Pole Weapons",player.skill[3]); txt_write(buffer);
  gotoxy(1,19); if (player.skill[4]>4) textcolor(14); else textcolor(8);
  sprintf(buffer,"%2d Hunting",player.skill[4]); txt_write(buffer);
  gotoxy(20,16); if (player.skill[5]>4) textcolor(14); else textcolor(8);
  sprintf(buffer,"%2d Scouting",player.skill[5]); txt_write(buffer);
  gotoxy(20,17); if (player.skill[6]>4) textcolor(14); else textcolor(8);
  sprintf(buffer,"%2d Language",player.skill[6]); txt_write(buffer);
  gotoxy(20,18); if (player.skill[7]>4) textcolor(14); else textcolor(8);
  sprintf(buffer,"%2d Lore",player.skill[7]); txt_write(buffer);
  gotoxy(20,19); if (player.skill[8]>4) textcolor(14); else textcolor(8);
  sprintf(buffer,"%2d Magic",player.skill[8]); txt_write(buffer);
  gotoxy(40,16); if (player.skill[9]>4) textcolor(14); else textcolor(8);
  sprintf(buffer,"%2d Healing",player.skill[9]); txt_write(buffer);
  gotoxy(40,17); if (player.skill[10]>4) textcolor(14); else textcolor(8);
  sprintf(buffer,"%2d Medicine",player.skill[10]); txt_write(buffer);
  gotoxy(40,18); if (player.skill[11]>4) textcolor(14); else textcolor(8);
  sprintf(buffer,"%2d Riding",player.skill[11]); txt_write(buffer);
  gotoxy(40,19); if (player.skill[12]>4) textcolor(14); else textcolor(8);
  sprintf(buffer,"%2d Boating",player.skill[12]); txt_write(buffer);
  gotoxy(60,16); if (player.skill[13]>4) textcolor(14); else textcolor(8);
  sprintf(buffer,"%2d Oracle",player.skill[13]); txt_write(buffer);
  gotoxy(60,17); if (player.skill[14]>4) textcolor(14); else textcolor(8);
  sprintf(buffer,"%2d Charm",player.skill[14]); txt_write(buffer);
  gotoxy(60,18); if (player.skill[15]>4) textcolor(14); else textcolor(8);
  sprintf(buffer,"%2d Survival",player.skill[15]); txt_write(buffer);
  gotoxy(60,19); if (player.skill[16]>4) textcolor(14); else textcolor(8);
  sprintf(buffer,"%2d Combat",player.skill[16]); txt_write(buffer);
  textcolor(14);
  player.map_x = 67;player.map_y = 10;
  player.land_x = 73; player.land_y = 16;
  player.region = 9;
  for (x=1; x<=100; x++)
    for (y=1; y<=100; y++)
      player.known[x][y] = 0;
  m_file = open("temp01.$$$",O_WRONLY | O_CREAT | O_TRUNC,0660);
  if (m_file < 0) {
    printf("Fatal Error: Could not open temp01.$$$\n");
    exit(1);
    }
  for (i=1; i<=NO_OF_MAPS; i++) {
    lseek(m_file,sizeof(KNOW_TYPE) * i,SEEK_SET);
    write(m_file,&(player.known),sizeof(KNOW_TYPE));
    }
  close(m_file);
  player.day = 1; player.month = 1; player.hour = 0; player.min = 1;
  for (i=1; i<=55; i++) player.spell[i] = 0;
  for (i=1; i<=19; i++) player.invent[i].otype = O_NONE;
  for (i=1; i<=32; i++) player.pack[i].otype = O_NONE;
  for (i=0; i<1000; i++) player.hole[i].otype = O_NONE;
  for (i=0; i<5; i++) {
    player.houses[i].region = 0;
    for (j=0; j<500; j++) player.houses[i].inventory[j].otype = O_NONE;
    }
  for (i=1; i<=1000; i++) player.oknow[i] = 0;
  for (i=1; i<=8; i++) player.potion[i] = 0;
  for (i=1; i<=8; i++) player.ring[i] = 0;
  for (i=1; i<=12; i++) player.staff[i] = 0;
  for (i=1; i<=11; i++) player.oknow[i] = 1;
  for (i=32; i<=35; i++) player.oknow[i] = 1;
  for (i=39; i<=40; i++) player.oknow[i] = 1;
  for (i=44; i<=45; i++) player.oknow[i] = 1;
  for (i=49; i<=53; i++) player.oknow[i] = 1;
  for (i=164; i<=182; i++) player.oknow[i] = 1;
  for (i=1; i<=5000; i++) player.gen[i] = 0;
  for (i=1; i<=5000; i++) player.lore[i] = 0;
  for (i=1; i<=10; i++) strcpy(player.fspell[i],"");
  for (i=0; i<1000; i++) player.quests[i] = 'N';
  for (i=1; i<=10; i++) {
    player.tardis_x[i] = 0;
    player.tardis_y[i] = 0;
    player.tardis_r[i] = 0;
    strcpy(player.tardis_d[i],"");
    }
  player.oknow[60] = 1; player.oknow[66] = 1; player.oknow[70] = 1;
  player.oknow[74] = 1; player.oknow[78] = 1; player.oknow[82] = 1;
  for (i=1; i<=8; i++) {
    j = u_random(8)+1;
    while (player.potion[j] != 0) {
      j = u_random(8)+1;
      }
    player.potion[j] = i;
    }
  for (i=1; i<=8; i++) {
    j = u_random(8)+1;
    while (player.ring[j] != 0) j = u_random(8)+1;
    player.ring[j] = i;
    }
  for (i=1; i<=12; i++) {
    j = u_random(12)+1;
    while (player.staff[j] != 0) j = u_random(12)+1;
    player.staff[j] = i;
    }
  if (player.class == 6) new_spell();
  if (player.class == 4) new_spell();
  if (player.class == 5) new_spell();
  new_pawn();
  disp_char();
  }
