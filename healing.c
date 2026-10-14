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

void healing() {
  int amount;
  int i;
  int a,j;
  amount = player.skill[9] * 2;
  for (i=1; i<=5; i++) {
    if (strcmp(player.party[i].name,"Acolyte") == 0 ||
        strcmp(player.party[i].name,"Adept") == 0 ||
        strcmp(player.party[i].name,"Priest") == 0 ||
        strcmp(player.party[i].name,"Curate") == 0 ||
        strcmp(player.party[i].name,"Perfect") == 0 ||
        strcmp(player.party[i].name,"Canon") == 0 ||
        strcmp(player.party[i].name,"Lama") == 0 ||
        strcmp(player.party[i].name,"Patriarch") == 0 ||
        strcmp(player.party[i].name,"High Priest") == 0)
      if (amount < player.party[i].level * 5)
        amount = player.party[i].level * 5;
    }
  if (player.class == 2)
    if (amount <((player.level - 7) * 4)) amount = (player.level - 7) * 4;
  if (amount > 0) {
    h_count = 100;
    j = trunc(amount * 0.3);
    a = u_random(amount) + 1;
    if (a <j) a = j;
    player.chp += a;
    if (player.chp > player.mhp) player.chp = player.mhp;
    show_side();
    }
  }

