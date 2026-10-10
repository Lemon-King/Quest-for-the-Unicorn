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

void show_inventory(OBJECT_REC* item) {
  int i;
  char buffer[256];
  textcolor(3);
    gotoxy(25,3);
    if (item != NULL && item->otype != O_NONE) {
      itemColor(item);
      txt_write("                                                ");
      gotoxy(25,3);
      strcpy(buffer,get_name(item));
      if (strlen(buffer) > 40) {
        buffer[40] = 0;
        strcat(buffer,"...");
        }
      txt_write(buffer);
      } 
    else txt_write("                                                ");
    for (i=4; i<=22; i++) {
      gotoxy(25,i);
      if (player.invent[i-3].otype != O_NONE) {
        itemColor(&(player.invent[i-3]));
        txt_write("                                                ");
        gotoxy(25,i);
        strcpy(buffer,get_name(&(player.invent[i-3])));
        if (strlen(buffer) > 40) {
          buffer[40] = 0;
          strcat(buffer,"...");
          }
        txt_write(buffer);
//        txt_write(get_name(&(player.invent[i-3])));
        }
      else txt_write("                                                ");
      }
  }

