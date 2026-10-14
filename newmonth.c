/*
 *******************************************************************
 *** This software is copyright 1985-2007 by Michael H Riley     ***
 *** You have permission to use, modify, copy, and distribute    ***
 *** this software so long as this copyright notice is retained. ***
 *** This software may not be used in commercial applications    ***
 *** without express written permission from the author.         ***
 *******************************************************************
*/

#include "header.h"

void new_month() {
  int i;
  double p;
  player.day -= 31;
  player.month = player.month+1;
  new_pawn();
  player.interest = player.bank * .005;
  player.bank += player.interest;
  for (i=0; i<5; i++)
    if (player.houses[i].region != 0) {
      player.houses[i].interest = player.houses[i].mortgage * 0.005;
      player.houses[i].mortgage += player.houses[i].interest;
      p = player.houses[i].payment;
      if (p > player.houses[i].mortgage) p = player.houses[i].mortgage;
      if (p <= player.bank) {
        player.bank -= p;
        player.houses[i].mortgage -= p;
        } else {
        player.houses[i].region = 0;
        msg("House repossessed!!!",12);
        }
      }
  if (player.month == 13) {
    player.month = 1;
    player.cav_paid = 'N';
    player.age = player.age+1;
    }
  }

