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

void new_pawn() {
  int i,j;
  for (i=1; i<=9; i++)
    for (j=1; j<=10; j++) {
      player.pawn[i][j] = objects[u_random(NO_OF_OBJECTS) + 1];
      while (u_random(200) >= player.pawn[i][j].rarity) {
        player.pawn[i][j] = objects[u_random(NO_OF_OBJECTS) + 1];
        }
      }
  }

