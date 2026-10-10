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

void transcribe() {
  int i;
  OBJECT_REC* item;
  item = NULL;
  saveScreen();
  item = inventory(item);
  restoreScreen();
  if (item == NULL) return;
  if (item->otype == O_SCRL && item->effect == E_SPEL) {
    if (spells[item->control].level > (player.level-classes[player.class-1].becomes_caster)+1) {
      msg("Too advanced",12);
      return;
      }
    if (spells[item->control].mana > player.cmana) {
      msg("Not enough mana",12);
      return;
      }
    if (spells[item->control].allign == classes[player.class-1].spell_group) {
      i = 1;
      while (spellbook[i] != 0) i++;
      spellbook[i] = item->control;
      item->otype = O_NONE;
      msg("Spell learned",7);
      player.cmana -= spells[item->control].mana;
      show_side();
      } else {
      i = get_skill(SK_MAGIC) + get_skill(SK_LORE);
      i /= 20;
      if (u_random(100) <= i) {
        i = 1;
        while (spellbook[i] != 0) i++;
        spellbook[i] = item->control;
        item->otype = O_NONE;
        msg("Spell learned",7);
        player.cmana -= spells[item->control].mana;
        show_side();
        } else {
        msg("Failed",12);
        item->otype = O_NONE;
        }
      }
    }
  else msg("Invalid Item",12);
  }

