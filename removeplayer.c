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

void remove_player() {
  int x,y;
  byte color;
  x = player.x; y = player.y;
  if (player.known[player.x][player.y] != 0) show_spot(player.x,player.y);
    else show_sprite(x-player.map_x,y-player.map_y,10);
  color = 9;
  switch (player.map[x][y]) {
    case 21:color=4; break;
    case  7:color=8; break;
    case 22:color=14; break;
    case 23:color=14; break;
    case  1:color=10; break;
    case  2:color=2;  break;
    case  4:color=1;  break;
    case 24:color=3;  break;
    case 25:color=11; break;
    case 41:color=9; break;
    case 38:color=12; break;
    case 39:color=1; break;
    case 20:color=2; break;
    case  3:color=6; break;
    case  9:color=5; break;
    }
  putpixel(419+x*2,240+y*2,color);
  putpixel(420+x*2,240+y*2,color);
  putpixel(419+x*2,241+y*2,color);
  putpixel(420+x*2,241+y*2,color);
  }

