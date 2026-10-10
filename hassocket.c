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

int item_has_socket_effect(OBJECT_REC* item,int effect) {
  if (item == NULL) return 0;
  if (item->otype == O_NONE) return 0;
  effect /= 100;
  if (item->num_sockets > 0 && (item->sockets[0] / 100 == effect)) return -1;
  if (item->num_sockets > 1 && (item->sockets[1] / 100 == effect)) return -1;
  if (item->num_sockets > 2 && (item->sockets[2] / 100 == effect)) return -1;
  return 0;
  }

int has_socket(int intr) {
  int i;
  for (i=1; i<=19; i++) {
    if (player.invent[i].otype != O_NONE) {
      if ((i==I_NCK1 || i==I_NCK2) &&
          player.invent[i].otype == O_NECK &&
          item_has_socket_effect(&(player.invent[i]),intr)) return -1;
      else if ((i==I_RNG1 || i==I_RNG2 || i==I_RNG3 || i==I_RNG4) &&
          player.invent[i].otype == O_RING &&
          item_has_socket_effect(&(player.invent[i]),intr)) return -1;
      else if (i==I_SHLD &&
          player.invent[i].otype == O_SHLD &&
          item_has_socket_effect(&(player.invent[i]),intr)) return -1;
      else if (i==I_ARMR &&
          player.invent[i].otype == O_ARMR &&
          item_has_socket_effect(&(player.invent[i]),intr)) return -1;
      else if (i==I_ROBE &&
          player.invent[i].otype == O_ROBE &&
          item_has_socket_effect(&(player.invent[i]),intr)) return -1;
      else if (i==I_BOOT &&
          player.invent[i].otype == O_BOOT &&
          item_has_socket_effect(&(player.invent[i]),intr)) return -1;
      else if (i==I_HELM &&
          player.invent[i].otype == O_HELM &&
          item_has_socket_effect(&(player.invent[i]),intr)) return -1;
      else if (i==I_RHND &&
               player.invent[i].otype != O_EDGE &&
               player.invent[i].otype != O_POLE &&
               player.invent[i].otype != O_DAGR &&
               player.invent[i].otype != O_BLNT &&
               player.invent[i].otype != O_BOW  &&
               item_has_socket_effect(&(player.invent[i]),intr)) return -1;
      }
    }
  return 0;
  }

