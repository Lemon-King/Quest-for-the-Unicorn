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

/*
  1 - Fighter
  2 - Paladin
  3 - Ranger
  4 - Cleric
  5 - Druid
  6 - Mage
  7 - Monk
  8 - Assassin
  9 - Hierophant
 10 - Cavalier
 11 - Noble
 12 - Enchanter
*/

void mutable_legendary(OBJECT_REC* item) {
  if (item == NULL) return;
  item->num_enchantments = 3;
  item->num_sockets = 3;
  item->sockets[0] = 0;
  item->sockets[1] = 0;
  item->sockets[2] = 0;
  if (item->otype == O_ARMR) {
    switch (player.class) {
      case 1: item->enchantments[0] = S_STR + 5;
              item->enchantments[1] = S_ATP + 10;
              item->enchantments[2] = S_DEF + 16;
              break;
      case 2: item->enchantments[0] = S_STR + 5;
              item->enchantments[1] = S_ATP + 10;
              item->enchantments[2] = S_INT + 5;
              break;
      case 3: item->enchantments[0] = S_DEX + 5;
              item->enchantments[1] = S_HIT + 10;
              item->enchantments[2] = S_CRT + 10;
              break;
      case 4: item->enchantments[0] = S_INT + 5;
              item->enchantments[1] = S_SPP + 10;
              item->enchantments[2] = S_MAN + 50;
              break;
      case 5: item->enchantments[0] = S_INT + 5;
              item->enchantments[1] = S_DEX + 5;
              item->enchantments[2] = S_MAN + 50;
              break;
      case 6: item->enchantments[0] = S_INT + 5;
              item->enchantments[1] = S_SPP + 10;
              item->enchantments[2] = S_MAN + 50;
              break;
      case 7: item->enchantments[0] = S_DEX + 5;
              item->enchantments[1] = S_HIT + 10;
              item->enchantments[2] = S_ATP + 10;
              break;
      case 8: item->enchantments[0] = S_DEX + 5;
              item->enchantments[1] = S_CRT + 10;
              item->enchantments[2] = S_ATP + 10;
              break;
      case 9: item->enchantments[0] = S_INT + 5;
              item->enchantments[1] = S_DEX + 5;
              item->enchantments[2] = S_SPP + 10;
              break;
      case 10: item->enchantments[0] = S_STR + 5;
               item->enchantments[1] = S_ATP + 10;
               item->enchantments[2] = S_DEF + 16;
               break;
      case 11: item->enchantments[0] = S_STR + 5;
               item->enchantments[1] = S_ATP + 10;
               item->enchantments[2] = S_HIT + 10;
               break;
      case 12: item->enchantments[0] = S_DEX + 5;
               item->enchantments[1] = S_ATP + 10;
               item->enchantments[2] = S_CRT + 10;
               break;
      }
    }
  if (item->otype == O_ROBE) {
    switch (player.class) {
      case 1: item->enchantments[0] = S_STR + 3;
              item->enchantments[1] = S_ATP + 5;
              item->enchantments[2] = S_DEF + 8;
              break;
      case 2: item->enchantments[0] = S_STR + 3;
              item->enchantments[1] = S_ATP + 5;
              item->enchantments[2] = S_INT + 3;
              break;
      case 3: item->enchantments[0] = S_DEX + 3;
              item->enchantments[1] = S_HIT + 5;
              item->enchantments[2] = S_CRT + 5;
              break;
      case 4: item->enchantments[0] = S_INT + 3;
              item->enchantments[1] = S_SPP + 5;
              item->enchantments[2] = S_MAN + 25;
              break;
      case 5: item->enchantments[0] = S_INT + 3;
              item->enchantments[1] = S_DEX + 3;
              item->enchantments[2] = S_MAN + 25;
              break;
      case 6: item->enchantments[0] = S_INT + 3;
              item->enchantments[1] = S_SPP + 5;
              item->enchantments[2] = S_MAN + 25;
              break;
      case 7: item->enchantments[0] = S_DEX + 3;
              item->enchantments[1] = S_HIT + 5;
              item->enchantments[2] = S_ATP + 5;
              break;
      case 8: item->enchantments[0] = S_DEX + 3;
              item->enchantments[1] = S_CRT + 5;
              item->enchantments[2] = S_ATP + 5;
              break;
      case 9: item->enchantments[0] = S_INT + 3;
              item->enchantments[1] = S_DEX + 3;
              item->enchantments[2] = S_SPP + 5;
              break;
      case 10: item->enchantments[0] = S_STR + 3;
               item->enchantments[1] = S_ATP + 5;
               item->enchantments[2] = S_DEF + 8;
               break;
      case 11: item->enchantments[0] = S_STR + 3;
               item->enchantments[1] = S_ATP + 5;
               item->enchantments[2] = S_HIT + 5;
               break;
      case 12: item->enchantments[0] = S_DEX + 3;
               item->enchantments[1] = S_ATP + 5;
               item->enchantments[2] = S_CRT + 5;
               break;
      }
    }
  if (item->otype == O_HELM) {
    switch (player.class) {
      case 1: item->enchantments[0] = S_STR + 3;
              item->enchantments[1] = S_ATP + 5;
              item->enchantments[2] = S_DEF + 8;
              break;
      case 2: item->enchantments[0] = S_STR + 3;
              item->enchantments[1] = S_ATP + 5;
              item->enchantments[2] = S_INT + 3;
              break;
      case 3: item->enchantments[0] = S_DEX + 3;
              item->enchantments[1] = S_HIT + 5;
              item->enchantments[2] = S_CRT + 5;
              break;
      case 4: item->enchantments[0] = S_INT + 3;
              item->enchantments[1] = S_SPP + 5;
              item->enchantments[2] = S_MAN + 25;
              break;
      case 5: item->enchantments[0] = S_INT + 3;
              item->enchantments[1] = S_DEX + 3;
              item->enchantments[2] = S_MAN + 25;
              break;
      case 6: item->enchantments[0] = S_INT + 3;
              item->enchantments[1] = S_SPP + 5;
              item->enchantments[2] = S_MAN + 25;
              break;
      case 7: item->enchantments[0] = S_DEX + 3;
              item->enchantments[1] = S_HIT + 5;
              item->enchantments[2] = S_ATP + 5;
              break;
      case 8: item->enchantments[0] = S_DEX + 3;
              item->enchantments[1] = S_CRT + 5;
              item->enchantments[2] = S_ATP + 5;
              break;
      case 9: item->enchantments[0] = S_INT + 3;
              item->enchantments[1] = S_DEX + 3;
              item->enchantments[2] = S_SPP + 5;
              break;
      case 10: item->enchantments[0] = S_STR + 3;
               item->enchantments[1] = S_ATP + 5;
               item->enchantments[2] = S_DEF + 8;
               break;
      case 11: item->enchantments[0] = S_STR + 3;
               item->enchantments[1] = S_ATP + 5;
               item->enchantments[2] = S_HIT + 5;
               break;
      case 12: item->enchantments[0] = S_DEX + 3;
               item->enchantments[1] = S_ATP + 5;
               item->enchantments[2] = S_CRT + 5;
               break;
      }
    }
  if (item->otype == O_BOOT) {
    switch (player.class) {
      case 1: item->enchantments[0] = S_STR + 3;
              item->enchantments[1] = S_ATP + 5;
              item->enchantments[2] = S_DEF + 8;
              break;
      case 2: item->enchantments[0] = S_STR + 3;
              item->enchantments[1] = S_ATP + 5;
              item->enchantments[2] = S_INT + 3;
              break;
      case 3: item->enchantments[0] = S_DEX + 3;
              item->enchantments[1] = S_HIT + 5;
              item->enchantments[2] = S_CRT + 5;
              break;
      case 4: item->enchantments[0] = S_INT + 3;
              item->enchantments[1] = S_SPP + 5;
              item->enchantments[2] = S_MAN + 25;
              break;
      case 5: item->enchantments[0] = S_INT + 3;
              item->enchantments[1] = S_DEX + 3;
              item->enchantments[2] = S_MAN + 25;
              break;
      case 6: item->enchantments[0] = S_INT + 3;
              item->enchantments[1] = S_SPP + 5;
              item->enchantments[2] = S_MAN + 25;
              break;
      case 7: item->enchantments[0] = S_DEX + 3;
              item->enchantments[1] = S_HIT + 5;
              item->enchantments[2] = S_ATP + 5;
              break;
      case 8: item->enchantments[0] = S_DEX + 3;
              item->enchantments[1] = S_CRT + 5;
              item->enchantments[2] = S_ATP + 5;
              break;
      case 9: item->enchantments[0] = S_INT + 3;
              item->enchantments[1] = S_DEX + 3;
              item->enchantments[2] = S_SPP + 5;
              break;
      case 10: item->enchantments[0] = S_STR + 3;
               item->enchantments[1] = S_ATP + 5;
               item->enchantments[2] = S_DEF + 8;
               break;
      case 11: item->enchantments[0] = S_STR + 3;
               item->enchantments[1] = S_ATP + 5;
               item->enchantments[2] = S_HIT + 5;
               break;
      case 12: item->enchantments[0] = S_DEX + 3;
               item->enchantments[1] = S_ATP + 5;
               item->enchantments[2] = S_CRT + 5;
               break;
      }
    }
  if (item->otype == O_RING) {
    item->effect = E_INTR;
    item->control = A_RELE;
    switch (player.class) {
      case 1: item->enchantments[0] = S_STR + 3;
              item->enchantments[1] = S_ATP + 5;
              item->enchantments[2] = S_DEF + 8;
              break;
      case 2: item->enchantments[0] = S_STR + 3;
              item->enchantments[1] = S_ATP + 5;
              item->enchantments[2] = S_INT + 3;
              break;
      case 3: item->enchantments[0] = S_DEX + 3;
              item->enchantments[1] = S_HIT + 5;
              item->enchantments[2] = S_CRT + 5;
              break;
      case 4: item->enchantments[0] = S_INT + 3;
              item->enchantments[1] = S_SPP + 5;
              item->enchantments[2] = S_MAN + 25;
              break;
      case 5: item->enchantments[0] = S_INT + 3;
              item->enchantments[1] = S_DEX + 3;
              item->enchantments[2] = S_MAN + 25;
              break;
      case 6: item->enchantments[0] = S_INT + 3;
              item->enchantments[1] = S_SPP + 5;
              item->enchantments[2] = S_MAN + 25;
              break;
      case 7: item->enchantments[0] = S_DEX + 3;
              item->enchantments[1] = S_HIT + 5;
              item->enchantments[2] = S_ATP + 5;
              break;
      case 8: item->enchantments[0] = S_DEX + 3;
              item->enchantments[1] = S_CRT + 5;
              item->enchantments[2] = S_ATP + 5;
              break;
      case 9: item->enchantments[0] = S_INT + 3;
              item->enchantments[1] = S_DEX + 3;
              item->enchantments[2] = S_SPP + 5;
              break;
      case 10: item->enchantments[0] = S_STR + 3;
               item->enchantments[1] = S_ATP + 5;
               item->enchantments[2] = S_DEF + 8;
               break;
      case 11: item->enchantments[0] = S_STR + 3;
               item->enchantments[1] = S_ATP + 5;
               item->enchantments[2] = S_HIT + 5;
               break;
      case 12: item->enchantments[0] = S_DEX + 3;
               item->enchantments[1] = S_ATP + 5;
               item->enchantments[2] = S_CRT + 5;
               break;
      }
    }
  if (item->otype == O_EDGE) {
    item->enchantments[0] = S_HIT + 10;
    item->enchantments[1] = S_ATP + 10;
    item->enchantments[2] = S_CRT + 10;
    switch (player.class) {
      case 1: item->otype = O_EDGE;
              item->skill = SK_1HSWORD;
              strcpy(item->name,"Ayres'_Mythical_Sword");
              break;
      case 2: item->otype = O_BLNT;
              strcpy(item->name,"Ayres'_Mythical_Hammer");
              item->skill = SK_MACE;
              break;
      case 3: item->otype = O_BOW;
              strcpy(item->name,"Ayres'_Mythical_Bow");
              item->skill = SK_BOW;
              break;
      case 4: item->otype = O_BLNT;
              strcpy(item->name,"Ayres'_Mythical_Mace");
              item->skill = SK_MACE;
              item->enchantments[1] = S_SPP + 10;
              break;
      case 5: item->otype = O_BLNT;
              strcpy(item->name,"Ayres'_Mythical_Branch");
              item->skill = SK_FLAIL;
              item->enchantments[1] = S_SPP + 10;
              break;
      case 6: item->otype = O_WAND;
              strcpy(item->name,"Ayres'_Mythical_Wand");
              item->skill = SK_MAGIC;
              item->enchantments[1] = S_SPP + 10;
              break;
      case 7: item->otype = O_DAGR;
              strcpy(item->name,"Ayres'_Mythical_Dirk");
              item->skill = SK_DAGGER;
              break;
      case 8: item->otype = O_DAGR;
              strcpy(item->name,"Ayres'_Mythical_Dagger");
              item->skill = SK_DAGGER;
              break;
      case 9: item->otype = O_BLNT;
              strcpy(item->name,"Ayres'_Mythical_Flail");
              item->skill = SK_FLAIL;
              item->enchantments[1] = S_SPP + 10;
              break;
      case 10: item->otype = O_POLE;
              strcpy(item->name,"Ayres'_Mythical_War_Axe");
              item->skill = SK_AXE;
              break;
      case 11: item->otype = O_EDGE;
              strcpy(item->name,"Ayres'_Mythical_Rapier");
              item->skill = SK_1HSWORD;
              break;
      case 12: item->otype = O_EDGE;
              strcpy(item->name,"Ayres'_Mythical_Scimitar");
              item->skill = SK_1HSWORD;
              break;
      }
    }
  }

