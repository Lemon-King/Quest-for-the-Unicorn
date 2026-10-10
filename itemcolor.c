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

void itemColor(OBJECT_REC* item) {
  if (item == NULL) return;
  if (item->level >= 0) {
    textcolor(3); 
    return;
    }
  if (abs(item->rarity) > 2500) {               /* Common */
    textcolor(7); 
    return;
    }
  if (abs(item->rarity) > 500) {                /* Uncommon */
    textcolor(15);
    return;
    }
  if (abs(item->rarity) > 100) {                /* Rare */
    textcolor(10);
    return;
    }
  if (abs(item->rarity) > 20) {                 /* Very Rare */
    textcolor(9);
    return;
    }
  if (abs(item->rarity) > 1)  {                 /* Ultra Rare */
    textcolor(13);
    return;
    }
  textcolor(14);
  }

