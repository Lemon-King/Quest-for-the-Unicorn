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

double item_cost(OBJECT_REC* item) {
  double ret;
  ret = item->cost;
  if (item->charges > 0) ret += (item->charges * item->costp);
  if (item->plus > 0) ret += (item->plus * item->costp);
  if (ret < item->cost) ret = item->cost;
  return ret;
  }

