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

void title() {
  char   key;
  double scale;
  scale = 1.3714;
  setcolor(14);
  settextstyle(4,0,4);
  outtextxy(290,trunc(20*scale),"Quest");
  settextstyle(4,0,2);
  setcolor(2);
  outtextxy(285,trunc(60*scale),"for the");
  settextstyle(4,0,4);
  setcolor(14);
  outtextxy(285,trunc(80*scale),"Unicorn");
  settextstyle(4,0,2);
  setcolor(4);
  outtextxy(288,trunc(115*scale),VERSION);
  settextstyle(4,0,3);
  setcolor(9);
  outtextxy(268,trunc(135*scale),"by Mike Riley");
  settextstyle(0,0,1);
  setcolor(15);
  outtextxy(100,trunc(175*scale),
    "This program is copyright by Michel H. Riley and may be copied, modified,");
  outtextxy(100,trunc(185*scale),
    "and distributed so long as this title screen is not modified or removed.");
  outtextxy(100,trunc(195*scale),
    "This program may not be used for commercial purposes without the express");
  outtextxy(100,trunc(205*scale),
    "written permission from the author.");
  outtextxy(230,trunc(330*scale),"Press <ENTER> to continue");
  key = ' ';
  while (key != 13) {
    key = inkey();
    }
  }

