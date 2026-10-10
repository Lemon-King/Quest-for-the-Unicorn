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

int is_weapon(OBJECT_REC* item) {
  if (item == NULL) return 0;
  if (item->otype == O_DAGR) return -1;
  if (item->otype == O_WAND) return -1;
  if (item->otype == O_EDGE) return -1;
  if (item->otype == O_BLNT) return -1;
  if (item->otype == O_BOW) return -1;
  if (item->otype == O_POLE) return -1;
  return 0;
  }

