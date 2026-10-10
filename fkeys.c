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

void fkey_pressed(int n) {
  if (fkey_mode == 'S') cast_spell(n);
  if (fkey_mode == 'W') {
    if (n == 10) n = 0;
    load_gear('Y',n);
    }
  if (fkey_mode == 'G') {
    if (n == 10) n = 0;
    load_gear('N',n);
    }
  if (fkey_mode == 'M') strcpy(currentMacro, macros[n-1]);
  }

void shift_fkey_pressed(int n) {
  if (fkey_mode == 'W') {
    if (n == 10) n = 0;
    save_gear('Y',n);
    }
  if (fkey_mode == 'G') {
    if (n == 10) n = 0;
    save_gear('N',n);
    }
  if (fkey_mode == 'S') {
    if (n == 10) n = 0;
    save_gear('Y',n);
    }
  if (fkey_mode == 'M') {
    if (n == 10) n = 0;
    save_gear('Y',n);
    }
  }

void alt_fkey_pressed(int n) {
  if (fkey_mode == 'W' || fkey_mode == 'G') cast_spell(n);
  if (fkey_mode == 'S') {
    if (n == 10) n = 0;
    load_gear('Y',n);
    }
  if (fkey_mode == 'M') {
    if (n == 10) n = 0;
    load_gear('Y',n);
    }
  }

void ctrl_fkey_pressed(int n) {
  if (fkey_mode != 'M') strcpy(currentMacro, macros[n-1]);
  if (fkey_mode == 'M') cast_spell(n);
  }

