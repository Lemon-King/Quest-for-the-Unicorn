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

void light_room() {
  int flag;
  int color;
  int min_x,max_x;
  int min_y,max_y;
  int x,y;
  if (player.gateway == '*') return;
  flag = -1;
  x = player.x; y = player.y;
  while (flag) flag = in_room(--x,y);
  min_x = x;
  flag = -1;
  x = player.x; y = player.y;
  while (flag) flag = in_room(++x,y);
  max_x = x;
  flag = -1;
  x = player.x; y = player.y;
  while (flag) flag = in_room(x,--y);
  min_y = y;
  flag = -1;
  x = player.x; y = player.y;
  while (flag) flag = in_room(x,++y);
  max_y = y;
  if (min_x < 1) min_x = 1;
  if (max_x > 99) max_x = 99;
  if (min_y < 1) min_y = 1;
  if (max_y > 99) max_y = 99;
  open_display();
  for (y=min_y; y<=max_y; y++)
    for (x=min_x; x<=max_x; x++)
      if (player.known[x][y] == 0) {
        player.known[x][y] = 1;
        show_spot(x,y);

        color = 8;
        switch (player.map[x][y]) {
          case  21:color = 4; break;
          case   7:color = 8; break;
          case  22:color = 14; break;
          case  23:color = 14; break;
          case   1:color = 10; break;
          case   4:color = 1; break;
          case  24:color = 3; break;
          case  25:color = 11; break;
          case  41:color = 9; break;
          case  38:color = 12; break;
          case  39:color = 1; break;
          case  20:color = 2; break;
          case   3:color = 6; break;
          case   9:color = 5; break;
          case   2:color = 2; break;
          }
//        plot(419+x*2,240+y*2,color);
//        plot(420+x*2,240+y*2,color);
//        plot(419+x*2,241+y*2,color);
//        plot(420+x*2,241+y*2,color);
        plot(smap_offset_x-2+x*2,smap_offset_y-1+y*2,color);
        plot(smap_offset_x-1+x*2,smap_offset_y-1+y*2,color);
        plot(smap_offset_x-2+x*2,smap_offset_y-0+y*2,color);
        plot(smap_offset_x-1+x*2,smap_offset_y-0+y*2,color);
        }
  close_display();
  }

