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

void get_shop_items(int otype1,int otype2,int otype3,int otype4,int otype5,int otype6,int rarity) {
  int i;
  n_shop_items = 0;
  i = 0;
  while (i >= 0) {
    if (objects[i].control2 >= 0 &&
        (objects[i].align & 0x40000000) != 0 &&
        ( objects[i].otype == otype1 ||
          objects[i].otype == otype2 ||
          objects[i].otype == otype3 ||
          objects[i].otype == otype4 ||
          objects[i].otype == otype5 ||
          objects[i].otype == otype6)) {
      shop_items[n_shop_items++] = objects[i];
      }
    if (objects[i].otype >= 99) i=-1;
      else i++;
    }
  sort_shop_items();
  }

