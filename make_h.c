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

void make_h() {
  player.class = 8;
  strcpy(player.title,"Hierophant Druid");
  player.exp = 0;
  player.exp_next = 5e5;
  player.level = 1;
  }

