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

void get_shop_recipes() {
  int i;
  OBJECT_REC *item;
  OBJECT_REC *dest;
  n_shop_items = 0;
  item = find_linked_item(ITEM_RECIPE);
  if (item == NULL) return;
  for (i=0; i<recipe_count; i++) {
    dest = find_linked_item(recipes[i].object);
    if (dest != NULL) {
      shop_items[n_shop_items++] = *item;
      shop_items[n_shop_items-1].control = 110;
      shop_items[n_shop_items-1].control2 = i;
      shop_items[n_shop_items-1].cost = dest->cost / 4;
      if (shop_items[n_shop_items-1].cost < 20) shop_items[n_shop_items-1].cost = 20;
      strcpy(shop_items[n_shop_items-1].name,"Recipe:");
      strcat(shop_items[n_shop_items-1].name,dest->name);
      }
    }
  sort_shop_items();
  }

