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

void show_messages() {
  int i;
  setfillstyle(1,0);
  bar(screen_width-220,94,screen_width,100 + NUM_MSG * MESSAGE_HEIGHT);
  for (i=0; i<NUM_MSG; i++) {
    setcolor(msg_clr[i]);
    while (strlen(messages[i]) < 22) strcat(messages[i]," ");
  if (strlen(messages[i]) > 22) messages[i][21] = 0;
#ifdef ASCII
    outtext_xy(TEXT_GRID_WIDTH - 24,11+i,messages[i]);
#else
    outtextxy(screen_width-215,110+i*12,messages[i]);
#endif
    }
  }

