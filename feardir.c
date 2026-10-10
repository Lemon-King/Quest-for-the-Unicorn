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

char fear_dir(int start_x,int start_y,int end_x,int end_y) {
  int xdir,ydir;
  int x,y;
  x = start_x;
  y = start_y;
  xdir=0; ydir=0;
  if (x < end_x && y < end_y) { xdir = 1; ydir = 1; }
  if (x > end_x && y < end_y) { xdir = -1; ydir = 1; }
  if (x < end_x && y > end_y) { xdir = 1; ydir = -1; }
  if (x > end_x && y > end_y) { xdir = -1; ydir = -1; }
  if (x == end_x && y < end_y) ydir = 1;
  if (x == end_x && y > end_y) ydir = -1;
  if (x < end_x && y == end_y) xdir = 1;
  if (x > end_x && y == end_y) xdir = -1;
  xdir = -xdir;
  ydir = -ydir;
  if (passable(start_x+xdir,start_y+ydir,'N')) { x+=xdir; y+=ydir; }
  else if (passable(start_x+xdir,start_y,'N')) x+=xdir;
  else if (passable(start_x,start_y+ydir,'N')) y+=ydir;
  else if (xdir == 0 && passable(start_x+1,start_y+ydir,'N')) { x++; y+=ydir; }
  else if (xdir == 0 && passable(start_x-1,start_y+ydir,'N')) { x--; y+=ydir; }
  else if (ydir == 0 && passable(start_x+xdir,start_y-1,'N')) { x+=xdir; y--; }
  else if (ydir == 0 && passable(start_x+xdir,start_y+1,'N')) { x+=xdir; y++; }
  if (x<start_x && y>start_y) return '1';
  if (x==start_x && y>start_y) return '2';
  if (x>start_x && y>start_y) return '3';
  if (x<start_x && y==start_y) return '4';
  if (x>start_x && y==start_y) return '6';
  if (x<start_x && y<start_y) return '7';
  if (x==start_x && y<start_y) return '8';
  if (x>start_x && y<start_y) return '9';
  return ' ';

  }


