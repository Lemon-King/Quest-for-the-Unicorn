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

void remove_land_player() {
  int x,y;
  int color;
  x = player.x; y = player.y;
  show_sprite(player.x-player.map_x,player.y-player.map_y,
              player.map[player.x][player.y]);
  color = 0;
  switch (player.map[x][y]) {
    case 1:color = 10; break;
    case 2:color = 2; break;
    case 3:color = 6; break;
    case 4:color = 1; break;
    case 5:color = 4; break;
    case 6:color = 3; break;
    case 7:color = 8; break;
    case 8:color = 14; break;
    case 9:color = 5; break;
    case 11:color = 4; break;
    case 17:color = 4; break;
    case 19:color = 6; break;
    }
  putpixel(419+x*2,240+y*2,color);
  putpixel(420+x*2,240+y*2,color);
  putpixel(419+x*2,241+y*2,color);
  putpixel(420+x*2,241+y*2,color);
  }

