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

int compass(int suggest) {
  int dx,dy;
  int px,py;
  dx = (links[suggest].region % 4) * 100 + links[suggest].x;
  dy = (links[suggest].region / 4) * 100 + links[suggest].y;
  px = (player.region % 4) * 100 + player.x;
  py = (player.region / 4) * 100 + player.y;
  if (abs(px-dx)<4 && py<dy) return 92;
  if (abs(px-dx)<4 && py>dy) return 91;
  if (px<dx && abs(py-dy)<4) return 93;
  if (px>dx && abs(py-dy)<4) return 94;
  if (px<dx && py<dy) return 97;
  if (px>dx && py<dy) return 98;
  if (px<dx && py>dy) return 95;
  if (px>dx && py>dy) return 96;
  return 10;
  }

