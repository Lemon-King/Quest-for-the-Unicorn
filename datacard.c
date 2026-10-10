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

void get_attribute_name(char* buffer,int ench) {
  char plus[255];
  strcpy(buffer,"");
  switch (ench / 100) {
    case 1: strcat(buffer,"Strength +"); break;
    case 2: strcat(buffer,"Dexterity +"); break;
    case 3: strcat(buffer,"Intelligence +"); break;
    case 4: strcat(buffer,"Wisdom +"); break;
    case 5: strcat(buffer,"Constitution +"); break;
    case 6: strcat(buffer,"Charisma +"); break;
    case 7: strcat(buffer,"Mana +"); break;
    case 8: strcat(buffer,"Health +"); break;
    case 9: strcat(buffer,"Attack Power +"); break;
    case 10: strcat(buffer,"Defense +"); break;
    case 11: strcat(buffer,"To Hit +"); break;
    case 12: strcat(buffer,"Health Regen +"); break;
    case 13: strcat(buffer,"Mana Regen +"); break;
    case 14: strcat(buffer,"All Stats +"); break;
    case 15: strcat(buffer,"Experience +"); break;
    case 16: strcat(buffer,"Magic Find +"); break;
    case 17: strcat(buffer,"Health/Mana +"); break;
    case 18: strcat(buffer,"Magic Resist +"); break;
    case 19: strcat(buffer,"Monster Level +"); break;
    case 20: strcat(buffer,"Crit +"); break;
    case 21: strcat(buffer,"Dodge +"); break;
    case 22: strcat(buffer,"Fire +"); break;
    case 23: strcat(buffer,"Cold +"); break;
    case 24: strcat(buffer,"Electric +"); break;
    case 25: strcat(buffer,"Arcane +"); break;
    case 26: strcat(buffer,"Spell Power +"); break;
    case 27: strcat(buffer,"Resist Elements"); break;
    case 28: strcat(buffer,"Resist Poison"); break;
    case 29: strcat(buffer,"Immunity Poison"); break;
    case 30: strcat(buffer,"fire/cold/elec/arcn+"); break;
    case 31: strcat(buffer,"Skill: Bow+"); break;
    case 32: strcat(buffer,"Skill: 1h Sword+"); break;
    case 33: strcat(buffer,"Skill: Spear+"); break;
    case 34: strcat(buffer,"Skill: Mace+"); break;
    case 35: strcat(buffer,"Skill: Scouting+"); break;
    case 36: strcat(buffer,"Skill: Language+"); break;
    case 37: strcat(buffer,"Skill: Lore+"); break;
    case 38: strcat(buffer,"Skill: Magic+"); break;
    case 39: strcat(buffer,"Skill: Healing+"); break;
    case 40: strcat(buffer,"Skill: Medicine+"); break;
    case 41: strcat(buffer,"Skill: Riding+"); break;
    case 42: strcat(buffer,"Skill: Boating+"); break;
    case 43: strcat(buffer,"Skill: Oracle+"); break;
    case 44: strcat(buffer,"Skill: Charm+"); break;
    case 45: strcat(buffer,"Skill: Survival+"); break;
    case 46: strcat(buffer,"Skill: Combat+"); break;
    case 47: strcat(buffer,"Skill: Dagger+"); break;
    case 48: strcat(buffer,"Skill: 2h Swords+"); break;
    case 49: strcat(buffer,"Skill: Axe+"); break;
    case 50: strcat(buffer,"Skill: Flail+"); break;
    case 51: strcat(buffer,"Skill: Crossbow+"); break;
    case 52: strcat(buffer,"Skill: Trident+"); break;
    case 53: strcat(buffer,"Skill: Poleaxe+"); break;
    case 54: strcat(buffer,"Skill: Thrown+"); break;
    }
  strcpy(plus,"");
  if (buffer[strlen(buffer)-1] == '+') sprintf(plus,"%d",ench % 100);
  strcat(buffer,plus);
  }

void data_card(OBJECT_REC* item) {
  int i;
  char key;
  char buffer[128];
  char buffer2[128];
  int line;
  int control;
  int amount;
  double price;
  if (item->otype == O_NONE) return;
  base_name(buffer,item);
  textcolor(7); gotoxy(20,5);   txt_write("+--------------------------------+");
  textcolor(7); gotoxy(20,18);  txt_write("+--------------------------------+");
  for (i=6; i<18; i++) {
    textcolor(7); gotoxy(20,i); txt_write("|                                |");
    }
  itemColor(item);
  gotoxy(22,6); txt_write(buffer);
  gotoxy(22,7);
  textcolor(7);
  switch (item->otype) {
    case O_EDGE: txt_write("Edge Weapon"); break;
    case O_BLNT: txt_write("Blunt Weapon"); break;
    case O_ARMR: txt_write("Armor"); break;
    case O_POTN: txt_write("Potion"); break;
    case O_RING: txt_write("Ring"); break;
    case O_STFF: txt_write("Staff"); break;
    case O_WAND: txt_write("Wand"); break;
    case O_FOOD: txt_write("Food"); break;
    case O_MISC: txt_write("Miscellaneous"); break;
    case O_SCRL: txt_write("Scroll"); break;
    case O_NECK: txt_write("Necklace"); break;
    case O_ROBE: txt_write("Robe"); break;
    case O_BOOT: txt_write("Boots"); break;
    case O_HELM: txt_write("Helm"); break;
    case O_SHLD: txt_write("Shield"); break;
    case O_BOOK: txt_write("Book"); break;
    case O_POLE: txt_write("Polearm"); break;
    case O_BOW : txt_write("Missile"); break;
    case O_JEWL: txt_write("Jewel"); break;
    case O_PROJ: txt_write("Energy"); break;
    case O_DAGR: txt_write("Dagger"); break;
    case O_CRFT: txt_write("Craft Item"); break;
    case O_ALCH: txt_write("Alcohol"); break;
    case O_CONS: txt_write("Consumable"); break;
    case O_TRAP: txt_write("Trap"); break;
    case O_THRN: txt_write("Thrown"); break;
    case O_CARD: txt_write("Card"); break;
    case O_GACH: txt_write("Gacha"); break;
    }
  if (item->level < 0) {
    if (item->effect == E_LGCY) {
      strcpy(buffer,"Legacy");
      gotoxy(44,7); txt_write(buffer);
      }
    else {
      if (abs(item->rarity) > 2500) { gotoxy(46,7);                             txt_write("Common"); }
      if (abs(item->rarity) > 500 && abs(item->rarity) <= 2500) { gotoxy(44,7); txt_write("Uncommon"); }
      if (abs(item->rarity) > 100 && abs(item->rarity) <= 500) { gotoxy(48,7);  txt_write("Rare"); }
      if (abs(item->rarity) > 5 && abs(item->rarity) <= 100) { gotoxy(43,7);   txt_write("Very Rare"); }
      if (abs(item->rarity) > 0 && abs(item->rarity) <= 5) { gotoxy(42,7);     txt_write("Ultra Rare"); }
      }
    }
  else {
    gotoxy(45,7); txt_write("Unknown");
    }

  if (item->level < 0) {
    line = 8;
    strcpy(buffer,"");
    switch (item->otype) {
      case O_EDGE:
      case O_POLE:
      case O_DAGR:
      case O_BOW:
      case O_BLNT:
      case O_WAND:
      case O_PROJ: if (item->effect != E_ATCK) sprintf(buffer,"Damage: %d\n",item->damage); break;
      case O_ARMR:
      case O_SHLD:
      case O_HELM:
      case O_ROBE:
      case O_BOOT: if (item->effect != E_PROT) sprintf(buffer,"Protection: %d\n",item->damage);
                   break;
      }
    if (strlen(buffer) > 0) {
      gotoxy(22,line++);
      txt_write(buffer);
      }
    strcpy(buffer,"");
    switch (item->effect) {
      case E_SPEL:sprintf(buffer,"%s Lvl: %d Mana: %d",classes[spells[item->control].allign-1].name,
                                                       spells[item->control].level,
                                                       spells[item->control].mana);
                  gotoxy(22,line++);
                  txt_write(buffer);
                  show_spell(item->control,20,7,line+1);
                  textcolor(7);
                  strcpy(buffer,"");
                  break;
      case E_ATCK:switch (item->control) {
                    case 1: sprintf(buffer,"Damage: %d\n",item->damage); break;
                    case 2: sprintf(buffer,"Missile: %d\n",item->damage); break;
                    case 3: sprintf(buffer,"AOE Damage: %d\n",item->damage); break;
                    case 4: sprintf(buffer,"Large AOE: %d\n",item->damage); break;
                    case 5: sprintf(buffer,"Missile AOE: %d\n",item->damage); break;
                    }
                  break;
      case E_PROT:  sprintf(buffer,"Protection: %d\n", item->control); break;
      case E_SPCL:control = item->control;
                  if (control >= 1000) control /= 1000;
                  switch (control) {
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
                    case 61: sprintf(buffer,"Effect: Fear"); break;
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
                    case 92: sprintf(buffer,"Effect: Cold Resistance"); break;
                    case 93: sprintf(buffer,"Effect: Electirc Resistance"); break;
                    case 94: sprintf(buffer,"Effect: Arcane Resistance"); break;
                    case 95: sprintf(buffer,"Effect: Increase HP"); break;
                    case 99: sprintf(buffer,"Effect: Cube of Force"); break;
                    case 100: sprintf(buffer,"Effect: Unknown"); break;
                    case 101: sprintf(buffer,"Effect: Recall"); break;
                    case 102: sprintf(buffer,"Effect: Digging"); break;
                    }
                  break;
      case E_SOCK:control = (item->control / 100) * 100;
                  amount = item->control % 100;
                  switch (control) {
                    case S_STR: sprintf(buffer,"Socket: Strength+%d",amount); break;
                    case S_DEX: sprintf(buffer,"Socket: Dexterity+%d",amount); break;
                    case S_INT: sprintf(buffer,"Socket: Intelligence+%d",amount); break;
                    case S_WIS: sprintf(buffer,"Socket: Wisdom+%d",amount); break;
                    case S_CON: sprintf(buffer,"Socket: Constitution+%d",amount); break;
                    case S_CHR: sprintf(buffer,"Socket: Charisma+%d",amount); break;
                    case S_ATP: sprintf(buffer,"Socket: Attack Power+%d",amount); break;
                    case S_MAN: sprintf(buffer,"Socket: Mana+%d",amount); break;
                    case S_HPS: sprintf(buffer,"Socket: Hit Points+%d",amount); break;
                    case S_DEF: sprintf(buffer,"Socket: Defense+%d",amount); break;
                    case S_HIT: sprintf(buffer,"Socket: To Hit+%d",amount); break;
                    case S_HPR: sprintf(buffer,"Socket: HP Regen+%d",amount); break;
                    case S_MNR: sprintf(buffer,"Socket: Mana Regen+%d",amount); break;
                    case S_ALL: sprintf(buffer,"Socket: Base Stats+%d",amount); break;
                    case S_EXP: sprintf(buffer,"Socket: Experience+%d%%",amount); break;
                    case S_MGF: sprintf(buffer,"Socket: Magic Find+%d",amount); break;
                    case S_MAG: sprintf(buffer,"Socket: HP/Mana+%d",amount); break;
                    case S_MGR: sprintf(buffer,"Socket: Magic Resistance+%d",amount); break;
                    case S_MLV: sprintf(buffer,"Socket: Monster Level+%d",amount); break;
                    case S_CRT: sprintf(buffer,"Socket: Crit+%d",amount); break;
                    case S_DDG: sprintf(buffer,"Socket: Dodge+%d",amount); break;
                    case S_FIR: sprintf(buffer,"Socket: Elemental Fire+%d",amount); break;
                    case S_CLD: sprintf(buffer,"Socket: Elemental Cold+%d",amount); break;
                    case S_ELC: sprintf(buffer,"Socket: Elemental Electric+%d",amount); break;
                    case S_ARC: sprintf(buffer,"Socket: Elemental Arcane+%d",amount); break;
                    case S_SPP: sprintf(buffer,"Socket: Spell Power+%d",amount); break;
                    case S_ELE: sprintf(buffer,"Socket: Resist Elemental+%d",amount); break;
                    case S_RPS: sprintf(buffer,"Socket: Resist Poison+%d",amount); break;
                    case S_IPS: sprintf(buffer,"Socket: Immune Poison+%d",amount); break;
                    case S_FCE: sprintf(buffer,"Socket: Elemental+%d",amount); break;
                    }
                  break;
      }



    if (strlen(buffer) > 0) {
      gotoxy(22,line++);
      txt_write(buffer);
      }
    if (item->effect == E_INTR) {
      switch (item->control) {
        case  1: strcpy(buffer,"No Sleep"); break;
        case  2: strcpy(buffer,"No Poison"); break;
        case  3: strcpy(buffer,"Resist Fear"); break;
        case  4: strcpy(buffer,"Levitation"); break;
        case  5: strcpy(buffer,"Levitation/Speed"); break;
        case  6: strcpy(buffer,"Auto Search"); break;
        case  7: strcpy(buffer,"Speed"); break;
        case  8: strcpy(buffer,"HP Recover"); break;
        case  9: strcpy(buffer,"Reflection"); break;
        case 10: strcpy(buffer,"Resist Fire"); break;
        case 11: strcpy(buffer,"Resist Elemental"); break;
        case 12: strcpy(buffer,"XRay Vision"); break;
        case 13: strcpy(buffer,"Gateway Vision"); break;
        case 14: strcpy(buffer,"Reduced Mana"); break;
        case 15: strcpy(buffer,"No Fear"); break;
        case 16: strcpy(buffer,"Detect Traps"); break;
        case 17: strcpy(buffer,"Identification"); break;
        case 18: strcpy(buffer,"Detect Curse"); break;
        case 19: strcpy(buffer,"Improved Sleep"); break;
        case 20: strcpy(buffer,"Detect Food"); break;
        case 21: strcpy(buffer,"Detect Up"); break;
        case 22: strcpy(buffer,"Detect Down"); break;
        case 23: strcpy(buffer,"Double Experience"); break;
        case 24: strcpy(buffer,"Increase Experience"); break;
        case 25: strcpy(buffer,"Read Lore"); break;
        case 26: strcpy(buffer,"Read Language"); break;
        case 27: strcpy(buffer,"Read All"); break;
        case 28: strcpy(buffer,"Activate Gateway"); break;
        case 29: strcpy(buffer,"See Gateway"); break;
        case 30: strcpy(buffer,"Tardis"); break;
        case 31: strcpy(buffer,"Direction"); break;
        case 32: strcpy(buffer,"No Hunger"); break;
        case 33: strcpy(buffer,"Water Travel"); break;
        case 34: strcpy(buffer,"Flight"); break;
        case 35: strcpy(buffer,"Negate Force Field"); break;
        case 36: strcpy(buffer,"Resist Cold"); break;
        case 37: strcpy(buffer,"Resist Electric"); break;
        case 38: strcpy(buffer,"Resist Arcane"); break;
        case 39: strcpy(buffer,"Resist Psionic"); break;
        case 40: strcpy(buffer,"Resist Sleep"); break;
        case 41: strcpy(buffer,"Resist Poison"); break;
        case 42: strcpy(buffer,"Walk on Water"); break;
        }
      gotoxy(22,line++);
      txt_write(buffer);
      }
    if (item->num_sockets > 0) {
      if (item->sockets[0] != 0) {
        get_attribute_name(buffer2,item->sockets[0]);
        sprintf(buffer,"(%s)",buffer2);
        } else strcpy(buffer,"()");
      gotoxy(22,line++);
      txt_write(buffer);
      }
    if (item->num_sockets > 1) {
      if (item->sockets[1] != 0) {
        get_attribute_name(buffer2,item->sockets[1]);
        sprintf(buffer,"(%s)",buffer2);
        } else strcpy(buffer,"()");
      gotoxy(22,line++);
      txt_write(buffer);
      }
    if (item->num_sockets > 2) {
      if (item->sockets[2] != 0) {
        get_attribute_name(buffer2,item->sockets[2]);
        sprintf(buffer,"(%s)",buffer2);
        } else strcpy(buffer,"()");
      gotoxy(22,line++);
      txt_write(buffer);
      }
    if (item->num_enchantments > 0) {
      if (item->enchantments[0] != 0) {
        get_attribute_name(buffer2,item->enchantments[0]);
        sprintf(buffer,"%s",buffer2);
        gotoxy(22,line++);
        txt_write(buffer);
        }
      }
    if (item->num_enchantments > 1) {
      if (item->enchantments[1] != 0) {
        get_attribute_name(buffer2,item->enchantments[1]);
        sprintf(buffer,"%s",buffer2);
        gotoxy(22,line++);
        txt_write(buffer);
        }
      }
    if (item->num_enchantments > 2) {
      if (item->enchantments[2] != 0) {
        get_attribute_name(buffer2,item->enchantments[2]);
        sprintf(buffer,"%s",buffer2);
        gotoxy(22,line++);
        txt_write(buffer);
        }
      }
    price = item->cost;
    if (item->charges > 0) price += (item->charges * item->costp);
    sprintf(buffer,"Base Value: %.0f gold",price);
    gotoxy(22,17);
    txt_write(buffer);
    }
  key = 0;
  while (key != 13 && key != 27) key = inkey();
  }

