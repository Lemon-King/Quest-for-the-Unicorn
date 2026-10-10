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

void activate(int x,int y) {
  int i;
  int effect;
  if (player.map[x][y] == 901) {
    msg("Activating Altar",14);
    effect = u_random(90);
    if (effect < 10) special68();
    else if (effect < 20) special69();
    else if (effect < 30) special70();
    else if (effect < 40) special71();
    else if (effect < 45) {
      special8();
      special9();
      special22();
      special43();
      msg("You sense your surroundings",15);
      }
    else if (effect < 48) {
      special14();
      }
    else if (effect < 50) {
      special31(6);
      msg("You feel more skillful",15);
      }
    else if (effect < 55) {
      special61();
      special62();
      special63();
      }
    else if (effect < 60) special77();
    else if (effect < 65) special80();
    else if (effect < 75) special55();
    else if (effect < 80) special53();
    else if (effect < 90) {
      for (i=0;i<20;i++)
        if (player.invent[i].otype != 0) 
          player.invent[i].level = -1;
      for (i=0;i<33;i++)
        if (player.pack[i].otype != 0) 
          player.pack[i].level = -1;
      msg("Everything glows briefly",15);
      }
    player.map[x][y] = 902;
    }
  else if (player.map[x][y] == 902) {
    msg("Altar already used",14);
    }
  else if (player.map[x][y] == 903) {
    msg("Runestone already used",14);
    }
  else if (player.map[x][y] == 904) {
    player.cmana = get_mmana();
    player.map[x][y] = 903;
    show_side();
    }
  else if (player.map[x][y] == 905) {
    player.chp = get_mhp();
    player.map[x][y] = 903;
    show_side();
    }
  else if (player.map[x][y] == 906) {
    player.effect[PE_FIRE] = 10000;
    player.map[x][y] = 903;
    show_side();
    }
  else if (player.map[x][y] == 907) {
    player.effect[PE_PROT] = 10000;
    player.effect[PE_APROT] = 10;
    player.map[x][y] = 903;
    show_side();
    }
  else if (player.map[x][y] == 908) {
    player.effect[PE_LIGHT] = 20000;
    player.map[x][y] = 903;
    show_side();
    }
  else if (player.map[x][y] == 909) {
    player.effect[PE_LEV] = 5000;
    player.map[x][y] = 903;
    show_side();
    }
  else if (player.map[x][y] == 910) {
    player.effect[PE_HASTE] = 2000;
    player.map[x][y] = 903;
    show_side();
    }
  else msg("Nothing to activate",14);
  }

