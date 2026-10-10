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

void show_sprite(int x,int y,int sprt) {
  if (x<1 || x>100 || y<1 || y>100) return;
  if (sprt >= 2000 && sprt <2100) sprt = 88;
  if (sprt >= 600 && sprt <700) sprt = 41;
  if (sprt >= 800 && sprt <900) sprt = 7;
  if (sprt >= 520 && sprt <=535) sprt = 28;
  if (sprt == 536) sprt = 350;
#ifdef ASCII
  putimage(10+25*x,10+27*y,select_sprite(sprt),0);
#else
  putimage(-15+25*x,-16+27*y,select_sprite(sprt),0);
#endif
  }

