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

char* fix_ability(int ability) {
  static STRING32 ret;
  if (player.ability[ability] >= -99 && player.ability[ability] <= -5)
    strcpy(ret," Pathetic");
  if (player.ability[ability] >= -4 && player.ability[ability] <= -3)
    strcpy(ret,"      Bad");
  if (player.ability[ability] >= -2 && player.ability[ability] <= -1)
    strcpy(ret,"     Poor");
  if (player.ability[ability] == 0)
    strcpy(ret,"  Average");
  if (player.ability[ability] >= 1 && player.ability[ability] <= 2)
    strcpy(ret,"     Fair");
  if (player.ability[ability] >= 3 && player.ability[ability] <= 4)
    strcpy(ret,"     Good");
  if (player.ability[ability] >= 5 && player.ability[ability] <= 99)
    strcpy(ret,"Excellent");
  return ret;
  }

