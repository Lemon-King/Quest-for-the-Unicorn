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

void scale_monster(NPC_REC* monster, int scale) {
  int    i;
  double d;
  i = (monster->hp / monster->level) * scale;
  monster->hp += i;
  i = (monster->mana / monster->level) * scale;
  monster->mana += i;
  i = (monster->attack / monster->level) * scale;
  monster->attack += i;
  i = (monster->defense / monster->level) * scale;
  monster->defense += i;
  d = (monster->exp / monster->level) * scale;
  monster->exp += d;
  d = (monster->exp_hp / monster->level) * scale;
  monster->exp_hp += d;
  monster->level += scale;
  }

void multiply_monster(NPC_REC* monster, int scale) {
  monster->hp *= scale;
  monster->mana *= scale;
  monster->attack *= scale;
  monster->defense *= scale;
  monster->exp *= scale;
  monster->exp_hp *= scale;
  monster->level *= scale;
  }

