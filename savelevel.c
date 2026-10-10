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

void save_level() {
  int x,y,i;
  for (x=0; x<101; x++)
    for (y=0; y<101; y++) {
      current_dungeon.level[player.d_level-1].map[x][y] = player.map[x][y];
      current_dungeon.level[player.d_level-1].known[x][y] = player.known[x][y];
      }
  for (i=0; i<1000; i++)
    current_dungeon.level[player.d_level-1].objects[i] = player.map_objects[i];
  for (x=0; x<6; x++)
    for (y=0; y<61; y++) {
      current_dungeon.level[player.d_level-1].monsters[x][y] = player.monster[x][y];
      }
  }
  
