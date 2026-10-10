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

  void check_autos() {
    int i;
    if (auto_pickup_torch == 'Y') {
      if (player.map[player.x][player.y] == 84) {
        player.torch++;
        player.map[player.x][player.y] = currentFloor;
        i = 0;
        show_spot(player.x,player.y);
        show_player();
        msg("Picked up torch",7);
        }
      }
    if (auto_pickup_gold == 'Y') {
      if (player.map[player.x][player.y] == 79) {
        i = u_random(player.diff * 10 + player.d_level)+1;
        clear_prompt();
        sprintf(buffer,"Found %d Gold Pieces",i);
        msg(buffer,14);
        player.map[player.x][player.y] = currentFloor;
        add_gold(i);
        stats.counts[STAT_GOLD_LOOTED] += i;
        i = 0;
        show_spot(player.x,player.y);
        show_player();
        }
      }
    }

