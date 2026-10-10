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

int set_trap(int n) {
  int x,y;
  int xdir,ydir;
  get_dir(&xdir,&ydir);
  x = player.x + xdir;
  y = player.y + ydir;
  if (player.map[x][y] == currentFloor) {
    player.map[x][y] = 950 + n;
    show_map();
    show_player();
    return -1;
    }
  return 0;
  }

