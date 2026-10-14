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

void pack_item(OBJECT_REC* item,int line) {
  char flag;
  int  slot;
  OBJECT_REC  pitem;
  slot = 1;
  if (line > 3) pitem = player.invent[line - 3];
    else pitem = *item;
  flag = ' ';
  while (flag == ' ') {
    if (player.pack[slot].otype == O_NONE) flag = '*';
    if (flag != '*') slot++;
    if (slot == 33) flag = '#';
    }
  if (flag != '#') {
    player.pack[slot] = pitem;
    if (line > 3) player.invent[line - 3].otype = O_NONE;
      else item->otype = O_NONE;
    if (line == 5) player.weapon = 0;
    gotoxy(5,2); textcolor(12);
    txt_write("Packed      ");
    show_inventory(item);
    }
  else {
    gotoxy(5,2); textcolor(12);
    txt_write("Pack full!!!");
    }
  }

