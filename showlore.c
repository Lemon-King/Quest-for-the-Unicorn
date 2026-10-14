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

void show_message(char* message) {
  int   i;
  char* cr;
  int x,y;
  int space;
  int size;
  char last;
  x = 120; y = 100; space = 25; size = 30;
  while (strlen(message) != 0) {
    cr = strchr(message,'\n');
    if (cr != NULL && cr-message < size) {
      *cr = 0;
      write_font(x,y,0,message);
      cr++;
      strcpy(message,cr);
      y += 19;
      }
    else if (strlen(message) < size) {
      write_font(x,y,0,message);
      strcpy(message,"");
      }
    else {
      i = size;
      while (i > 0 && message[i] != ' ') i--;
      last = message[i];
      message[i] = 0;
      write_font(x,y,0,message);
      message[i] = last;
      i++;
      y += 19;
      strcpy(message,message+i);
      }
    }
  }

void show_lore(int item) {
  int i;
  char key;
  MESSAGE general;
  i = item;
  general = lore[i];
  player.lore[i] = -1;
  graphmode();
  display_scroll();
  setcolor(0);
  show_message(general.message);
  key = inkey();
  }

