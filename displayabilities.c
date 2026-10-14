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

void display_abilities() {
  int i;
  for (i=1; i<11; i++) {
    gotoxy(65,i);
    if (player.ability[i] >= -99 && player.ability[i] <= -5) {
      textcolor(12);
      txt_write("Pathetic");
      }
    if (player.ability[i] >= -4 && player.ability[i] <= -3) {
      textcolor(4);
      txt_write("Bad");
      }
    if (player.ability[i] >= -2 && player.ability[i] <= -1) {
      textcolor(5);
      txt_write("Poor");
      }
    if (player.ability[i] == 0) {
      textcolor(14);
      txt_write("Average");
      }
    if (player.ability[i] >= 1 && player.ability[i] <= 2) {
      textcolor(1);
      txt_write("Fair");
      }
    if (player.ability[i] >= 3 && player.ability[i] <= 4) {
      textcolor(9);
      txt_write("Good");
      }
    if (player.ability[i] >= 5 && player.ability[i] <= 99) {
      textcolor(3);
      txt_write("Excellent");
      }
    }
  }

