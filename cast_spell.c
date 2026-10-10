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

int spell_adjust(int base_damage) {
  int sp;
  double tmp;
  sp = get_spell_power();
  tmp = base_damage;
  tmp *= (1.0 + (sp / 100.0));
  sp = get_skill(SK_MAGIC);
  tmp *= (1.0 + (sp / 100.0));
  return tmp;
  }

void cast_spell(int number) {
  int spell;
  int am,mn;
  spell = castspell(number);
  if (spell == 0) {
    msg("Cast cancelled",7);
    return;
    }
  if (spell != 0 && player.cmana >= mana_cost(spells[spell].mana)) {
    player.cmana -= mana_cost(spells[spell].mana);
    add_skill(SK_MAGIC,1);
    if (spells[spell].user_hp != 0) {
      mn = rcs_trunc(spell_adjust(spells[spell].user_hp) * 0.3);
      am = u_random(spell_adjust(spells[spell].user_hp)) + 1;
      if (am < mn) am = mn;
      do_heal(am,0);
      }
    if (spells[spell].user_health != 0) {
      player.health += u_random(spells[spell].user_health) + 1;
      if (player.health > 100) player.health = 100;
      }
    switch (spells[spell].effect) {
      case 1:do_blink();
      case 2:player.effect[PE_PROT] = spell_adjust(player.level * 8);
             player.effect[PE_APROT] = spells[spell].control * player.level;
             break;
      case 3:touch(spell_adjust(spells[spell].control),spells[spell].special); break;
      case 4:missile(spell_adjust(spells[spell].control),spells[spell].special,0); break;
      case 6:do_sleep(); break;
      case 7:special(spells[spell].control,NULL); break;
      case 8:fear(0); break;
      case 9:missile(spell_adjust(spells[spell].control),spells[spell].special,1); break;
      case 10:blind(); break;
      case 11:area25(spell_adjust(spells[spell].control),spells[spell].special,player.x,player.y); break;
      case 12:drain(spell_adjust(spells[spell].control),spells[spell].special); break;
      case 13:area49(spell_adjust(spells[spell].control),spells[spell].special,player.x,player.y); break;
      case 14:super(spells[spell].control,spells[spell].special); break;
      case SP_ENCH:
           if (player.level < 12) enchant(spells[spell].control,1);
           else if (player.level < 18) enchant(spells[spell].control,2);
           else enchant(spells[spell].control,3);
           break;
      }
    }
  else {
    clear_prompt();
    msg("Not enough Mana!!",14);
    }
  show_side();
  } /* void cast_spell(int number) */

