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

void healing() {
  int amount;
  int i;
  int a,j;
  OBJECT_REC* item;
  if (player.effect[PE_HCOUNT] <= 0) {
    amount = get_skill(SK_HEAL) * 2;
    if (amount == 0) amount = 1;
    for (i=1; i<=5; i++) {
      if (player.party[i].hp > 0 && (player.party[i].special & MS_HEALER) != 0)
        if (amount < player.party[i].level * 5)
          amount = player.party[i].level * 5;
      }
    if (classes[player.class-1].flags & CF_PALADIN)
      if (amount <((player.level - 7) * 4)) amount = (player.level - 7) * 4;
    if (amount > 0) {
      add_skill(SK_HEAL,1);
      player.effect[PE_HCOUNT] = HEAL_TIME;
      j = rcs_trunc(amount * 0.3);
      a = u_random(amount) + 1;
      if (a <j) a = j;
      do_heal(a,0);
      show_side();
      return;
      }
    }
   /* ***** If healing is still on cooldown, look for healing item ***** */
    item = NULL;
    for (i=1; i<11; i++)
      if (player.invent[i].otype != O_NONE) {
        if (player.invent[i].effect == E_HEAL) {
           item = &(player.invent[i]);
           i = 99;
          }
        else if (player.invent[i].user_hp != 0 && player.invent[i].otype != O_FOOD) {
          item = &(player.invent[i]);
          i = 99;
          }
        else if (player.invent[i].effect == E_SPCL &&
                 player.invent[i].control == 88) {
          item = &(player.invent[i]);
          i = 99;
          }
        }
    if (item == NULL) {
      for (i=1; i<=32; i++)
        if (player.pack[i].otype != O_NONE) {
          if (player.pack[i].effect == E_HEAL) {
            item = &(player.pack[i]);
            i = 99;
            }
          else if (player.pack[i].user_hp != 0 && player.pack[i].otype != O_FOOD) {
            item = &(player.pack[i]);
            i = 99;
            }
          else if (player.pack[i].effect == E_SPCL &&
                 player.pack[i].control == 88) {
            item = &(player.pack[i]);
            i = 99;
            }
        }
      }
    if (item == NULL) {
      msg("No healing item!!!",15);
      }
    else {
      if (item->charges != -1) item->charges--;
      if (item->charges == 0) {
        item->otype = O_NONE;
        }
      perform_effect(item);
      show_side();
      }

  }

