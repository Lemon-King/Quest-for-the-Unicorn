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

void make_n() {
  player.class = 11;
  strcpy(player.title,"Lord");
  if (player.sex == 'F') strcpy(player.title,"Lady");
  player.exp = 0;
  player.exp_next = 1e6;
  player.level = 1;
  }

