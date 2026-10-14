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

void poison_trap() {
  char flag;
  flag = ' ';
  if (player.class == 8) flag = '*';
  if (has_intrinsic(A_NOPS)) flag = '*';
  if (flag == ' ') {
      player.effect[PE_POISON] += (player.diff*5+player.d_level / 3) +
                      u_random(player.diff*5+player.d_level / 3);
      clear_prompt();
      msg("Poisoned!!",11);
      show_side();
    }
  }

