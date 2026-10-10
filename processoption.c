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

int option_value(char* option) {
  while (*option != 0 && *option != '=') option++;
  if (*option == 0) return 0;
  option++;
  while (*option != 0 && *option == ' ') option++;
  if (*option == 0) return 0;
  return atoi(option);
  }

int process_option(char* pChar) {
  int ret;
  char option[1024];
  ret = -1;
  if (strlen(pChar) < 1) return ret;
  strcpy(option,pChar);
  if (option[0] == '-') {
    if (strcasecmp(option,"-abd") == 0) auto_open_doors = 'Y';
    if (strcasecmp(option,"-abw") == 0) auto_bump_walls = 'Y';
    if (strcasecmp(option,"-ac") == 0) no_arena = 'N';
    if (strcasecmp(option,"-aod") == 0) auto_open_doors = 'Y';
    if (strcasecmp(option,"-apg") == 0) auto_pickup_gold = 'Y';
    if (strcasecmp(option,"-apt") == 0) auto_pickup_torch = 'Y';
    if (strcasecmp(option,"-asw") == 0) auto_bump_walls = 'Y';
    if (strcasecmp(option,"-at") == 0) auto_target = 'Y';
    if (strcasecmp(option,"-c") == 0) heroicMode = -1;
    if (strcasecmp(option,"-clr") == 0) no_color = 'N';
    if (strcasecmp(option,"-e") == 0) heroicMode = 4;
    if (strcasecmp(option,"-eds") == 0) dungeon_scaling = 'Y';
    if (strcasecmp(option,"-fcd") == 0) party_combat_mode = 'F';
    if (strcasecmp(option,"-h") == 0) heroicMode = 2;
    if (strcasecmp(option,"-m") == 0) no_color = 'Y';
    if (strcasecmp(option,"-n") == 0) heroicMode = 0;
    if (strcasecmp(option,"-nabd") == 0) auto_open_doors = 'N';
    if (strcasecmp(option,"-nabw") == 0) auto_bump_walls = 'N';
    if (strcasecmp(option,"-nac") == 0) no_arena = 'Y';
    if (strcasecmp(option,"-naod") == 0) auto_open_doors = 'N';
    if (strcasecmp(option,"-napg") == 0) auto_pickup_gold = 'N';
    if (strcasecmp(option,"-napt") == 0) auto_pickup_torch = 'N';
    if (strcasecmp(option,"-nasw") == 0) auto_bump_walls = 'N';
    if (strcasecmp(option,"-nat") == 0) auto_target = 'N';
    if (strcasecmp(option,"-nds") == 0) dungeon_scaling = 'N';
    if (strcasecmp(option,"-nocrc") == 0) skipcheck = 'Y';
    if (strcasecmp(option,"-rcd") == 0) party_combat_mode = 'R';
    if (strcasecmp(option,"-s") == 0) showStats = -1;
    if (strcasecmp(option,"-sk") == 0) show_keys = 'Y';
    if (strncasecmp(option,"-d=",3) == 0) {
      bottom = option_value(option);
      if (bottom < 2) bottom = 2;
      if (bottom > 10) bottom = 10;
      }
    if (strncasecmp(option,"-dh=",4) == 0) {
      delay_hit = option_value(option);
      }
    if (strncasecmp(option,"-dr=",4) == 0) {
      delay_ranged = option_value(option);
      }
    if (strncasecmp(option,"-dt=",4) == 0) {
      delay_trap = option_value(option);
      }
    if (strncasecmp(option,"-mc=",4) == 0) {
      monster_count = option_value(option);
      if (monster_count < 10) monster_count = 10;
      if (monster_count > 60) monster_count = 60;
      }
    if (strncasecmp(option,"-w=",3) == 0) {
      screen_width = option_value(option);
      }
    if (strncasecmp(option,"-h=",3) == 0) {
      screen_height = option_value(option);
      }
    }
  else {
         if (strcasecmp(option,"ArenaCombat"       ) == 0) no_arena = 'N';
    else if (strcasecmp(option,"AutoOpenDoors"     ) == 0) auto_open_doors = 'Y';
    else if (strcasecmp(option,"AutoPickupGold"    ) == 0) auto_pickup_gold = 'Y';
    else if (strcasecmp(option,"AutoPickupTorch"   ) == 0) auto_pickup_torch = 'Y';
    else if (strcasecmp(option,"AutoSearchWalls"   ) == 0) auto_bump_walls = 'Y';
    else if (strcasecmp(option,"AutoTarget"        ) == 0) auto_target = 'Y';
    else if (strcasecmp(option,"Casual"            ) == 0) heroicMode = -1;
    else if (strcasecmp(option,"Color"             ) == 0) no_color = 'N';
    else if (strcasecmp(option,"DowngradeArena"    ) == 0) downgrade_arena = 'Y';
    else if (strcasecmp(option,"DungeonScaling"    ) == 0) dungeon_scaling = 'Y';
    else if (strcasecmp(option,"Epic"              ) == 0) heroicMode = 4;
    else if (strcasecmp(option,"FkeyGear"          ) == 0) fkey_mode = 'G';
    else if (strcasecmp(option,"FkeyMacros"        ) == 0) fkey_mode = 'M';
    else if (strcasecmp(option,"FkeySpells"        ) == 0) fkey_mode = 'S';
    else if (strcasecmp(option,"FkeyWeapons"       ) == 0) fkey_mode = 'W';
    else if (strcasecmp(option,"FullPartyCombat"   ) == 0) party_combat_mode = 'F';
    else if (strcasecmp(option,"Heroic"            ) == 0) heroicMode = 2;
    else if (strcasecmp(option,"Monochrome"        ) == 0) no_color = 'Y';
    else if (strcasecmp(option,"NoArenaCombat"     ) == 0) no_arena = 'Y';
    else if (strcasecmp(option,"NoAutoOpenDoors"   ) == 0) auto_open_doors = 'N';
    else if (strcasecmp(option,"NoAutoPickupGold"  ) == 0) auto_pickup_gold = 'N';
    else if (strcasecmp(option,"NoAutoPickupTorch" ) == 0) auto_pickup_torch = 'N';
    else if (strcasecmp(option,"NoAutoSearchWalls" ) == 0) auto_bump_walls = 'Y';
    else if (strcasecmp(option,"NoAutoTarget"      ) == 0) auto_target = 'N';
    else if (strcasecmp(option,"NoDungeonScaling"  ) == 0) dungeon_scaling = 'N';
    else if (strcasecmp(option,"NoFullPartyCombat" ) == 0) party_combat_mode = 'R';
    else if (strcasecmp(option,"Normal"            ) == 0) heroicMode = 0;
    else if (strcasecmp(option,"NoCrc"             ) == 0) skipcheck = 'Y';
    else if (strcasecmp(option,"ShowKeys"          ) == 0) show_keys = 'Y';
    else if (strcasecmp(option,"ShowStats"         ) == 0) showStats = -1;
    else if (strncasecmp(option,"DelayHit=",9) == 0) {
           delay_hit = option_value(option);
           }
    else if (strncasecmp(option,"DelayRanged=",12) == 0) {
           delay_ranged = option_value(option);
           }
    else if (strncasecmp(option,"DelayTraps=",11) == 0) {
           delay_trap = option_value(option);
           }
    else if (strncasecmp(option,"Depth=",6) == 0) {
           bottom = option_value(option);
           if (bottom < 2) bottom = 2;
           if (bottom > 10) bottom = 10;
           }
    else if (strncasecmp(option,"MonsterCount=",13) == 0) {
           monster_count = option_value(option);
           if (monster_count < 10) monster_count = 10;
           if (monster_count > 60) monster_count = 60;
           }
    else if (strncasecmp(option,"Width=",6) == 0) {
           screen_width = option_value(option);
           }
    else if (strncasecmp(option,"Height=",7) == 0) {
           screen_height = option_value(option);
           }
    else if (strncasecmp(option,"DowngradeDepth=",9) == 0) {
           downgrade_depth = option_value(option);
           if (downgrade_depth < 2) downgrade_depth = 2;
           }
    else if (strncasecmp(option,"F1=",3) == 0) strcpy(macros[0], option+3);
    else if (strncasecmp(option,"F2=",3) == 0) strcpy(macros[1], option+3);
    else if (strncasecmp(option,"F3=",3) == 0) strcpy(macros[2], option+3);
    else if (strncasecmp(option,"F4=",3) == 0) strcpy(macros[3], option+3);
    else if (strncasecmp(option,"F5=",3) == 0) strcpy(macros[4], option+3);
    else if (strncasecmp(option,"F6=",3) == 0) strcpy(macros[5], option+3);
    else if (strncasecmp(option,"F7=",3) == 0) strcpy(macros[6], option+3);
    else if (strncasecmp(option,"F8=",3) == 0) strcpy(macros[7], option+3);
    else if (strncasecmp(option,"F9=",3) == 0) strcpy(macros[8], option+3);
    else if (strncasecmp(option,"F10=",4) == 0) strcpy(macros[9], option+4);
    else ret = 0;
    }
  return ret;
  }

