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

void take_time() {
  int time;
  double mult;
  double skill;
  if (player.mount == 0) time = 15;
  if (player.mount != 0) time = 10;
  if (player.peg != 0) time = 5;
  if (player.mount != 0 && u_random(25) == 5) add_skill(SK_RIDE,1);
  switch (player.map[player.x][player.y]) {
    case 2:
           if (player.mount == 0) time = 20;
           if (player.mount != 0) time = 13;
           if (player.peg != 0) time = 5;
           break;
    case 3:
           if (player.mount == 0) time = 45;
           if (player.mount != 0) time = 30;
           if (player.peg != 0) time = 5;
           break;
    case 6:
           if (player.mount == 0) time = 25;
           if (player.mount != 0) time = 15;
           if (player.peg != 0) time = 5;
           break;
    case 8:
           if (player.mount == 0) time = 20;
           if (player.mount != 0) time = 13;
           if (player.peg != 0) time = 5;
           break;
    case 9:
           if (player.mount == 0) time = 30;
           if (player.mount != 0) time = 20;
           if (player.peg != 0) time = 5;
           break;
    }
  mult = 4.0;
  if (player.map[player.x][player.y] == 4 && player.peg == 0) {
    skill = get_skill(SK_BOAT);
    skill /= 100;
    skill *= 2;
    mult -= skill;
    }
  else if (player.mount != 0) {
    skill = get_skill(SK_RIDE);
    skill /= 100;
    skill *= 2;
    mult -= skill;
    }
  time = (int)(time*mult);
  player.min = player.min+time;
  while (player.min>59) {
    player.min = player.min-60;
    player.hour = player.hour+1;
    if (!has_intrinsic(A_FOOD)) player.health--;
    show_side();
    if (player.hour == 24) {
      player.hour = 0;
      player.day = player.day+1;
      if (player.day == 32) {
      new_month();
        }
      }
    }
  }

