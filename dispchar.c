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

void skillcolor(int skill) {
  if (skill >= 90) {
    textcolor(14);   /* Yellow */
    return;
    }
  if (skill >= 80) {
    textcolor(13);   /* Purple */
    return;
    }
  if (skill >= 50) {
    textcolor(9);   /* Blue */
    return;
    }
  if (skill >= 25) {
    textcolor(10);   /* Green */
    return;
    }
  if (skill >= 10) {
    textcolor(15);   /* White */
    return;
    }
  if (skill >= 5) {
    textcolor(7);   /* Light Gray */
    return;
    }
  textcolor(8);
  }

void show_skills() {
  int i;
  for (i=18; i<23; i++) {
    gotoxy(1,i); txt_write("                                       ");
    gotoxy(40,i); txt_write("                                       ");
    }
  gotoxy(1,18);  skillcolor(get_skill(SK_DAGGER));    txt_write(show_int(get_skill(SK_DAGGER)));    gotoxy(4,18); txt_write("Daggers");
  gotoxy(1,19);  skillcolor(get_skill(SK_1HSWORD));   txt_write(show_int(get_skill(SK_1HSWORD)));   gotoxy(4,19); txt_write("1H Swords");
  gotoxy(1,20);  skillcolor(get_skill(SK_2HSWORD));   txt_write(show_int(get_skill(SK_2HSWORD)));   gotoxy(4,20); txt_write("2H Swords");
  gotoxy(1,21);  skillcolor(get_skill(SK_AXE));       txt_write(show_int(get_skill(SK_AXE)));       gotoxy(4,21); txt_write("Axes");
  gotoxy(1,22);  skillcolor(get_skill(SK_MACE));      txt_write(show_int(get_skill(SK_MACE)));      gotoxy(4,22); txt_write("Maces");

  gotoxy(17,18);  skillcolor(get_skill(SK_BOW));      txt_write(show_int(get_skill(SK_BOW)));       gotoxy(20,18); txt_write("Bows");
  gotoxy(17,19);  skillcolor(get_skill(SK_CROSSBOW)); txt_write(show_int(get_skill(SK_CROSSBOW)));  gotoxy(20,19); txt_write("Crossbows");
  gotoxy(17,20);  skillcolor(get_skill(SK_THROWN));   txt_write(show_int(get_skill(SK_THROWN)));    gotoxy(20,20); txt_write("Thrown");
  gotoxy(17,21);  skillcolor(get_skill(SK_TRIDENT));  txt_write(show_int(get_skill(SK_TRIDENT)));   gotoxy(20,21); txt_write("Tridents");
  gotoxy(17,22);  skillcolor(get_skill(SK_POLEAXE));  txt_write(show_int(get_skill(SK_POLEAXE)));   gotoxy(20,22); txt_write("Poleaxes");

  gotoxy(33,18);  skillcolor(get_skill(SK_FLAIL));    txt_write(show_int(get_skill(SK_FLAIL)));     gotoxy(36,18); txt_write("Flails");
  gotoxy(33,19);  skillcolor(get_skill(SK_SPEAR));    txt_write(show_int(get_skill(SK_SPEAR)));     gotoxy(36,19); txt_write("Spears");
  gotoxy(33,20);  skillcolor(get_skill(SK_MAGIC));    txt_write(show_int(get_skill(SK_MAGIC)));     gotoxy(36,20); txt_write("Magic");
  gotoxy(33,21);  skillcolor(get_skill(SK_LANG));     txt_write(show_int(get_skill(SK_LANG)));      gotoxy(36,21); txt_write("Language");
  gotoxy(33,22);  skillcolor(get_skill(SK_LORE));     txt_write(show_int(get_skill(SK_LORE)));      gotoxy(36,22); txt_write("Lore");

  gotoxy(49,18);  skillcolor(get_skill(SK_SCOUT));    txt_write(show_int(get_skill(SK_SCOUT)));     gotoxy(52,18); txt_write("Scouting");
  gotoxy(49,19);  skillcolor(get_skill(SK_HEAL));     txt_write(show_int(get_skill(SK_HEAL)));      gotoxy(52,19); txt_write("Healing");
  gotoxy(49,20);  skillcolor(get_skill(SK_MED));      txt_write(show_int(get_skill(SK_MED)));       gotoxy(52,20); txt_write("Medicine");
  gotoxy(49,21);  skillcolor(get_skill(SK_RIDE));     txt_write(show_int(get_skill(SK_RIDE)));      gotoxy(52,21); txt_write("Riding");
  gotoxy(49,22);  skillcolor(get_skill(SK_BOAT));     txt_write(show_int(get_skill(SK_BOAT)));      gotoxy(52,22); txt_write("Boating");

  gotoxy(65,18);  skillcolor(get_skill(SK_ORACLE));   txt_write(show_int(get_skill(SK_ORACLE)));    gotoxy(68,18); txt_write("Oracle");
  gotoxy(65,19);  skillcolor(get_skill(SK_CHARM));    txt_write(show_int(get_skill(SK_CHARM)));     gotoxy(68,19); txt_write("Charm");
  gotoxy(65,20);  skillcolor(get_skill(SK_SURVIVE));  txt_write(show_int(get_skill(SK_SURVIVE)));   gotoxy(68,20); txt_write("Survival");
  gotoxy(65,21);  skillcolor(get_skill(SK_COMBAT));   txt_write(show_int(get_skill(SK_COMBAT)));    gotoxy(68,21); txt_write("Combat");
  }

void char_sheet_labels(char showall) {
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
  gotoxy(55,6); txt_write("Ranged :");
  gotoxy(55,7); txt_write("Stealth:");
  gotoxy(55,8); txt_write("Disarm :");
  gotoxy(55,9); txt_write("Search :");
  gotoxy(55,10); txt_write("Magic  :");
  if (showall == 'Y') {
    gotoxy(1,12); txt_write("Torches:");
    gotoxy(1,13); txt_write("Gold   :");
    gotoxy(1,14); txt_write("Mount  :");
    gotoxy(1,15); txt_write("Winged :");
    gotoxy(1,16); txt_write("MagFind:");
    gotoxy(31,12); txt_write("To Hit :");
    gotoxy(31,13); txt_write("Crit   :");
    gotoxy(31,14); txt_write("Dodge  :");
    gotoxy(31,15); txt_write("Weight :");
    gotoxy(31,16); txt_write("MnstLvl:");
    gotoxy(55,12); txt_write("Armor  :");
    gotoxy(55,13); txt_write("Weapon :");
    gotoxy(55,14); txt_write("AtkPwr :");
    gotoxy(55,15); txt_write("SplPwr :");
    gotoxy(55,16); txt_write("MagRes :");
    }
  }

void char_sheet_data() {
  int i;
  char buffer[32];
  textcolor(14);
  gotoxy(10,1); txt_write(player.name);
  gotoxy(10,2); txt_write(show_int(player.age));
  gotoxy(10,3);
  if (player.sex == 'F') txt_write("Female"); else txt_write("Male");
  show_health();
  show_align();
  gotoxy(10,4);
  txt_write(races[player.race-1].name);
  gotoxy(10,5); txt_write(show_int(player.level));
  gotoxy(10,6); txt_write(show_flt(player.exp));
  txt_write(" ("); txt_write(show_flt(player.exp_next)); txt_write(")");
  gotoxy(10,7);
  txt_write(classes[player.class-1].name);
  gotoxy(10,8); txt_write(player.title);
  for (i=1; i<7; i++) {
    gotoxy(40,i);
    if (i==1) sprintf(buffer,"%d/%d",get_str(),get_base_str());
    if (i==2) sprintf(buffer,"%d/%d",get_dex(),get_base_dex());
    if (i==3) sprintf(buffer,"%d/%d",get_con(),get_base_con());
    if (i==4) sprintf(buffer,"%d/%d",get_int(),get_base_int());
    if (i==5) sprintf(buffer,"%d/%d",get_wis(),get_base_wis());
    if (i==6) sprintf(buffer,"%d/%d",get_chr(),get_base_chr());
    txt_write(buffer);
    }
  gotoxy(40,7); txt_write(show_int(player.chp));
  sprintf(buffer,"%d/%d",get_mhp(),get_base_mhp());
  gotoxy(40,8); txt_write(buffer);
  gotoxy(40,9); txt_write(show_int(player.cmana));
  sprintf(buffer,"%d/%d",get_mmana(),get_base_mmana());
  gotoxy(40,10); txt_write(buffer);
  display_abilities();
  textcolor(14);
  gotoxy(10,12); txt_write(show_int(player.torch));
  sprintf(buffer,"%d/%d/%d",player.adamantite_coins,player.mithril_coins,player.gold_coins);
  gotoxy(10,13); txt_write(buffer);
  gotoxy(10,14);
  if (player.mount == 0) txt_write("No"); else txt_write("Yes");
  gotoxy(10,15);
  if (player.peg == 0) txt_write("No"); else txt_write("Yes");
  sprintf(buffer,"%d/%d",get_armour(),get_base_armour());
  gotoxy(64,12); txt_write(buffer);
  sprintf(buffer,"%d/%d",get_weapon(),get_base_weapon());
  gotoxy(64,13); txt_write(buffer);
  sprintf(buffer,"%+d",get_attack_power()); gotoxy(64,14); txt_write(buffer);
  sprintf(buffer,"%+d",get_spell_power()); gotoxy(64,15); txt_write(buffer);
  sprintf(buffer,"%+d",(int)(get_magic_resistance() * 100)); gotoxy(64,16); txt_write(buffer);
  sprintf(buffer,"%+d",get_magic_find()); gotoxy(10,16); txt_write(buffer);
  sprintf(buffer,"%+d",get_hit()); gotoxy(40,12); txt_write(buffer);
  sprintf(buffer,"%+d",get_crit()); gotoxy(40,13); txt_write(buffer);
  sprintf(buffer,"%+d",get_dodge()); gotoxy(40,14); txt_write(buffer);
  sprintf(buffer,"%d/%d",get_weight(),get_max_weight()); gotoxy(40,15); txt_write(buffer);
  sprintf(buffer,"%+d",get_monster_level_plus()); gotoxy(40,16); txt_write(buffer);
  }

void do_disp_char() {
  clrscr();
  char_sheet_labels('Y');
  char_sheet_data();
  show_skills();
  textcolor(14);
  gotoxy(14,24); txt_write("<ENTER,ESC> to exit, <T>rophies, <S>tatistics, <F>keys");
  if (player.effect[PE_HEROIC] < 0) {
    textcolor(10);
    gotoxy(1,25); txt_write("Casual");
    }
  if (player.effect[PE_HEROIC] == 2) {
    textcolor(12);
    gotoxy(1,25); txt_write("Heroic");
    }
  if (player.effect[PE_HEROIC] == 4) {
    textcolor(13);
    gotoxy(1,25); txt_write("EPIC");
    }
  }

void disp_char() {
  char key;
  do_disp_char();
  key = ' ';
  while (key != 13 && key != 27) {
    key = inkey();
    if (key == 's' || key == 'S') {
      show_stats();
      do_disp_char();
      }
    if (key == 't' || key == 'T') {
      show_trophies();
      do_disp_char();
      }
    if (key == 'f' || key == 'F') {
      show_f_keys();
      textcolor(14);
      gotoxy(14,24); txt_write("<ENTER,ESC> to exit, <T>rophies, <S>tatistics, s<K>ills");
      }
    if (key == 'k' || key == 'K') {
      show_skills();
      textcolor(14);
      gotoxy(14,24); txt_write("<ENTER,ESC> to exit, <T>rophies, <S>tatistics, <F>keys ");
      }
    }
  }

