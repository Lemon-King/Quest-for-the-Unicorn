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

void show_sm_map() {
  int x,y;
  int color;
  pixel = 0;
  setfillstyle(1,0);
  bar(421,241,620,442);
  for (x=1; x<=100; x++)
    for (y=1; y<=100; y++)
      if (player.known[x][y] != 0 && in_arena != 'Y') {
        color = 8;
        switch (player.map[x][y]) {
          case  1:color = 10; break;
          case  2:color = 2; break;
          case  3:color = 6; break;
          case  4:color = 1; break;
          case  7:color = 8; break;
          case  9:color = 5; break;
          case 20:color = 2; break;
          case 21:color = 4; break;
          case 22:color = 14; break;
          case 23:color = 14; break;
          case 24:color = 3; break;
          case 25:color = 11; break;
          case 38:color = 12; break;
          case 39:color = 1; break;
          case 41:color = 9; break;
          }
#ifdef USEX
        XDrawPoint(display,window,colors[color],419+x*2,240+y*2);
        XDrawPoint(display,window,colors[color],420+x*2,240+y*2);
        XDrawPoint(display,window,colors[color],419+x*2,241+y*2);
        XDrawPoint(display,window,colors[color],420+x*2,241+y*2);
        XDrawPoint(display,screen,colors[color],419+x*2,240+y*2);
        XDrawPoint(display,screen,colors[color],420+x*2,240+y*2);
        XDrawPoint(display,screen,colors[color],419+x*2,241+y*2);
        XDrawPoint(display,screen,colors[color],420+x*2,241+y*2);
        XFlush(display);
#else
        putpixel(419+x*2,240+y*2,color);
        putpixel(420+x*2,240+y*2,color);
        putpixel(419+x*2,241+y*2,color);
        putpixel(420+x*2,241+y*2,color);
#endif
        }
  }

