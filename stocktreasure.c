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

void stock_treasure() {
  int i;
  int s;
  int lvl;
  byte x,y;
  for (i=1; i<1000; i++) player.map_objects[i].otype = 0;
  prompt("Stocking Treasure...");
  lvl = player.diff + player.d_level / 3;
  for (i=1; i<=25; i++) {
    x = u_random(100) + 1; y = u_random(100) + 1;
    while (player.map[x][y] != 7) {
      x = u_random(100) + 1; y = u_random(100) + 1;
      }
    s = place_object(lvl);
    if (s >= 0) player.map[x][y] = s + 1000;
/*
    j = u_random(NO_OF_OBJECTS) + 1;
    while (objects[j].level == 0 || objects[j].level > lvl ||
           u_random(100) >= objects[j].rarity / 2)
      j = u_random(NO_OF_OBJECTS) + 1;
    player.map[x][y] = j + 1000;
*/

    }
  }

