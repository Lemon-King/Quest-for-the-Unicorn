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

void make_c() {
  int i;
  int flag;
  flag = -1;
  for (i=0; i<NUM_CLASSES; i++) if (classes[i].flags & CF_CAVALIER) flag = i;
  if (flag >= 0) {
    player.class = flag+1;
    player.exp = 0;
    player.exp_next = classes[flag].first_exp;
    player.level = 1;
    player.skill[2] += 500000;
    player.skill[3] += 500000;
    player.skill[11] += 500000;
    player.skill[16] += 500000;
    add_gold(1000);
    player.cav_paid = 'Y';
    set_title();
    }
  }

