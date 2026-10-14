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

int intrinsic_count(int intr) {
  int ret;
  int i;
  ret = 0;
  for (i=5; i<=6; i++)
    if (player.invent[i].otype != O_NONE &&
        player.invent[i].effect == E_INTR &&
        player.invent[i].control == intr) ret++;
  for (i=13; i<=19; i++)
    if (player.invent[i].otype != O_NONE &&
        player.invent[i].effect == E_INTR &&
        player.invent[i].control == intr) ret++;
  if (intr == A_SPD && player.effect[PE_HASTE] != 0) ret++;
  if (intr == A_RFIR && player.effect[PE_FIRE] != 0) ret++;
  if (intr == A_LEV) ret += has_intrinsic(A_SPLV);
  if (intr == A_SPD) ret += has_intrinsic(A_SPLV);
  return ret;
  }

