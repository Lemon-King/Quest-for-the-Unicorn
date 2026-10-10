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

void missile(int damage,int elem,int radius) {
  int  i;
  target(100,0,-1);
  i = 90 + (player.level * 10) + player.skill[SK_MAGIC] / 2;
  aoe(target_x,target_y,E_DAMG,0,damage,elem,radius,M_MAGIC,i);
  return;
  }

