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

void do_exchange(OBJECT_REC* item,int line) {
  OBJECT_REC temp;
  if (line-3 == I_RHND &&
      player.invent[line-3].plus < 0) {
    if (player.invent[2].otype == O_DAGR ||
        player.invent[2].otype == O_EDGE ||
        player.invent[2].otype == O_POLE ||
        player.invent[2].otype == O_BOW) return;
    }
  if (line-3 == I_NCK1 ||
      line-3 == I_NCK2 ||
      line-3 >= I_SHLD) {
    if (player.invent[line-3].plus < 0) return;
    }
  if (inv_valid(item,line-3) != 'Y') return;
  temp = *item;
  *item = player.invent[line - 3];
  player.invent[line - 3] = temp;
  show_inventory(item);
  }

