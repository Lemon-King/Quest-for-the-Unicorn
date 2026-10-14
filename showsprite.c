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

void show_sprite(int x,int y,int sprt) {
#ifdef DEBUG
  printf("%*sEntering: show_sprite(%d,%d,%d)\n",debug_tab,"",x,y,sprt);
  debug_tab += 2;
#endif
  if (sprt >= 2000 && sprt <2100) sprt = 88;
  if (sprt >= 600 && sprt <700) sprt = 41;
  if (sprt >= 800 && sprt <900) sprt = 7;
  if (sprt >= 520 && sprt <=535) sprt = 28;
  putimage(10+25*x,10+27*y,select_sprite(sprt),0);
#ifdef DEBUG
  printf("%*sExiting: show_sprite()\n",debug_tab,"");
  debug_tab -= 2;
#endif
  }

