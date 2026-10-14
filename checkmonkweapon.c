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

void check_monk_weapon() {
  if (player.invent[2].otype == O_NONE) player.weapon = player.level * 2 + 3;
  else if (player.invent[2].otype == O_DAGR)
    player.weapon = player.invent[2].damage/8;
  else if (player.invent[2].otype == O_EDGE)
    player.weapon = player.invent[2].damage/8;
  else if (player.invent[2].otype == O_POLE)
    player.weapon = player.invent[2].damage/4;
  else if (player.invent[2].otype == O_BOW)
    player.weapon = player.invent[2].damage/4;
  else player.weapon = 0;
  player.armour = player.level * 2 + 5;
  if (player.invent[11].otype != O_NONE || 
      player.invent[12].otype != O_NONE) player.armour = 0;
  }

