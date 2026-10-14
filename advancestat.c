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

void advance_stat() {
  int i;
  i = 1 + u_random(6);
  if (u_random(100) < 40) {
    player.stat[i] ++;
    if (player.stat[i] > 26) player.stat[i] = 26;
    switch (i) {
      case 1:msg("Gained Strength",14); break;
      case 2:msg("Gained Dexterity",14); break;
      case 3:msg("Gained Constitution",14); break;
      case 4:msg("Gained Intelligence",14); break;
      case 5:msg("Gained Wisdom",14); break;
      case 6:msg("Gained Charisma",14); break;
      }
    }
  }

