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

int check_class_change(int class) {
  int i;
  int flag;
  flag = -1;
  i = 0;
  while (class_changes[i].from != 99) {
    if (class_changes[i].from == player.class &&
        class_changes[i].to == class) flag = i;
    i++;
    }
  if (flag < 0) return 0;
  if (player.level >= class_changes[flag].level) return -1;
  return 0;
  }

