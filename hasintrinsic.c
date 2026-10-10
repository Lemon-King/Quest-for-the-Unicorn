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

int has_intrinsic2(int intr) {
  int i;
  i = 0;
  while (class_traits[i].class != 99) {
    if (class_traits[i].class == player.class - 1 &&
        class_traits[i].level <= player.level &&
        class_traits[i].trait == intr) return -1;
    i++;
    }
  i = 0;
  while (race_traits[i].class != 99) {
    if (race_traits[i].class == player.race - 1 &&
        race_traits[i].level <= player.level &&
        race_traits[i].trait == intr) return -1;
    i++;
    }
  for (i=1; i<=19; i++) {
    if (player.invent[i].otype != O_NONE) {
      if ((i==I_NCK1 || i==I_NCK2) &&
          player.invent[i].otype == O_NECK &&
          player.invent[i].effect == E_INTR &&
          player.invent[i].control == intr) return -1;
      else if ((i==I_RNG1 || i==I_RNG2 || i==I_RNG3 || i==I_RNG4) &&
          player.invent[i].otype == O_RING &&
          player.invent[i].effect == E_INTR &&
          player.invent[i].control == intr) return -1;
      else if (i==I_SHLD &&
          player.invent[i].otype == O_SHLD &&
          player.invent[i].effect == E_INTR &&
          player.invent[i].control == intr) return -1;
      else if (i==I_ARMR &&
          player.invent[i].otype == O_ARMR &&
          player.invent[i].effect == E_INTR &&
          player.invent[i].control == intr) return -1;
      else if (i==I_ROBE &&
          player.invent[i].otype == O_ROBE &&
          player.invent[i].effect == E_INTR &&
          player.invent[i].control == intr) return -1;
      else if (i==I_BOOT &&
          player.invent[i].otype == O_BOOT &&
          player.invent[i].effect == E_INTR &&
          player.invent[i].control == intr) return -1;
      else if (i==I_HELM &&
          player.invent[i].otype == O_HELM &&
          player.invent[i].effect == E_INTR &&
          player.invent[i].control == intr) return -1;
      else if (i==I_RHND &&
               player.invent[i].otype != O_NECK &&
               player.invent[i].otype != O_RING &&
               player.invent[i].otype != O_SHLD &&
               player.invent[i].otype != O_ARMR &&
               player.invent[i].otype != O_ROBE &&
               player.invent[i].otype != O_BOOT &&
               player.invent[i].otype != O_HELM &&
               player.invent[i].effect == E_INTR &&
               player.invent[i].control == intr) return -1;
      else if ((i==I_LHND || i==I_RHND || i==I_BLTL || i==I_BLTR ||
                i==I_BLTF || i==I_BLTB || i==I_LSHL || i==I_RSHL) &&
               player.invent[i].otype != O_NECK &&
               player.invent[i].otype != O_RING &&
               player.invent[i].otype != O_SHLD &&
               player.invent[i].otype != O_ARMR &&
               player.invent[i].otype != O_ROBE &&
               player.invent[i].otype != O_BOOT &&
               player.invent[i].otype != O_HELM &&
               player.invent[i].otype != O_DAGR &&
               player.invent[i].otype != O_EDGE &&
               player.invent[i].otype != O_BLNT &&
               player.invent[i].otype != O_POLE &&
               player.invent[i].otype != O_BOW &&
               player.invent[i].effect == E_INTR &&
               player.invent[i].control == intr) return -1;
      }
    }
  if (intr == A_RDLR && player.effect[PE_READLORE] != 0) return -1;
  if (intr == A_RDLN && player.effect[PE_READLANG] != 0) return -1;
  if (intr == A_SPD && player.effect[PE_HASTE] != 0) return -1;
  if (intr == A_RFIR && player.effect[PE_FIRE] != 0) return -1;
  if (intr == A_LEV && player.effect[PE_LEV] != 0) return -1;
  if (intr == A_LEV) return has_intrinsic(A_SPLV);
  if (intr == A_SPD) return has_intrinsic(A_SPLV);
  if (intr == A_RELE) return has_socket(S_ELE);
  if (intr == A_FLY) {
    for (i=1; i<=5; i++)
      if (player.party[i].hp > 0) {
        if ((player.party[i].special & MS_FLY) != 0 &&
            (player.party[i].special & MS_MOUNT) != 0) return -1;
        }
    }
  return 0;
  }

int has_intrinsic(int intr) {
  if (has_intrinsic2(intr)) return -1;
  if (intr == A_RFIR) {
    if (has_intrinsic2(A_RELE)) return -1;
    if (has_socket(S_FIR)) return -1;
    if (has_socket(S_ELE)) return -1;
    if (has_socket(S_FCE)) return -1;
    if (player.effect[PE_FIRE] != 0) return -1;
    }
  if (intr == A_RELC) {
    if (has_intrinsic2(A_RELE)) return -1;
    if (has_socket(S_ELC)) return -1;
    if (has_socket(S_ELE)) return -1;
    if (has_socket(S_FCE)) return -1;
    if (player.effect[PE_ELEC] != 0) return -1;
    }
  if (intr == A_RCLD) {
    if (has_intrinsic2(A_RELE)) return -1;
    if (has_socket(S_CLD)) return -1;
    if (has_socket(S_ELE)) return -1;
    if (has_socket(S_FCE)) return -1;
    if (player.effect[PE_COLD] != 0) return -1;
    }
  if (intr == A_RDRK) {
    if (has_intrinsic2(A_RELE)) return -1;
    if (has_socket(S_ARC)) return -1;
    if (has_socket(S_ELE)) return -1;
    if (has_socket(S_FCE)) return -1;
    if (player.effect[PE_ARCN] != 0) return -1;
    }
  if (intr == A_RELE) {
    if (has_socket(S_ELE)) return -1;
    if (has_socket(S_FCE)) return -1;
    }
  if (intr == A_RDLR) {
    if (has_intrinsic(A_RALL)) return -1;
    }
  if (intr == A_RDLN) {
    if (has_intrinsic(A_RALL)) return -1;
    }
  if (intr == A_RSPS) {
    if (has_socket(S_RPS)) return -1;
    }
  if (intr == A_NOPS) {
    if (has_socket(S_IPS)) return -1;
    }
  return 0;
  }
