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

void msg(char* message,int color) {
  int i;
  if (color >= 0) {
    for (i=0; i<NUM_MSG-1; i++) {
      strcpy(messages[i],messages[i+1]);
      msg_clr[i] = msg_clr[i+1];
      }
    }
  color = abs(color);
  msg_clr[NUM_MSG-1] = color;
  strcpy(messages[NUM_MSG-1],message);
  show_messages();
  }

