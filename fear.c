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

void fear(int radius) {
  int  x,y;
  int  tx,ty;
  int  i;
  NPC_REC* monster;
  if (radius == 0) {
    target(80,-1,-1);
    tx = target_x;
    ty = target_y;
    } else {
    tx = player.x;
    ty = player.y;
    }
  for (x=tx-radius; x<= tx+radius; x++)
    for (y=ty-radius; y<=ty+radius; y++) {
      monster = get_monster(x,y);
    if (monster != NULL) {
      i=50+5*(player.level-monster->level);
      if ((monster->special & MS_AMAGIC) == MS_AMAGIC) i=0;
      if (u_random(100) < i) {
        clear_prompt();
        prompt("SCARED!!!");
        if (in_sight(x,y) == '*') {
          show_sprite(x-player.map_x,y-player.map_y,80);
          delay(delay_hit);
          show_spot(x,y);
          }
          monster->fear=player.level + u_random(5*(player.level-monster->level));
        }
      else {
        clear_prompt();
        prompt("Fizzle. . . ");
        }
        }
    }

  }


