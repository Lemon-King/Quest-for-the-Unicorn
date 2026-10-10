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

void do_get() {
  int i;
  OBJECT_REC* item;
  char buffer[80];
  if (player.map[player.x][player.y] >= 2000 &&
      player.map[player.x][player.y] < 3000) {
    saveScreen();
    i = 0;
    while (i < NO_OF_LORE) {
      if (lore[i].link == player.map[player.x][player.y]-1000) {
        show_lore(i);
        player.lore[i] = -1;
        player.quests[player.dungeon_number] = 'Y';
        }
      i++;
      }
    restoreScreen();
    }
  else if (player.map[player.x][player.y] >= 1000 &&
      player.map[player.x][player.y] < 2000) {
    item=&(player.map_objects[player.map[player.x][player.y] - 1000]);
    player.map[player.x][player.y] = currentFloor;
    saveScreen();
    inventory(item);
    restoreScreen();
    item->otype = O_NONE;
    }
  else if (player.map[player.x][player.y] == 84) {
    player.torch++;
    player.map[player.x][player.y] = currentFloor;
    i = 0;
    show_spot(player.x,player.y);
    show_player();
    }
  else if (player.map[player.x][player.y] == 79) {
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
  else {
    saveScreen();
    inventory(NULL);
    restoreScreen();
    }
  show_spot(player.x,player.y);
  show_player();
  auto_detect();
  }

