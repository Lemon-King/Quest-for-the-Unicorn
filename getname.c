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

char* get_name(OBJECT_REC* item) {
  int i;
  static char iname[33];
  char *pchar;
  if (item != NULL) strcpy(iname,item->name);
    else strcpy(iname," ");
  if (item->level >= 0) {
    pchar = strchr(iname,' ');
    if (pchar != NULL) *pchar = 0;
    } else if (item->charges >=0) {
    sprintf(iname,"%s (%d)",iname,item->charges);
    }
  if (item != NULL && item->level < 0) {
    if (item->otype == O_EDGE ||
        item->otype == O_POLE ||
        item->otype == O_DAGR ||
        item->otype == O_BOW ||
        item->otype == O_ARMR ||
        item->otype == O_SHLD ||
        item->otype == O_BOOT ||
        item->otype == O_HELM)
      sprintf(iname,"%s %+d",iname,item->plus);
    }
  else if (has_intrinsic(A_CURS)) {
    if (item->plus < 0) sprintf(iname,"%s (Cursed)",iname);
    if (item->plus > 0) sprintf(iname,"%s (Blessed)",iname);
    }
  while (strlen(iname) < 30) strcat(iname," ");
  for (i=0; i<strlen(iname); i++)
    if (iname[i] == '_') iname[i] = ' ';
  return iname;
  }

