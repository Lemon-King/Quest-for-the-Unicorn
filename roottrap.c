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

void root_trap() {
  if (player.effect[PE_ROOT] > 0) return;
  player.effect[PE_ROOT] = 2 * ((player.diff+player.d_level) + u_random(player.diff+player.d_level / 3));
  clear_prompt();
  prompt("Cannot move!!");
  show_player();
  }

