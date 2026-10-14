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

void take_time() {
  int time;
  if (player.mount == 0) time = 15;
  if (player.mount != 0) time = 10;
  if (player.peg != 0) time = 5;
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
  time = time*4;
  player.min = player.min+time;
  while (player.min>59) {
    player.min = player.min-60;
    player.hour = player.hour+1;
    player.health = player.health-1;
    show_side();
    if (player.hour == 24) {
      player.hour = 0;
      player.day = player.day+1;
      if (player.day == 32) {
      new_month();
/*
        player.day = 1;
        player.month = player.month+1;
        new_pawn();
        player.interest = player.bank * .005;
        player.bank += player.interest;
        if (player.month == 13) {
          player.month = 1;
          player.cav_paid = 'N';
          player.age = player.age+1;
          }
*/
        }
      }
    }
  }

