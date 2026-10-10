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

char* base_name(char* buffer,OBJECT_REC* item) {
  int i;
  char *pchar;
  char *pchar2;
  if (item != NULL) strcpy(buffer,item->name);
    else strcpy(buffer," ");
  pchar = strchr(buffer,'|');
  if (pchar != NULL) {
    if (item->level >= 0) {
      *pchar = 0;
      } else {
      strcpy(buffer,pchar+1);
      }
    } else {
    if (item->level >= 0) {
      pchar = strchr(buffer,' ');
      pchar2 = strchr(buffer,',');
      if (pchar2 != NULL && pchar2 < pchar) pchar = pchar2;
      if (pchar != NULL) *pchar = 0;
      }
    }
  for (i=0; i<strlen(buffer); i++)
    if (buffer[i] == '_') buffer[i] = ' ';
  return buffer;
  }

char* get_enchant_name(int ench) {
  static char ename[128];
  char buffer[32];
  switch (ench / 100) {
    case 1: strcpy(ename,"STR+"); break;
    case 2: strcpy(ename,"DEX+"); break;
    case 3: strcpy(ename,"INT+"); break;
    case 4: strcpy(ename,"WIS+"); break;
    case 5: strcpy(ename,"CON+"); break;
    case 6: strcpy(ename,"CHR+"); break;
    case 7: strcpy(ename,"Mp+"); break;
    case 8: strcpy(ename,"Hp+"); break;
    case 9: strcpy(ename,"AP+"); break;
    case 10: strcpy(ename,"DEF+"); break;
    case 11: strcpy(ename,"Hit+"); break;
    case 12: strcpy(ename,"HpR+"); break;
    case 13: strcpy(ename,"MnR+"); break;
    case 14: strcpy(ename,"All+"); break;
    case 15: strcpy(ename,"Exp+"); break;
    case 16: strcpy(ename,"MF+"); break;
    case 17: strcpy(ename,"Hp/Mp+"); break;
    case 18: strcpy(ename,"MGR+"); break;
    case 19: strcpy(ename,"MLV+"); break;
    case 20: strcpy(ename,"CRT+"); break;
    case 21: strcpy(ename,"DDG+"); break;
    case 22: strcpy(ename,"FIRE+"); break;
    case 23: strcpy(ename,"COLD+"); break;
    case 24: strcpy(ename,"ELEC+"); break;
    case 25: strcpy(ename,"ARCN+"); break;
    case 26: strcpy(ename,"SP+"); break;
    case 27: strcpy(ename,"RELE"); break;
    case 28: strcpy(ename,"RPSN"); break;
    case 29: strcpy(ename,"IPSN"); break;
    case 30: strcpy(ename,"FCEA"); break;
    case 31: strcpy(ename,"Bow+"); break;
    case 32: strcpy(ename,"1hSword+"); break;
    case 33: strcpy(ename,"Spear+"); break;
    case 34: strcpy(ename,"Mace+"); break;
    case 35: strcpy(ename,"Scout+"); break;
    case 36: strcpy(ename,"Lang+"); break;
    case 37: strcpy(ename,"Lore+"); break;
    case 38: strcpy(ename,"Magic+"); break;
    case 39: strcpy(ename,"Heal+"); break;
    case 40: strcpy(ename,"Med+"); break;
    case 41: strcpy(ename,"Ride+"); break;
    case 42: strcpy(ename,"Boat+"); break;
    case 43: strcpy(ename,"Oracle+"); break;
    case 44: strcpy(ename,"Charm+"); break;
    case 45: strcpy(ename,"Surv+"); break;
    case 46: strcpy(ename,"Combat+"); break;
    case 47: strcpy(ename,"Dagger+"); break;
    case 48: strcpy(ename,"2hSword+"); break;
    case 49: strcpy(ename,"Axe+"); break;
    case 50: strcpy(ename,"Flail+"); break;
    case 51: strcpy(ename,"CrsBow+"); break;
    case 52: strcpy(ename,"Trident+"); break;
    case 53: strcpy(ename,"Poleaxe+"); break;
    case 54: strcpy(ename,"Thrown+"); break;
    }
  strcpy(buffer,"");
  if (ename[strlen(ename)-1] == '+') sprintf(buffer,"%d",ench % 100);
  strcat(ename,buffer);
  return ename;
  }

char* get_name(OBJECT_REC* item) {
  int i;
  static char iname[128];
  char *pchar;
  char *pchar2;
  if (item != NULL) strcpy(iname,item->name);
    else strcpy(iname," ");
  pchar = strchr(iname,'|');
  if (pchar != NULL) {
    if (item->level >= 0) {
      *pchar = 0;
      } else {
      strcpy(iname,pchar+1);
      }
    } else {
    if (item->level >= 0) {
      pchar = strchr(iname,' ');
      pchar2 = strchr(iname,',');
      if (pchar2 != NULL && pchar2 < pchar) pchar = pchar2;
      if (pchar != NULL) *pchar = 0;
      } 
    }
  if (item->level < 0 && item->charges >=0) {
    sprintf(iname,"%s [%d]",iname,item->charges);
    }
  if (item != NULL && item->level < 0) {
    if (item->otype == O_EDGE ||
        item->otype == O_POLE ||
        item->otype == O_BLNT ||
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
  for (i=0; i<strlen(iname); i++)
    if (iname[i] == '_') iname[i] = ' ';

  if (item->level < 0) {
    for (i=0; i<item->num_enchantments; i++) {
      strcat(iname," ");
      if (item->enchantments[i] > 0) {
        strcat(iname,get_enchant_name(item->enchantments[i]));
        }
      }
    }

  if (item->num_sockets > 0) strcat(iname," ");
  for (i=0; i<item->num_sockets; i++) {
    strcat(iname,"(");
    if (item->sockets[i] > 0) {
      strcat(iname,get_enchant_name(item->sockets[i]));
      }
    strcat(iname,")");
    }
  if (item->effect == E_SOCK) {
    strcat(iname," (");
    strcat(iname,get_enchant_name(item->control));
    strcat(iname,")");
    }
  while (strlen(iname) < 30) strcat(iname," ");
  return iname;
  }

