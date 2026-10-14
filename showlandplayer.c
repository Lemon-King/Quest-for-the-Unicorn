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

void show_land_player() {
  int x,y;
  x = player.x;
  y = player.y;
  if (player.inship == ' ')
    show_sprite(player.x-player.map_x,player.y-player.map_y,35);
  else
    show_sprite(player.x-player.map_x,player.y-player.map_y,12);
  putpixel(419+x*2,240+y*2,15);
  putpixel(420+x*2,240+y*2,15);
  putpixel(419+x*2,241+y*2,15);
  putpixel(420+x*2,241+y*2,15);
  }

