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

void mutable_set_name(OBJECT_REC* it) {
  char prefix[10];
  char postfix[20];
  char fullname[100];
  int  e;
  strcpy(prefix,"");
  strcpy(postfix,"");
  strcpy(fullname,"");
  if (it->effect == E_INTR) {
    switch (it->control) {
      case  A_NOSL: strcpy(prefix,"Glass"); break;
      case  A_NOPS: strcpy(prefix,"Stone"); break;
      case  A_RSFR: strcpy(prefix,"Wood"); break;
      case  A_LEV: strcpy(prefix,"Brass"); break;
      case  A_SPD: strcpy(prefix,"Bronze"); break;
      case  A_HEAL: strcpy(prefix,"Elm"); break;
      case  A_NOFR: strcpy(prefix,"Oak"); break;
      case  A_CURS: strcpy(prefix,"Pine"); break;
      case  A_RELE: strcpy(prefix,"Ash"); break;
      case  A_SPLV: strcpy(prefix,"Teak"); break;
      case  A_DTUP: strcpy(prefix,"Opal"); break;
      case  A_DTDN: strcpy(prefix,"Ruby"); break;
      case  A_RDLR: strcpy(prefix,"Onyx"); break;
      case  A_RDLN: strcpy(prefix,"Gold"); break;
      case  A_RFIR: strcpy(prefix,"Amber"); break;
      case  A_TRAP: strcpy(prefix,"Lead"); break;
      }
    }
  e = 0;
  if (it->num_enchantments > 1) {
    e++;
    switch (it->enchantments[0]/100) {
      case  1:strcpy(postfix,"Red "); break;
      case  2:strcpy(postfix,"Blue "); break;
      case  3:strcpy(postfix,"Green "); break;
      case  4:strcpy(postfix,"Orange "); break;
      case  5:strcpy(postfix,"Gold "); break;
      case  6:strcpy(postfix,"Silver "); break;
      case  7:strcpy(postfix,"Yellow "); break;
      case  8:strcpy(postfix,"White "); break;
      case  9:strcpy(postfix,"Black "); break;
      case 10:strcpy(postfix,"Gray "); break;
      case 11:strcpy(postfix,"Amber "); break;
      case 12:strcpy(postfix,"Aqua "); break;
      case 13:strcpy(postfix,"Bone "); break;
      case 14:strcpy(postfix,"Coral "); break;
      case 15:strcpy(postfix,"Cyan "); break;
      case 16:strcpy(postfix,"Pink "); break;
      case 17:strcpy(postfix,"Lilac "); break;
      case 18:strcpy(postfix,"Jade "); break;
      case 19:strcpy(postfix,"Ivory "); break;
      case 20:strcpy(postfix,"Mauve "); break;
      case 21:strcpy(postfix,"Ochre "); break;
      case 22:strcpy(postfix,"Crimson "); break;
      case 23:strcpy(postfix,"Azure "); break;
      case 24:strcpy(postfix,"Tawny "); break;
      case 25:strcpy(postfix,"Indigo "); break;
      case 26:strcpy(postfix,"Teal "); break;
      case 27:strcpy(postfix,"Brown "); break;
      case 28:strcpy(postfix,"Plum "); break;
      case 29:strcpy(postfix,"Maroon "); break;
      case 30:strcpy(postfix,"Olive "); break;
      }
    }
  switch (it->enchantments[e]/100) {
    case  1:strcat(postfix,"Ox"); break;
    case  2:strcat(postfix,"Boar"); break;
    case  3:strcat(postfix,"Lion"); break;
    case  4:strcat(postfix,"Tiger"); break;
    case  5:strcat(postfix,"Bat"); break;
    case  6:strcat(postfix,"Cat"); break;
    case  7:strcat(postfix,"Owl"); break;
    case  8:strcat(postfix,"Whale"); break;
    case  9:strcat(postfix,"Mouse"); break;
    case 10:strcat(postfix,"Rat"); break;
    case 11:strcat(postfix,"Lynx"); break;
    case 12:strcat(postfix,"Fish"); break;
    case 13:strcat(postfix,"Wolf"); break;
    case 14:strcat(postfix,"Bear"); break;
    case 15:strcat(postfix,"Deer"); break;
    case 16:strcat(postfix,"Elk"); break;
    case 17:strcat(postfix,"Ram"); break;
    case 18:strcat(postfix,"Shark"); break;
    case 19:strcat(postfix,"Hawk"); break;
    case 20:strcat(postfix,"Eagle"); break;
    case 21:strcat(postfix,"Snake"); break;
    case 22:strcat(postfix,"Viper"); break;
    case 23:strcat(postfix,"Seal"); break;
    case 24:strcat(postfix,"Eel"); break;
    case 25:strcat(postfix,"Frog"); break;
    case 26:strcat(postfix,"Serpent"); break;
    case 27:strcat(postfix,"Lizard"); break;
    case 28:strcat(postfix,"Horse"); break;
    case 29:strcat(postfix,"Jackal"); break;
    case 30:strcat(postfix,"Lemur"); break;
    }
  if (strlen(prefix) > 0) {
    strcpy(fullname,prefix);
    strcat(fullname," ");
    }
  strcat(fullname,it->name);
  strcat(fullname," of the ");
  strcat(fullname,postfix);
  if (strlen(fullname) > 32) fullname[32] = 0;
  strcpy(it->name,fullname);
  }

int mutable_enchant() {
  int e;
  int a;
  a = 1;
  e = u_random(S_MAX_ENCH) + 1;
  switch(e) {
    case 1:   /* STR */
    case 2:   /* DEX */
    case 3:   /* INT */
    case 4:   /* WIS */
    case 5:   /* CON */
    case 6:   /* CHR */
    case 12:  /* HPR */
    case 13:  /* MNR */
    case 14:  /* Base */
    case 15:  /* EXP */
    case 16:  /* mgf */
    case 18:  /* Mgr */
    case 19:  /* MLV */
    case 20:  /* Crit */
    case 21:  /* Dodge */
    case 26:  /* Spell Power */
           a = u_random(5)+1;
           break;
    case 7:   /* mmana */
    case 8:   /* mhps */
    case 17:  /* hp/mp */
           a = (u_random(5)+1) * 10;
           break;
    case 9:   /* atp */
    case 10:  /* def */
    case 11:  /* hit */
           a = u_random(16)+1;
           break;
    case 23:  /* cold */
    case 24:  /* elec */
    case 25:  /* arcane */
    case 30:  /* all elements */
           a = (u_random(5)+1) * 5;
           break;
  }
  return (e * 100) + a;
  }

void mutable(OBJECT_REC* it) {
  int  e;
  char flag;
  it->num_enchantments = 0;
  if (it->otype == O_DAGR ||
      it->otype == O_EDGE ||
      it->otype == O_BLNT ||
      it->otype == O_BOW  ||
      it->otype == O_POLE) {
    it->damage = (abs(it->level) * 3) + (abs(u_random(abs(it->level)) - u_random(abs(it->level))) >> 1);
    it->effect = E_ATCK;
    }
  if (it->otype == O_ARMR) {
    it->damage = ((it->damage / 5) * abs(it->level)) + abs(u_random(it->damage) - u_random(it->damage));
    it->effect = E_NONE;
    }
  switch (u_random(48)) {
    case  1: it->effect = E_INTR; it->control = A_NOSL; break;
    case  2: it->effect = E_INTR; it->control = A_NOPS; break;
    case  3: it->effect = E_INTR; it->control = A_RSFR; break;
    case  4: it->effect = E_INTR; it->control = A_LEV; break;
    case  5: it->effect = E_INTR; it->control = A_SPD; break;
    case  6: it->effect = E_INTR; it->control = A_HEAL; break;
    case  7: it->effect = E_INTR; it->control = A_NOFR; break;
    case  8: it->effect = E_INTR; it->control = A_CURS; break;
    case  9: it->effect = E_INTR; it->control = A_RELE; break;
    case 10: it->effect = E_INTR; it->control = A_SPLV; break;
    case 11: it->effect = E_INTR; it->control = A_DTUP; break;
    case 12: it->effect = E_INTR; it->control = A_DTDN; break;
    case 13: it->effect = E_INTR; it->control = A_RDLR; break;
    case 14: it->effect = E_INTR; it->control = A_RDLN; break;
    case 15: it->effect = E_INTR; it->control = A_RFIR; break;
    case 16: it->effect = E_INTR; it->control = A_TRAP; break;
    }
  if (u_random(100) <= 25) {
    e = mutable_enchant();
    it->enchantments[0] = e;
    it->num_enchantments = 1;
    }
  flag = 0;
  while (flag == 0) {
    flag = -1;
    e = mutable_enchant();
    it->enchantments[it->num_enchantments++] = e;
    if (it->num_enchantments == 2 && (it->enchantments[1] / 100) == (it->enchantments[0] / 100)) {
      flag = 0;
      it->num_enchantments--;
      }
    }
  if (u_random(200) <= it->level) it->num_sockets++;
  if (u_random(200) <= it->level) it->num_sockets++;
  if (u_random(200) <= it->level) it->num_sockets++;
  it->cost = it->damage * ((it->damage / 10) * 10);
  if (it->effect == E_INTR) it->cost += 1000;
  if (it->num_sockets == 1) it->cost += 100;
  if (it->num_sockets == 2) it->cost += 500;
  if (it->num_sockets == 3) it->cost += 1000;
  if (it->num_enchantments == 1) it->cost += 1000;
  if (it->num_enchantments == 2) it->cost += 5000;
  if (it->num_enchantments == 3) it->cost += 10000;
  }

