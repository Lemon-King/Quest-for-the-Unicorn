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

void dead_monster(NPC_REC* mon,char tr,int x,int y) {
  int i;
  int lvl;
  int drop;
  if (mon->hp <= 0) {
    if (mon->level >= (player.level + 10)) stats.counts[STAT_HARD_MOB]++;
    stats.counts[STAT_MOBS_KILLED]++;
    if (strstr(mon->name,"Dragon") != NULL) stats.counts[STAT_DRAGONS]++;
    if (strcmp(mon->name,FINAL_BOSS) == 0) winner();
    mon->poison = 0;
    gain_exp(mon->exp,0);
    if (tr == 'Y') {
      i = u_random(100);
      if (i >=0 && i<=60) {
        lvl = mon->level;
        drop = place_object(lvl) + 1000;
        }
      else if (i >=61 && i<=80) drop = 79;
      else drop = 84;
      if (mon->prev == currentFloor) mon->prev = drop;
      else {
        can_drop(x,y,'N');
        if (drop_x > 0 && drop_y > 0) {
          player.map[drop_x][drop_y] = drop;
          show_spot(drop_x,drop_y);
          }
        }
      }
    player.map[x][y] = mon->prev;
    show_spot(x,y);
    if ((mon->special & MS_FRIENDLY) == MS_FRIENDLY) {
      player.align -= 20;
      if (player.align < 0) player.align = 0;
      }
    show_side();
    }
  }

