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

void compress() {
  int i,j;
  char flag;
  for (i=32; i>=2; i--)
    if (player.pack_q[i] != 0) {
      flag = ' ';
      for (j=1; j<i; j++)
        if (flag == ' ' && player.pack[j] == player.pack[i]) {
          player.pack_q[j] += player.pack_q[i];
          player.pack_q[i] = 0;
          flag = '*';
          }
      }
  }

