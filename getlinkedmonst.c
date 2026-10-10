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

int get_linked_monster(int n) {
  int i;
  i = 0;
  while (monsters[i].number < 999) {
    if (monsters[i].number == n) return i;
    i++;
    }
  return -1;
  }

