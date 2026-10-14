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

int find_item_slot() {
  int i;
  for (i=1; i<1000; i++)
    if (player.map_objects[i].otype == O_NONE) return i;
  return -1;
  }

