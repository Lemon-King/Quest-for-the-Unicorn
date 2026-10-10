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

int is_magic_weapon(OBJECT_REC* weapon,NPC_REC* target) {
  int min_plus;
  min_plus = ((target->level - 1) / 5) + 1;
  if (weapon == NULL) return 0;
  if (!is_weapon(weapon)) return 0;
  if (weapon->num_enchantments > 0) return -1;
  if (weapon->num_sockets > 0 && weapon->sockets[0] != 0) return -1;
  if (weapon->num_sockets > 1 && weapon->sockets[1] != 0) return -1;
  if (weapon->num_sockets > 2 && weapon->sockets[2] != 0) return -1;
  if (weapon->plus <= 0) return 0;
  if (target == NULL) return -1;
  if (weapon->plus >= min_plus) return -1;
  return 0;
  }

int max_damage(OBJECT_REC* weapon,NPC_REC* target,int base) {
  int physical;
  int fire;
  int cold;
  int elec;
  int arcn;
  physical = 0;
  fire = 0;
  cold = 0;
  elec = 0;
  arcn = 0;
  if (weapon == NULL) {
    if ((target->special & MS_APHYSICAL) == MS_APHYSICAL) base = 0;
    return base;
    }
  if (is_weapon(weapon) == 0) base = u_random(get_str() / 3);
  physical = base;
  if (weapon != NULL && weapon->otype != O_NONE) {
    if (weapon->num_sockets > 0 && weapon->sockets[0] >= S_FIR  && weapon->sockets[0] <= S_FIR+99) fire = base;
    if (weapon->num_sockets > 1 && weapon->sockets[1] >= S_FIR  && weapon->sockets[1] <= S_FIR+99) fire = base;
    if (weapon->num_sockets > 2 && weapon->sockets[2] >= S_FIR  && weapon->sockets[2] <= S_FIR+99) fire = base;
    if (weapon->num_sockets > 0 && weapon->sockets[0] >= S_CLD  && weapon->sockets[0] <= S_CLD+99) cold = base;
    if (weapon->num_sockets > 1 && weapon->sockets[1] >= S_CLD  && weapon->sockets[1] <= S_CLD+99) cold = base;
    if (weapon->num_sockets > 2 && weapon->sockets[2] >= S_CLD  && weapon->sockets[2] <= S_CLD+99) cold = base;
    if (weapon->num_sockets > 0 && weapon->sockets[0] >= S_ELC  && weapon->sockets[0] <= S_ELC+99) elec = base;
    if (weapon->num_sockets > 1 && weapon->sockets[1] >= S_ELC  && weapon->sockets[1] <= S_ELC+99) elec = base;
    if (weapon->num_sockets > 2 && weapon->sockets[2] >= S_ELC  && weapon->sockets[2] <= S_ELC+99) elec = base;
    if (weapon->num_sockets > 0 && weapon->sockets[0] >= S_ARC  && weapon->sockets[0] <= S_ARC+99) arcn = base;
    if (weapon->num_sockets > 1 && weapon->sockets[1] >= S_ARC  && weapon->sockets[1] <= S_ARC+99) arcn = base;
    if (weapon->num_sockets > 2 && weapon->sockets[2] >= S_ARC  && weapon->sockets[2] <= S_ARC+99) arcn = base;
    }
  if ((target->special & MS_RFIRE) == MS_RFIRE) {
    cold += (cold / 2);
    fire /= 2;
    }
  if ((target->special & MS_RCOLD) == MS_RCOLD) {
    fire += (fire / 2);
    cold /= 2;
    }
  if ((target->special & MS_RELEC) == MS_RELEC) {
    arcn += (arcn / 2);
    elec /= 2;
    }
  if ((target->special & MS_RARCN) == MS_RARCN) {
    elec += (elec / 2);
    arcn /= 2;
    }
  if ((target->special & MS_IFIRE) == MS_IFIRE) {
    cold *= 2;
    fire = 0;
    }
  if ((target->special & MS_ICOLD) == MS_ICOLD) {
    fire *= 2;
    cold = 0;
    }
  if ((target->special & MS_IELEC) == MS_IELEC) {
    arcn *= 2;
    elec = 0;
    }
  if ((target->special & MS_IARCN) == MS_IARCN) {
    elec *= 2;
    arcn = 0;
    }
  if ((target->special & MS_APHYSICAL) == MS_APHYSICAL && is_magic_weapon(weapon,target) == 0) {
    physical = 0;
    fire = 0;
    cold = 0;
    elec = 0;
    arcn = 0;
    }
  if ((target->special & MS_AMAGIC) == MS_AMAGIC && is_magic_weapon(weapon,target) != 0) {
    physical = 0;
    fire = 0;
    cold = 0;
    elec = 0;
    arcn = 0;
    }
  if (physical > fire && physical > cold && physical > elec && physical > arcn) return physical;
  if (fire > physical && fire > cold && fire > elec && fire > arcn) return fire;
  if (cold > physical && cold > fire && cold > elec && cold > arcn) return cold;
  if (elec > physical && elec > fire && elec > cold && elec > arcn) return elec;
  if (arcn > physical && arcn > fire && arcn > cold && arcn > elec) return arcn;
  return 0;
  }

