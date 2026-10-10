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

void set_title() {
  int i;
  int flag;
  i=0;
  flag = -1;
  while (titles[i].class != 99) {
    if (titles[i].class == player.class &&
        player.level >= titles[i].level) flag = i;
    i++;
    }
  if (flag >= 0) {
    if (player.sex == 'F') strcpy(player.title,titles[flag].female);
      else strcpy(player.title,titles[flag].male);
    }
  }

