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

void open_door() {
  char key;
  prompt("Dir ?");
  key = ' ';
  while (key != '2' && key != '8' && key != '4' && key != '6') key = inkey();
  switch (key) {
    case '2':if (player.map[player.x][player.y+1] == 22 ||
                 player.map[player.x][player.y+1] == 33) {
               player.map[player.x][player.y+1] = 23;
               player.known[player.x][player.y+1] = 0;
               show_spot(player.x,player.y+1);
               }
             break;
    case '8':if (player.map[player.x][player.y-1] == 22 ||
                 player.map[player.x][player.y-1] == 33) {
               player.map[player.x][player.y-1] = 23;
               player.known[player.x][player.y-1] = 0;
               show_spot(player.x,player.y-1);
               }
             break;
    case '4':if (player.map[player.x-1][player.y] == 22 ||
                 player.map[player.x-1][player.y] == 33) {
               player.map[player.x-1][player.y] = 23;
               player.known[player.x-1][player.y] = 0;
               show_spot(player.x-1,player.y);
               }
             break;
    case '6':if (player.map[player.x+1][player.y] == 22 ||
                 player.map[player.x+1][player.y] == 33) {
               player.map[player.x+1][player.y] = 23;
               player.known[player.x+1][player.y] = 0;
               show_spot(player.x+1,player.y);
               }
             break;
    }
  clear_prompt();
  }

