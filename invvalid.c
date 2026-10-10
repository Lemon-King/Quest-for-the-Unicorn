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

char inv_valid(OBJECT_REC* item,int line) {
  char ret;
  char classValid;
  ret = 'Y';
  if (line == I_RHND && is_weapon(&(player.invent[I_RHND])) && player.invent[I_RHND].plus < 0) ret = ' ';
  if (line == I_LHND && is_weapon(&(player.invent[I_LHND])) && player.invent[I_LHND].plus < 0) ret = ' ';
  if (line == I_NCK1 && player.invent[I_NCK1].otype != O_NONE && player.invent[I_NCK1].plus < 0) ret = ' ';
  if (line == I_NCK2 && player.invent[I_NCK2].otype != O_NONE && player.invent[I_NCK2].plus < 0) ret = ' ';
  if (line == I_RNG1 && player.invent[I_RNG1].otype != O_NONE && player.invent[I_RNG1].plus < 0) ret = ' ';
  if (line == I_RNG2 && player.invent[I_RNG2].otype != O_NONE && player.invent[I_RNG2].plus < 0) ret = ' ';
  if (line == I_RNG3 && player.invent[I_RNG3].otype != O_NONE && player.invent[I_RNG3].plus < 0) ret = ' ';
  if (line == I_RNG4 && player.invent[I_RNG4].otype != O_NONE && player.invent[I_RNG4].plus < 0) ret = ' ';
  if (line == I_ARMR && player.invent[I_ARMR].otype != O_NONE && player.invent[I_ARMR].plus < 0) ret = ' ';
  if (line == I_SHLD && player.invent[I_SHLD].otype != O_NONE && player.invent[I_SHLD].plus < 0) ret = ' ';
  if (line == I_ROBE && player.invent[I_ROBE].otype != O_NONE && player.invent[I_ROBE].plus < 0) ret = ' ';
  if (line == I_BOOT && player.invent[I_BOOT].otype != O_NONE && player.invent[I_BOOT].plus < 0) ret = ' ';
  if (line == I_HELM && player.invent[I_HELM].otype != O_NONE && player.invent[I_HELM].plus < 0) ret = ' ';
  if (item == NULL) return ret;
  if (item->otype == O_NONE) return ret;
  if (line == I_LHND && item->otype == O_POLE) return ' ';
  if (line == I_LHND && item->skill == SK_2HSWORD) return ' ';
  if (line == I_LHND && item->otype == O_BOW) return ' ';
  if (line == I_LHND && player.invent[I_RHND].otype == O_POLE) return ' ';
  if (line == I_LHND && player.invent[I_RHND].otype == O_EDGE && player.invent[I_RHND].skill == SK_2HSWORD) return ' ';
  if (item->align == 0 || item->align == 0x40000000) classValid = 'Y';
  else {
    classValid = ((item->align & (1 << player.class)) != 0) ? 'Y' : 'N';
    }
  if (line == I_RHND && is_weapon(item) ) {
    if (classValid != 'Y') ret = ' ';
    if (is_weapon(&(player.invent[I_LHND]))) {
      if (get_skill(player.invent[I_LHND].skill) < 25) ret = ' ';
      if (get_skill(item->skill) < 25) ret = ' ';
      }
    }
  if (line == I_LHND && is_weapon(item)) {
    if (get_skill(SK_COMBAT) < 25) ret = ' ';
    if (classValid != 'Y') ret = ' ';
    if (is_weapon(&(player.invent[I_RHND])) == 0) ret = ' ';
    if (get_skill(player.invent[I_RHND].skill) < 25) ret = ' ';
    if (get_skill(item->skill) < 25) ret = ' ';
    }
  if (line == I_NCK1) {
    if (item->otype != O_NECK) ret = ' ';
    if (classValid != 'Y') ret = ' ';
    }
  if (line == I_NCK2) {
    if (item->otype != O_NECK) ret = ' ';
    if (classValid != 'Y') ret = ' ';
    }
  if (line == I_SHLD) {
    if (item->otype != O_SHLD) ret = ' ';
    if (classValid != 'Y') ret = ' ';
    }
  if (line == I_ARMR) {
    if (item->otype != O_ARMR) ret = ' ';
    if (classValid != 'Y') ret = ' ';
    }
  if (line == I_RNG1) {
    if (item->otype != O_RING) ret = ' ';
    if (classValid != 'Y') ret = ' ';
    }
  if (line == I_RNG2) {
    if (item->otype != O_RING) ret = ' ';
    if (classValid != 'Y') ret = ' ';
    }
  if (line == I_RNG3) {
    if (item->otype != O_RING) ret = ' ';
    if (classValid != 'Y') ret = ' ';
    }
  if (line == I_RNG4) {
    if (item->otype != O_RING) ret = ' ';
    if (classValid != 'Y') ret = ' ';
    }
  if (line == I_ROBE) {
    if (item->otype != O_ROBE) ret = ' ';
    if (classValid != 'Y') ret = ' ';
    }
  if (line == I_BOOT) {
    if (item->otype != O_BOOT) ret = ' ';
    if (classValid != 'Y') ret = ' ';
    }
  if (line == I_HELM) {
    if (item->otype != O_HELM) ret = ' ';
    if (classValid != 'Y') ret = ' ';
    }
  return ret;
  }

