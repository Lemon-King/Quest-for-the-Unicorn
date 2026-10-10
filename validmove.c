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

char valid_move(int x,int y) {
  int i;
  char flag;
  flag = '*';
  if (player.map[x][y] == 3) flag = ' ';
  if (player.map[x][y] == 4) flag = ' ';
  if (player.map[x][y] == 16) flag = ' ';
  if (player.map[x][y] == 18) flag = ' ';
  if (player.map[x][y] == 20) flag = ' ';
  if (player.map[x][y] == 21 && player.effect[PE_ETHER] <= 0) flag = ' ';
  if (player.map[x][y] == 22 && player.effect[PE_ETHER] <= 0) flag = ' ';
  if (player.map[x][y] == 30 && player.effect[PE_ETHER] <= 0) flag = ' ';
  if (player.map[x][y] == 33 && player.effect[PE_ETHER] <= 0) flag = ' ';
  if (player.map[x][y] == 143) flag = ' ';
  if (player.map[x][y] == 176) flag = ' ';
  if (player.map[x][y] == 178) flag = ' ';
  if (player.map[x][y] >= 600 && player.map[x][y] <700) {
    i = player.level;
    if (i < 1) i = 1;
    player.map[x][y] -= i;
    if (player.map[x][y] < 600) {
      player.map[x][y] = currentFloor;
      if (in_sight(x,y) == '*') show_spot(x,y);
      }
    else
      flag = ' ';
    }
  if (x<1 || x>100 || y<1 || y>100) flag = ' ';
  if (player.inship != ' ') {
    flag = ' ';
    if (player.map[x][y] == 4) flag = '*';
    }
  return flag;
  } /* char valid(int x,int y) */

