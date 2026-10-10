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

OBJECT_REC* find_gear(char* name) {
  int i;
  for (i=1; i<=19; i++) {
    if (player.invent[i].otype != O_NONE && strcmp(name,player.invent[i].name) == 0)
      return &(player.invent[i]);
    }
  for (i=1; i<=32; i++) {
    if (player.pack[i].otype != O_NONE && strcmp(name,player.pack[i].name) == 0)
      return &(player.pack[i]);
    }
  return NULL;
  }

OBJECT_REC* find_empty_slot() {
  int i;
  for (i=3; i<=10; i++) {
    if (player.invent[i].otype == O_NONE)
      if (i==3 || i==4 || (i>=7 && i<=10)) return &(player.invent[i]);
    }
  for (i=1; i<=32; i++) {
    if (player.pack[i].otype == O_NONE) return &(player.pack[i]);
    }
  return NULL;
  }

void load_gear(char weapons_only,int slot) {
  char key;
  OBJECT_REC* item;
  OBJECT_REC  temp;
  if (slot < 0) {
    msg("Equip set (0-9)?",15);
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
  msg("Equipped:",15);
  if (strlen(gear_manager[slot].main_hand) > 0) {
    item = find_gear(gear_manager[slot].main_hand);
    if (item != NULL) {
      temp = player.invent[I_RHND];
      player.invent[I_RHND] = *item;
      *item = temp;
      msg(player.invent[I_RHND].name,7);
      }
    }
  if (is_weapon(&(player.invent[I_RHND])) &&
      is_weapon(&(player.invent[I_LHND]))) {
    item = find_empty_slot();
    if (item == NULL) {
      return;
      }
    *item = player.invent[I_LHND];
    player.invent[I_LHND].otype = O_NONE;
    }
  if (strlen(gear_manager[slot].off_hand) > 0) {
    item = find_gear(gear_manager[slot].off_hand);
    if (item != NULL) {
      temp = player.invent[I_LHND];
      player.invent[I_LHND] = *item;
      *item = temp;
      msg(player.invent[I_LHND].name,7);
      }
    }
  if (weapons_only != 'Y' && strlen(gear_manager[slot].neck_1) > 0) {
    item = find_gear(gear_manager[slot].neck_1);
    if (item != NULL) {
      temp = player.invent[I_NCK1];
      player.invent[I_NCK1] = *item;
      *item = temp;
      msg(player.invent[I_NCK1].name,7);
      }
    }
  if (weapons_only != 'Y' && strlen(gear_manager[slot].neck_2) > 0) {
    item = find_gear(gear_manager[slot].neck_2);
    if (item != NULL) {
      temp = player.invent[I_NCK2];
      player.invent[I_NCK2] = *item;
      *item = temp;
      msg(player.invent[I_NCK2].name,7);
      }
    }
  if (weapons_only != 'Y' && strlen(gear_manager[slot].shield) > 0) {
    item = find_gear(gear_manager[slot].shield);
    if (item != NULL) {
      temp = player.invent[I_SHLD];
      player.invent[I_SHLD] = *item;
      *item = temp;
      msg(player.invent[I_SHLD].name,7);
      }
    }
  if (weapons_only != 'Y' && strlen(gear_manager[slot].armor) > 0) {
    item = find_gear(gear_manager[slot].armor);
    if (item != NULL) {
      temp = player.invent[I_ARMR];
      player.invent[I_ARMR] = *item;
      *item = temp;
      temp = player.invent[I_ARMR];
      }
    }
  if (weapons_only != 'Y' && strlen(gear_manager[slot].cloak) > 0) {
    item = find_gear(gear_manager[slot].cloak);
    if (item != NULL) {
      temp = player.invent[I_ROBE];
      player.invent[I_ROBE] = *item;
      *item = temp;
      temp = player.invent[I_ROBE];
      }
    }
  if (weapons_only != 'Y' && strlen(gear_manager[slot].boots) > 0) {
    item = find_gear(gear_manager[slot].boots);
    if (item != NULL) {
      temp = player.invent[I_BOOT];
      player.invent[I_BOOT] = *item;
      *item = temp;
      temp = player.invent[I_BOOT];
      }
    }
  if (weapons_only != 'Y' && strlen(gear_manager[slot].helm) > 0) {
    item = find_gear(gear_manager[slot].helm);
    if (item != NULL) {
      temp = player.invent[I_HELM];
      player.invent[I_HELM] = *item;
      *item = temp;
      temp = player.invent[I_HELM];
      }
    }
  if (weapons_only != 'Y' && strlen(gear_manager[slot].ring_l1) > 0) {
    item = find_gear(gear_manager[slot].ring_l1);
    if (item != NULL) {
      temp = player.invent[I_RNG1];
      player.invent[I_RNG1] = *item;
      *item = temp;
      temp = player.invent[I_RNG1];
      }
    }
  if (weapons_only != 'Y' && strlen(gear_manager[slot].ring_l2) > 0) {
    item = find_gear(gear_manager[slot].ring_l2);
    if (item != NULL) {
      temp = player.invent[I_RNG2];
      player.invent[I_RNG2] = *item;
      *item = temp;
      temp = player.invent[I_RNG2];
      }
    }
  if (weapons_only != 'Y' && strlen(gear_manager[slot].ring_r1) > 0) {
    item = find_gear(gear_manager[slot].ring_r1);
    if (item != NULL) {
      temp = player.invent[I_RNG3];
      player.invent[I_RNG3] = *item;
      *item = temp;
      temp = player.invent[I_RNG3];
      }
    }
  if (weapons_only != 'Y' && strlen(gear_manager[slot].ring_r2) > 0) {
    item = find_gear(gear_manager[slot].ring_r2);
    if (item != NULL) {
      temp = player.invent[I_RNG4];
      player.invent[I_RNG4] = *item;
      *item = temp;
      temp = player.invent[I_RNG4];
      }
    }
  player_attack_defense();
  adjust_abilities();
  }

