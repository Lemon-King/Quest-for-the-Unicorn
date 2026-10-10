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

void random_spell(OBJECT_REC* item) {
  int spell;
  int i;
  char buffer[64];
  item->effect = E_SPEL;
  for (i=0; i<100; i++) {
    spell = u_random(num_spells);
    if (spells[spell].level >= item->control &&
        spells[spell].level <= item->control2) i = 999;
    }
  item->control = spell;
  item->cost = 1000 * spells[spell].level;
  strcpy(buffer,"Scroll|Spell:");
  strcat(buffer,spells[spell].name);
  if (strlen(buffer) > 33) buffer[33] = 0;
  strcpy(item->name,buffer);
  }

int random_enchant(int e1, int e2, int e3) {
  int e;
  int a;
  a = 0;
  e = u_random(S_MAX_ENCH) + 1;
  if (e == 31) e = 31 + u_random(24);
  while ((e == (e1 / 100)) ||
         (e == (e2 / 100)) ||
         (e == (e3 / 100)) ) {
     e = u_random(S_MAX_ENCH) + 1;
     if (e == 31) e = 31 + u_random(24);
     }
  switch (e) {
    case 1:   /* STR */
    case 2:   /* DEX */
    case 3:   /* INT */
    case 4:   /* WIS */
    case 5:   /* CON */
    case 6:   /* CHR */
    case 12:  /* HPR */
    case 13:  /* MNR */
    case 14:  /* Base */
    case 15:  /* EXP */
    case 16:  /* mgf */
    case 18:  /* Mgr */
    case 19:  /* Mlv */
    case 20:  /* Crit */
    case 21:  /* Dodge */
    case 26:  /* Spell Power */
    case 31:  /* Skill Bow */
    case 32:  /* Skill 1hsword */
    case 33:  /* Skill spear */
    case 34:  /* Skill mace */
    case 35:  /* Skill scout */
    case 36:  /* Skill lang */
    case 37:  /* Skill lore */
    case 38:  /* Skill magic */
    case 39:  /* Skill heal */
    case 40:  /* Skill med */
    case 41:  /* Skill ride */
    case 42:  /* Skill boat */
    case 43:  /* Skill oracle */
    case 44:  /* Skill charm */
    case 45:  /* Skill survive */
    case 46:  /* Skill combat */
    case 47:  /* Skill dagger */
    case 48:  /* Skill 2hsword */
    case 49:  /* Skill axe */
    case 50:  /* Skill flail */
    case 51:  /* Skill crossbow */
    case 52:  /* Skill trident */
    case 53:  /* Skill poleaxe */
    case 54:  /* Skill thrown */
           a = u_random(5)+1;
           break;
    case 7:   /* mmana */
    case 8:   /* mhps */
    case 17:  /* hp/mp */
           a = (u_random(5)+1) * 10;
           break;
    case 9:   /* atp */
    case 10:  /* def */
    case 11:  /* hit */
           a = u_random(16)+1;
           break;
    case 22:  /* fire */
    case 23:  /* cold */
    case 24:  /* elec */
    case 25:  /* arcane */
    case 30:  /* all elements */
           a = (u_random(5)+1) * 5;
           break;
    }
  return (e * 100) + a;;
  }

int place_object(int level) {
  int j;
  int s;
  int pls;
  int enchants;
  int e1,e2,e3;
  j = u_random(NO_OF_OBJECTS) + 1;
  while (abs(objects[j].level) > level ||
         objects[j].level == 0 ||
         (objects[j].control2 < 0 && -objects[j].control2 != date.tm_mon) ||
         (u_random(20000) - get_magic_find() * 5) >= objects[j].rarity)
     j = u_random(NO_OF_OBJECTS) + 1;
  s = find_item_slot();
  if (s >= 0) {
    player.map_objects[s] = objects[j];
    if (player.map_objects[s].effect == E_RSPL) {
      random_spell(&(player.map_objects[s]));
      }
    if (player.map_objects[s].charges > 0)
      player.map_objects[s].charges = u_random(player.map_objects[s].charges) + 1;
    if (player.map_objects[s].otype == O_ARMR ||
        player.map_objects[s].otype == O_SHLD ||
        player.map_objects[s].otype == O_HELM ||
        player.map_objects[s].otype == O_BOOT ||
        player.map_objects[s].otype == O_DAGR ||
        player.map_objects[s].otype == O_EDGE ||
        player.map_objects[s].otype == O_BLNT ||
        player.map_objects[s].otype == O_POLE ||
        player.map_objects[s].otype == O_BOW) {
      if (u_random(100)<20) {
        pls = u_random(player.diff/4+1+player.d_level/7);
        if (pls != 0 && u_random(100) >= 30) {
          player.map_objects[s].plus = pls;
          }
        else {
          player.map_objects[s].plus = 0 - pls;
          }
        }
      }
    if (player.map_objects[s].num_sockets == 0) {
      player.map_objects[s].sockets[0] = 0;
      player.map_objects[s].sockets[1] = 0;
      player.map_objects[s].sockets[2] = 0;
      if (player.map_objects[s].otype == O_ARMR ||
          player.map_objects[s].otype == O_SHLD ||
          player.map_objects[s].otype == O_HELM ||
          player.map_objects[s].otype == O_BOOT ||
          player.map_objects[s].otype == O_RING ||
          player.map_objects[s].otype == O_NECK ||
          player.map_objects[s].otype == O_DAGR ||
          player.map_objects[s].otype == O_EDGE ||
          player.map_objects[s].otype == O_BLNT ||
          player.map_objects[s].otype == O_POLE ||
          player.map_objects[s].otype == O_BOW) {
        if (u_random(200) <= player.map_objects[s].level) player.map_objects[s].num_sockets++;
        if (u_random(200) <= player.map_objects[s].level) player.map_objects[s].num_sockets++;
        if (u_random(200) <= player.map_objects[s].level) player.map_objects[s].num_sockets++;
        if (player.map_objects[s].num_sockets == 1) player.map_objects[s].cost += 25;
        if (player.map_objects[s].num_sockets == 2) player.map_objects[s].cost += 150;
        if (player.map_objects[s].num_sockets == 3) player.map_objects[s].cost += 300;
        }
      }
    if (player.map_objects[s].num_enchantments == 0) {
      enchants = 0;
      if (player.map_objects[s].otype == O_ARMR ||
          player.map_objects[s].otype == O_SHLD ||
          player.map_objects[s].otype == O_HELM ||
          player.map_objects[s].otype == O_BOOT ||
          player.map_objects[s].otype == O_RING ||
          player.map_objects[s].otype == O_NECK ||
          player.map_objects[s].otype == O_DAGR ||
          player.map_objects[s].otype == O_EDGE ||
          player.map_objects[s].otype == O_BLNT ||
          player.map_objects[s].otype == O_POLE ||
          player.map_objects[s].otype == O_BOW) {
        if (u_random(1000) <= (player.map_objects[s].level*player.map_objects[s].level)) enchants++;
        if (u_random(1000) <= (player.map_objects[s].level*player.map_objects[s].level)) enchants++;
        if (u_random(1000) <= (player.map_objects[s].level*player.map_objects[s].level)) enchants++;
        e1 = 0;
        e2 = 0;
        e3 = 0;
        if (enchants >= 1)  e1 = random_enchant(e1,e2,e3);
        if (enchants >= 2)  e2 = random_enchant(e1,e2,e3);
        if (enchants >= 3)  e3 = random_enchant(e1,e2,e3);
        player.map_objects[s].num_enchantments = enchants;
        player.map_objects[s].enchantments[0] = e1;
        player.map_objects[s].enchantments[1] = e2;
        player.map_objects[s].enchantments[2] = e3;
        }

      }
    if (player.map_objects[s].effect == E_MUTA) {
      player.map_objects[s].level = level;
      mutable(&(player.map_objects[s]));
      }
    if (player.map_objects[s].effect == E_LGND) mutable_legendary(&(player.map_objects[s]));
    if (player.map_objects[s].effect == E_SPCL && player.map_objects[s].control == 79) convert_recipe(&(player.map_objects[s]));
    }
  return s;
  }

