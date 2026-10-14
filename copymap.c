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

void copyMap(MAP_TYPE* dest,int num) {
  int x,y;
  for (y=0; y<=100; y++)
    for (x=0; x<=100; x++)
      player.map[x][y] = maps[num][y][x];
  }

