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

void say_word() {
  char invoke[33];
  char buffer[80];
  char key;
  int  x,y;
  word_counter = 120;
  strcpy(invoke,"");
  prompt("Say ? _");
  key = 0;
  while (key != 13) {
    key = inkey();
    if (key > 31) {
      invoke[strlen(invoke) + 1] = 0;
      invoke[strlen(invoke)] = key;
      sprintf(buffer,"Say ? %s_",invoke);
      clear_prompt();
      prompt(buffer);
      }
    if (key == 8 && strlen(invoke) > 0) {
      invoke[strlen(invoke)-1] = 0;
      sprintf(buffer,"Say ? %s_",invoke);
      clear_prompt();
      prompt(buffer);
      }
    }
  if (strcasecmp(invoke,"mintaal") == 0) {
    if (u_random(100) < 75) special(15);
      else go_bottom();
    }
  if (strcasecmp(invoke,"laatnim") == 0) {
    if (u_random(100) < 75) special(15);
      else go_bottom();
    }
  if (strcasecmp(invoke,"ilital") == 0) {
    if (u_random(100) < 75) go_up();
      else go_down();
    }
  if (strcasecmp(invoke,"latili") == 0) {
    if (u_random(100) < 75) go_down();
      else go_up();
    }
  if (strcasecmp(invoke,"indral") == 0) {
    if (u_random(100) < 90) player.effect[PE_POISON] = 0;
      else player.effect[PE_POISON] *= 2;
    }
  if (strcasecmp(invoke,"oraclal") == 0) {
    if (u_random(100) < 90) special(1);
    }
  if (strcasecmp(invoke,"illumina") == 0) {
    if (u_random(100) < 75) special(6);
      else player.effect[PE_LIGHT] = 0;
    }
  if (strcasecmp(invoke,"auraral") == 0) {
    if (u_random(100) < 25) special(42);
    }
  if (strcasecmp(invoke,"manatal") == 0) {
    if (u_random(100) < 50) special(19);
      else player.cmana = 0;
    }
  if (strcasecmp(invoke,"hurar") == 0) {
    if (u_random(100) < 60) special(3);
      else player.effect[PE_SLEEP] += 10;
    }
  if (strcasecmp(invoke,"fearaway") == 0) {
    if (u_random(100) < 60) special(36);
      else player.effect[PE_FEAR] *= 2;
    }
  if (strcasecmp(invoke,"blinkahl") == 0) {
    if (u_random(100) < 40) do_blink();
    }
  if (strcasecmp(invoke,"visorae") == 0) {
    if (u_random(100) < 50) {
      special(14);
      show_screen();
      }
    else {
      for (x=1; x<=100; x++)
        for (y=1; y<=100; y++) player.known[x][y] = 0;
      show_screen();
      }
    }
  clear_prompt();
  }
