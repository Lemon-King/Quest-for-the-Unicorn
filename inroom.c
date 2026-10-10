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

int cell_is_wall(int x,int y) {
  if (player.map[x][y] == 21) return -1;
  if (player.map[x][y] == 22) return -1;
  if (player.map[x][y] == 23) return -1;
  if (player.map[x][y] == 33) return -1;
  return 0;
  }

int wall_in_block(int sx,int sy,int ex,int ey) {
  int x,y;
  for (y=sy; y<=ey; y++)
    for (x=sx; x<=ex; x++)
      if (x > 0 && x < 100 && y > 0 && y < 100)
        if (cell_is_wall(x,y)) return -1;
  return 0;
  }

int in_room(int x,int y) {
  int wallCount;
  if (player.gateway == '*') return 0;
  wallCount = 0;
  if (wall_in_block(x-1,y-1,x,y)) wallCount++;
  if (wall_in_block(x,y-1,x+1,y)) wallCount++;
  if (wall_in_block(x-1,y,x,y+1)) wallCount++;
  if (wall_in_block(x,y,x+1,y+1)) wallCount++;
  return (wallCount != 4) ? -1 : 0;
  }

