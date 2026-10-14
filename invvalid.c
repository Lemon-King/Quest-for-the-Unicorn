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

char inv_valid(OBJECT_REC* item,int line) {
  char ret;
  ret = 'Y';
  if (item == NULL) return ret;
  if (item->otype == O_NONE) return ret;
  if (line == I_NCK1 ||
      line == I_NCK2) {
    if (item->otype != O_NECK) ret = ' ';
    }
  if (line == I_SHLD) {
    if (item->otype != O_SHLD) ret = ' ';
    }
  if (line == I_ARMR) {
    if (item->otype != O_ARMR) ret = ' ';
    }
  if (line == I_RNG1 ||
      line == I_RNG2 ||
      line == I_RNG3 ||
      line == I_RNG4) {
    if (item->otype != O_RING) ret = ' ';
    }
  if (line == I_ROBE) {
    if (item->otype != O_ROBE) ret = ' ';
    }
  if (line == I_BOOT) {
    if (item->otype != O_BOOT) ret = ' ';
    }
  if (line == I_HELM) {
    if (item->otype != O_HELM) ret = ' ';
    }
  return ret;
  }

