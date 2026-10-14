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

void go_ship() {
  if (player.inship != ' ') {
    player.inship = ' ';
    player.map[player.x][player.y] = 12;
    show_spot(player.x,player.y);
    player.ship_x = player.x;
    player.ship_y = player.y;
    player.ship_r = player.region;
    }
  else if (player.map[player.x][player.y] == 12) {
    player.inship = '*';
    player.map[player.x][player.y] = 4;
    }
  show_player();
  }

