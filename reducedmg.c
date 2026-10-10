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

int reduce_damage(int damage,int element) {
  double dmg;
  double reduction;
  dmg = damage;
  reduction = get_bonus(element);
  reduction += get_bonus(S_FCE);
  reduction /= 100.0;
  if (reduction > 0.85) reduction = 0.85;
  if (reduction < 0) reduction = 0;
  reduction = dmg * reduction;
  dmg = dmg - reduction;
  if (dmg < 0) dmg = 0;
  return (int)dmg;
  }

