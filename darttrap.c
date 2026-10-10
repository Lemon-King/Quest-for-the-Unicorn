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

void dart_trap() {
  int i;
  i = u_random((player.diff+player.d_level / 3) * 5);
  stats_take_damage(i);
  player.chp -= i;
  if (player.chp < 0) player.chp = 0;
  clear_prompt();
  msg("Hit by a dart!",11);
  show_side();
  }

