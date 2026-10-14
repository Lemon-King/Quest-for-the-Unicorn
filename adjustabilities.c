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

void adjust_abilities() {
  if (player.stat[1] == 3) player.ability[1] = -3;
  if (player.stat[1] >= 4 && player.stat[1] <= 5) player.ability[1] = -2;
  if (player.stat[1] >= 6 && player.stat[1] <= 10) player.ability[1] = -1;
  if (player.stat[1] >= 11 && player.stat[1] <= 15) player.ability[1] = 0;
  if (player.stat[1] >= 16 && player.stat[1] <= 17) player.ability[1] = 1;
  if (player.stat[1] >= 18 && player.stat[1] <= 21) player.ability[1] = 2;
  if (player.stat[1] >= 22 && player.stat[1] <= 99) player.ability[1] = 3;

  if (player.stat[2] >= 3 && player.stat[2] <= 4) player.ability[1] -= 2;
  if (player.stat[2] >= 5 && player.stat[2] <= 8) player.ability[1] -= 1;
  if (player.stat[2] >= 16 && player.stat[2] <= 20) player.ability[1] += 1;
  if (player.stat[2] >= 21 && player.stat[2] <= 22) player.ability[1] += 2;
  if (player.stat[2] >= 23 && player.stat[2] <= 24) player.ability[1] += 3;
  if (player.stat[2] >= 25 && player.stat[2] <= 99) player.ability[1] += 4;

  if (player.stat[2] >= 3 && player.stat[2] <= 4) player.ability[2] = -3;
  if (player.stat[2] >= 5 && player.stat[2] <= 6) player.ability[2] = -2;
  if (player.stat[2] >= 7 && player.stat[2] <= 7) player.ability[2] = -1;
  if (player.stat[2] >= 8 && player.stat[2] <= 14) player.ability[2] = 0;
  if (player.stat[2] >= 15 && player.stat[2] <= 16) player.ability[2] = 1;
  if (player.stat[2] >= 17 && player.stat[2] <= 20) player.ability[2] = 2;
  if (player.stat[2] >= 21 && player.stat[2] <= 24) player.ability[2] = 3;
  if (player.stat[2] >= 25 && player.stat[2] <= 99) player.ability[2] = 4;

  if (player.stat[1] >= 3 && player.stat[1] <= 4) player.ability[3] = -2;
  if (player.stat[1] >= 5 && player.stat[1] <= 7) player.ability[3] = -1;
  if (player.stat[1] >= 8 && player.stat[1] <= 14) player.ability[3] = 0;
  if (player.stat[1] >= 15 && player.stat[1] <= 17) player.ability[3] = 1;
  if (player.stat[1] >= 18 && player.stat[1] <= 21) player.ability[3] = 2;
  if (player.stat[1] >= 22 && player.stat[1] <= 23) player.ability[3] = 3;
  if (player.stat[1] >= 24 && player.stat[1] <= 99) player.ability[3] = 4;

  if (player.stat[3] >= 3 && player.stat[3] <= 4) player.ability[4] = -2;
  if (player.stat[3] >= 5 && player.stat[3] <= 7) player.ability[4] = -1;
  if (player.stat[3] >= 8 && player.stat[3] <= 14) player.ability[4] = 0;
  if (player.stat[3] >= 15 && player.stat[3] <= 17) player.ability[4] = 1;
  if (player.stat[3] >= 18 && player.stat[3] <= 21) player.ability[4] = 2;
  if (player.stat[3] >= 22 && player.stat[3] <= 23) player.ability[4] = 3;
  if (player.stat[3] >= 24 && player.stat[3] <= 99) player.ability[4] = 4;

  if (player.stat[5] >= 3 && player.stat[5] <= 4) player.ability[5] = -2;
  if (player.stat[5] >= 5 && player.stat[5] <= 7) player.ability[5] = -1;
  if (player.stat[5] >= 8 && player.stat[5] <= 14) player.ability[5] = 0;
  if (player.stat[5] >= 15 && player.stat[5] <= 17) player.ability[5] = 1;
  if (player.stat[5] >= 18 && player.stat[5] <= 21) player.ability[5] = 2;
  if (player.stat[5] >= 22 && player.stat[5] <= 23) player.ability[5] = 3;
  if (player.stat[5] >= 24 && player.stat[5] <= 99) player.ability[5] = 4;

  if (player.stat[2] >= 3 && player.stat[2] <= 3) player.ability[6] = -4;
  if (player.stat[2] >= 4 && player.stat[2] <= 5) player.ability[6] = -3;
  if (player.stat[2] >= 6 && player.stat[2] <= 7) player.ability[6] = -2;
  if (player.stat[2] >= 8 && player.stat[2] <= 10) player.ability[6] = -1;
  if (player.stat[2] >= 11 && player.stat[2] <= 16) player.ability[6] = 0;
  if (player.stat[2] >= 17 && player.stat[2] <= 22) player.ability[6] = 1;
  if (player.stat[2] >= 23 && player.stat[2] <= 25) player.ability[6] = 2;
  if (player.stat[2] >= 26 && player.stat[2] <= 99) player.ability[6] = 3;

  if (player.stat[2] >= 3 && player.stat[2] <= 3) player.ability[7] = -5;
  if (player.stat[2] >= 4 && player.stat[2] <= 5) player.ability[7] = -4;
  if (player.stat[2] >= 6 && player.stat[2] <= 7) player.ability[7] = -3;
  if (player.stat[2] >= 8 && player.stat[2] <= 10) player.ability[7] = -2;
  if (player.stat[2] >= 11 && player.stat[2] <= 12) player.ability[7] = -1;
  if (player.stat[2] >= 13 && player.stat[2] <= 17) player.ability[7] = 0;
  if (player.stat[2] >= 18 && player.stat[2] <= 21) player.ability[7] = 1;
  if (player.stat[2] >= 22 && player.stat[2] <= 23) player.ability[7] = 2;
  if (player.stat[2] >= 24 && player.stat[2] <= 25) player.ability[7] = 3;
  if (player.stat[2] >= 26 && player.stat[2] <= 99) player.ability[7] = 4;

  if (player.stat[2] >= 3 && player.stat[2] <= 3) player.ability[8] = -3;
  if (player.stat[2] >= 4 && player.stat[2] <= 5) player.ability[8] = -2;
  if (player.stat[2] >= 6 && player.stat[2] <= 9) player.ability[8] = -1;
  if (player.stat[2] >= 10 && player.stat[2] <= 17) player.ability[8] = 0;
  if (player.stat[2] >= 18 && player.stat[2] <= 21) player.ability[8] = 1;
  if (player.stat[2] >= 22 && player.stat[2] <= 24) player.ability[8] = 2;
  if (player.stat[2] >= 25 && player.stat[2] <= 99) player.ability[8] = 3;

  if (player.stat[4] >= 3 && player.stat[4] <= 4) player.ability[9] = -2;
  if (player.stat[4] >= 5 && player.stat[4] <= 8) player.ability[9] = -1;
  if (player.stat[4] >= 9 && player.stat[4] <= 15) player.ability[9] = 0;
  if (player.stat[4] >= 16 && player.stat[4] <= 19) player.ability[9] = 1;
  if (player.stat[4] >= 20 && player.stat[4] <= 22) player.ability[9] = 2;
  if (player.stat[4] >= 23 && player.stat[4] <= 24) player.ability[9] = 3;
  if (player.stat[4] >= 25 && player.stat[4] <= 99) player.ability[9] = 4;

  if (player.stat[3] >= 3 && player.stat[3] <= 3) player.ability[9] -= 5;
  if (player.stat[3] >= 4 && player.stat[3] <= 4) player.ability[9] -= 4;
  if (player.stat[3] >= 5 && player.stat[3] <= 5) player.ability[9] -= 3;
  if (player.stat[3] >= 6 && player.stat[3] <= 6) player.ability[9] -= 2;
  if (player.stat[3] >= 7 && player.stat[3] <= 7) player.ability[9] -= 1;
  if (player.stat[3] >= 19 && player.stat[3] <= 20) player.ability[9] += 1;
  if (player.stat[3] >= 21 && player.stat[3] <= 23) player.ability[9] += 2;
  if (player.stat[3] >= 24 && player.stat[3] <= 99) player.ability[9] += 3;

  if (player.stat[4] >= 3 && player.stat[4] <= 4) player.ability[10] = -2;
  if (player.stat[4] >= 5 && player.stat[4] <= 7) player.ability[10] = -1;
  if (player.stat[4] >= 8 && player.stat[4] <= 14) player.ability[10] = 0;
  if (player.stat[4] >= 15 && player.stat[4] <= 17) player.ability[10] = 1;
  if (player.stat[4] >= 18 && player.stat[4] <= 21) player.ability[10] = 2;
  if (player.stat[4] >= 22 && player.stat[4] <= 23) player.ability[10] = 3;
  if (player.stat[4] >= 24 && player.stat[4] <= 99) player.ability[10] = 4;
  }
