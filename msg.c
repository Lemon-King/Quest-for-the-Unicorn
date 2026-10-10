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

void scroll_msg() {
  int i;
  for (i=0; i<NUM_MSG-1; i++) {
    strcpy(messages[i],messages[i+1]);
    msg_clr[i] = msg_clr[i+1];
    }
  }

void msg(char* message,int color) {
  char buffer[256];
  char *pChar;
  char *next;
  strcpy(buffer,message);
  pChar = buffer;
  if (color >= 0) {
    scroll_msg();
    }
  color = abs(color);
  while (strlen(pChar) > 21) {
    next = pChar + 21;
    while (*next != ' ') next--;
    *next = 0;
    msg_clr[NUM_MSG-1] = color;
    strcpy(messages[NUM_MSG-1],pChar);
    pChar = next + 1;
    if (color >= 0) scroll_msg();
    }
  msg_clr[NUM_MSG-1] = color;
  strcpy(messages[NUM_MSG-1],pChar);
  show_messages();
  }

