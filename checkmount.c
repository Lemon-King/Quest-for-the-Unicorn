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

void check_mount() {
  int i;
  player.mount = 0; player.peg = 0;
  for (i=1; i<=5; i++)
    if (player.party[i].hp > 0) {
      if ((player.party[i].special & MS_FLY) != 0 &&
          (player.party[i].special & MS_MOUNT) != 0) player.peg = 1;
      if ((player.party[i].special & MS_MOUNT) != 0) player.mount = 1;
      }
  }

