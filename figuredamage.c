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

int figure_damage(int damage,int elem,NPC_REC* monster) {
  if (elem == MS_FIRE_ATK && (monster->special & MS_RFIRE) == MS_RFIRE) damage /= 2;
  if (elem == MS_FIRE_ATK && (monster->special & MS_IFIRE) == MS_IFIRE) damage = 0;
  if (elem == MS_FIRE_ATK && (monster->special & MS_RCOLD) == MS_RCOLD) damage += (damage / 2);
  if (elem == MS_FIRE_ATK && (monster->special & MS_ICOLD) == MS_ICOLD) damage *= 2;

  if (elem == MS_COLD_ATK && (monster->special & MS_RCOLD) == MS_RCOLD) damage /= 2;
  if (elem == MS_COLD_ATK && (monster->special & MS_ICOLD) == MS_ICOLD) damage = 0;
  if (elem == MS_COLD_ATK && (monster->special & MS_RFIRE) == MS_RFIRE) damage += (damage / 2);
  if (elem == MS_COLD_ATK && (monster->special & MS_IFIRE) == MS_IFIRE) damage *= 2;

  if (elem == MS_ELEC_ATK && (monster->special & MS_RELEC) == MS_RELEC) damage /= 2;
  if (elem == MS_ELEC_ATK && (monster->special & MS_IELEC) == MS_IELEC) damage = 0;
  if (elem == MS_ELEC_ATK && (monster->special & MS_RARCN) == MS_RARCN) damage += (damage / 2);
  if (elem == MS_ELEC_ATK && (monster->special & MS_IARCN) == MS_IARCN) damage *= 2;

  if (elem == MS_ARCN_ATK && (monster->special & MS_RARCN) == MS_RARCN) damage /= 2;
  if (elem == MS_ARCN_ATK && (monster->special & MS_IARCN) == MS_IARCN) damage = 0;
  if (elem == MS_ARCN_ATK && (monster->special & MS_RELEC) == MS_RELEC) damage += (damage / 2);
  if (elem == MS_ARCN_ATK && (monster->special & MS_IELEC) == MS_IELEC) damage *= 2;


  return damage;
  }

