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

void make_c() {
  player.class = 9;
  strcpy(player.title,"Armiger");
  player.exp = 0;
  player.exp_next = 5e5;
  player.level = 1;
  player.skill[2] += 5;
  player.skill[3] += 5;
  player.skill[11] += 5;
  player.skill[16] += 5;
  player.gold += 1000;
  player.cav_paid = 'Y';
  }

