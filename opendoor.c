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

void open_door() {
  int xdir,ydir;
  char dir;
  dir = item_dir(22);
  if (dir != ' ') {
    switch (dir) {
      case '1': xdir = -1; ydir = 1; break;
      case '2': xdir = 0; ydir = 1; break;
      case '3': xdir = 1; ydir = 1; break;
      case '4': xdir = -1; ydir = 0; break;
      case '5': xdir = 0; ydir = 0; break;
      case '6': xdir = 1; ydir = 0; break;
      case '7': xdir = -1; ydir = -1; break;
      case '8': xdir = 0; ydir = -1; break;
      case '9': xdir = 1; ydir = -1; break;
      }
    }
    else get_dir(&xdir,&ydir);
  if (player.map[player.x+xdir][player.y+ydir] == 22 ||
                 player.map[player.x+xdir][player.y+ydir] == 33) {
               player.map[player.x+xdir][player.y+ydir] = 23;
//               player.known[player.x+xdir][player.y+ydir] = 0;
               show_spot(player.x+xdir,player.y+ydir);
    }
  return;
  }

