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

void do_exchange(OBJECT_REC* item,int line) {
  OBJECT_REC temp;
/*
  if (line-3 == I_RHND && player.invent[line-3].plus < 0) {
    if (is_weapon(&(player.invent[I_RHND]))) return;
    }
  if (line-3 == I_LHND && player.invent[line-3].plus < 0) {
    if (is_weapon(&(player.invent[I_LHND]))) return;
    }
  if (line-3 == I_LHND && is_weapon(item)) {
    if (get_skill(SK_COMBAT) < 25) return;
    if (is_weapon(&(player.invent[I_RHND])) == 0) return;
    if (player.invent[I_RHND].otype == O_EDGE && get_skill(SK_EDGE) < 25) return;
    if (player.invent[I_RHND].otype == O_DAGR && get_skill(SK_EDGE) < 25) return;
    if (player.invent[I_RHND].otype == O_POLE && get_skill(SK_POLE) < 25) return;
    if (player.invent[I_RHND].otype == O_BLNT && get_skill(SK_BLNT) < 25) return;
    if (player.invent[I_RHND].otype == O_BOW  && get_skill(SK_MISSILE) < 25) return;
    if (item->otype == O_EDGE && get_skill(SK_EDGE) < 25) return;
    if (item->otype == O_DAGR && get_skill(SK_EDGE) < 25) return;
    if (item->otype == O_POLE && get_skill(SK_POLE) < 25) return;
    if (item->otype == O_BLNT && get_skill(SK_BLNT) < 25) return;
    if (item->otype == O_BOW  && get_skill(SK_MISSILE) < 25) return;
    }
  if (line-3 == I_RHND && is_weapon(item) && is_weapon(&(player.invent[I_LHND]))) {
    if (player.invent[I_LHND].otype == O_EDGE && get_skill(SK_EDGE) < 25) return;
    if (player.invent[I_LHND].otype == O_DAGR && get_skill(SK_EDGE) < 25) return;
    if (player.invent[I_LHND].otype == O_POLE && get_skill(SK_POLE) < 25) return;
    if (player.invent[I_LHND].otype == O_BLNT && get_skill(SK_BLNT) < 25) return;
    if (player.invent[I_LHND].otype == O_BOW  && get_skill(SK_MISSILE) < 25) return;
    if (item->otype == O_EDGE && get_skill(SK_EDGE) < 25) return;
    if (item->otype == O_DAGR && get_skill(SK_EDGE) < 25) return;
    if (item->otype == O_POLE && get_skill(SK_POLE) < 25) return;
    if (item->otype == O_BLNT && get_skill(SK_BLNT) < 25) return;
    if (item->otype == O_BOW  && get_skill(SK_MISSILE) < 25) return;
    }
  if (line-3 == I_NCK1 ||
      line-3 == I_NCK2 ||
      line-3 >= I_SHLD) {
    if (player.invent[line-3].plus < 0) return;
    }
*/
  if (inv_valid(item,line-3) != 'Y') return;
  temp = *item;
  *item = player.invent[line - 3];
  player.invent[line - 3] = temp;
  show_inventory(item);
  }

