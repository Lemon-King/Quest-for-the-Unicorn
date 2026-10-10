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

int get_bonus(int typ) {
  int ret;
  int slot;
  int i;
  ret = 0;
  for (slot=1; slot < 20; slot++)
    if (slot == I_NCK1 ||
	slot == I_NCK2 ||
	slot == I_SHLD ||
	slot == I_ARMR ||
	slot == I_RNG1 ||
	slot == I_RNG2 ||
	slot == I_RNG3 ||
	slot == I_RNG4 ||
	slot == I_ROBE ||
	slot == I_BOOT ||
	slot == I_HELM ||
        (slot == I_RHND && player.invent[slot].otype == O_HAND) ||
        (slot == I_LHND && player.invent[slot].otype == O_HAND) ||
        (slot == I_RHND && is_weapon(&(player.invent[slot]))) ||
        (slot == I_LHND && is_weapon(&(player.invent[slot]))) ) {
    if (player.invent[slot].otype != 0) {
      for (i=0; i<player.invent[slot].num_sockets; i++) {
        if ( (player.invent[slot].sockets[i] / 100) == typ/100)
          ret += (player.invent[slot].sockets[i] % 100);
        }
      for (i=0; i<player.invent[slot].num_enchantments; i++) {
        if ( (player.invent[slot].enchantments[i] / 100) == typ/100)
          ret += (player.invent[slot].enchantments[i] % 100);
        }
      }
    }
  return ret;
  }

int has_birthstone_ring() {
  if (player.invent[I_RNG1].link-265 == date.tm_mon) return 1;
  if (player.invent[I_RNG2].link-265 == date.tm_mon) return 1;
  if (player.invent[I_RNG3].link-265 == date.tm_mon) return 1;
  if (player.invent[I_RNG4].link-265 == date.tm_mon) return 1;
  return 0;
  }

int get_base_str() {
  return player.stat[1];
 }

int get_base_dex() {
  return player.stat[2];
 }

int get_base_con() {
  return player.stat[3];
 }

int get_base_int() {
  return player.stat[4];
 }

int get_base_wis() {
  return player.stat[5];
 }

int get_base_chr() {
  return player.stat[6];
 }

int get_base_mmana() {
  return player.mmana;
  }

int get_base_mhp() {
  return player.mhp;
  }

int get_base_weapon() {
  return player.weapon;
  }

int get_base_armour() {
  return player.armour;
  }

int get_str() {
  int ret;
  ret = player.stat[1];
  ret += get_bonus(S_STR);
  ret += get_bonus(S_ALL);
  if (has_birthstone_ring()) ret *= 1.10;
  if (ret > 99) ret = 99;
  return ret;
  }

int get_dex() {
  int ret;
  ret = player.stat[2];
  ret += get_bonus(S_DEX);
  ret += get_bonus(S_ALL);
  if (has_birthstone_ring()) ret *= 1.10;
  if (ret > 99) ret = 99;
  return ret;
  }

int get_con() {
  int ret;
  ret = player.stat[3];
  ret += get_bonus(S_CON);
  ret += get_bonus(S_ALL);
  if (has_birthstone_ring()) ret *= 1.10;
  if (ret > 99) ret = 99;
  return ret;
  }

int get_int() {
  int ret;
  ret = player.stat[4];
  ret += get_bonus(S_INT);
  ret += get_bonus(S_ALL);
  if (has_birthstone_ring()) ret *= 1.10;
  if (ret > 99) ret = 99;
  return ret;
  }

int get_wis() {
  int ret;
  ret = player.stat[5];
  ret += get_bonus(S_WIS);
  ret += get_bonus(S_ALL);
  if (has_birthstone_ring()) ret *= 1.10;
  if (ret > 99) ret = 99;
  return ret;
  }

int get_chr() {
  int ret;
  ret = player.stat[6];
  ret += get_bonus(S_CHR);
  ret += get_bonus(S_ALL);
  if (has_birthstone_ring()) ret *= 1.10;
  if (ret > 99) ret = 99;
  return ret;
  }

int get_mmana() {
  int ret;
  ret = player.mmana;
  ret += get_bonus(S_MAN);
  ret += get_bonus(S_MAG);
  if (player.mmana > 0) {
    ret += get_int();
    ret += get_skill(SK_MAGIC);
    }
  if (has_birthstone_ring()) ret *= 1.10;
  return ret;
  }

int get_mhp() {
  int ret;
  ret = player.mhp;
  ret += get_bonus(S_HPS);
  ret += get_bonus(S_MAG);
  if (has_birthstone_ring()) ret *= 1.10;
  return ret;
  }

int get_weapon() {
  int ret;
  double tmp;
  double wtmp;
  OBJECT_REC *weapon;
  tmp = player.weapon;
  if (player.invent[I_RHND].otype != O_NONE &&
      player.invent[I_RHND].otype == classes[player.class-1].weapon_affinity)
    tmp *= 1.15;
  if (player.effect[PE_POLYTIME] > 0) tmp += monsters[player.effect[PE_POLYMORPH]].attack;
  tmp *= (get_attack_power() / 100.0 + 1.0);
  wtmp = 1;
  weapon = &(player.invent[I_RHND]);
  if (is_weapon(weapon) && get_skill(weapon->skill) < 5) {
    if (get_skill(weapon->skill) == 0) wtmp = 0.16;
    if (get_skill(weapon->skill) == 1) wtmp = 0.32;
    if (get_skill(weapon->skill) == 2) wtmp = 0.48;
    if (get_skill(weapon->skill) == 3) wtmp = 0.64;
    if (get_skill(weapon->skill) == 4) wtmp = 0.80;
    }
  if (is_weapon(weapon) && get_skill(weapon->skill) >= 5) {
    wtmp = get_skill(weapon->skill) - 5;
    wtmp = wtmp / 200.0 + 1.0;
    }
  tmp *= wtmp;
  wtmp = get_skill(SK_COMBAT);
  wtmp =  wtmp / 400.0 + 1.0;
  tmp *= wtmp;
  ret = tmp;
  if (has_birthstone_ring()) ret *= 1.10;
  return ret;
  }

int offhand_weapon() {
  int ret;
  double tmp;
  double wtmp;
  OBJECT_REC *weapon;
  if (is_weapon(&(player.invent[I_LHND])))
    ret = player.invent[I_LHND].damage;
    else ret = 0;
  if (player.invent[I_LHND].otype != O_NONE &&
      player.invent[I_LHND].otype == classes[player.class-1].weapon_affinity)
    ret += (ret >> 1);
  if (player.effect[PE_POLYTIME] > 0) ret += monsters[player.effect[PE_POLYMORPH]].attack;
  tmp = ret;
  tmp *= (get_attack_power() / 100.0 + 1.0);
  wtmp = 1;
  weapon = &(player.invent[I_LHND]);
  if (is_weapon(weapon) && get_skill(weapon->skill) < 5) {
    if (get_skill(weapon->skill) == 0) wtmp = 0.16;
    if (get_skill(weapon->skill) == 1) wtmp = 0.32;
    if (get_skill(weapon->skill) == 2) wtmp = 0.48;
    if (get_skill(weapon->skill) == 3) wtmp = 0.64;
    if (get_skill(weapon->skill) == 4) wtmp = 0.80;
    }
  if (is_weapon(weapon) && get_skill(weapon->skill) >= 5) wtmp = (get_skill(weapon->skill) - 5) / 100.0 + 1.0;
  tmp *= wtmp;
  wtmp = (get_skill(SK_COMBAT) / 2) / 100.0 + 1.0;
  tmp *= wtmp;
  ret = tmp;
  if (has_birthstone_ring()) ret *= 1.10;
  return ret;
  }

int get_attack_power() {
  int ret;
  int i;
  ret = get_bonus(S_ATP);
  i = get_str();
  if (i > 18) {
    i = (i-16) / 3;
    ret += i;
    }
  return ret;
  }

int get_spell_power() {
  int ret;
  int i;
  ret = get_bonus(S_SPP);
  i = get_int();
  if (i > 18) {
    i = (i-16) / 3;
    ret += i;
    }
  return ret;
  }

int get_armour() {
  int i;
  int ret;
  ret = player.armour;
  ret += get_bonus(S_DEF);
  if (player.effect[PE_PROT] != 0) ret += player.effect[PE_APROT];
  if (player.effect[PE_POLYTIME] > 0) ret += monsters[player.effect[PE_POLYMORPH]].defense;
  for (i=I_NCK1; i<=I_NCK2; i++)
    if (player.invent[i].otype != O_NONE &&
        player.invent[i].effect == E_PROT) {
          ret += player.invent[i].control;
          }
  for (i=I_SHLD; i<=I_HELM; i++)
    if (player.invent[i].otype != O_NONE &&
        player.invent[i].effect == E_PROT) {
          ret += player.invent[i].control;
          }
  if (has_birthstone_ring()) ret *= 1.10;
  return ret;
  }

int get_hpr() {
  int i;
  int ret;
  ret = 1;
  if (napping == '*') {
    ret += 5;
    if (has_intrinsic(A_NPHL)) ret += 15;
    }
  ret += get_bonus(S_HPR);
  player.hp_count -= classes[player.class-1].hp_regen;
  for (i=1; i<=19; i++) {
    if (player.invent[i].otype != O_NONE) {
      if ((i==I_NCK1 || i==I_NCK2) &&
          player.invent[i].otype == O_NECK &&
          player.invent[i].effect == E_INTR &&
          player.invent[i].control == A_HEAL) 
        ret += player.invent[i].damage;
      else if ((i==I_RNG1 || i==I_RNG2 || i==I_RNG3 || i==I_RNG4) &&
          player.invent[i].otype == O_RING &&
          player.invent[i].effect == E_INTR &&
          player.invent[i].control == A_HEAL) 
        ret += player.invent[i].damage;
      else if (i==I_SHLD &&
          player.invent[i].otype == O_SHLD &&
          player.invent[i].effect == E_INTR &&
          player.invent[i].control == A_HEAL) 
        ret += player.invent[i].damage;
      else if (i==I_ARMR &&
          player.invent[i].otype == O_ARMR &&
          player.invent[i].effect == E_INTR &&
          player.invent[i].control == A_HEAL) 
        ret += player.invent[i].damage;
      else if (i==I_ROBE &&
          player.invent[i].otype == O_ROBE &&
          player.invent[i].effect == E_INTR &&
          player.invent[i].control == A_HEAL) 
        ret += player.invent[i].damage;
      else if (i==I_BOOT &&
          player.invent[i].otype == O_BOOT &&
          player.invent[i].effect == E_INTR &&
          player.invent[i].control == A_HEAL) 
        ret += player.invent[i].damage;
      else if (i==I_HELM &&
          player.invent[i].otype == O_HELM &&
          player.invent[i].effect == E_INTR &&
          player.invent[i].control == A_HEAL) 
        ret += player.invent[i].damage;
      else if (player.invent[i].otype != O_NECK &&
               player.invent[i].otype != O_RING &&
               player.invent[i].otype != O_SHLD &&
               player.invent[i].otype != O_ARMR &&
               player.invent[i].otype != O_ROBE &&
               player.invent[i].otype != O_BOOT &&
               player.invent[i].otype != O_HELM &&
               player.invent[i].effect == E_INTR &&
               player.invent[i].control == A_HEAL) 
             ret += player.invent[i].damage;
      }
    }
  return ret;
  }

int get_manar() {
  int ret;
  ret = 1;
  ret += get_bonus(S_MNR);
  if (napping == '*') ret += 5;
  return ret;
  }

int get_hit() {
  int i;
  int ret;
  ret = 0;
  ret += get_bonus(S_HIT);
  for (i=1; i<=10; i++) {
    if (player.invent[i].otype != O_NONE && player.invent[i].effect == E_INHT)
      ret+= player.invent[i].control;
    }
  if (is_weapon(&(player.invent[I_RHND]))) ret += player.invent[I_RHND].plus;
  if (get_dex() > 15) ret += ((get_dex() - 10) / 5);
  if (has_birthstone_ring()) ret *= 1.10;
  return ret;
  }

double get_exp_multiplier() {
  double bonus;
  bonus = get_bonus(S_EXP);
  bonus = 1 + (bonus / 100);
  return bonus;
  }

int get_magic_find() {
  int ret;
  ret = 0;
  ret += get_bonus(S_MGF);
  ret += has_birthstone_ring() * 3;
  ret += stats.num_trophies;
  ret += player.effect[PE_REBIRTH];
  return ret;
  }

double get_magic_resistance() {
  double ret;
  ret = 0;
  ret += get_bonus(S_MGR);
  ret += (get_int() / 2);
  if (ret > 90) ret = 90;
  ret /= 100;
  return ret;
  }

int get_monster_level_plus() {
  int ret;
  ret = 0;
  ret += (get_bonus(S_MLV));
  return ret;
  }

int get_crit() {
  int ret;
  ret = 0;
  if (get_dex() > 16) ret = (get_dex() - 15) / 5;
  ret += get_bonus(S_CRT);
  if (has_birthstone_ring()) ret += 5;
  return ret;
  }

int get_dodge() {
  int ret;
  ret = 0;
  if (get_dex() > 16) ret = (get_dex() - 15) / 5;
  ret += get_bonus(S_DDG);
  if (has_birthstone_ring()) ret += 5;
  if (ret > 25) ret = 25;
  return ret;
  }

int get_weight() {
  int ret;
  int i;
  ret = 0;
  for (i=0; i<20; i++) {
    if (player.invent[i].otype != O_NONE) ret += player.invent[i].weight;
    }
  for (i=0; i<32; i++) {
    if (player.pack[i].otype != O_NONE) ret += player.pack[i].weight;
    }
  ret += get_coins() / 250;
  return ret;
  }

int get_max_weight() {
  int ret;
  ret = get_str() * 10;
  if (player.invent[I_RNG1].otype == O_RING && player.invent[I_RNG1].effect == E_WGHT) ret += player.invent[I_RNG1].control;
  if (player.invent[I_RNG2].otype == O_RING && player.invent[I_RNG2].effect == E_WGHT) ret += player.invent[I_RNG2].control;
  if (player.invent[I_RNG3].otype == O_RING && player.invent[I_RNG3].effect == E_WGHT) ret += player.invent[I_RNG3].control;
  if (player.invent[I_RNG4].otype == O_RING && player.invent[I_RNG4].effect == E_WGHT) ret += player.invent[I_RNG4].control;
  if (player.invent[I_NCK1].otype == O_NECK && player.invent[I_NCK1].effect == E_WGHT) ret += player.invent[I_NCK1].control;
  if (player.invent[I_NCK2].otype == O_NECK && player.invent[I_NCK2].effect == E_WGHT) ret += player.invent[I_NCK2].control;
  if (player.invent[I_BOOT].otype == O_BOOT && player.invent[I_BOOT].effect == E_WGHT) ret += player.invent[I_BOOT].control;
  return ret;
  }

int32_t get_gold() {
  int32_t ret;
  ret = player.gold_coins;
  ret += (player.mithril_coins * 100);
  ret += (player.adamantite_coins * 10000);
  return ret;
  }

int32_t get_coins() {
  return player.gold_coins + player.mithril_coins + player.adamantite_coins;
  }

int can_be_seen() {
  if (player.effect[PE_INVIS] != 0) return 0;
  if ((classes[player.class-1].flags & CF_ROGUE) == CF_ROGUE) return 0;
  return -1;
  }

