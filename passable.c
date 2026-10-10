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

int passable(int x,int y,char monstPass) {
  int flag;
  flag = -1;
  if (x<1 || x>99 || y<1 || y>99) return 0;
  if (player.map[x][y] == 21) flag = 0;
  if (player.map[x][y] == 22) flag = 0;
  if (player.map[x][y] == 30) flag = 0;
  if (player.map[x][y] == 33) flag = 0;
  if (player.map[x][y] == 3) flag = 0;
  if (player.map[x][y] == 4) flag = 0;
  if (player.map[x][y] < 0 && monstPass != 'Y') flag = 0;
  if (player.map[x][y] < 0 && monstPass == 'Y') flag = -2;
  if (player.map[x][y] == 38) flag = 0;
  if (player.map[x][y] == 39) flag = 0;
  if (player.map[x][y] == 41) flag = 0;
  return flag;
  }

