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

void convert_time(int32_t t,char* buffer) {
  int days;
  int hours;
  int minutes;
  days = t / 86400;
  t -= (days * 86400);
  hours = t / 3600;
  t -= (hours * 3600);
  minutes = t / 60;
  t -= (minutes * 60);
  sprintf(buffer,"%dD %dH %dM %dS",days,hours,minutes,t);
  }

