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

void sort_shop_spells_class() {
  int i;
  char flag;
  OBJECT_REC temp;
  flag = '*';
  while (flag == '*') {
    flag = ' ';
    for (i=0; i<n_shop_items-1; i++) {
      if (spells[shop_items[i].control].allign > spells[shop_items[i+1].control].allign) {
        temp = shop_items[i]; shop_items[i] = shop_items[i+1]; shop_items[i+1] = temp;
        flag = '*';
        }
      }
    }
  }

void sort_shop_spells_level() {
  int i;
  char flag;
  OBJECT_REC temp;
  flag = '*';
  while (flag == '*') {
    flag = ' ';
    for (i=0; i<n_shop_items-1; i++) {
      if (spells[shop_items[i].control].level > spells[shop_items[i+1].control].level) {
        temp = shop_items[i]; shop_items[i] = shop_items[i+1]; shop_items[i+1] = temp;
        flag = '*';
        }
      }
    }
  }

void get_shop_spells(int level) {
  int i;
  n_shop_items = 0;
  i = 1;
  while (i >= 0) {
    if (spells[i].level <= level && spells[i].for_sale != 0) {
      shop_items[n_shop_items] = *(find_linked_item(SPELL_SCROLL));
      shop_items[n_shop_items].effect = E_SPEL;
      shop_items[n_shop_items].control = i;
      shop_items[n_shop_items].rarity = 2500;
      shop_items[n_shop_items].level = -spells[i].level;
      strcpy(shop_items[n_shop_items].name,"Spell:");
      strcat(shop_items[n_shop_items].name,spells[i].name);
      if (spells[i].level <= 10) shop_items[n_shop_items].cost = spells[i].level * 1000;
      else if (spells[i].level <= 20) shop_items[n_shop_items].cost = spells[i].level * 2500;
      else shop_items[n_shop_items].cost = spells[i].level * 5000;
      if (spells[i].allign == classes[player.class-1].spell_group) shop_items[n_shop_items].cost /= 10;
      n_shop_items++;
      }
    if (spells[++i].effect >= 900) i=-1;
    }
  sort_shop_spells_level();
  sort_shop_spells_class();
  }

