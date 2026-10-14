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

void advancement() {
  int i;
  char buffer[40];

  void show_gain(int g) {
    switch (g) {
      case 1:msg("Gained Missile",14); break;
      case 2:msg("Gained Edge",14); break;
      case 3:msg("Gained Pole",14); break;
      case 4:msg("Gained Hunting",14); break;
      case 5:msg("Gained Scouting",14); break;
      case 6:msg("Gained Language",14); break;
      case 7:msg("Gained Lore",14); break;
      case 8:msg("Gained Magic",14); break;
      case 9:msg("Gained Healing",14); break;
      case 10:msg("Gained Medicine",14); break;
      case 11:msg("Gained Riding",14); break;
      case 12:msg("Gained Boating",14); break;
      case 13:msg("Gained Oracle",14); break;
      case 14:msg("Gained Charm",14); break;
      case 15:msg("Gained Survival",14); break;
      case 16:msg("Gained Combat",14); break;
      }
    }

  void skills1() {
    int i;
    int j;
    int s;
    for (i=0; i<2; i++) {
      j = u_random(29);
      s = 0;
      if (j>=1 && j<=5) s=1;
      if (j>=6 && j<=10) s=2;
      if (j>=11 && j<=15) s=3;
      if (j==16) s=4;
      if (j==17) s=5;
      if (j==18) s=6;
      if (j==19) s=9;
      if (j==20) s=10;
      if (j==21) s=11;
      if (j==22) s=12;
      if (j==23) s=13;
      if (j==24) s=14;
      if (j==25) s=15;
      if (j>=26 && j<=28) s=16;
      if (s>0) {
        player.skill[s]++;
        show_gain(s);
        }
      }
    }

  void skills2() {
    int i;
    int j;
    int s;
    for (i=0; i<3; i++) {
      j = u_random(42);
      s = 0;
      if (j>=1 && j<=5) s=1;
      if (j>=6 && j<=10) s=2;
      if (j>=11 && j<=15) s=3;
      if (j==16) s=4;
      if (j==17) s=5;
      if (j==18) s=6;
      if (j==19) s=7;
      if (j==20) s=8;
      if (j>=21 && j<=25) s=9;
      if (j>=26 && j<=30) s=10;
      if (j==31) s=11;
      if (j==32) s=12;
      if (j==33) s=13;
      if (j>=34 && j<=37) s=14;
      if (j==38) s=15;
      if (j>=39 && j<=41) s=16;
      if (s>0) {
        player.skill[s]++;
        show_gain(s);
        }
      }
    }

  void skills3() {
    int i;
    int j;
    int s;
    for (i=0; i<3; i++) {
      j = u_random(42);
      s = 0;
      if (j>=1 && j<=5) s=1;
      if (j>=6 && j<=10) s=2;
      if (j>=11 && j<=15) s=3;
      if (j>=16 && j<=20) s=4;
      if (j>=21 && j<=25) s=5;
      if (j>=26 && j<=27) s=6;
      if (j==28) s=7;
      if (j==29) s=8;
      if (j==30) s=9;
      if (j==31) s=10;
      if (j>=32 && j<=34) s=11;
      if (j==35) s=12;
      if (j==36) s=13;
      if (j==37) s=14;
      if (j>=38 && j<=40) s=15;
      if (j==41) s=16;
      if (s>0) {
        player.skill[s]++;
        show_gain(s);
        }
      }
    }

  void skills4() {
    int i;
    int j;
    int s;
    for (i=0; i<2; i++) {
      j = u_random(22);
      s = 0;
      if (j==1) s=1;
      if (j==2) s=2;
      if (j==3) s=3;
      if (j==4) s=4;
      if (j==5) s=5;
      if (j==6) s=6;
      if (j==7) s=7;
      if (j==8) s=8;
      if (j>=9 && j<=12) s=9;
      if (j>=13 && j<=15) s=10;
      if (j==16) s=11;
      if (j==17) s=12;
      if (j==18) s=13;
      if (j==19) s=14;
      if (j==20) s=15;
      if (j==21) s=16;
      if (s>0) {
        player.skill[s]++;
        show_gain(s);
        }
      }
    }

  void skills5() {
    int i;
    int j;
    int s;
    for (i=0; i<3; i++) {
      j = u_random(30);
      s = 0;
      if (j==1) s=1;
      if (j==2) s=2;
      if (j==3) s=3;
      if (j>=4 && j<=6) s=4;
      if (j>=7 && j<=9) s=5;
      if (j>=10 && j<=11) s=6;
      if (j==12) s=7;
      if (j==13) s=8;
      if (j>=14 && j<=16) s=9;
      if (j>=17 && j<=19) s=10;
      if (j>=20 && j<=21) s=11;
      if (j>=22 && j<=23) s=12;
      if (j==24) s=13;
      if (j==25) s=14;
      if (j>=26 && j<=28) s=15;
      if (j==29) s=16;
      if (s>0) {
        player.skill[s]++;
        show_gain(s);
        }
      }
    }

  void skills6() {
    int i;
    int j;
    int s;
    for (i=0; i<2; i++) {
      j = u_random(24);
      s = 0;
      if (j==1) s=1;
      if (j==2) s=2;
      if (j==3) s=3;
      if (j==4) s=4;
      if (j==5) s=5;
      if (j>=6 && j<=7) s=6;
      if (j>=8 && j<=10) s=7;
      if (j>=11 && j<=15) s=8;
      if (j==16) s=9;
      if (j==17) s=10;
      if (j==18) s=11;
      if (j==19) s=12;
      if (j==20) s=13;
      if (j==21) s=14;
      if (j==22) s=15;
      if (j==23) s=16;
      if (s>0) {
        player.skill[s]++;
        show_gain(s);
        }
      }
    }

  void skills7() {
    int i;
    int j;
    int s;
    for (i=0; i<2; i++) {
      j = u_random(41);
      s = 0;
      if (j>=1 && j<=5) s=1;
      if (j>=6 && j<=10) s=2;
      if (j>=11 && j<=15) s=3;
      if (j>=16 && j<=20) s=4;
      if (j>=21 && j<=25) s=5;
      if (j==26) s=6;
      if (j==27) s=9;
      if (j==28) s=10;
      if (j==29) s=11;
      if (j==30) s=12;
      if (j==31) s=13;
      if (j>=32 && j<=35) s=15;
      if (j>=36 && j<=40) s=16;
      if (s>0) {
        player.skill[s]++;
        show_gain(s);
        }
      }
    }


  msg("Gained a Level !!!",15);
  if (player.class == 1) {
    player.level++;
    i = u_random(10) + 1;
    if (player.stat[3] > 14) i++;
    if (player.stat[3] > 17) i++;
    if (player.stat[3] > 20) i+=2;
    player.chp += i;
    player.mhp += i;
    sprintf(buffer,"Gained %d Hit Points",i);
    msg(buffer,10);
    skills1();
    advance_stat();
    adjust_abilities();
    if (player.exp_next<1e5) player.exp_next += player.exp_next;
      else player.exp_next *= 1.2;
    if (player.level >=2 && player.level <=4) strcpy(player.title,"Warrior");
    if (player.level >=5 && player.level <=7) {
      if (player.sex == 'F') strcpy(player.title,"Swordmaiden");
        else strcpy(player.title,"Swordsman");
      }
    if (player.level >=8 && player.level <=10) {
      if (player.sex == 'F') strcpy(player.title,"Heroine");
        else strcpy(player.title,"Hero");
      }
    if (player.level >=11 && player.level <=13) strcpy(player.title,"Swashbuckler");
    if (player.level >=14 && player.level <=16) strcpy(player.title,"Myrmidon");
    if (player.level >=17 && player.level <=19) strcpy(player.title,"Champion");
    if (player.level >=20 && player.level <=22) strcpy(player.title,"Superhero");
    if (player.level >=23 && player.level <=99) {
      if (player.sex == 'F') strcpy(player.title,"Lady");
        else strcpy(player.title,"Lord");
      }
    return;
    }
  if (player.class == 2) {
    player.level++;
    i = u_random(10) + 1;
    if (player.stat[3] > 14) i++;
    if (player.stat[3] > 17) i++;
    if (player.stat[3] > 20) i+=2;
    player.chp += i;
    player.mhp += i;
    sprintf(buffer,"Gained %d Hit Points",i);
    msg(buffer,10);
    skills2();
    advance_stat();
    adjust_abilities();
    if (player.level >= 9) {
      i = u_random(5) + 5;
      player.mmana += i;
      player.cmana += i;
      sprintf(buffer,"Gained %d Mana Points",i);
      msg(buffer,10);
      }
    if (player.exp_next<1e5) player.exp_next += player.exp_next;
      else player.exp_next *= 1.3;
    if (player.level >= 9) {
      new_spell();
      show_screen();
      }
    if (player.level >=2 && player.level <=4) strcpy(player.title,"Keeper");
    if (player.level >=5 && player.level <=7) strcpy(player.title,"Protector");
    if (player.level >=8 && player.level <=10) strcpy(player.title,"Defender");
    if (player.level >=11 && player.level <=13) strcpy(player.title,"Warder");
    if (player.level >=14 && player.level <=16) strcpy(player.title,"Guardian");
    if (player.level >=17 && player.level <=19) strcpy(player.title,"Chevalier");
    if (player.level >=20 && player.level <=22) strcpy(player.title,"Justiciar");
    if (player.level >=23 && player.level <=99) strcpy(player.title,"Paladin");
    return;
    }
  if (player.class == 3) {
    player.level++;
    i = u_random(8) + 1;
    if (player.stat[3] > 14) i++;
    if (player.stat[3] > 17) i++;
    if (player.stat[3] > 20) i+=2;
    player.chp += i;
    player.mhp += i;
    sprintf(buffer,"Gained %d Hit Points",i);
    msg(buffer,10);
    skills3();
    advance_stat();
    adjust_abilities();
    if (player.level >= 8) {
      i = u_random(5) + 5;
      player.mmana += i;
      player.cmana += i;
      sprintf(buffer,"Gained %d Mana Points",i);
      msg(buffer,10);
      }
    if (player.exp_next<1e5) player.exp_next += player.exp_next;
      else player.exp_next *= 1.25;
    if (player.level >= 8) {
      new_spell();
      show_screen();
      }
    if (player.level >=2 && player.level <=4) strcpy(player.title,"Strider");
    if (player.level >=5 && player.level <=7) strcpy(player.title,"Scout");
    if (player.level >=8 && player.level <=10) strcpy(player.title,"Courser");
    if (player.level >=11 && player.level <=13) strcpy(player.title,"Tracker");
    if (player.level >=14 && player.level <=16) strcpy(player.title,"Guide");
    if (player.level >=17 && player.level <=19) strcpy(player.title,"Pathfinder");
    if (player.level >=20 && player.level <=22) strcpy(player.title,"Ranger");
    if (player.level >=23 && player.level <=25) strcpy(player.title,"Ranger Knight");
    if (player.level >=26 && player.level <=99) strcpy(player.title,"Ranger Lord");
    return;
    }
  if (player.class == 4) {
    player.level++;
    i = u_random(6) + 1;
    if (player.stat[3] > 14) i++;
    if (player.stat[3] > 17) i++;
    if (player.stat[3] > 20) i+=2;
    player.chp += i;
    player.mhp += i;
    sprintf(buffer,"Gained %d Hit Points",i);
    msg(buffer,10);
    skills4();
    advance_stat();
    adjust_abilities();
    i = u_random(5) + 5;
    player.mmana += i;
    player.cmana += i;
    sprintf(buffer,"Gained %d Mana Points",i);
    msg(buffer,10);
    if (player.exp_next<1e5) player.exp_next += player.exp_next;
      else player.exp_next *= 1.25;
    new_spell();
    show_screen();
    if (player.level >=2 && player.level <=4) strcpy(player.title,"Adept");
    if (player.level >=5 && player.level <=7) 
      strcpy(player.title,((player.sex == 'F') ? "Priestess" : "Priest"));
    if (player.level >=8 && player.level <=10) strcpy(player.title,"Curate");
    if (player.level >=11 && player.level <=13) strcpy(player.title,"Perfect");
    if (player.level >=14 && player.level <=16) strcpy(player.title,"Canon");
    if (player.level >=17 && player.level <=19) strcpy(player.title,"Lama");
    if (player.level >=20 && player.level <=22)
      strcpy(player.title,((player.sex == 'F') ? "Matriarch" : "Patriarch"));
    if (player.level >=23 && player.level <=25)
      strcpy(player.title,((player.sex == 'F') ? "High Priestess" : "High Priest"));
    if (player.level >=26 && player.level <=28) strcpy(player.title,"Prior");
    if (player.level >=29 && player.level <=31) strcpy(player.title,"Abbot");
    if (player.level >=32 && player.level <=34) strcpy(player.title,"Bishop");
    if (player.level >=35 && player.level <=99) strcpy(player.title,"Archbishop");
    return;
    }
  if (player.class == 5) {
    player.level++;
    i = u_random(6) + 1;
    if (player.stat[3] > 14) i++;
    if (player.stat[3] > 17) i++;
    if (player.stat[3] > 20) i+=2;
    player.chp += i;
    player.mhp += i;
    sprintf(buffer,"Gained %d Hit Points",i);
    msg(buffer,10);
    skills5();
    advance_stat();
    adjust_abilities();
    i = u_random(5) + 5;
    player.mmana += i;
    player.cmana += i;
    sprintf(buffer,"Gained %d Mana Points",i);
    msg(buffer,10);
    if (player.exp_next<1e5) player.exp_next += player.exp_next;
      else player.exp_next *= 1.25;
    new_spell();
    show_screen();
    if (player.level >=2 && player.level <=4) strcpy(player.title,"Ovate");
    if (player.level >=5 && player.level <=7) strcpy(player.title,"1st Circle");
    if (player.level >=8 && player.level <=10) strcpy(player.title,"2nd Circle");
    if (player.level >=11 && player.level <=13) strcpy(player.title,"3rd Circle");
    if (player.level >=14 && player.level <=16) strcpy(player.title,"4th Circle");
    if (player.level >=17 && player.level <=19) strcpy(player.title,"5th Circle");
    if (player.level >=20 && player.level <=22) strcpy(player.title,"6th Circle");
    if (player.level >=23 && player.level <=25) strcpy(player.title,"7th Circle");
    if (player.level >=26 && player.level <=28) strcpy(player.title,"8th Circle");
    if (player.level >=29 && player.level <=31) strcpy(player.title,"9th Circle");
    if (player.level >=32 && player.level <=34) strcpy(player.title,"Druid");
    if (player.level >=35 && player.level <=37) strcpy(player.title,"Archdruid");
    if (player.level >=38 && player.level <=99) strcpy(player.title,"The Great Druid");
    return;
    }
  if (player.class == 6) {
    player.level++;
    i = u_random(6) + 1;
    if (player.stat[3] > 14) i++;
    if (player.stat[3] > 17) i++;
    if (player.stat[3] > 20) i+=2;
    player.chp += i;
    player.mhp += i;
    sprintf(buffer,"Gained %d Hit Points",i);
    msg(buffer,10);
    skills6();
    advance_stat();
    adjust_abilities();
    i = u_random(5) + 5;
    player.mmana += i;
    player.cmana += i;
    sprintf(buffer,"Gained %d Mana Points",i);
    msg(buffer,10);
    if (player.exp_next<1e5) player.exp_next += player.exp_next;
      else player.exp_next *= 1.4;
    new_spell();
    show_screen();
    if (player.level >=2 && player.level <=4) strcpy(player.title,"Evoker");
    if (player.level >=5 && player.level <=7) strcpy(player.title,"Conjurer");
    if (player.level >=8 && player.level <=10) strcpy(player.title,"Theurgist");
    if (player.level >=11 && player.level <=13) strcpy(player.title,"Thaumaturgist");
    if (player.level >=14 && player.level <=16) strcpy(player.title,"Magician");
    if (player.level >=17 && player.level <=19)
      strcpy(player.title,((player.sex == 'F') ? "Enchantress" : "Enchanter"));
    if (player.level >=20 && player.level <=22)
      strcpy(player.title,((player.sex == 'F') ? "Witch" : "Warlock"));
    if (player.level >=23 && player.level <=25)
      strcpy(player.title,((player.sex == 'F') ? "Sorceress" : "Sorcerer"));
    if (player.level >=26 && player.level <=28) strcpy(player.title,"Necromancer");
    if (player.level >=29 && player.level <=31)
      strcpy(player.title,((player.sex == 'F') ? "Wizardess" : "Wizard"));
    if (player.level >=32 && player.level <=34) strcpy(player.title,"Mage");
    if (player.level >=35 && player.level <=37) strcpy(player.title,"Grand Mage");
    if (player.level >=38 && player.level <=99) strcpy(player.title,"Arch Mage");
    return;
    }
  if (player.class == 7) {
    player.level++;
    i = u_random(6) + 1;
    if (player.stat[3] > 14) i++;
    if (player.stat[3] > 17) i++;
    if (player.stat[3] > 20) i+=2;
    player.chp += i;
    player.mhp += i;
    sprintf(buffer,"Gained %d Hit Points",i);
    msg(buffer,10);
    skills7();
    advance_stat();
    adjust_abilities();
    if (player.exp_next<1e5) player.exp_next += player.exp_next;
      else player.exp_next *= 1.3;
    if (player.level >=2 && player.level <=4) strcpy(player.title,"Rutterkin");
    if (player.level >=5 && player.level <=7) strcpy(player.title,"Waghalter");
    if (player.level >=8 && player.level <=10) strcpy(player.title,"Murderer");
    if (player.level >=11 && player.level <=13) strcpy(player.title,"Thug");
    if (player.level >=14 && player.level <=16) strcpy(player.title,"Killer");
    if (player.level >=17 && player.level <=19) strcpy(player.title,"Cutthroat");
    if (player.level >=20 && player.level <=22) strcpy(player.title,"Executioner");
    if (player.level >=23 && player.level <=25) strcpy(player.title,"Assassin");
    if (player.level >=26 && player.level <=28) strcpy(player.title,"Expert Assassin");
    if (player.level >=29 && player.level <=31) strcpy(player.title,"Senior Assassin");
    if (player.level >=32 && player.level <=34) strcpy(player.title,"Chief Assassin");
    if (player.level >=35 && player.level <=37) strcpy(player.title,"Prime Assassin");
    if (player.level >=38 && player.level <=40) strcpy(player.title,"Guildmaster Assassin");
    if (player.level >=41 && player.level <=99) strcpy(player.title,"Gransfather of Assassins");
    return;
    }
  if (player.class == 8) {
    player.level++;
    i = u_random(6) + 1;
    if (player.stat[3] > 14) i++;
    if (player.stat[3] > 17) i++;
    if (player.stat[3] > 20) i+=2;
    player.chp += i;
    player.mhp += i;
    sprintf(buffer,"Gained %d Hit Points",i);
    msg(buffer,10);
    skills5();
    advance_stat();
    adjust_abilities();
    i = u_random(5) + 5;
    player.mmana += i;
    player.cmana += i;
    sprintf(buffer,"Gained %d Mana Points",i);
    msg(buffer,10);
    if (player.exp_next<1e5) player.exp_next += player.exp_next;
      else player.exp_next *= 1.3;
    new_spell();
    show_screen();
    if (player.level >=4 && player.level <=7) strcpy(player.title,"Hierophant Initiate");
    if (player.level >=8 && player.level <=11) strcpy(player.title,"Hierophant Adept");
    if (player.level >=12 && player.level <=15) strcpy(player.title,"Hierophant Master");
    if (player.level >=16 && player.level <=20) strcpy(player.title,"Numinous Hierophant");
    if (player.level >=21 && player.level <=25) strcpy(player.title,"Mystic Hierophant");
    if (player.level >=26 && player.level <=30) strcpy(player.title,"Arcane Hierophant");
    if (player.level >=31 && player.level <=99) strcpy(player.title,"Hierophant of the Cabal");
    return;
    }
  if (player.class == 9) {
    player.level++;
    switch (u_random(4)) {
      case 0:player.skill[2]++; show_gain(2); break;
      case 1:player.skill[3]++; show_gain(3); break;
      case 2:player.skill[15]++; show_gain(15); break;
      case 3:player.skill[16]++; show_gain(16); break;
      }
    i = u_random(12) + 1;
    if (player.stat[3] > 14) i++;
    if (player.stat[3] > 17) i++;
    if (player.stat[3] > 20) i+=2;
    player.chp += i;
    player.mhp += i;
    sprintf(buffer,"Gained %d Hit Points",i);
    msg(buffer,10);
    skills1();
    advance_stat();
    adjust_abilities();
    if (player.exp_next<1e5) player.exp_next += player.exp_next;
      else player.exp_next *= 1.2;
    if (player.level >=2 && player.level <=4) strcpy(player.title,"Scutifer");
    if (player.level >=5 && player.level <=7) strcpy(player.title,"Esquire");
    if (player.level >=8 && player.level <=10) strcpy(player.title,"Knight Errant");
    if (player.level >=11 && player.level <=13) strcpy(player.title,"Knight Bachelor");
    if (player.level >=14 && player.level <=16) strcpy(player.title,"Knight");
    if (player.level >=17 && player.level <=19) strcpy(player.title,"Grand Knight");
    if (player.level >=20 && player.level <=22) strcpy(player.title,"Banneret");
    if (player.level >=23 && player.level <=25) strcpy(player.title,"Chevalier");
    if (player.level >=26 && player.level <=99) strcpy(player.title,"Cavalier");
    return;
    }
  if (player.class == 10) {
    player.level++;
    switch (u_random(4)) {
      case 0:player.skill[2]++; show_gain(2); break;
      case 1:player.skill[3]++; show_gain(3); break;
      case 2:player.skill[15]++; show_gain(15); break;
      case 3:player.skill[16]++; show_gain(16); break;
      }
    i = u_random(4) + 1;
    if (player.stat[3] > 14) i++;
    if (player.stat[3] > 17) i++;
    if (player.stat[3] > 20) i+=2;
    player.chp += i;
    player.mhp += i;
    sprintf(buffer,"Gained %d Hit Points",i);
    msg(buffer,10);
    skills1();
    advance_stat();
    adjust_abilities();
    check_monk_weapon();
    if (player.exp_next<1e5) player.exp_next += player.exp_next;
      else player.exp_next *= 1.3;
    if (player.level >=2 && player.level <=4) strcpy(player.title,"Initiate");
    if (player.level >=5 && player.level <=7) strcpy(player.title,"Brother");
    if (player.level >=8 && player.level <=10) strcpy(player.title,"Disciple");
    if (player.level >=11 && player.level <=13) strcpy(player.title,"Immaculate");
    if (player.level >=14 && player.level <=16) strcpy(player.title,"Master");
    if (player.level >=17 && player.level <=19) strcpy(player.title,"Superior Master");
    if (player.level >=20 && player.level <=22) strcpy(player.title,"Master of Dragons");
    if (player.level >=23 && player.level <=25) strcpy(player.title,"Master of the N. Wind");
    if (player.level >=26 && player.level <=28) strcpy(player.title,"Master of the W. Wind");
    if (player.level >=29 && player.level <=31) strcpy(player.title,"Master of the S. Wind");
    if (player.level >=32 && player.level <=34) strcpy(player.title,"Master of the E. Wind");
    if (player.level >=35 && player.level <=37) strcpy(player.title,"Master of Winter");
    if (player.level >=38 && player.level <=40) strcpy(player.title,"Master of Autumn");
    if (player.level >=41 && player.level <=43) strcpy(player.title,"Master of Summer");
    if (player.level >=44 && player.level <=46) strcpy(player.title,"Master of Spring");
    if (player.level >=47 && player.level <=99) strcpy(player.title,"Grand Master of Flowers");
    return;
    }
  if (player.class == 11) {
    player.level++;
    player.gold += (player.level * 10000);
    i = u_random(10) + 1;
    if (player.stat[3] > 14) i++;
    if (player.stat[3] > 17) i++;
    if (player.stat[3] > 20) i+=2;
    player.chp += i;
    player.mhp += i;
    sprintf(buffer,"Gained %d Hit Points",i);
    msg(buffer,10);
    skills1();
    advance_stat();
    adjust_abilities();
    if (player.exp_next<1e5) player.exp_next += player.exp_next;
      else player.exp_next *= 1.3;
    if (player.level >=2 && player.level <=5) strcpy(player.title,"Baronet");
    if (player.level >=6 && player.level <=9)
      strcpy(player.title,((player.sex == 'F') ? "Baroness" : "Baron"));
    if (player.level >=10 && player.level <=13)
      strcpy(player.title,((player.sex == 'F') ? "Viscountess" : "Viscount"));
    if (player.level >=14 && player.level <=17)
      strcpy(player.title,((player.sex == 'F') ? "Countess" : "Count"));
    if (player.level >=18 && player.level <=21)
      strcpy(player.title,((player.sex == 'F') ? "Marquise" : "Marquis"));
    if (player.level >=22 && player.level <=25)
      strcpy(player.title,((player.sex == 'F') ? "Duchess" : "Duke"));
    if (player.level >=26 && player.level <=29)
      strcpy(player.title,((player.sex == 'F') ? "Princess" : "Prince"));
    if (player.level >=30 && player.level <=33)
      strcpy(player.title,((player.sex == 'F') ? "Queen of Halkanar" : "King of Halkanar"));
    if (player.level >=34 && player.level <=99)
      strcpy(player.title,((player.sex == 'F') ? "Empress of Arne" : "Emperor of Arne"));
    return;
    }
  }

