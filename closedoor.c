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

void close_door() {
//  int xdir,ydir;
//  get_dir(&xdir,&ydir);
  int xdir,ydir;
  char dir;
  dir = item_dir(23);
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

  if (player.map[player.x+xdir][player.y+ydir] == 23) {
               player.map[player.x+xdir][player.y+ydir] = 22;
//               player.known[player.x+xdir][player.y+ydir] = 0;
               show_spot(player.x+xdir,player.y+ydir);
    }
  return;

  char key;
  prompt("Dir ?");
  key = ' ';
  while (key != '2' && key != '8' && key != '4' && key != '6') key = inkey();
  switch (key) {
    case '2':if (player.map[player.x][player.y+1] == 23) {
               player.map[player.x][player.y+1] = 22;
               player.known[player.x][player.y+1] = 0;
               show_spot(player.x,player.y+1);
               }
             break;
    case '8':if (player.map[player.x][player.y-1] == 23) {
               player.map[player.x][player.y-1] = 22;
               player.known[player.x][player.y-1] = 0;
               show_spot(player.x,player.y-1);
               }
             break;
    case '4':if (player.map[player.x-1][player.y] == 23) {
               player.map[player.x-1][player.y] = 22;
               player.known[player.x-1][player.y] = 0;
               show_spot(player.x-1,player.y);
               }
             break;
    case '6':if (player.map[player.x+1][player.y] == 23) {
               player.map[player.x+1][player.y] = 22;
               player.known[player.x+1][player.y] = 0;
               show_spot(player.x+1,player.y);
               }
             break;
    }
  clear_prompt();
  }

