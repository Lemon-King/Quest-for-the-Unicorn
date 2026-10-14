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

void eshter() {
  char key;
  textmode(3);
  textcolor(2);
  txt_writeln("Congratulations!!!! You have defeated Eshter and freed the Unicorns!!");
  txt_writeln("After Eshter's defeat the power of the unicorns was capable of driving");
  txt_writeln("the rest of the evil out of this realm.  consequently the unicorns decided");
  txt_writeln("to remain in this realm where they would be safe from further malice");
  txt_writeln("against htem.  For their gratitude for rescuing them, the unicorns have");
  txt_writeln("given you 50,000 gold pieces plus free travel back through the Gateway");
  txt_writeln("to your home world.");
  txt_writeln("");
  txt_writeln("");
  textcolor(14); gotoxy(28,10);
  key = inkey();
  player.d_level = 0;
  player.gold += 50000;
  player.gateway = 'F';
  }

