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

void save_gear(char weapons_only,int slot) {
  char key;
  if (slot < 0) {
    msg("Save set (0-9)?",15);
    key = inkey();
    while (key != 27 && (key < '0' || key > '9')) {
       key = inkey();
      }
    if (key == 27) {
      msg("Cancelled",15);
      return;
      }
    slot = key - '0';
    }
  strcpy(gear_manager[slot].main_hand,"");
  strcpy(gear_manager[slot].off_hand,"");
  if (weapons_only != 'Y') {
    strcpy(gear_manager[slot].neck_1,"");
    strcpy(gear_manager[slot].neck_2,"");
    strcpy(gear_manager[slot].shield,"");
    strcpy(gear_manager[slot].armor,"");
    strcpy(gear_manager[slot].ring_l1,"");
    strcpy(gear_manager[slot].ring_l2,"");
    strcpy(gear_manager[slot].ring_r1,"");
    strcpy(gear_manager[slot].ring_r2,"");
    strcpy(gear_manager[slot].cloak,"");
    strcpy(gear_manager[slot].boots,"");
    strcpy(gear_manager[slot].helm,"");
    }
  if (player.invent[I_RHND].otype != O_NONE)
    strcpy(gear_manager[slot].main_hand,player.invent[I_RHND].name);
  if (player.invent[I_LHND].otype != O_NONE)
    strcpy(gear_manager[slot].off_hand,player.invent[I_LHND].name);
  if (weapons_only != 'Y') {
    if (player.invent[I_NCK1].otype != O_NONE)
      strcpy(gear_manager[slot].neck_1,player.invent[I_NCK1].name);
    if (player.invent[I_NCK2].otype != O_NONE)
      strcpy(gear_manager[slot].neck_2,player.invent[I_NCK2].name);
    if (player.invent[I_SHLD].otype != O_NONE)
      strcpy(gear_manager[slot].shield,player.invent[I_SHLD].name);
    if (player.invent[I_ARMR].otype != O_NONE)
      strcpy(gear_manager[slot].armor,player.invent[I_ARMR].name);
    if (player.invent[I_RNG1].otype != O_NONE)
      strcpy(gear_manager[slot].ring_l1,player.invent[I_RNG1].name);
    if (player.invent[I_RNG2].otype != O_NONE)
      strcpy(gear_manager[slot].ring_l2,player.invent[I_RNG2].name);
    if (player.invent[I_RNG3].otype != O_NONE)
      strcpy(gear_manager[slot].ring_r1,player.invent[I_RNG3].name);
    if (player.invent[I_RNG4].otype != O_NONE)
      strcpy(gear_manager[slot].ring_r2,player.invent[I_RNG4].name);
    if (player.invent[I_ROBE].otype != O_NONE)
      strcpy(gear_manager[slot].cloak,player.invent[I_ROBE].name);
    if (player.invent[I_BOOT].otype != O_NONE)
      strcpy(gear_manager[slot].boots,player.invent[I_BOOT].name);
    if (player.invent[I_HELM].otype != O_NONE)
      strcpy(gear_manager[slot].helm,player.invent[I_HELM].name);
    }
  msg("Saved",15);
  }

