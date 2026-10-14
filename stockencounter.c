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

void stock_encounter() {
  int j;
  byte x;
  int min;
  int max;
  char flag;
  int number;
  max = player.level / 3;
  min = max-6;
  if (min<1) min = 1;
  if (min>20) min = 20;
  if (max<min) max = min;
  number = player.level / 3;
  if (number<1) number = 1;
  if (number>5) number = 5;
  for (x=1; x<=5; x++)
    player.monster[x][1].hp = 0;
  for (j=1; j<=number; j++) {
    flag = ' ';
    while (flag == ' ') {
      player.monster[j][1] = monsters[u_random(NO_OF_MONSTERS)];
      if (player.monster[j][1].level>=min && player.monster[j][1].level<=max)
        flag = '*';
      if (player.monster[j][1].special>9) flag = ' ';
      }
    player.monster[j][1].hp = u_random(player.monster[j][1].hp)+1;
    player.monster[j][1].exp = player.monster[j][1].exp+
    player.monster[j][1].exp_hp*player.monster[j][1].hp;
    player.monster[j][1].prev = player.map[player.x][player.y];
    }
  }

