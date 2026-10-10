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

int los(int x1,int y1,int x2,int y2,char monstPass) {
  int x,y;
  int ret;
  int difx;
  int dify;
  int count;
  int dir;
  ret = -1;
  if (abs(x1-x2) < 2 && abs(y1-y2) < 2) ret = -1;
  else if (x1 == x2) {
    if (y1 > y2) { y = y1; y1 = y2; y2 = y; }
    y1++;
    y2--;
    for (y=y1; y<=y2; y++)
      if (passable(x1,y,monstPass) == 0) return 0;
    }
  else if (y1 == y2) {
    if (x1 > x2) { x = x1; x1 = x2; x2 = x; }
    x1++;
    x2--;
    for (x=x1; x<=x2; x++)
      if (passable(x,y1,monstPass) == 0) return 0;
    }
  else {
    difx = abs(x1 - x2);
    dify = abs(y1 - y2);
    count = 0;
    if (difx > dify) {
      if (x1 > x2) {
        x = x1; x1 = x2; x2 = x;
        y = y1; y1 = y2; y2 = y;
        }
      dir = (y1 < y2) ? 1 : -1;
      x1++;
      x2--;
      y = y1;
      count = dify;
      for (x=x1; x<=x2; x++) {
        count += dify;
        if (count >= difx) {
          count -= difx;
          y += dir;
          }
        if (passable(x,y,monstPass) == 0) return 0;
        }
      } else {
      if (y1 > y2) {
        x = x1; x1 = x2; x2 = x;
        y = y1; y1 = y2; y2 = y;
        }
      dir = (x1 < x2) ? 1 : -1;
      y1++;
      y2--;
      x = x1;
      count = difx;
      for (y=y1; y<=y2; y++) {
        count += difx;
        if (count >= dify) {
          count -= dify;
          x += dir;
          }
        if (passable(x,y,monstPass) == 0) return 0;
        }
      }
    }
  return ret;
  }

