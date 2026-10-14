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

void do_blink() {
  int x,y;
  char flag;
  flag = ' ';
  while (flag == ' ') {
    x = player.x + u_random(12) - u_random(12);
    y = player.y + u_random(12) - u_random(12);
    if (x>1 && x<99 && y>1 && y<99 && player.map[x][y] == 7) flag = '*';
    }
  player.x = x; player.y = y;
  player.map_x = player.x-8;
  player.map_y = player.y-8;
  if (player.x<1) player.x = 1;
  if (player.y<1) player.y = 1;
  if (player.x>84) player.x = 84;
  if (player.y>84) player.y = 84;
  show_screen();
  }

