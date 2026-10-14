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

void gain_exp(double amt) {
  char buffer[80];
  if (has_intrinsic(A_DEXP)) amt *= 2;
  if (has_intrinsic(A_IEXP)) amt *= 0.15;
  player.exp += amt;
  sprintf(buffer,"Exp=%.0f",amt);
  msg(buffer,15);
  }

