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

void show_map() {
  int x,y;
  setfillstyle(1,12);
//  bar(0,0,420,10); bar(0,443,420,453);       /* Top/bottom frame */
//  bar(0,0,10,453); bar(410,0,420,453);       /* Left/Right frame */
//  bar(419,230,630,240); bar(419,443,630,453); bar(621,230,630,453);

  bar(0,0,screen_width-220,10); bar(0,screen_height-37,screen_width-220,screen_height-27);       /* Top/bottom frame */
  bar(0,0,10,screen_height-27); bar(screen_width-230,0,screen_width-220,screen_height-27);       /* Left/Right frame */
  bar(screen_width-221,screen_height-250,screen_width-10,screen_height-240); 
  bar(screen_width-221,screen_height- 37,screen_width-10,screen_height- 27); 
  bar(screen_width- 19,screen_height-250,screen_width-10,screen_height- 27);

  setfillstyle(1,0);
//  bar(10,10,409,442);
  bar(10,10,TILES_X * tile_width+10,TILES_Y * tile_height+10);
  for (x=player.map_x; x<=player.map_x+TILES_X; x++)
    for (y=player.map_y; y<=player.map_y+TILES_Y; y++) 
      show_spot(x,y);
  show_headings();
  }

