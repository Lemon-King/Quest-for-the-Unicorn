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

void show_messages() {
  int i;
  setfillstyle(1,0);
  bar(420,94,640,230);
  for (i=0; i<NUM_MSG; i++) {
    setcolor(msg_clr[i]);
    outtextxy(425,110+i*12,messages[i]);
    }
  }

