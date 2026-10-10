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

void do_heal(int amount,int who) {
  char buffer[64];
  if (who == 0) {                                   /* player */
    player.chp += amount;
    if (player.chp > get_mhp()) player.chp = get_mhp();
    sprintf(buffer,"Healed %d",amount);
    msg(buffer,15);
    }
  if (who > 0) {                                    /* party member */
    player.party[who].hp += amount;
    if (player.party[who].hp > player.party[who].level * 9) player.party[who].hp = player.party[who].level * 9;
    }
  }

