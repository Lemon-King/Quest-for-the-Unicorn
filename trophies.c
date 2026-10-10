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

void draw_trophy() {
  gotoxy(28,2); textcolor(14); txt_write("+----------------------+");
  gotoxy(28,3); textcolor(14); txt_write("|                      |");
  gotoxy(28,4); textcolor(14); txt_write("|                      |");
  gotoxy(28,5); textcolor(14); txt_write("|                      |");
  gotoxy(29,6); textcolor(14); txt_write("\\                    /");
  gotoxy(30,7); textcolor(14); txt_write("\\                  /");
  gotoxy(31,8); textcolor(14); txt_write("\\                /");
  gotoxy(32,9); textcolor(14); txt_write("\\              /");
  gotoxy(33,10); textcolor(14); txt_write("\\            /");
  gotoxy(34,11); textcolor(14); txt_write("\\          /");
  gotoxy(35,12); textcolor(14); txt_write("\\        /");
  gotoxy(36,13); textcolor(14); txt_write("\\      /");
  gotoxy(36,14); textcolor(14); txt_write("/      \\");
  gotoxy(31,15); textcolor(14); txt_write("+---+--------+---+");
  gotoxy(30,16); textcolor(14); txt_write("/                  \\");
  gotoxy(20,17); textcolor(6); txt_write("+--------+--------------------+--------+");
  gotoxy(20,18); textcolor(6); txt_write("| +----------------------------------+ |");
  gotoxy(20,19); textcolor(6); txt_write("| |                                  | |");
  gotoxy(20,20); textcolor(6); txt_write("| |                                  | |");
  gotoxy(20,21); textcolor(6); txt_write("| |                                  | |");
  gotoxy(20,22); textcolor(6); txt_write("| +----------------------------------+ |");
  gotoxy(20,23); textcolor(6); txt_write("+--------+--------------------+--------+");
  gotoxy(22,18); textcolor(14); txt_write("+----------------------------------+");
  gotoxy(22,19); textcolor(14); txt_write("|               For:               |");
  gotoxy(22,20); textcolor(14); txt_write("|                                  |");
  gotoxy(22,21); textcolor(14); txt_write("|                                  |");
  gotoxy(22,22); textcolor(14); txt_write("+----------------------------------+");
  }

int has_trophy(int num) {
  int i;
  for (i=0; i<stats.num_trophies; i++)
    if (stats.trophies[i] == num) return -1;
  return 0;
  }

void new_trophy(int num) {
  int key;
  int i;
  if (has_trophy(num) != 0) return;
  stats.num_trophies++;
  for (i=stats.num_trophies - 1; i > 0; i--) stats.trophies[i] = stats.trophies[i-1];
  stats.trophies[0] = num;
  saveScreen();
  draw_trophy();
  gotoxy(40-(strlen(trophies[num].name)/2),4);
  textcolor(14); txt_write(trophies[num].name);
  gotoxy(40-(strlen(trophies[num].desc)/2),20);
  textcolor(14); txt_write(trophies[num].desc);
  key = 0;
  while (key != 13) key=inkey();
  restoreScreen();
  }

void check_trophies() {
  int i,c,j;
  int mask;
  OBJECT_REC* item;
  i = 0;
  while (trophies[i].criteria_type < 999) {
    if (has_trophy(i) == 0)
      switch (trophies[i].criteria_type) {
        case TC_LEVEL:
                       if (player.level >= trophies[i].control[0]) new_trophy(i);
                       break;
        case TC_FMOUNT:
                        if (player.mount != 0 && player.peg != 0) new_trophy(i);
                        break;
        case TC_TORCH:
                       if (player.torch >= trophies[i].control[0]) new_trophy(i);
                       break;
        case TC_STEPS:
                       if (stats.counts[STAT_STEPS_TAKEN] >= trophies[i].control[0]) new_trophy(i);
                       break;
        case TC_SLEEP:
                       if (stats.counts[STAT_HOURS_NAPPED] >= trophies[i].control[0]) new_trophy(i);
                       break;
        case TC_LGOLD:
                       if (stats.counts[STAT_GOLD_LOOTED] >= trophies[i].control[0]) new_trophy(i);
                       break;
        case TC_GOLD:
                       if (get_gold() >= trophies[i].control[0]) new_trophy(i);
                       break;
        case TC_COMN:
                       if (stats.counts[STAT_COMMONS] >= trophies[i].control[0]) new_trophy(i);
                       break;
        case TC_RARE:
                       if (stats.counts[STAT_RARES] >= trophies[i].control[0]) new_trophy(i);
                       break;
        case TC_VRARE:
                       if (stats.counts[STAT_VERY_RARES] >= trophies[i].control[0]) new_trophy(i);
                       break;
        case TC_URARE:
                       if (stats.counts[STAT_ULTRA_RARES] >= trophies[i].control[0]) new_trophy(i);
                       break;
        case TC_LCLEAR:
                       if (stats.counts[STAT_LEVELS_CLEARED] >= trophies[i].control[0]) new_trophy(i);
                       break;
        case TC_DCLEAR:
                       if (stats.counts[STAT_DUNGEON_CLEARED] & trophies[i].control[0]) new_trophy(i); 
                       break;
        case TC_IDENT:
                       if (stats.counts[STAT_ITEMS_IDENTED] >= trophies[i].control[0]) new_trophy(i);
                       break;
        case TC_FIRE:
                       if (stats.counts[STAT_ARROWS_FIRED] >= trophies[i].control[0]) new_trophy(i);
                       break;
        case TC_DMGDN:
                       if (stats.counts[STAT_DAMAGE] >= trophies[i].control[0]) new_trophy(i);
                       break;
        case TC_DMGTK:
                       if (stats.counts[STAT_DAMAGE_TAKEN] >= trophies[i].control[0]) new_trophy(i);
                       break;
        case TC_TOXIC:
                       if (stats.counts[STAT_POISONED] >= trophies[i].control[0]) new_trophy(i);
                       break;
        case TC_TALK:
                       if (stats.counts[STAT_CONVERSATIONS] >= trophies[i].control[0]) new_trophy(i);
                       break;
        case TC_CLASS:
                       if (stats.counts[STAT_CLASSES_TAKEN] >= trophies[i].control[0]) new_trophy(i);
                       break;
        case TC_ENCH:
                       if (stats.counts[STAT_ENCHANTMENTS] >= trophies[i].control[0]) new_trophy(i);
                       break;
        case TC_SOCK:
                       if (stats.counts[STAT_SOCKETS_ADDED] >= trophies[i].control[0]) new_trophy(i);
                       break;
        case TC_SOLD:
                       if (stats.counts[STAT_ITEMS_SOLD] >= trophies[i].control[0]) new_trophy(i);
                       break;
        case TC_LORE:
                      c = 1;
                      for (j=0; j<NO_OF_LORE; j++)
                        if (player.lore[j] == 0) c = 0;
                      if (c != 0) new_trophy(i);
                      break;
        case TC_MESG:
                      c = 1;
                      for (j=0; j<NO_OF_GENS; j++)
                        if (player.gen[j] == 0) c = 0;
                      if (c != 0) new_trophy(i);
                      break;
        case TC_HOUSE:
                      c = 0;
                      for (j=0; j<5; j++) {
                        if (player.houses[j].region != 0 &&
                            player.houses[j].mortgage == 0) c++;
                        }
                      if (c >= trophies[i].control[0]) new_trophy(i);
                      break;
        case TC_MSTAT:
                      c = 0; 
                      for (j=1; j<7; j++)
                        if (player.stat[j] == 99) c++;
                      if (c >= trophies[i].control[0]) new_trophy(i);
                      break;
        case TC_CRAFT:
                       if (stats.counts[STAT_ITEMS_CRAFTED] >= trophies[i].control[0]) new_trophy(i);
                       break;
        case TC_ITEM:
                      c = 1;
                      if (stats.counts[trophies[i].control[2]] < trophies[i].control[1]) c = 0;
                      if (trophies[i].control[3] > 0)
                        if (stats.counts[trophies[i].control[5]] < trophies[i].control[4]) c = 0;
                      if (c == 1) new_trophy(i);
                      break;
        case TC_DEF:
                      if (get_armour() >= 250) new_trophy(i);
                      break;
        case TC_TYPE:
                      c = 1;
                      if (stats.counts[trophies[i].control[2]] < trophies[i].control[1]) c = 0;
                      if (trophies[i].control[3] > 0)
                        if (stats.counts[trophies[i].control[5]] < trophies[i].control[4]) c = 0;
                      if (c == 1) new_trophy(i);
                      break;
        case TC_PICKT:
                      c = 1;
                      if (stats.counts[trophies[i].control[2]] < trophies[i].control[1]) c = 0;
                      if (trophies[i].control[3] > 0)
                        if (stats.counts[trophies[i].control[5]] < trophies[i].control[4]) c = 0;
                      if (c == 1) new_trophy(i);
                      break;
        case TC_PICKI:
                      c = 1;
                      if (stats.counts[trophies[i].control[2]] < trophies[i].control[1]) c = 0;
                      if (trophies[i].control[3] > 0)
                        if (stats.counts[trophies[i].control[5]] < trophies[i].control[4]) c = 0;
                      if (c == 1) new_trophy(i);
                      break;
        case TC_PICKR:
                      mask = 0;
                      for (j=0; j<(trophies[i].control[1] - trophies[i].control[0] + 1); j++)
                        mask = (mask << 1) | 1;
                      if ((stats.counts[trophies[i].control[2]] & mask) == mask) new_trophy(i);
                      break;
        case TC_ITEMR:
                      mask = 0;
                      for (j=0; j<(trophies[i].control[1] - trophies[i].control[0] + 1); j++)
                        mask = (mask << 1) | 1;
                      if ((stats.counts[trophies[i].control[2]] & mask) == mask) new_trophy(i);
                      break;
        case TC_EQUIP:
                      if (stats.counts[trophies[i].control[7]] > 0) new_trophy(i);
                      break;
        case TC_HKILL:
                       if (stats.counts[STAT_HARD_MOB] >= trophies[i].control[0]) new_trophy(i);
                       break;
        case TC_TRICK:
                      mask = 0;
                      for (j=0; j<(trophies[i].control[1] - trophies[i].control[0] + 1); j++)
                        mask = (mask << 1) | 1;
                      if ((stats.counts[trophies[i].control[3]] & mask) == mask) new_trophy(i);
                      break;
        case TC_DRAGON:
                       if (stats.counts[STAT_DRAGONS] >= trophies[i].control[0]) new_trophy(i);
                       break;
        case TC_SKILL:
                       if (get_skill(trophies[i].control[0]) >= trophies[i].control[1]) new_trophy(i);
                       break;
        case TC_TROPHY:
                       if (stats.num_trophies == (trophy_count-1)) {
                         new_trophy(i);
                         item = find_linked_item(502);
                         if (item != NULL) inventory(item);
                         }
                       break;
        case TC_QUESTS:
                       c = 1;
                       j = 0;
                       while (j >= 0) {
                         if (player.quests[j] != 'Y') c = 0;
                         j++;
                         if (links[j].region > 90) j = -1;
                         }
                       if (c == 1) new_trophy(i);
                       break;
        case TC_CARDS:
                       if (stats.counts[trophies[i].control[0]] == trophies[i].control[1]) new_trophy(i);
                       break;
        }
    i++;
    }

/*
  if (player.level >= 10 && has_trophy(0) == 0) new_trophy(0);
  if (player.level >= 20 && has_trophy(1) == 0) new_trophy(1);
  if (player.level >= 30 && has_trophy(2) == 0) new_trophy(2);
  if (player.level >= 40 && has_trophy(3) == 0) new_trophy(3);
  if (player.level >= 50 && has_trophy(4) == 0) new_trophy(4);
  if (player.mount != 0 && player.peg != 0 && has_trophy(5) == 0) new_trophy(5);
  if (player.torch >= 1000 && has_trophy(6) == 0) new_trophy(6);
  if (stats.counts[STAT_STEPS_TAKEN] >= 10000000 && has_trophy(7) == 0) new_trophy(7);
  if (stats.counts[STAT_HOURS_NAPPED] >= 8760 && has_trophy(8) == 0) new_trophy(8);
  if (stats.counts[STAT_GOLD_LOOTED] >= 1000000 && has_trophy(9) == 0) new_trophy(9);
  if (get_gold() >= 1000000 && has_trophy(10) == 0) new_trophy(10);
  if (stats.counts[STAT_COMMONS] >= 10000 && has_trophy(13) == 0) new_trophy(13);
  if (stats.counts[STAT_RARES] >= 1 && has_trophy(14) == 0) new_trophy(14);
  if (stats.counts[STAT_VERY_RARES] >= 1 && has_trophy(15) == 0) new_trophy(15);
  if (stats.counts[STAT_ULTRA_RARES] >= 1 && has_trophy(16) == 0) new_trophy(16);
  if (stats.counts[STAT_LEVELS_CLEARED] >= 200 && has_trophy(18) == 0) new_trophy(18);
  if ((stats.counts[STAT_DUNGEON_CLEARED] & 0x3f) == 0x3f && has_trophy(17) == 0) new_trophy(17); 
  if (stats.counts[STAT_ITEMS_IDENTED] >= 10000 && has_trophy(44) == 0) new_trophy(44);
  if (stats.counts[STAT_ARROWS_FIRED] >= 2500 && has_trophy(32) == 0) new_trophy(32);
  if (stats.counts[STAT_DAMAGE] >= 10000000 && has_trophy(38) == 0) new_trophy(38);
  if (stats.counts[STAT_DAMAGE_TAKEN] >= 1000000 && has_trophy(39) == 0) new_trophy(39);
  if (stats.counts[STAT_POISONED] >= 500 && has_trophy(36) == 0) new_trophy(36);
  if (stats.counts[STAT_CONVERSATIONS] >= 2000 && has_trophy(41) == 0) new_trophy(41);
  if (stats.counts[STAT_CLASSES_TAKEN] >= 100 && has_trophy(42) == 0) new_trophy(42);
  if (stats.counts[STAT_ENCHANTMENTS] >= 250 && has_trophy(25) == 0) new_trophy(25);
  if (stats.counts[STAT_SOCKETS_ADDED] >= 100 && has_trophy(24) == 0) new_trophy(24);
  if (stats.counts[STAT_ITEMS_SOLD] >= 10000 && has_trophy(40) == 0) new_trophy(40);
  if (stats.counts[STAT_ITEMS_CRAFTED] >= 100 && has_trophy(21) == 0) new_trophy(21);
  if (stats.counts[STAT_SEX_CHANGE] >= 25 && has_trophy(12) == 0) new_trophy(12);
  if (stats.counts[STAT_MEAT_EATEN] >= 100 && stats.counts[STAT_POTATOS_EATEN] >= 100 && has_trophy(34) == 0) new_trophy(34);
  if (stats.counts[STAT_APPLEUP_EATEN] >= 2 && has_trophy(35) == 0) new_trophy(35);
  if (stats.counts[STAT_GREEN_BEERS] >= 100 && stats.counts[STAT_CORNED_BEEF] >= 100 && has_trophy(46) == 0) new_trophy(46);
  if (stats.counts[STAT_TURKEY_DINNERS] >= 100 && has_trophy(53) == 0) new_trophy(53);
  if (stats.counts[STAT_PRESENTS_OPENED] >= 20 && has_trophy(54) == 0) new_trophy(54);
  if (stats.counts[STAT_MISTLETOE] >= 25 && has_trophy(56) == 0) new_trophy(56);
  if (stats.counts[STAT_CANDY_HEARTS] >= 100 && has_trophy(57) == 0) new_trophy(57);
  if (stats.counts[STAT_ALCOHOL_DRANK] >= 1000 && has_trophy(11) == 0) new_trophy(11);
  if (stats.counts[STAT_SCROLLS_READ] >= 2500 && has_trophy(27) == 0) new_trophy(27);
  if (stats.counts[STAT_POTIONS_DRUNK] >= 2500 && has_trophy(28) == 0) new_trophy(28);
  if (stats.counts[STAT_MEALS_EATEN] >= 2500 && has_trophy(29) == 0) new_trophy(29);
  if (stats.counts[STAT_ROCK_HOUND] >= 2000 && has_trophy(30) == 0) new_trophy(30);
  if (stats.counts[STAT_EGGS_FOUND] >= 250 && has_trophy(33) == 0) new_trophy(33);
  if (stats.counts[STAT_BSTONE_RINGS] == 0xfff && has_trophy(45) == 0) new_trophy(45);
  if (stats.counts[STAT_CHARMS] == 0xfffff && has_trophy(49) == 0) new_trophy(49);
  if (stats.counts[STAT_CANDY] == 0xfffff && has_trophy(51) == 0) new_trophy(51);
  if (stats.counts[STAT_FIREWORKS] == 0xfffff && has_trophy(50) == 0) new_trophy(50);
  if (stats.counts[STAT_BRIDE] >= 1 && has_trophy(47) == 0) new_trophy(47);
  if (stats.counts[STAT_GROOM] >= 1 && has_trophy(48) == 0) new_trophy(48);
  if (stats.counts[STAT_SANTA] >= 1 && has_trophy(55) == 0) new_trophy(55);
  if (stats.counts[STAT_HARD_MOB] >= 1 && has_trophy(43) == 0) new_trophy(43);
  if (stats.counts[STAT_COSTUMES] == 0xfff && has_trophy(52) == 0) new_trophy(52);
  if (stats.counts[STAT_DRAGONS] >= 1000 && has_trophy(26) == 0) new_trophy(26);
  c = 1;
  for (i=0; i<NO_OF_LORE; i++)
    if (player.lore[i] == 0) c = 0;
  if (c != 0 && has_trophy(22) == 0) new_trophy(22);
  c = 1;
  for (i=0; i<NO_OF_GENS; i++)
    if (player.gen[i] == 0) c = 0;
  if (c != 0 && has_trophy(23) == 0) new_trophy(23);
  c = 0;
  for (i=0; i<5; i++) {
    if (player.houses[i].region != 0) c++;
    if (player.houses[i].region != 0 &&
	player.houses[i].mortgage == 0 && has_trophy(19) == 0) new_trophy(19);
    }
  if (c == 5 && has_trophy(20) == 0) new_trophy(20);
  for (i=1; i<7; i++)
    if (player.stat[i] == 99 && has_trophy(31) == 0) new_trophy(31);
  if (get_armour() >= 250 && has_trophy(37) == 0) new_trophy(37);
*/
  }

int show_trophy_group(int top) {
  int i;
  int count;
  int bottom;
  count = 0;
  bottom = top + 20;
  if (bottom > stats.num_trophies) bottom = stats.num_trophies;
  textmode(3);
  textcolor(15); gotoxy(31,1); txt_write("Trophies Collected:");
  textcolor(10);
  for (i=top; i<bottom; i++) {
    count++;
    textcolor(10);
    gotoxy(1,i+3); txt_write(trophies[stats.trophies[i]].name);
    gotoxy(20,i+3); txt_write(trophies[stats.trophies[i]].desc);
    }
  textcolor(7);
  gotoxy(34,25); txt_write("<ESC> to exit");
  return count;
  }

void show_trophies() {
  int key;
  int top;
  int count;
  top = 0;
  count = show_trophy_group(top);
  key = 0;
  while (key != 13 && key != 27) {
    key = inkey();
    if (key == '3' && count == 20) {
      top += 20;
      count = show_trophy_group(top);
      if (count == 0) {
        top -= 20;
        if (top < 0) top = 0;
        count = show_trophy_group(top);
        }
      }
    if (key == '9' && top > 0) {
      top -= 20;
      if (top < 0) top = 0;
      count = show_trophy_group(top);
      }
    }
  }

