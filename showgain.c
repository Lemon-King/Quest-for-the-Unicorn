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

  void show_gain(int g) {
    switch (g) {
      case 1:msg("Gained Bow",14); break;
      case 2:msg("Gained 1H Sword",14); break;
      case 3:msg("Gained Spear",14); break;
      case 4:msg("Gained Mace",14); break;
      case 5:msg("Gained Scouting",14); break;
      case 6:msg("Gained Language",14); break;
      case 7:msg("Gained Lore",14); break;
      case 8:msg("Gained Magic",14); break;
      case 9:msg("Gained Healing",14); break;
      case 10:msg("Gained Medicine",14); break;
      case 11:msg("Gained Riding",14); break;
      case 12:msg("Gained Boating",14); break;
      case 13:msg("Gained Oracle",14); break;
      case 14:msg("Gained Charm",14); break;
      case 15:msg("Gained Survival",14); break;
      case 16:msg("Gained Combat",14); break;
      case 17:msg("Gained Dagger",14); break;
      case 18:msg("Gained 2H Sword",14); break;
      case 19:msg("Gained Axe",14); break;
      case 20:msg("Gained Flail",14); break;
      case 21:msg("Gained Crossbow",14); break;
      case 22:msg("Gained Trident",14); break;
      case 23:msg("Gained Poleaxe",14); break;
      case 24:msg("Gained Thrown",14); break;
      }
    }


