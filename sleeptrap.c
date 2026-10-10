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

void sleep_trap() {
  int amt;
  char flag;
  flag = ' ';
  if (has_intrinsic(A_NOSL)) flag = '*';
  if (has_intrinsic(A_RSSL) && u_random(100) < 50) flag = '*';
  if (player.effect[PE_SLEEP] > 0) flag = '*';
  if (flag == ' ') {
      amt = (player.diff+player.d_level) + u_random(player.diff+player.d_level / 3);
      if (has_intrinsic(A_RSSL)) amt /= 2;
      if (amt < 1) amt = 1;
      player.effect[PE_SLEEP] = amt;
      clear_prompt();
      prompt("Slept!!");
      show_player();
    }
  }

