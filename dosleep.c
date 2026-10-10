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

void do_sleep() {
  int  x,y;
  int  mon;
  int  i;
  target(80,0,-1);
  x = target_x;
  y = target_y;
  if (player.map[x][y] < 0 || (player.map[x][y]>400 && player.map[x][y]<500)) {
    if (in_arena == 'Y') mon = player.map[x][y] - 400;
      else mon = player.map[x][y];
    if (in_arena == 'Y') i=50+5*(player.level-player.monster[mon][a_mon].level);
      else i=50+5*(player.level-player.monster[1][mon].level);
    if (in_arena == 'Y' && (player.monster[mon][a_mon].special & MS_AMAGIC) == MS_AMAGIC) i=0;
    if (in_arena != 'Y' && (player.monster[1][mon].special & MS_AMAGIC) == MS_AMAGIC) i=0;
    if (u_random(100) < i) {
      clear_prompt();
      prompt("SLEPT !!!");
      if (in_sight(x,y) == '*') {
        show_sprite(x-player.map_x,y-player.map_y,80);
        delay(delay_hit);
        show_spot(x,y);
        }
      if (in_arena != 'Y')
        player.monster[1][mon].sleep=u_random(2*(player.level-player.monster[1][mon].level));
      if (in_arena == 'Y')
        player.monster[mon][a_mon].sleep=u_random(2*(player.level-player.monster[mon][a_mon].level));
      }
    else {
      clear_prompt();
      prompt("Fizzle. . . ");
      }
    }
  }

