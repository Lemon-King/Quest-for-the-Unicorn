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

int has_intrinsic(int intr) {
  int i;
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
               player.invent[i].otype != O_POLE &&
               player.invent[i].otype != O_BOW &&
               player.invent[i].effect == E_INTR &&
               player.invent[i].control == intr) return -1;
      }
    }


/*
  if ( (player.invent[2].otype == O_EDGE ||
        player.invent[2].otype == O_POLE ||
        player.invent[2].otype == O_DAGR ||
        player.invent[2].otype == O_BOW) &&
       player.invent[2].effect == E_INTR &&
       player.invent[2].control == intr) return -1;

  for (i=5; i<=6; i++)
    if (player.invent[i].otype != O_NONE &&
        player.invent[i].effect == E_INTR &&
        player.invent[i].control == intr) return -1;
  for (i=11; i<=19; i++)
    if (player.invent[i].otype != O_NONE &&
        player.invent[i].effect == E_INTR &&
        player.invent[i].control == intr) return -1;
*/
  if (intr == A_RALL) return (has_intrinsic(A_RDLR) | has_intrinsic(A_RDLN));
  if (intr == A_RDLR && player.effect[PE_READLORE] != 0) return -1;
  if (intr == A_RDLN && player.effect[PE_READLANG] != 0) return -1;
  if (intr == A_SPD && player.effect[PE_HASTE] != 0) return -1;
  if (intr == A_RFIR && player.effect[PE_FIRE] != 0) return -1;
  if (intr == A_LEV && player.effect[PE_LEV] != 0) return -1;
  if (intr == A_LEV) return has_intrinsic(A_SPLV);
  if (intr == A_SPD) return has_intrinsic(A_SPLV);
  return 0;
  }

