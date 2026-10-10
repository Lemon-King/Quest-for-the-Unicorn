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

void show_spell(int num,int ox,int oy,int line) {
  char buffer[128];
    gotoxy(ox+2,line++);
    if (spells[num].user_hp != 0) {
      txt_write("Effect: Healing");
      sprintf(buffer,"  Amount : %d",spells[num].user_hp);
      gotoxy(ox+2,line++); txt_write(buffer);
      gotoxy(ox+2,line++);
      }
    if (spells[num].user_health != 0) {
      txt_write("Effect: Food");
      sprintf(buffer,"  Amount : %d",spells[num].user_health);
      gotoxy(ox+2,line++); txt_write(buffer);
      gotoxy(ox+2,line++);
      }
    switch (spells[num].effect) {
      case 1:                                         /* Blink */
              txt_write("Effect: Blink");
              break;
      case 2:                                         /* Protection */
              txt_write("Effect: Protection");
              sprintf(buffer,"  Defense : %d",spells[num].control);
              gotoxy(ox+2,line++); txt_write(buffer);
              break;
      case 3:                                         /* Touch */
              txt_write("Effect: Touch Damage");
              sprintf(buffer,"  Damage : %d",spells[num].control);
              gotoxy(ox+2,line++); txt_write(buffer);
              break;
      case 4:                                         /* Missile */
              txt_write("Effect: Missile Damage");
              sprintf(buffer,"  Damage : %d",spells[num].control);
              gotoxy(ox+2,line++); txt_write(buffer);
              break;
      case 5:                                         /* Teleport */
              txt_write("Effect: Teleport");
              break;
      case 6:                                         /* Sleep */
              txt_write("Effect: Sleep");
              break;
      case 7:                                         /* Special */
              switch (spells[num].control) {
                case 1: sprintf(buffer,"Effect: Clairaudience"); break;
                case 2: sprintf(buffer,"Effect: Clairvoyance"); break;
                case 3: sprintf(buffer,"Effect: Haste"); break;
                case 4: sprintf(buffer,"Effect: Giant Strength"); break;
                case 5: sprintf(buffer,"Effect: Ethereal"); break;
                case 6: sprintf(buffer,"Effect: Light"); break;
                case 7: sprintf(buffer,"Effect: Locate All"); break;
                case 8: sprintf(buffer,"Effect: Object Location"); break;
                case 9: sprintf(buffer,"Effect: Monster Location"); break;
                case 10: sprintf(buffer,"Effect: Lore"); break;
                case 11: sprintf(buffer,"Effect: Information"); break;
                case 12: sprintf(buffer,"Effect: Identification"); break;
                case 13: sprintf(buffer,"Effect: Protection"); break;
                case 14: sprintf(buffer,"Effect: Mapping"); break;
                case 15: sprintf(buffer,"Effect: Recall"); break;
                case 16: sprintf(buffer,"Effect: Strength"); break;
                case 17: sprintf(buffer,"Effect: Dexterity"); break;
                case 18: sprintf(buffer,"Effect: Intelligence"); break;
                case 19: sprintf(buffer,"Effect: Mana Charge"); break;
                case 20: sprintf(buffer,"Effect: Information"); break;
                case 21: sprintf(buffer,"Effect: Read Language"); break;
                case 22: sprintf(buffer,"Effect: Detect Magic"); break;
                case 23: sprintf(buffer,"Effect: Identify Monster"); break;
                case 24: sprintf(buffer,"Effect: Slow Poison"); break;
                case 25: sprintf(buffer,"Effect: Cure Poison"); break;
                case 26: sprintf(buffer,"Effect: Illumination"); break;
                case 27: sprintf(buffer,"Effect: Summoning"); break;
                case 28: sprintf(buffer,"Effect: Read Lore"); break;
                case 29: sprintf(buffer,"Effect: Dispell"); break;
                case 30: sprintf(buffer,"Effect: Forcefield"); break;
                case 31: sprintf(buffer,"Effect: Increase"); break;
                case 32: sprintf(buffer,"Effect: Summoning"); break;
                case 33: sprintf(buffer,"Effect: Summoning"); break;
                case 34: sprintf(buffer,"Effect: Phase Door"); break;
                case 35: sprintf(buffer,"Effect: Permanancy"); break;
                case 36: sprintf(buffer,"Effect: Remove Fear"); break;
                case 37: sprintf(buffer,"Effect: Find Traps"); break;
                case 38: sprintf(buffer,"Effect: Fire Resistance"); break;
                case 39: sprintf(buffer,"Effect: Summon Shadow"); break;
                case 40: sprintf(buffer,"Effect: Summon Food"); break;
                case 41: sprintf(buffer,"Effect: Summon Snakes"); break;
                case 42: sprintf(buffer,"Effect: Summon"); break;
                case 43: sprintf(buffer,"Effect: Trap Location"); break;
                case 44: sprintf(buffer,"Effect: Air Elemental"); break;
                case 45: sprintf(buffer,"Effect: Water Elemental"); break;
                case 51: sprintf(buffer,"Effect: Lore"); break;
                case 52: sprintf(buffer,"Effect: Enlightenment"); break;
                case 53: sprintf(buffer,"Effect: Knowledge"); break;
                case 54: sprintf(buffer,"Effect: Restore Mana"); break;
                case 55: sprintf(buffer,"Effect: Mana Reserve"); break;
                case 56: sprintf(buffer,"Effect: Experience Gain"); break;
                case 57: sprintf(buffer,"Effect: Experience Gain"); break;
                case 58: sprintf(buffer,"Effect: Experience Gain"); break;
                case 59: sprintf(buffer,"Effect: Experience Gain"); break;
                case 60: sprintf(buffer,"Effect: Sleep"); break;
                case 61: sprintf(buffer,"Effect: Blindness"); break;
                case 62: sprintf(buffer,"Effect: Blindness"); break;
                case 63: sprintf(buffer,"Effect: Confusion"); break;
                case 64: sprintf(buffer,"Effect: Cure Confusion"); break;
                case 65: sprintf(buffer,"Effect: Cure Fear"); break;
                case 66: sprintf(buffer,"Effect: Cure Blindness"); break;
                case 67: sprintf(buffer,"Effect: Cureall"); break;
                case 68: sprintf(buffer,"Effect: Enchant Weapon"); break;
                case 69: sprintf(buffer,"Effect: Enchant Armour"); break;
                case 70: sprintf(buffer,"Effect: Corrode Weapon"); break;
                case 71: sprintf(buffer,"Effect: Corrode Armour"); break;
                case 72: sprintf(buffer,"Effect: Bless"); break;
                case 73: sprintf(buffer,"Effect: Recharge"); break;
                case 74: sprintf(buffer,"Effect: Bless"); break;
                case 75: sprintf(buffer,"Effect: Summon Torch"); break;
                case 76: sprintf(buffer,"Effect: Levitation"); break;
                case 77: sprintf(buffer,"Effect: Opposition"); break;
                case 78: sprintf(buffer,"Effect: Intoxicating"); break;
                case 79: sprintf(buffer,"Effect: Recipe"); break;
                case 80: sprintf(buffer,"Effect: Create Socket"); break;
                case 81: sprintf(buffer,"Effect: Remove Enchants"); break;
                case 82: sprintf(buffer,"Effect: De-Socket"); break;
                case 86: sprintf(buffer,"Effect: Charm"); break;
                case 87: sprintf(buffer,"Effect: Remove Root"); break;
                case 88: sprintf(buffer,"Effect: Bandage"); break;
                case 89: sprintf(buffer,"Effect: Polymorph"); break;
                }
              txt_write(buffer);
              break;
      case 8:                                         /* Fear */
              txt_write("Effect: Fear");
              break;
      case 9:                                         /* Missile 9 */
              txt_write("Effect: Missile 9 Damage");
              sprintf(buffer,"  Damage : %d",spells[num].control);
              gotoxy(ox+2,line++); txt_write(buffer);
              break;
      case 10:                                         /* Blind */
              txt_write("Effect: Blind");
              break;
      case 11:                                         /* Area 25 */
              txt_write("Effect: Area 25 Damage");
              sprintf(buffer,"  Damage : %d",spells[num].control);
              gotoxy(ox+2,line++); txt_write(buffer);
              break;
      case 12:                                         /* Drain */
              txt_write("Effect: Drain Damage");
              sprintf(buffer,"  Damage : %d",spells[num].control);
              gotoxy(ox+2,line++); txt_write(buffer);
              break;
      case 13:                                         /* Area 49 */
              txt_write("Effect: Area 49 Damage");
              sprintf(buffer,"  Damage : %d",spells[num].control);
              gotoxy(ox+2,line++); txt_write(buffer);
              break;
      case 14:                                         /* Very Large Area */
              txt_write("Effect: Large Area Damage");
              sprintf(buffer,"  Damage : %d",spells[num].control);
              gotoxy(ox+2,line++); txt_write(buffer);
              break;
      case 15:                                         /* enchantment */
              txt_write("Effect: Enchantment");
              gotoxy(ox+2,line++); txt_write("  ");
              get_attribute_name(buffer,spells[num].control);
              txt_write(buffer);
              break;
      }

    line++;
    if (spells[num].special & MS_FIRE_ATK) {
      textcolor(12); gotoxy(ox+2,line++); txt_write("Fire");
      }
    if (spells[num].special & MS_COLD_ATK) {
      textcolor(9); gotoxy(ox+2,line++); txt_write("Cold");
      }
    if (spells[num].special & MS_ARCN_ATK) {
      textcolor(11); gotoxy(ox+2,line++); txt_write("Arcane");
      }
    if (spells[num].special & MS_ELEC_ATK) {
      textcolor(14); gotoxy(ox+2,line++); txt_write("Electric");
      }
  }
