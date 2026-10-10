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

void blind_trap() {
  int i;
  i = (player.diff + player.d_level) * 5;
  i += u_random((player.diff+player.d_level) * 5);
  player.effect[PE_BLIND] += i;
  clear_prompt();
  msg("Bright flash of light!",11);
  show_side();
  show_map();
  }

