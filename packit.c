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

void pack_it(int floor) {
  int  i;
  int  ct;
  char buffer[40];
  char flag;
  int  slot;
  int  pitem;
  slot = 1;
  pitem = player.map[player.x][player.y] - 1000;
  flag = ' ';
  while (flag == ' ') {
    if (player.pack[slot].otype == O_NONE) flag = '*';
    if (flag != '*') slot++;
    if (slot == 33) flag = '#';
    }
  if (flag != '#') {
    player.pack[slot] = player.map_objects[pitem];
    clear_prompt();
    msg("Packed     ",14);
    player.map[player.x][player.y] = floor;
    show_spot(player.x,player.y);
    ct = 0;
    for (i=1; i<=32; i++)
      if (player.pack[i].otype != O_NONE) ct++;
    sprintf(buffer,"Pack now contains %d items",ct);
    msg(buffer,15);
    show_player();
    }
  else {
    clear_prompt();
    msg("Pack full !!!",14);
    }
  }

