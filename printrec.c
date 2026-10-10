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

void print_rec() {
  char pack1[33],pack2[33];
  int  spel1,spel2;
  int  mana1,mana2;
  int  lvl1,lvl2;
  int  i;
  printf("Name   : %s    STR: %2d          Attack : %10s\n",fix_name(player.name),player.stat[1],fix_ability(1));
  printf("Age    : %3d                      DEX: %2d          Defense: %10s\n",player.age,player.stat[2],fix_ability(2));
  printf("Sex    : %s    CON: %2d          Damage : %10s\n",fix_name(get_sex()),player.stat[3],fix_ability(3));
  printf("Race   : %s    INT: %2d          N. Save: %10s\n",fix_name(get_race()),player.stat[4],fix_ability(4));
  printf("Level  : %3d                      WIS: %2d          M. Save: %10s\n",player.level,player.stat[5],fix_ability(5));
  printf("Exp    : %9.0f (%9.0f)        CHR: %2d          Missile: %10s\n",player.exp,player.exp_next,player.stat[6],fix_ability(6));
  printf("Class  : %s   C HP: %4d        Stealth: %10s\n",fix_name(get_class()),player.chp,fix_ability(7));
  printf("Title  : %s   M HP: %4d        Disarm : %10s\n",fix_name(player.title),player.mhp,fix_ability(8));
  printf("Health : %s C Mana: %4d        Search : %10s\n",fix_name(get_health()),player.cmana,fix_ability(9));
  printf("Align. : %s M Mana: %4d        Magic  : %10s\n",fix_name(get_align()),player.mmana,fix_ability(10));
  printf("\n");
  printf("Torches: %4d                     Mount  :%s          Armor  : %3d\n",player.torch,yes_no(player.mount),player.armour);
  printf("Gold   : %9d                Winged :%s          Weapon : %3d\n",get_gold(),yes_no(player.peg),player.weapon);
  printf("\n");
  printf("SKILLS:\n");
  printf("%3d Arrow        ",get_skill(1));
  printf("%3d Scouting     ",get_skill(5));
  printf("%3d Healing      ",get_skill(9));
  printf("%3d Oracle       \n",get_skill(13));
  printf("%3d Edge Weapons ",get_skill(2));
  printf("%3d Language     ",get_skill(6));
  printf("%3d Medicine     ",get_skill(10));
  printf("%3d Charm        \n",get_skill(14));
  printf("%3d Pole Weapons ",get_skill(3));
  printf("%3d Lore         ",get_skill(7));
  printf("%3d Riding       ",get_skill(11));
  printf("%3d Survival     \n",get_skill(15));
  printf("%3d Hunting      ",get_skill(4));
  printf("%3d Magic        ",get_skill(8));
  printf("%3d Boats        ",get_skill(12));
  printf("%3d Combat       \n",get_skill(16));
  printf("\n");
  printf("INVENTORY:\n");
  printf("Left Hand      : %s",fix_name(get_name(&(player.invent[I_LHND]))));
  printf("Shield : %s\n",fix_name(get_name(&(player.invent[I_SHLD]))));
  printf("Right Hand     : %s",fix_name(get_name(&(player.invent[I_RHND]))));
  printf("Armor  : %s\n",fix_name(get_name(&(player.invent[I_ARMR]))));
  printf("Left Shoulder  : %s",fix_name(get_name(&(player.invent[I_LSHL]))));
  printf("Ring   : %s\n",fix_name(get_name(&(player.invent[I_RNG1]))));
  printf("Right Shoulder : %s",fix_name(get_name(&(player.invent[I_RSHL]))));
  printf("Ring   : %s\n",fix_name(get_name(&(player.invent[I_RNG2]))));
  printf("Neck           : %s",fix_name(get_name(&(player.invent[I_NCK1]))));
  printf("Ring   : %s\n",fix_name(get_name(&(player.invent[I_RNG2]))));
  printf("Neck           : %s",fix_name(get_name(&(player.invent[I_NCK2]))));
  printf("Ring   : %s\n",fix_name(get_name(&(player.invent[I_RNG4]))));
  printf("Belt Front     : %s",fix_name(get_name(&(player.invent[I_BLTL]))));
  printf("Robe   : %s\n",fix_name(get_name(&(player.invent[I_ROBE]))));
  printf("Belt Back      : %s",fix_name(get_name(&(player.invent[I_BLTR]))));
  printf("Boots  : %s\n",fix_name(get_name(&(player.invent[I_BOOT]))));
  printf("Belt Left      : %s",fix_name(get_name(&(player.invent[I_BLTF]))));
  printf("Helm   : %s\n",fix_name(get_name(&(player.invent[I_HELM]))));
  printf("Belt Right     : %s\n",fix_name(get_name(&(player.invent[I_BLTB]))));
  printf("\n");
  printf("PACK:\n");
  for (i=1; i<=16; i++) {
    if (player.pack[i].otype == O_NONE) strcpy(pack1,fix_name(" "));
      else strcpy(pack1,fix_name(get_name(&(player.pack[i]))));
    if (player.pack[i+16].otype == O_NONE) strcpy(pack2,fix_name(" "));
      else strcpy(pack2,fix_name(get_name(&(player.pack[i+16]))));
    printf("%2d: %s     %2d: %s\n",i,pack1,i+16,pack2);
    }
  printf("\n");
  printf("FUNCTION KEY SPELLS\n");
  printf("F1 - %s",fix_name(player.fspell[1]));
  printf("       F2  - %s\n",fix_name(player.fspell[2]));
  printf("F3 - %s",fix_name(player.fspell[3]));
  printf("       F4  - %s\n",fix_name(player.fspell[4]));
  printf("F5 - %s",fix_name(player.fspell[5]));
  printf("       F6  - %s\n",fix_name(player.fspell[6]));
  printf("F7 - %s",fix_name(player.fspell[7]));
  printf("       F8  - %s\n",fix_name(player.fspell[8]));
  printf("F9 - %s",fix_name(player.fspell[9]));
  printf("       F10 - %s\n",fix_name(player.fspell[10]));
  printf("\n");
  printf("SPELLS:\n");
  printf("   Lvl Mana Name                           Lvl Mana Name\n");
  for (i=1; i<=27; i++) {
    if (spellbook[i] != 0) {
      spel1 = spellbook[i];
      strcpy(pack1,fix_name(spells[spel1].name));
      lvl1 = spells[spel1].level;
      mana1 = mana_cost(spells[spel1].mana);
      }
    else {
      strcpy(pack1,fix_name(" "));
      lvl1 = 0;
      mana1 = 0;
      }
    if (spellbook[i+27] != 0) {
      spel2 = spellbook[i+27];
      strcpy(pack2,fix_name(spells[spel2].name));
      lvl2 = spells[spel2].level;
      mana2 = mana_cost(spells[spel2].mana);
      }
    else {
      strcpy(pack2,fix_name(" "));
      lvl2 = 0;
      mana2 = 0;
      }
    printf("%2d: %2d   %2d %s   ",i,lvl1,mana1,pack1);
    printf("%2d: %2d   %2d %s   \n",i+27,lvl2,mana2,pack2);
    }
  printf("\n");
  printf("PARTY:\n");
  printf("Pos. Name                    Lvl    Hp  Mana Attack   Defense\n");
  for (i=1; i<=5; i++)
    if (player.party[i].hp != 0) {
      printf("  %d: %s%2d  %4d  %4d  %3d     %4d\n",i,
             fix_name(player.party[i].name),
             player.party[i].level,player.party[i].hp,
             player.party[i].mana,player.party[i].attack,
             player.party[i].defense);
      }
  if (player.quests[41] == 'Y') {
    printf("\n");
    printf("TARDIS DESTINATION LOG\n");
    printf("                Region   X   Y   Description\n");
    for (i=1; i<=10; i++) {
      printf("          %2d      %2d    %2d  %2d   %s\n",i,
             player.tardis_r[i],player.tardis_x[i],player.tardis_y[i],
             player.tardis_d[i]);
      }
    }
  printf("\n");
  }
