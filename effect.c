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

char* effect(int e,int c,char* buffer) {
  switch (e) {
    case E_NONE:sprintf(buffer,"Effect: None"); break;
    case E_HEAL:sprintf(buffer,"Effect: Healing"); break;
    case E_ARMR:sprintf(buffer,"Effect: Armor"); break;
    case E_ATCK:switch (c) {
                  case 1:sprintf(buffer,"Effect: Attack-Touch"); break;
                  case 2:sprintf(buffer,"Effect: Attack-Missile"); break;
                  case 3:sprintf(buffer,"Effect: Attack-Area 9"); break;
                  case 4:sprintf(buffer,"Effect: Attack-Area 25"); break;
                  case 5:sprintf(buffer,"Effect: Attack-Missile 9"); break;
                  default:sprintf(buffer,"Effect: Attack"); break;
                  }
                break;
    case E_FEAR:sprintf(buffer,"Effect: Fear"); break;
    case E_SLEP:sprintf(buffer,"Effect: Sleep"); break;
    case E_TELE:sprintf(buffer,"Effect: Teleportation"); break;
    case E_POSN:sprintf(buffer,"Effect: Poison"); break;
    case E_BLES:sprintf(buffer,"Effect: Bless"); break;
    case E_INHT:sprintf(buffer,"Effect: Increase To-Hit"); break;
    case E_PROT:sprintf(buffer,"Effect: Protection"); break;
    case E_DAMG:sprintf(buffer,"Effect: Damage"); break;
    case E_ITEM:sprintf(buffer,"Effect: Summon Item"); break;
    case E_MANA:sprintf(buffer,"Effect: Restore Mana"); break;
    case E_SOCK:sprintf(buffer,"Effect: Socketable"); break;
    case E_ENCH:sprintf(buffer,"Effect: Enchantment"); break;
    case E_WGHT:sprintf(buffer,"Effect: Increased Carrying"); break;
    case E_TRAP:sprintf(buffer,"Effect: Trap"); break;
    case E_RSPL:sprintf(buffer,"Effect: Spell"); break;
    case E_SPEL:sprintf(buffer,"Effect: Spell"); break;
    case E_INTR:switch (c) {
                  case 1:sprintf(buffer,"Effect: Sleep Immunity"); break;
                  case 2:sprintf(buffer,"Effect: Poison Immunity"); break;
                  case 3:sprintf(buffer,"Effect: Resist Fear"); break;
                  case 4:sprintf(buffer,"Effect: Levitation"); break;
                  case 5:sprintf(buffer,"Effect: Haste/Levitation"); break;
                  case 6:sprintf(buffer,"Effect: Auto Search"); break;
                  case 7:sprintf(buffer,"Effect: Haste"); break;
                  case 8:sprintf(buffer,"Effect: HP Regen"); break;
                  case 9:sprintf(buffer,"Effect: Reflection"); break;
                  case 10:sprintf(buffer,"Effect: Resist Fire"); break;
                  case 11:sprintf(buffer,"Effect: Resist Elemental"); break;
                  case 12:sprintf(buffer,"Effect: XRay Vision"); break;
                  case 13:sprintf(buffer,"Effect: Gateway vision"); break;
                  case 14:sprintf(buffer,"Effect: Mana Reduction"); break;
                  case 15:sprintf(buffer,"Effect: Fear Immunity"); break;
                  case 16:sprintf(buffer,"Effect: Detect Traps"); break;
                  case 17:sprintf(buffer,"Effect: Identification"); break;
                  case 18:sprintf(buffer,"Effect: Detect Curse"); break;
                  case 19:sprintf(buffer,"Effect: HP Regen"); break;
                  case 20:sprintf(buffer,"Effect: Detect Food"); break;
                  case 21:sprintf(buffer,"Effect: Detect Up Stairs"); break;
                  case 22:sprintf(buffer,"Effect: Detect Down Stairs"); break;
                  case 23:sprintf(buffer,"Effect: Double Exp"); break;
                  case 24:sprintf(buffer,"Effect: Increased Exp"); break;
                  case 25:sprintf(buffer,"Effect: Read Lore"); break;
                  case 26:sprintf(buffer,"Effect: Read Language"); break;
                  case 27:sprintf(buffer,"Effect: Read All"); break;
                  case 28:sprintf(buffer,"Effect: Activate Gateway"); break;
                  case 29:sprintf(buffer,"Effect: See Gateway"); break;
                  case 30:sprintf(buffer,"Effect: Transportation"); break;
                  case 31:sprintf(buffer,"Effect: Compass"); break;
                  case 32:sprintf(buffer,"Effect: No Hunger"); break;
                  case 33:sprintf(buffer,"Effect: Water Travel"); break;
                  case 34:sprintf(buffer,"Effect: Flight"); break;
                  case 35:sprintf(buffer,"Effect: Negate Force"); break;
                  case 36:sprintf(buffer,"Effect: Resist Cold"); break;
                  case 37:sprintf(buffer,"Effect: Resist Electric"); break;
                  case 38:sprintf(buffer,"Effect: Resist Dark"); break;
                  case 39:sprintf(buffer,"Effect: Resist Psionic"); break;
                  case 40:sprintf(buffer,"Effect: Resist Sleep"); break;
                  case 41:sprintf(buffer,"Effect: Resist Poison"); break;
                  }
                break;
    case E_SPCL:switch (c) {
                  case 1: sprintf(buffer,"Effect: Clairaudience"); break;
                  case 2: sprintf(buffer,"Effect: Clairvoyance"); break;
                  case 3: sprintf(buffer,"Effect: Haste"); break;
                  case 4: sprintf(buffer,"Effect: Giant Strength"); break;
                  case 5: sprintf(buffer,"Effect: Ethereal"); break;
                  case 6: sprintf(buffer,"Effect: Light"); break;
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
                  case 69: sprintf(buffer,"Effect: Enchant Armor"); break;
                  case 70: sprintf(buffer,"Effect: Corrode Weapon"); break;
                  case 71: sprintf(buffer,"Effect: Corrode Armor"); break;
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
                  case 90: sprintf(buffer,"Effect: Pacify"); break;
                  case 91: sprintf(buffer,"Effect: Light"); break;
                  }
    }
  return buffer;
  }



