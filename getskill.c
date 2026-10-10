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

int get_skill(int num) {
  int ret;
  ret = player.skill[num] / 100000;
  ret += get_bonus((num + 30) * 100);
  if (ret > 99) ret = 99;
  return ret;
  }


