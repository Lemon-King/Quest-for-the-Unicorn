/*
 *******************************************************************
 *** This software is copyright 1985-2014 by Michael H Riley     ***
 *** You have permission to use, modify, copy, and distribute    ***
 *** this software so long as this copyright notice is retained. ***
 *** This software may not be used in commercial applications    ***
 *** without express written permission from the author.         ***
 *******************************************************************
*/

#define MAIN

#include "header.h"

int main2(int argc,char** argv) {
  int i;
  int loadgame;
  struct timeval tim;
  time_t         date_time;
  int loot_commons;
  int loot_uncommons;
  int loot_rares;
  int loot_very_rares;
  int loot_ultra_rares;

#ifdef ASCII
  char k;
  int  tw,th;
  tw = 0;
  th = 0;
  unbuffer();
  printf("\e[18t\n");
  delay(100);
  i = 0;
  while (keypressed() && i < 20) {
    read(0, &k, 1);
    buffer[i++] = k;
    }
  if (buffer[strlen(buffer)-1] == 't') {
    sscanf(buffer+3,";%d;%d",&th,&tw);
    }
  restoreTerm();
#endif


#ifdef DEBUG
  debug_tab = 0;
#endif
  strcpy(currentMacro,"");
  Rcs_Seed(1);
  current_dungeon.dungeon_number = -1;
  date_time = time(NULL);
  date = *(localtime(&date_time));
  date.tm_mon += 1;
  date.tm_year += 1900;
  screen_width = 640;
  screen_height = 480;
  tile_width = 25;
  tile_height = 27;
  TEXT_GRID_WIDTH = 80;
  TEXT_GRID_HEIGHT = 25;
  NUM_MSG = 10;
  for (i=0; i<10; i++) strcpy(macros[i],"");
#ifdef ASCII
  TILES_X = 55;
  TILES_Y = 23;
#else
  TILES_X = 16;
  TILES_Y = 16;
#endif
  fkey_mode = 'S';
  loot_commons = 0;
  loot_uncommons = 0;
  loot_rares = 0;
  loot_very_rares = 0;
  loot_ultra_rares = 0;
  showStats = 0;
  in_arena = 'N';
  auto_target = 'Y';
  combat_mode = 's';
  score1 = 0;
  score2 = 0;
  wizardmode = 'N';
  u_randomize();
  soundon = 'Y';
  restock = 'N';
  loadgame = 0;
  bottom = 5;
  no_color = 'N';
  heroicMode = 0;
  skipcheck = 'N';
  in_upland = 'N';
  show_keys = 'N';
  auto_pickup_gold = 'N';
  auto_pickup_torch = 'N';
  auto_open_doors = 'N';
  auto_bump_walls = 'N';
  no_arena = 'Y';
  downgrade_arena = 'N';
  downgrade_depth = -1;
  dungeon_scaling = 'N';
  used_sunstone = 'N';
  party_combat_mode = 'R';
  monster_count = 60;
  delay_ranged = 5;
  delay_hit = 200;
  delay_trap = 100;
  last_target_x = 0;
  last_target_y = 0;
  gettimeofday(&tim,NULL);
  start_time = tim.tv_sec;
  for (i=0; i<60; i++) {
    strcpy(messages[i],"");
    msg_clr[i] = 15;
    }
  process_config("unicorn");
  for (i=1; i<argc; i++) {
    if (process_option(argv[i]) == 0) {
      loadgame = 1;
      strcpy(loadname,argv[i]);
      }
    }
  if (loadgame == 1) {
    for (i=0; i<strlen(loadname); i++)
      if (loadname[i] == '.') loadname[i] = 0;
    process_config(loadname);
    }
  if (screen_width < 640) screen_width = 640;
  if (screen_height < 480) screen_height = 480;
#ifndef ASCII
  TILES_X = (screen_width - 240) / tile_width;
  TILES_Y = (screen_height - 48) / tile_height;
  screen_width = (TILES_X * tile_width) + 240;
  screen_height = (TILES_Y * tile_height) + 48;
#endif
  TEXT_GRID_WIDTH = screen_width / 8;
  TEXT_GRID_HEIGHT = screen_height / 19;
  smap_offset_x = screen_width - 219;
  smap_offset_y = screen_height - 239;
#ifndef ASCII
  NUM_MSG = (smap_offset_y - 110) / MESSAGE_HEIGHT;
#endif
#ifdef ASCII
  text_offset_x = 0;
  text_offset_y = 0;
  TEXT_GRID_WIDTH = 80;
  TEXT_GRID_HEIGHT = 25;
//  if (tw > 80 && th > 24) {
//    TEXT_GRID_WIDTH = tw;
//    TEXT_GRID_HEIGHT = th;
//    TILES_X = TEXT_GRID_WIDTH - 25;
//    TILES_Y = TEXT_GRID_HEIGHT - 2;
//    }
#else
  text_offset_x = (TEXT_GRID_WIDTH - 80) / 2;
  text_offset_y = (TEXT_GRID_HEIGHT - 25) / 2;
#endif
  trophy_count = 0;
  while (trophies[trophy_count].criteria_type < 999) trophy_count++;
  if (showStats) printf("Trophy Count: %d\n",trophy_count);
  i=0;
  while (objects[i].otype < 999) {
    if (objects[i].rarity > 2500) loot_commons++;
    if (objects[i].rarity > 500 && objects[i].rarity <= 2500) loot_uncommons++;
    if (objects[i].rarity > 100 && objects[i].rarity <= 500) loot_rares++;
    if (objects[i].rarity > 5 && objects[i].rarity <= 100) loot_very_rares++;
    if (objects[i].rarity > 0 && objects[i].rarity <= 5) loot_ultra_rares++;
    i++;
    }
  NO_OF_OBJECTS = i;
  TOTAL_OBJECTS = i;
  if (showStats) {
    printf("Object Count: %d\n",i);
    printf("  Common     : %d\n",loot_commons);
    printf("  Uncommon   : %d\n",loot_uncommons);
    printf("  Rare       : %d\n",loot_rares);
    printf("  Very Rare  : %d\n",loot_very_rares);
    printf("  Ultra Rare : %d\n",loot_ultra_rares);
    printf("  Non Drop   : %d\n",i - (loot_commons + loot_uncommons + loot_rares + loot_very_rares + loot_ultra_rares));
    }
  i=0;
  while (gen[i].region < 99) i++;
  NO_OF_GENS = i;
  if (showStats) printf("Message Count: %d\n",i);
  i=0;
  recipe_start = -1;
  while (lore[i].region < 99) {
    if (strncmp(lore[i].message,"Recipe:",7) == 0 && recipe_start < 0) recipe_start = i;
    i++;
    }
  NO_OF_LORE = i;
  if (showStats) printf("Lore Count: %d\n",i);
  i=0;
  while (recipes[i].object < 999) i++;
  recipe_count = i;
  if (showStats) printf("Recipe Count: %d\n",i);
  num_spells = 0;
  while (spells[num_spells].effect != 999) {
    if (spells[num_spells].number != num_spells) printf("Spell number mismatch: %d\n",num_spells);
    num_spells++;
    }
  if (showStats) printf("Spell Count: %d\n",num_spells);
  i = 0;
  while (monsters[i].speed < 900) i++;
  NO_OF_MONSTERS = i;
  if (showStats) printf("Monster Count: %d\n",NO_OF_MONSTERS);
  if (showStats) {
    printf("Options:\r\n");
    printf("  Auto Pickup Gold: %c\r\n",auto_pickup_gold);
    printf("  Auto Pickup Torches: %c\r\n",auto_pickup_torch);
    printf("  Auto Open Doors: %c\r\n",auto_open_doors);
    printf("  Auto Search Walls: %c\r\n",auto_bump_walls);
    printf("  Dungeon Depth: %d\n",bottom);
    printf("  Dungeon Scaling: %c\n",dungeon_scaling);
    printf("  Monster Count: %d\n",monster_count);
    printf("  Party Combat Mode: %c\n",party_combat_mode);
    printf("  Delay (traps): %d\n",delay_trap);
    printf("  Delay (ranged): %d\n",delay_ranged);
    printf("  Delay (hit): %d\n",delay_hit);
    if (heroicMode == -1) printf("  Game Mode: Casual\n");
    if (heroicMode == 0) printf("  Game Mode: Normal\n");
    if (heroicMode == 2) printf("  Game Mode: Heroic\n");
    if (heroicMode == 4) printf("  Game Mode: Epic\n");
    if (fkey_mode == 'S') printf("  Fkeys: Spells\n");
    if (fkey_mode == 'W') printf("  Fkeys: Weapons\n");
    if (fkey_mode == 'G') printf("  Fkeys: Gear\n");
    printf("  Screen Size: %d x %d\n", screen_width, screen_height);
    printf("Macros:\n");
    for (i=0; i<10; i++)
      printf("  F%d = %s\n",i+1,macros[i]);
    }
  if (showStats != 0) return(0);
  graphics = ' ';
  read_sprites();
  unbuffer();
  init_graph();
  title();
//MessageBox(NULL, TEXT("Hmmmmm"), TEXT("Error"), MB_ICONERROR | MB_OK);
  hall_position = -1;
  death_position = -1;
  num_hall_of_fame = 0;
  num_final_scores = 0;
  load_scores();
  show_legends();
/*
  show_final_scores();
*/
  if (loadgame == 1) {
    i = strlen(loadname);
    if (i > 4 && loadname[i-4] == '.') loadname[i-4] = 0;
    textmode(3); gotoxy(1,1); textcolor(10);
    txt_write("Loading Game . . .");
    load();
    if (player.d_level>0) mod_exit = 2;
      else mod_exit = 1;
    disp_char();
    }
  else {
    new_game();
    make_char(0);
    mod_exit = 1;
    build_dungeon(7,0);
    }
  exit_flag = ' ';
  while (exit_flag == ' ') {
    if (mod_exit == 1) up_land();
    if (mod_exit == 2) cave();
    if (mod_exit == 3) exit_flag = '*';
    if (mod_exit == 4) exit_flag = 'S';
    if (mod_exit == 5) cave();
    if (mod_exit == 6) exit_flag = 'D';
    if (mod_exit == 7) { make_char(1); mod_exit = 1; }
    if (mod_exit == 9) exit_flag = 'O';
    }
  gettimeofday(&tim,NULL);
  end_time = tim.tv_sec;
  player.time_played += (end_time - start_time);
  if (exit_flag == 'S') save();
  textmode(3);
  unlink(backupname);
  score_position = 0;
  if (exit_flag == '*') {
    textcolor(12);
    gotoxy(21,12);
    txt_writeln("You have cowardly given up your quest!!");
    flush();
    delay(2500);
    final_score('Q');
    show_final_scores();
    }
  if (exit_flag == 'D') {
    textcolor(12);
    gotoxy(27,12);
    txt_writeln("Sorry but you have died!!");
    flush();
    delay(2500);
    final_score('D');
    show_final_scores();
    }
  if (exit_flag == 'O') {
    textcolor(12);
    gotoxy(22,12);
    txt_writeln("Sorry but you have died of old age!!");
    flush();
    delay(2500);
    final_score('D');
    show_final_scores();
    }
  check_scores();
  if (score1>0 || score2>0) show_scores();
  textmode(3);
  unlink("temp01.$$$");
#ifdef ASCII
  if (no_color != 'Y') printf("\e[0;30m");
  clrscr();
  restoreTerm();
#endif
  return 0;
  }

#ifndef WIN32
int main(int argc,char** argv) {
  return main2(argc, argv);
  }
#endif

#ifdef WIN32
#include <windows.h>

extern void rcs_initWin32(HINSTANCE hInstance);

int APIENTRY WinMain(HINSTANCE hInstance,
                                         HINSTANCE hPrevInstance,
                                         LPSTR     lpCmdLine,
                                         int       nCmdShow) {
        int argc;
                char **argv;
                char buffer[1024];
                char *pBuffer;
        rcs_initWin32(hInstance);
                strcpy(buffer,"unicorn");
                argv=(char**)malloc(sizeof(char*));
                argv[0] = (char*)malloc(strlen(buffer) + 1);
                strcpy(argv[0],buffer);
                argc = 1;
                pBuffer = buffer;
                while (*lpCmdLine != 0) {
                        if (*lpCmdLine <= ' ') {
                                if (pBuffer != buffer) {
                                        argc += 1;
                                        argv=(char**)realloc(argv,sizeof(char*) * argc);
                                        argv[argc-1] = (char*)malloc(strlen(buffer) + 1);
                                        strcpy(argv[argc-1],buffer);
                                        pBuffer = buffer;
                                }
                                lpCmdLine++;
                        } else {
                                *pBuffer++ = *lpCmdLine++;
                                *pBuffer = 0;
                        }
                }
                if (pBuffer != buffer) {
                        argc += 1;
                        argv=(char**)realloc(argv,sizeof(char*) * argc);
                        argv[argc-1] = (char*)malloc(strlen(buffer) + 1);
                        strcpy(argv[argc-1],buffer);
                        pBuffer = buffer;
                }
        main2(argc,argv);
        return 0;
}
#endif

