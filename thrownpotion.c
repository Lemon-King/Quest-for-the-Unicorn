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

void thrown_potion(OBJECT_REC* item,int x,int y) {
  NPC_REC* monster;
  if (item == NULL) return;
  if (item->otype != O_POTN) return;
  monster = get_monster(x,y);
  if (monster == NULL) return;
  if (item->user_hp != 0) {
    monster->hp += item->charges * abs(u_random(item->user_hp));
    prompt("Healed !!!");
    }
  if (item->effect == E_DAMG) {
    monster->hp -= u_random(item->control);
    }
  if (item->effect == E_SPCL &&
      item->control == 60) {
    monster->sleep = item->charges * u_random(5) + 3;
    prompt("Slept !!!");
    }
  if (item->effect == E_SPCL &&
      item->control == 61) {
    monster->fear = item->charges * u_random(10);
    prompt("Scared !!!");
    }
  if (item->effect == E_SPCL &&
      item->control == 62) {
    monster->blind = item->charges * u_random(10);
    prompt("Blinded !!!");
    }
  if (item->effect == E_SPCL &&
      item->control == 63) {
    monster->confused = item->charges * u_random(10);
    prompt("Confused !!!");
    }
  if (item->effect == E_SPCL &&
      item->control == 64) {
    monster->confused = 0;
    }
  if (item->effect == E_SPCL &&
      item->control == 65) {
    monster->fear = 0;
    }
  if (item->effect == E_SPCL &&
      item->control == 66) {
    monster->blind = 0;
    }
  if (item->effect == E_SPCL &&
      item->control == 67) {
    monster->blind = 0;
    monster->fear = 0;
    monster->confused = 0;
    monster->poison = 0;
    }
  if (item->effect == E_POSN) {
    monster->poison = item->charges * u_random(20);
    prompt("Poisoned !!!");
    }
  }

