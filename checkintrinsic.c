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

int check_intrinsic(OBJECT_REC obj,int intr) {
  if (obj.otype == O_NONE) return 0;
  if (obj.effect != E_INTR) return 0;
  if (obj.control == intr) return -1;
  return 0;
  }

