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

void convert_recipe(OBJECT_REC* item) {
  OBJECT_REC* dest;
  if (item == NULL) return;
  if (item->effect != E_SPCL) return;
  if (item->control != 79) return;
  item->control = 110;
  item->control2 = u_random(recipe_count);
  item->level = -1;
  strcpy(item->name,"Recipe:");
  dest = find_linked_item(recipes[item->control2].object);
  if (dest == NULL) return;
  item->cost = dest->cost / 4;
  if (item->cost < 1) item->cost = 1;
  strcat(item->name,dest->name);
  }

