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

void auto_detect() {
  int x,y;
  OBJECT_REC* item;
  for (x=1; x<=100; x++)
    for (y=1; y<=100; y++)
      if (player.map[x][y] >= 1000 && player.map[x][y] <2000) {
        item = &(player.map_objects[player.map[x][y]-1000]);
        if (has_intrinsic(A_DTFD) && item->otype == O_FOOD) {
          player.known[x][y] = 1;
          show_spot(x,y);
          }
        }
  }

