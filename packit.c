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

void pack_it(int floor) {
  int  i;
  int  ct;
  char buffer[40];
  char flag;
  int  slot;
  int  pitem;
  OBJECT_REC* it;
  slot = 1;
  pitem = player.map[player.x][player.y] - 1000;
  flag = ' ';
  while (flag == ' ') {
    if (player.pack[slot].otype == O_NONE) flag = '*';
    if (flag != '*') slot++;
    if (slot == 33) flag = '#';
    }
  if (flag != '#') {
    if (player.map_objects[pitem].rarity > 2500) stats.counts[STAT_COMMONS]++;
    if (player.map_objects[pitem].rarity > 100 && player.map_objects[pitem].rarity <= 2500) stats.counts[STAT_UNCOMMONS]++;
    if (player.map_objects[pitem].rarity > 50 && player.map_objects[pitem].rarity <= 100) stats.counts[STAT_RARES]++;
    if (player.map_objects[pitem].rarity > 5 && player.map_objects[pitem].rarity <= 50) stats.counts[STAT_VERY_RARES]++;
    if (player.map_objects[pitem].rarity > 0 && player.map_objects[pitem].rarity < 5) stats.counts[STAT_ULTRA_RARES]++;

    if (player.map_objects[pitem].otype != O_NONE && player.map_objects[pitem].effect != E_MUTA && player.map_objects[pitem].level >= 0) {
    if (player.map_objects[pitem].plus >= 0 && player.map_objects[pitem].rarity > 2500) player.map_objects[pitem].level = -player.map_objects[pitem].level;
    else if (player.map_objects[pitem].plus >= 0 && player.map_objects[pitem].rarity > 500 && (u_random(100)-get_skill(7)*5) < 25) player.map_objects[pitem].level = -player.map_objects[pitem].level;
    else if (player.map_objects[pitem].plus >= 0 && player.map_objects[pitem].rarity > 100 && (u_random(1000)-get_skill(7)*10) < 25) player.map_objects[pitem].level = -player.map_objects[pitem].level;
    else if (player.map_objects[pitem].plus >= 0 && player.map_objects[pitem].rarity > 5 && (u_random(10000)-get_skill(7)*15) < 25) player.map_objects[pitem].level = -player.map_objects[pitem].level;
    else if (player.map_objects[pitem].plus >= 0 && player.map_objects[pitem].rarity > 0 && (u_random(100000)-get_skill(7)*20) < 25) player.map_objects[pitem].level = -player.map_objects[pitem].level;
    }

  if (player.map_objects[pitem].rarity > 0) {
    it = &(player.map_objects[pitem]);
    i = 0;
    while (trophies[i].criteria_type < 999) {
      if (trophies[i].criteria_type == TC_PICKT) {
        if (it->otype == trophies[i].control[0]) stats.counts[trophies[i].control[2]]++;
        if (trophies[i].control[3] > 0)
          if (it->otype == trophies[i].control[3]) stats.counts[trophies[i].control[5]]++;
        }
      if (trophies[i].criteria_type == TC_PICKI) {
        if (it->link == trophies[i].control[0]) stats.counts[trophies[i].control[2]]++;
        if (trophies[i].control[3] > 0)
          if (it->link == trophies[i].control[3]) stats.counts[trophies[i].control[5]]++;
        }
      if (trophies[i].criteria_type == TC_PICKR) {
        if (it->link >= trophies[i].control[0] && it->link <= trophies[i].control[1]) {
          stats.counts[trophies[i].control[2]] |= (1 << (it->link - trophies[i].control[0]));
          }
        }
      i++;
      }
    }





    player.pack[slot] = player.map_objects[pitem];
    clear_prompt();
    msg("Packed     ",14);
    player.map[player.x][player.y] = floor;
    show_spot(player.x,player.y);
    ct = 0;
    for (i=1; i<=32; i++)
      if (player.pack[i].otype != O_NONE) ct++;
    sprintf(buffer,"Pack contains %d items",ct);
    msg(buffer,15);
    show_player();
    }
  else {
    clear_prompt();
    msg("Pack full !!!",14);
    }
  }

