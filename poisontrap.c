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

void poison_trap() {
  int i;
  char flag;
  flag = ' ';
  if (classes[player.class-1].flags & CF_ROGUE) flag = '*';
  if (has_intrinsic(A_NOPS)) flag = '*';
  if (has_intrinsic(A_RSPS) && u_random(100) < 50) flag = '*';
  if (flag == ' ') {
      i = (player.diff * 5) + (player.d_level / 3);
      i += u_random((player.diff * 10) + (player.d_level / 2));
      if (has_intrinsic(A_RSPS)) i /= 2;
      if (i < 1) i = 1;
      player.effect[PE_POISON] += i;
      clear_prompt();
      msg("Poisoned dart!!!",13);
      stats.counts[STAT_POISONED]++;
      show_side();
    }
  }

