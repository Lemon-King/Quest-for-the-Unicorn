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

int can_see() {
  if (player.effect[PE_BLIND] > 0) return 0;
  if (in_upland == 'Y') return -1;
  if (player.effect[PE_LIGHT] != 0) return -1;
  if (player.in_city == 'Y') return -1;
  if (has_intrinsic(A_INFRA)) return -1;
  return 0;
  }

