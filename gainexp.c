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

void gain_exp(double amt,int who) {
  int i;
  int sc;
  char buffer[80];
  int  count;
  double player_amt;
  double portion;
  if (has_intrinsic(A_DEXP)) amt *= 2;
  if (has_intrinsic(A_IEXP)) amt *= 1.15;
  amt *= get_exp_multiplier();
  count = 2;
  for (i=1; i<=5; i++)
    if (player.party[i].hp > 0) count++;
  portion  = amt / count;
  player_amt = portion;
  if (who == 0) player_amt += portion;
  player.exp += player_amt;
  sprintf(buffer,"Exp=%.0f",player_amt);
  msg(buffer,15);
  sc = (player.effect[PE_HEROIC] > 0) ? player.effect[PE_HEROIC] : 1;
  for (i=1; i<=5; i++)
    if (player.party[i].hp > 0) {
      player.party[i].exp += portion;
      if (i == who) player.party[i].exp += portion;
      if (player.party[i].exp >= needed(player.party[i].level +1)) {
        player.party[i].level++;
        player.party[i].attack = 2 * player.party[i].level * sc;
        player.party[i].defense = 2 * player.party[i].level * sc;
        if (player.party[i].mana > 0)
          player.party[i].mana = 25 * player.party[i].level;
        player.party[i].hp = player.party[i].level * 9 * sc;
        sprintf(buffer,"%s leveled",player.party[i].name);
        msg(buffer,15);
        }
      }
  }

