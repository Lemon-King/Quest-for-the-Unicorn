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

int magic_adjust(int n) {
  double armor;
  double dmg;
  dmg = n;
  armor = get_armour();
  armor /= 1000;
  armor += get_magic_resistance();
  if (armor > 0.7) armor = 0.7;
  dmg -= (dmg * armor);
  return (int)dmg;
  }

