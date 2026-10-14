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

void wizard() {
  int  i;
  char buffer[80];
  char buffer2[80];
  char key;
  char pword[41];
  int ret;
  char flag;

  int input(char* prompt) {
    int ret;
    strcpy(buffer,"");
    strcpy(pword,prompt);
    msg(pword,11);
    key = 0;
    while (key != 13) { 
      sprintf(buffer2,"%s_",pword);
      key = inkey();
      if (key >= ' ') {
        buffer[strlen(buffer) + 1] = 0;
        buffer[strlen(buffer)] = key;
        pword[strlen(pword) + 1] = 0;
        pword[strlen(pword)] = key;
        msg(pword,-11);
        }
      if (key == 8 && strlen(buffer) > 0) {
        buffer[strlen(buffer) - 1] = 0;
        pword[strlen(pword) - 1] = 0;
        msg(pword,-11);
        }
      }
    ret = atoi(buffer);
    return ret;
    }

  void mnsters() {
    int i;
    int top;
    int option;
    char flag;
    char buffer[80];
    top = 0;
    option = 0;
    flag = 'N';
    while (flag == 'N') {
      if (option == 0) {
        msg("",11);
        for (i=0; i<7; i++) {
          if (monsters[top].speed < 999) {
            sprintf(buffer,"%d. %s",top+1,monsters[top].name);
            msg(buffer,11);
            top++;
            }
          }
        msg("",11);
        }
      msg("999. Done",11);
      option = input("Option ?");
      if (option>0 && option<=NO_OF_MONSTERS) {
        option--;
        msg("",11);
        msg(monsters[option].name,3);
        sprintf(buffer,"HP:%d Mana:%d Lvl:%d",monsters[option].hp,monsters[option].mana,
               monsters[option].level);
        msg(buffer,3);
        sprintf(buffer,"ATK:%d Def:%d SPD:%d",monsters[option].attack,
               monsters[option].defense,monsters[option].speed);
        msg(buffer,3);
        sprintf(buffer,"EXP:%.0f +%.0f/HP",monsters[option].exp,
               monsters[option].exp_hp);
        msg(buffer,3);
        if (monsters[option].special == 2) msg("SPATK:Sleep",3);
        if (monsters[option].special == 3) msg("SPATK:Poison",3);
        if (monsters[option].special == 5) msg("SPATK:Fear",3);
        if (monsters[option].special == 10) msg("Friendly",3);
        msg("",11);
        }
      if (option == 999) flag = 'Y';
      }
    }

  void objcts() {
    int i;
    int top;
    int option;
    char flag;
    char buffer[80];
    char key;
    OBJECT_REC item;
    top = 0;
    option = 0;
    flag = 'N';
    while (flag == 'N') {
      if (option == 0) {
        msg("",11);
        for (i=0; i<7; i++) {
          if (objects[top].otype < 999) {
            sprintf(buffer,"%d. %s",top+1,objects[top].name);
            msg(buffer,11);
            top++;
            }
          }
        msg("",11);
        }
      msg("999. Done",11);
      option = input("Option ?");
      if (option>0 && option<=NO_OF_OBJECTS) {
        option--;
        msg("",11);
        msg(objects[option].name,3);
        switch (objects[option].otype) {
          case O_EDGE:msg("Type: Edge Weapon",3); break;
          case O_ARMR:msg("Type: Armour",3); break;
          case O_POTN:msg("Type: Potion",3); break;
          case O_RING:msg("Type: Ring",3); break;
          case O_WAND:msg("Type: Staff",3); break;
          case O_FOOD:msg("Type: Food",3); break;
          case O_MISC:msg("Type: Miscelaneous",3); break;
          case O_SCRL:msg("Type: Scroll",3); break;
          case O_NECK:msg("Type: Necklace",3); break;
          case O_ROBE:msg("Type: Robe",3); break;
          case O_BOOT:msg("Type: Boots",3); break;
          case O_HELM:msg("Type: Helm",3); break;
          case O_SHLD:msg("Type: Shield",3); break;
          case O_BOOK:msg("Type: Book",3); break;
          case O_POLE:msg("Type: Pole Weapon",3); break;
          case O_BOW:msg("Type: Missle Weapon",3); break;
          case O_JEWL:msg("Type: Jewel",3); break;
          case O_PROJ:msg("Type: Projected Energy Weapon",3); break;
          case O_DAGR:msg("Type: Dagger",3); break;
          case O_CRFT:msg("Type: Crafting Item",3); break;
          }
        switch (objects[option].effect) {
          case E_NONE:msg("Effect: None",3); break;
          case E_HEAL:msg("Effect: Healing",3); break;
          case E_ARMR:msg("Effect: Armour",3); break;
          case E_ATCK:switch (objects[option].control) {
                        case 1:msg("Effect: Attack-Touch",3); break;
                        case 2:msg("Effect: Attack-Missile",3); break;
                        case 3:msg("Effect: Attack-Area 9",3); break;
                        case 4:msg("Effect: Attack-Area 25",3); break;
                        case 5:msg("Effect: Attack-Missile 9",3); break;
                        default:msg("Effect: Attack",3); break;
                        }
                      break;
          case E_FEAR:msg("Effect: Fear",3); break;
          case E_SLEP:msg("Effect: Sleep",3); break;
          case E_TELE:msg("Effect: Teleportation",3); break;
          case E_POSN:msg("Effect: Poison",3); break;
          case E_BLES:msg("Effect: Bless",3); break;
          case E_PROT:msg("Effect: Protection",3); break;
          case E_INHT:msg("Effect: Increase To-Hit",3); break;
          case E_SPCL:switch (objects[option].control) {
                        case 1:msg("Effect: Clairaudience",3); break;
                        case 2:msg("Effect: Clairvoyance",3); break;
                        case 3:msg("Effect: Haste",3); break;
                        case 4:msg("Effect: Giant Strength",3); break;
                        case 5:msg("Effect: Ethereal",3); break;
                        case 6:msg("Effect: Light",3); break;
                        case 8:msg("Effect: Object Location",3); break;
                        case 9:msg("Effect: Monster Location",3); break;
                        case 10:msg("Effect: Lore Scroll",3); break;
                        case 11:msg("Effect: Information Scroll",3); break;
                        case 12:msg("Effect: Identification",3); break;
                        case 13:msg("Effect: Protection",3); break;
                        case 14:msg("Effect: Magic Mapping",3); break;
                        case 15:msg("Effect: Surface",3); break;
                        case 16:msg("Effect: Increase Strength",3); break;
                        case 17:msg("Effect: Increase Dexterity",3); break;
                        case 18:msg("Effect: Increase Intelligence",3); break;
                        case 19:msg("Effect: Double Current Mana",3); break;
                        case 20:msg("Effect: General Message",3); break;
                        case 21:msg("Effect: Read Languages",3); break;
                        case 22:msg("Effect: Detect Magic",3); break;
                        case 23:msg("Effect: Identify Monster",3); break;
                        case 24:msg("Effect: Slow Poison",3); break;
                        case 25:msg("Effect: Cure Poison",3); break;
                        case 26:msg("Effect: Permanent Light",3); break;
                        case 27:msg("Effect: Monster Summoning",3); break;
                        case 28:msg("Effect: Read Lore",3); break;
                        case 29:msg("Effect: Dispel Magic",3); break;
                        case 30:msg("Effect: Force Field",3); break;
                        case 31:msg("Effect: Increase Random Attribute",3); break;
                        case 32:msg("Effect: Monster Summoning II",3); break;
                        case 33:msg("Effect: Monster Summoning III",3); break;
                        case 34:msg("Effect: Phase Door",3); break;
                        case 35:msg("Effect: Permanancy",3); break;
                        case 36:msg("Effect: Remove Fear",3); break;
                        case 37:msg("Effect: Find Traps",3); break;
                        case 38:msg("Effect: Fire Resistance",3); break;
                        case 39:msg("Effect: Summon Shadow",3); break;
                        case 40:msg("Effect: Create Food",3); break;
                        case 41:msg("Effect: Sticks to Snakes",3); break;
                        case 42:msg("Effect: Summon Monster",3); break;
                        case 43:msg("Effect: Enhanced Trap Location",3); break;
                        case 44:msg("Effect: Summon Air Elemental",3); break;
                        case 45:msg("Effect: Summon Water Elemental",3); break;
                        case 46:msg("Effect: Talning Rod Functions",3); break;
                        case 47:msg("Effect: Tardis Functions",3); break;
                        case 48:msg("Effect: ??????",3); break;
                        case 49:msg("Effect: Library",3); break;
                        case 50:msg("Effect: Trio of Might",3); break;
                        case 51:msg("Effect: Lore Message",3); break;
                        case 52:msg("Effect: Enlightenment",3); break;
                        case 53:msg("Effect: Knowledge",3); break;
                        case 54:msg("Effect: Restore Mana",3); break;
                        case 55:msg("Effect: Double Mana",3); break;
                        case 56:msg("Effect: Experience * 5%",3); break;
                        case 57:msg("Effect: Experience * 7%",3); break;
                        case 58:msg("Effect: Experience * 10%",3); break;
                        case 59:msg("Effect: Experience * 15%",3); break;
                        case 60:msg("Effect: Causes Sleep",3); break;
                        case 61:msg("Effect: Causes Fear",3); break;
                        case 62:msg("Effect: Causes Blindness",3); break;
                        case 63:msg("Effect: Causes Confustion",3); break;
                        case 64:msg("Effect: Cures Confustion",3); break;
                        case 65:msg("Effect: Cures Fear",3); break;
                        case 66:msg("Effect: Cures Blindness",3); break;
                        case 67:msg("Effect: Universal Cure",3); break;
                        case 68:msg("Effect: Enchant Weapon",3); break;
                        case 69:msg("Effect: Enchant Armour",3); break;
                        case 70:msg("Effect: Corrode Weapon",3); break;
                        case 71:msg("Effect: Corrode Armour",3); break;
                        case 72:msg("Effect: Remove Curse",3); break;
                        case 73:msg("Effect: Charging",3); break;
                        case 74:msg("Effect: Enhanced Bless",3); break;
                        }
                      break;
          case E_INTR:switch (objects[option].control) {
                        case A_NOSL:msg("Intrinsic: Immune to sleep",3); break;
                        case A_NOPS:msg("Intrinsic: Immune to Poison",3); break;
                        case A_RSFR:msg("Intrinsic: Resist Fear",3); break;
                        case A_LEV:msg("Intrinsic: Levitation",3); break;
                        case A_SPLV:msg("Intrinsic: Haste & Levitation",3); break;
                        case A_SRCH:msg("Intrinsic: Search",3); break;
                        case A_SPD:msg("Intrinsic: Haste",3); break;
                        case A_HEAL:msg("Intrinsic: HP Recovery",3); break;
                        case A_REFL:msg("Intrinsic: Reflect Energy",3); break;
                        case A_RFIR:msg("Intrinsic: Resist Fire",3); break;
                        case A_RELE:msg("Intrinsic: Resist Elemental",3); break;
                        case A_XRAY:msg("Intrinsic: X-Ray Vision",3); break;
                        case A_GSEE:msg("Intrinsic: Gateway Vision",3); break;
                        case A_MANA:msg("Intrinsic: Reduce Mana Cost",3); break;
                        case A_NOFR:msg("Intrinsic: Immune to Fear",3); break;
                        case A_TRAP:msg("Intrinsic: Detect Traps",3); break;
                        case A_IDNT:msg("Intrinsic: Identification",3); break;
                        case A_CURS:msg("Intrinsic: Detect Curse",3); break;
                        case A_NPHL:msg("Intrinsic: Heal while sleeping",3); break;
                        case A_DTFD:msg("Intrinsic: Detect Food",3); break;
                        case A_DTUP:msg("Intrinsic: Detect Up Stairs",3); break;
                        case A_DTDN:msg("Intrinsic: Detect Down Stairs",3); break;
                        case A_DEXP:msg("Intrinsic: Double Experience",3); break;
                        case A_IEXP:msg("Intrinsic: Increase Experience",3); break;
                        case A_RDLR:msg("Intrinsic: Read Lore",3); break;
                        case A_RDLN:msg("Intrinsic: Read Languages",3); break;
                        case A_RALL:msg("Intrinsic: Read All",3); break;
                        }
                      break;
          }
        sprintf(buffer,"Damage/Defense:%d",objects[option].damage);
        msg(buffer,3);
        sprintf(buffer,"Lvl:%d HP:%d Hlth:%d",objects[option].level,
                                              objects[option].user_hp,
                                              objects[option].user_health);
        msg(buffer,3);
        sprintf(buffer,"Rar:%d Chg:%d Wgt:%d",objects[option].rarity,
                                              objects[option].charges,
                                              objects[option].weight);
        msg(buffer,3);
        sprintf(buffer,"Cost:%.0f +%.0f/(plus/charge)",objects[option].cost,
                                              objects[option].costp);
        msg(buffer,3);
        msg("Summon (Y/N) ?",2);
        key = ' ';
        while (key != 'Y' && key != 'N') {
          key = inkey();
          if (key == 'y') key = 'Y';
          if (key == 'n') key = 'N';
          }
        msg("",-2);
        if (key == 'Y') {
          item = objects[option];
          item.level = -1;
          saveScreen();
          inventory(&item);
          restoreScreen();
          }
        }
      if (option == 999) flag = 'Y';
      }
    }

  void messages() {
    char key;
    char flag;
    char buffer[40];
    int  m;
    flag = 'N';
    while (flag == 'N') {
      msg("",11);
      sprintf(buffer,"No of general: %d",NO_OF_GENS);
      msg(buffer,11);
      sprintf(buffer,"No of Lore: %d",NO_OF_LORE);
      msg(buffer,11);
      msg("",11);
      msg("1. Read General",11);
      msg("2. Read Lore",11);
      msg("0. exit",11);
      msg("   ?",2);
      key = inkey();
      if (key == '1') {
        m = input("General Number ?");
        if (m > 0 && m <= NO_OF_GENS) {
          saveScreen();
          show_gen(m);
          restoreScreen();
          }
        }
      if (key == '2') {
        m = input("Lore Number ?");
        if (m > 0 && m <= NO_OF_LORE) {
          saveScreen();
          show_lore(m);
          restoreScreen();
          }
        }
      if (key == '0') flag = 'Y';
      }
    }

  if (wizardmode == 'N') {
    strcpy(buffer,"");
    strcpy(pword,"Password ?");
    msg(pword,11);
    key = 0;
    while (key != 13) { 
      sprintf(buffer2,"%s_",pword);
      key = inkey();
      if (key >= ' ') {
        buffer[strlen(buffer) + 1] = 0;
        buffer[strlen(buffer)] = key;
        pword[strlen(pword) + 1] = 0;
        pword[strlen(pword)] = '*';
        msg(pword,-11);
        }
      if (key == 8 && strlen(buffer) > 0) {
        buffer[strlen(buffer) - 1] = 0;
        pword[strlen(pword) - 1] = 0;
        msg(pword,-11);
        }
      }
    }
  ret = 0;
  if (wizardmode != 'Y' && strcmp(buffer,"rcs123") != 0) return;
  wizardmode = 'Y';
  flag = 'N';
  while (flag != 'Y') {
    msg("",11);
    msg("1. Monsters",11);
    msg("2. Objects",11);
    msg("3. Messages",11);
    msg("4. Spells",11);
    msg("5. Special",11);
    msg("6. Character",11);
    msg("0. Exit",11);
    msg("   ?",2);
    key = inkey();
    if (key == '0') flag = 'Y';
    if (key == '1') mnsters();
    if (key == '2') objcts();
    if (key == '3') messages();
    }
  for (i=0; i<10; i++) msg("",11);
  }
