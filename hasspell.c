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

byte has_spell(int check) {
  int i;
  byte ret;
  ret = 0;
  for (i=1; i<=55; i++)
    if (player.spell[i] == check) ret = i;
  return ret;
  }

