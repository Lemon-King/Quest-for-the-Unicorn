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

void sort_shop_items() {
  int i;
  char flag;
  OBJECT_REC temp;
  flag = '*';
  while (flag == '*') {
    flag = ' ';
    for (i=0; i<n_shop_items-1; i++)
      if (strcmp(shop_items[i].name,shop_items[i+1].name) > 0) {
        flag = '*';
        temp = shop_items[i];
        shop_items[i] = shop_items[i+1];
        shop_items[i+1] = temp;
        }
    }
  }

