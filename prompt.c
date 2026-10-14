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

void prompt(char* display) {
  msg(display,10);
return;
  setfillstyle(1,0);
  bar(0,460,479,500);
  setcolor(14);
  settextstyle(0,0,1);
  outtextxy(1,470,display);
  }

