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

void add_ingredient(int num,char* buffer) {
  OBJECT_REC* item;
  if (num != 0) {
    item = find_linked_item(num);
    if (item == NULL) return;
    strcat(buffer,"\n");
    strcat(buffer,"  ");
    strcat(buffer,item->name);
    }
  }

void recipe_string(int num,char* buffer) {
  int i;
  OBJECT_REC* item;
  strcpy(buffer,"Recipe: ");
  if (recipes[num].object == 0) return;
  item = find_linked_item(recipes[num].object);
  if (item == NULL) return;
  strcat(buffer,item->name);
  strcat(buffer,"\nCraft Item:\n");
  if (recipes[num].craft_item != 0) {
    item = find_linked_item(recipes[num].craft_item);
    if (item == NULL) return;
    strcat(buffer,"  ");
    strcat(buffer,item->name);
    } else {
    strcat(buffer,"  none");
    }
  strcat(buffer,"\nIngredients:");
  add_ingredient(recipes[num].object1,buffer);
  add_ingredient(recipes[num].object2,buffer);
  add_ingredient(recipes[num].object3,buffer);
  add_ingredient(recipes[num].object4,buffer);
  add_ingredient(recipes[num].object5,buffer);
  add_ingredient(recipes[num].object6,buffer);
  add_ingredient(recipes[num].object7,buffer);
  add_ingredient(recipes[num].object8,buffer);
  add_ingredient(recipes[num].object9,buffer);
  add_ingredient(recipes[num].object10,buffer);
  for (i=0; i<strlen(buffer); i++)
    if (buffer[i] == '_') buffer[i] = ' ';
  }

