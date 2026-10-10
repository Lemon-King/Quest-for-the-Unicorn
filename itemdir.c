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

/* ************************************************************* */
/* ***** Returns direction key if only 1 found, else space ***** */
/* ************************************************************* */
char item_dir(int item) {
  int count;
  char dir;
  dir = ' ';
  count = 0;
  if (item >= 0) {
    if (player.map[player.x-1][player.y] == item) { count++; dir = '4'; };
    if (player.map[player.x+1][player.y] == item) { count++; dir = '6'; };
    if (player.map[player.x][player.y-1] == item) { count++; dir = '8'; };
    if (player.map[player.x][player.y+1] == item) { count++; dir = '2'; };
    if (player.map[player.x-1][player.y-1] == item) { count++; dir = '7'; };
    if (player.map[player.x+1][player.y-1] == item) { count++; dir = '9'; };
    if (player.map[player.x-1][player.y+1] == item) { count++; dir = '1'; };
    if (player.map[player.x+1][player.y+1] == item) { count++; dir = '3'; };
    } else {
    if (player.map[player.x-1][player.y] < 0) { count++; dir = '4'; };
    if (player.map[player.x+1][player.y] < 0) { count++; dir = '6'; };
    if (player.map[player.x][player.y-1] < 0) { count++; dir = '8'; };
    if (player.map[player.x][player.y+1] < 0) { count++; dir = '2'; };
    if (player.map[player.x-1][player.y-1] < 0) { count++; dir = '7'; };
    if (player.map[player.x+1][player.y-1] < 0) { count++; dir = '9'; };
    if (player.map[player.x-1][player.y+1] < 0) { count++; dir = '1'; };
    if (player.map[player.x+1][player.y+1] < 0) { count++; dir = '3'; };
    }
  if (count > 1) dir = ' ';
  return dir;
  }

