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

void show_sm_land() {
  int x,y;
  int color;
  pixel = 0;
  setfillstyle(1,0);
  bar(smap_offset_x,smap_offset_y,smap_offset_x+99,smap_offset_y+99);
  open_display();
  for (x=1; x<=100; x++)
    for (y=1; y<=100; y++) {
      color = 0;
      if (player.known[x][y] != 0) {
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
        }
      plot(screen_width-221+x*2,screen_height-240+y*2,color);
      plot(screen_width-220+x*2,screen_height-240+y*2,color);
      plot(screen_width-221+x*2,screen_height-239+y*2,color);
      plot(screen_width-220+x*2,screen_height-239+y*2,color);
      }
    close_display();
  }

