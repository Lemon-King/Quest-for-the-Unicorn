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

int mana_cost(int mana) {
  double amount;
  int    cast;
  amount = 1.0 - ((player.skill[8]-4)/10);
  if (player.skill[8] < 5) amount = 1;
  cast = (int)(mana * amount);
  if (has_intrinsic(A_MANA)) cast /= 2;
/* trio of might */
/*
  if (player.found[11] != 0 && player.found[12] !=0 && player.found[13] != 0)
    cast /= 2;
*/
  if (cast < 1) cast = 1;
  return cast;
  }

