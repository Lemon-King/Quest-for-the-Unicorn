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

void nap() {
  char invoke[20];
  char buffer[80];
  char key;
  word_counter = 120;
  strcpy(invoke,"");
  msg("How long ? _",11);
  key = 0;
  while (key != 13) {
    key = inkey();
    if (key > 31) {
      invoke[strlen(invoke) + 1] = 0;
      invoke[strlen(invoke)] = key;
      sprintf(buffer,"How long ? %s_",invoke);
      msg(buffer,-11);
      }
    if (key == 8 && strlen(invoke) > 0) {
      invoke[strlen(invoke) - 1] = 0;
      sprintf(buffer,"How long ? %s_",invoke);
      msg(buffer,-11);
      }
    }
  sprintf(buffer,"How long ? %s",invoke);
  msg(buffer,-11);
  player.effect[PE_SLEEP] = mval(invoke) * 60;
  if (player.effect[PE_SLEEP] > 0) napping = '*';
  clear_prompt();
  show_player();
  }

