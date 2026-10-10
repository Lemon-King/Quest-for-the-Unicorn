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

int find_path(int start_x,int start_y,int end_x,int end_y,int count) {
  int directions[10];
  int i;
  int best_dir;
  int best_count;
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
  return '5';





  if (count == 0) best_path = PATH_MAX;
  if (start_x == end_x && start_y == end_y) {
    best_path = count;
    return 0;
    }
  for (i=0; i<count; i++)
    if (path_x[i] == start_x && path_y[i] == start_y) return -1;
  count++;
  if (count > best_path) return -1;
  if (count >= PATH_MAX) return -1;
  path_x[count-1] = start_x;
  path_y[count-1] = start_y;
  for (i=1; i<=9; i++) directions[i] = -2;
  for (i=1; i<=9; i++)
    if (i != 5) {
      switch(i) {
        case 1: xdir = -1; ydir = +1; break;
        case 2: ydir = +1; break;
        case 3: xdir = +1; ydir = +1; break;
        case 4: xdir = -1; break;
        case 6: xdir = +1; break;
        case 7: xdir = -1; ydir = -1; break;
        case 8: ydir = -1; break;
        case 9: xdir = +1; ydir = -1; break;
        }
      if (passable(start_x + xdir,start_y + ydir,'N') == 0) 
        directions[i] = -1;
      else
        directions[i] = find_path(start_x + xdir,start_y + ydir,end_x,end_y,count);
      }
  best_count = PATH_MAX;
  best_dir = 5;
  for (i=2; i<=9; i+=2) {
    if (directions[i] >= 0 && directions[i] < best_count) {
      best_dir = i;
      best_count = directions[i];
      }
    }
  for (i=1; i<=9; i+=2) {
    if (i != 5 ) {
      if (directions[i] >= 0 && directions[i] < best_count) {
        best_dir = i;
        best_count = directions[i];
        }
      }
    }
  if (count == 1) return best_dir + '0';
  if (best_dir == 5) return -1;
  return best_count+1;
  }

