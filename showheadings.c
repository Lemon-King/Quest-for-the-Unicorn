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

void show_headings() {
  char buffer[80];
  setcolor(0);
  settextstyle(0,0,1);
  outtextxy(148,452,player.d_name);
  sprintf(buffer,"%d",player.diff);
  outtextxy(10,452,buffer);
  setcolor(14);
  outtextxy(450,10,"Level  :");
  outtextxy(450,20,"Date   :");
  outtextxy(450,30,"HP     :");
  outtextxy(450,40,"Mana   :");
  outtextxy(450,50,"Level  :");
  }

