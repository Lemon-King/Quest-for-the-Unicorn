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

OBJECT_REC* find_linked_item(int lnk) {
  int i;
  i = 0;
  while (objects[i].otype <100) {
    if (objects[i].link == lnk) return &(objects[i]);
    i++;
    }
  return NULL;
  }

