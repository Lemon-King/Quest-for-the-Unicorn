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

void show_inventory(OBJECT_REC* item) {
  int i;
  textcolor(3);
    gotoxy(25,3);
    if (item != NULL && item->otype != O_NONE) {
      txt_write(get_name(item));
      } 
    else txt_write("                               ");
    for (i=4; i<=22; i++) {
      gotoxy(25,i);
      if (player.invent[i-3].otype != O_NONE)
        txt_write(get_name(&(player.invent[i-3])));
      else txt_write("                               ");
      }
  }

