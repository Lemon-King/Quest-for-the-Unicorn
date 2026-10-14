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

void show_land() {
  int x,y;
  setfillstyle(1,12);
  bar(0,0,420,10); bar(0,443,420,453);
  bar(0,0,10,453); bar(410,0,420,453);
  bar(419,230,630,240); bar(419,443,630,453); bar(621,230,630,453);
  setfillstyle(1,0);
  bar(10,10,409,442);
  for (x=player.map_x; x<=player.map_x+15; x++)
    for (y=player.map_y; y<=player.map_y+15; y++)
      if (player.known[x][y] != 0)
        show_sprite(x-player.map_x,y-player.map_y,player.map[x][y]);
  show_headings();
  }

