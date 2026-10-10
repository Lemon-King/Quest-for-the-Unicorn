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

void up_land() {
  byte key;
  int  x = 0,y = 0;
  int  i;
  int  m_file;
  int  suggest;
  int  sug_level;
  int  see_dist;

  void light_distance() {
    see_dist = 1;
    if (player.hour >=5 && player.hour <6) see_dist = 2;
    if (player.hour >=6 && player.hour < 7) see_dist = 3;
    if (player.hour >=7 && player.hour < 19) see_dist = 5;
    if (player.hour >=19 && player.hour < 20) see_dist = 3;
    if (player.hour >=20 && player.hour < 21) see_dist = 2;
    }

  void discover() {
    int i,j,color = 0;
    light_distance();
    open_display();
    for (i=player.x-see_dist; i<=player.x+see_dist; i++)
      for (j=player.y-see_dist; j<=player.y+see_dist; j++)
        if (i>0 && i<101 && j>0 && j<101 && player.known[i][j] == 0) {
          player.known[i][j] = 1;
          if (i-player.map_x >= 0 && i-player.map_x <= TILES_X &&
              j-player.map_y >= 0 && j-player.map_y <= TILES_Y)
            show_sprite(i-player.map_x,j-player.map_y,player.map[i][j]);
          switch (player.map[i][j]) {
            case  1:color = 10; break;
            case  2:color = 2; break;
            case  3:color = 6; break;
            case  4:color = 1; break;
            case  5:color = 4; break;
            case  6:color = 3; break;
            case  7:color = 8; break;
            case  8:color = 14; break;
            case  9:color = 5; break;
            case 11:color = 4; break;
            case 17:color = 4; break;
            case 19:color = 6; break;
            }
          plot(smap_offset_x-2+i*2,smap_offset_y-1+j*2,color);
          plot(smap_offset_x-1+i*2,smap_offset_y-1+j*2,color);
          plot(smap_offset_x-2+i*2,smap_offset_y-0+j*2,color);
          plot(smap_offset_x-1+i*2,smap_offset_y-0+j*2,color);
          }
    close_display();
    } /* void discover() */

  void check_region() {
    char flag;
    int  m_file;
    flag = ' ';
    if (player.y == 0 && player.region>4) {
#ifdef MINGW
      m_file = open("temp01.$$$",O_RDWR | O_BINARY);
#else
      m_file = open("temp01.$$$",O_RDWR);
#endif
      if (m_file < 0) {
        printf("Fatal Error: Could not open temp01.$$$\n");
        exit(1);
        }
      lseek(m_file,sizeof(KNOW_TYPE) * player.region,SEEK_SET);
      write(m_file,&(player.known),sizeof(KNOW_TYPE));
      player.region = player.region-4;
      lseek(m_file,sizeof(KNOW_TYPE) * player.region,SEEK_SET);
      read(m_file,&(player.known),sizeof(KNOW_TYPE));
      close(m_file);
      copyMap(&player.map,player.region);
      player.y = 100;
      player.map_x = player.x-8;
      player.map_y = player.y-15;
      adjust_map();
      flag = '*';
      }
    if (player.y == 101 && player.region<9) {
#ifdef MINGW
      m_file = open("temp01.$$$",O_RDWR | O_BINARY);
#else
      m_file = open("temp01.$$$",O_RDWR);
#endif
      if (m_file < 0) {
        printf("Fatal Error: Could not open temp01.$$$\n");
        exit(1);
        }
      lseek(m_file,sizeof(KNOW_TYPE) * player.region,SEEK_SET);
      write(m_file,&(player.known),sizeof(KNOW_TYPE));
      player.region = player.region+4;
      lseek(m_file,sizeof(KNOW_TYPE) * player.region,SEEK_SET);
      read(m_file,&(player.known),sizeof(KNOW_TYPE));
      close(m_file);
      copyMap(&player.map,player.region);
      player.y = 1;
      player.map_x = player.x-8;
      player.map_y = player.y-8;
      adjust_map();
      flag = '*';
      }
    if (player.x == 101 && player.region != 4 && player.region != 8 && 
        player.region != 12) {
#ifdef MINGW
      m_file = open("temp01.$$$",O_RDWR | O_BINARY);
#else
      m_file = open("temp01.$$$",O_RDWR);
#endif
      if (m_file < 0) {
        printf("Fatal Error: Could not open temp01.$$$\n");
        exit(1);
        }
      lseek(m_file,sizeof(KNOW_TYPE) * player.region,SEEK_SET);
      write(m_file,&(player.known),sizeof(KNOW_TYPE));
      player.region = player.region+1;
      lseek(m_file,sizeof(KNOW_TYPE) * player.region,SEEK_SET);
      read(m_file,&(player.known),sizeof(KNOW_TYPE));
      close(m_file);
      copyMap(&player.map,player.region);
      player.x = 1;
      player.map_x = player.x-8;
      player.map_y = player.y-8;
      adjust_map();
      flag = '*';
      }
    if (player.x == 0 && player.region != 1 && player.region != 5 &&
        player.region != 9) {
#ifdef MINGW
      m_file = open("temp01.$$$",O_RDWR | O_BINARY);
#else
      m_file = open("temp01.$$$",O_RDWR);
#endif
      if (m_file < 0) {
        printf("Fatal Error: Could not open temp01.$$$\n");
        exit(1);
        }
      lseek(m_file,sizeof(KNOW_TYPE) * player.region,SEEK_SET);
      write(m_file,&(player.known),sizeof(KNOW_TYPE));
      player.region = player.region-1;
      lseek(m_file,sizeof(KNOW_TYPE) * player.region,SEEK_SET);
      read(m_file,&(player.known),sizeof(KNOW_TYPE));
      close(m_file);
      copyMap(&player.map,player.region);
      player.x = 100;
      player.map_x = player.x-15;
      player.map_y = player.y-8;
      adjust_map();
      flag = '*';
      }
    strcpy(player.d_name,regions[player.region-1].name);
    if (player.region == 12) {
      if (player.gateway == ' ' && has_intrinsic(A_GATE)) 
         player.map[80][78] = 32;
      if (player.gateway == ' ' && has_intrinsic(A_GATE) &&
         has_intrinsic(A_GACT)) player.map[80][78] = 31;
      }
    if (player.inship == ' ' && player.ship_r == player.region) {
      player.map[player.ship_x][player.ship_y] = 12;
      }
    if (player.x<=1) player.x = 1;
    if (player.x>100) player.x = 100;
    if (player.y<=1) player.y = 1;
    if (player.y>100) player.y = 100;
    if (flag != ' ')
      { show_land(); show_sm_land(); show_land_player(); }
    } /* void check_region() */

  char valid(int x,int y) {
    char flag;
    flag = '*';
    if (player.inship == ' ') {
      if (player.map[x][y] == 3) flag = ' ';
      if (player.map[x][y] == 4) flag = ' ';
      if (player.peg != 0) flag = '*';
      }
    else {
      flag = ' ';
      if (player.map[x][y] ==4) {
        flag = '*';
        add_skill(SK_BOAT,1);
        }
      }
    if (flag != '*' && player.map[x][y] == 4 && has_intrinsic(A_BOAT)) {
      flag = '*';
      add_skill(SK_BOAT,1);
      }
    if (has_intrinsic(A_WATER) && player.map[x][y] == 4) flag = '*';
    if (has_intrinsic(A_FLY)) flag = '*';
    return flag;
    } /* char valid(int x,int y) */

/*
  void adjust_player_map() {
    char changed;
    changed = 'N';
    if (player.y - player.map_y < 2) {
      player.map_y = player.y - (TILES_Y-4);
      changed = 'Y';
      if (player.map_y < 1) player.map_y = 1;
      }
    if (player.y - player.map_y > TILES_Y-2) {
      player.map_y = player.y - 4;
      changed = 'Y';
      if (player.map_y > 100-TILES_Y) player.map_y = 100-TILES_Y;
      }
    if (player.x - player.map_x < 2) {
      player.map_x = player.x - TILES_X-4;
      changed = 'Y';
      if (player.map_x < 1) player.map_x = 1;
      }
    if (player.x - player.map_x > TILES_X-2) {
      player.map_x = player.x - 4;
      changed = 'Y';
      if (player.map_x > 100-TILES_X) player.map_x = 100-TILES_X;
      }
    if (changed == 'Y') show_land();
    }
*/

  void move_up() {
    remove_land_player();
    player.y = player.y-1;
    check_region();
    if (valid(player.x,player.y) == ' ')
      player.y = player.y+1;
    if (adjust_map() == 'Y') show_land();
    show_land_player();
    stats.counts[STAT_STEPS_TAKEN]++;
    } /* void move_up() */

  void move_down() {
    remove_land_player();
    player.y = player.y+1;
    check_region();
    if (valid(player.x,player.y) == ' ')
      player.y = player.y-1;
    if (adjust_map() == 'Y') show_land();
    show_land_player();
    stats.counts[STAT_STEPS_TAKEN]++;
    } /* void move_down() */

  void move_left() {
    remove_land_player();
    player.x = player.x-1;
    check_region();
    if (valid(player.x,player.y) == ' ')
      player.x = player.x+1;
    if (adjust_map() == 'Y') show_land();
    show_land_player();
    stats.counts[STAT_STEPS_TAKEN]++;
  } /* void move_left() */

  void move_right() {
    remove_land_player();
    player.x = player.x+1;
    check_region();
    if (valid(player.x,player.y) == ' ')
      player.x = player.x-1;
    if (adjust_map() == 'Y') show_land();
    show_land_player();
    stats.counts[STAT_STEPS_TAKEN]++;
  } /* void move_right() */

  void move_up_left() {
    remove_land_player();
    player.y = player.y-1;
    player.x = player.x-1;
    check_region();
    if (valid(player.x,player.y) == ' ')
      { player.x = player.x+1; player.y = player.y+1; }
    if (adjust_map() == 'Y') show_land();
    show_land_player();
    stats.counts[STAT_STEPS_TAKEN]++;
  } /* void move_up_left() */

  void move_up_right() {
    remove_land_player();
    player.y = player.y-1;
    player.x = player.x+1;
    check_region();
    if (valid(player.x,player.y) == ' ')
      { player.x = player.x-1; player.y = player.y+1; }
    if (adjust_map() == 'Y') show_land();
    show_land_player();
    stats.counts[STAT_STEPS_TAKEN]++;
  } /* void move_up_right() */

  void move_down_left() {
    remove_land_player();
    player.y = player.y+1;
    player.x = player.x-1;
    check_region();
    if (valid(player.x,player.y) == ' ')
      { player.x = player.x+1; player.y = player.y-1; }
    if (adjust_map() == 'Y') show_land();
    show_land_player();
    stats.counts[STAT_STEPS_TAKEN]++;
  } /* void move_down_left() */

  void move_down_right() {
    remove_land_player();
    player.y = player.y+1;
    player.x = player.x+1;
    check_region();
    if (valid(player.x,player.y) == ' ')
      { player.x = player.x-1; player.y = player.y-1; }
    if (adjust_map() == 'Y') show_land();
    show_land_player();
    stats.counts[STAT_STEPS_TAKEN]++;
  } /* void move_down_right() */

  void enter_dungeon() {
    char flag;
    int  x;
    LINK_REC link;
    if (player.map[player.x][player.y] == 31) {
      strcpy(player.d_name,"The Gateway");
      exitf = 2;
      player.in_city = 'N';
      player.d_level = 0;
      player.diff = 20;
      if (player.gateway != 'F') player.gateway = '*';
      player.dungeon_number = 99;
      build_dungeon(7,player.dungeon_number);
      }
    if (player.map[player.x][player.y] == 17) {
      exitf = 5;
      player.d_level = 0;
      strcpy(player.d_name,"Village");
      player.in_city = 'Y';
      player.city = 15;
      player.dungeon_number = -1;
      }
    if (player.map[player.x][player.y] == 5) {
      x = 0;
      link = links[x++];
      flag = '*';
      if (link.x != player.x || link.y != player.y || link.typ != 5 ||
          link.region != player.region) flag = ' ';
      while (flag == ' ') {
        link = links[x++];
        flag = '*';
        if (link.x != player.x || link.y != player.y || link.typ != 5 ||
            link.region != player.region) flag = ' ';
        if (link.region == 99) flag = '*';
        }
      if (link.region != 99) {
        exitf = 5;
        player.d_level = 0;
        strcpy(player.d_name,link.name);
        player.in_city = 'Y';
        player.city = link.diff;
        player.dungeon_number = x-1;
        }
      }
    if (player.map[player.x][player.y] == 11) {
      x = 0;
      link = links[x++];
      flag = '*';
      if (link.x != player.x || link.y != player.y || link.typ != 11 ||
          link.region != player.region) flag = ' ';
      while (flag == ' ') {
        link = links[x++];
        flag = '*';
        if (link.x != player.x || link.y != player.y || link.typ != 11 ||
            link.region != player.region) flag = ' ';
        if (link.region == 99) flag = '*';
        }
      if (link.region != 99) {
        exitf = 2;
        player.in_city = 'N';
        player.d_level = 0;
        player.diff = link.diff;
        strcpy(player.d_name,link.name);
        player.dungeon_number = x-1;
        build_dungeon(7,player.dungeon_number);
        }
      }
  } /* void enter_dungeon() */

  void eat() {
    OBJECT_REC* item;
    int i;
    if (player.health > 100) {
      clear_prompt();
      prompt("Too full to eat any more");
      return;
      }
    item = NULL;
    for (i=1; i<11; i++)
      if (player.invent[i].otype == O_FOOD) {
         item = &(player.invent[i]);
         i = 99;
        }
    if (item == NULL) {
      for (i=1; i<=32; i++)
        if (player.pack[i].otype == O_FOOD) {
          item = &(player.pack[i]);
          i = 99;
          }
      }
    if (item == NULL) {
      clear_prompt();
      prompt("Nothing to Eat!!!");
      }
    else {
      if (item->charges != -1) item->charges--;
      if (item->charges == 0) {
        item->otype = O_NONE;
        }
      perform_effect(item);
      show_side();
      }
    }

/*
  void eat() {
    OBJECT_REC* item;
    inv_item = 0;
    item = NULL;
    if (player.health > 100) {
      clear_prompt();
      prompt("Too full to eat any more");
      return;
      }
    if (item == NULL) {
      saveScreen();
      item = inventory(NULL);
      restoreScreen();
      }
    if (item != NULL && item->otype == O_FOOD) {
      if (item->charges != -1) item->charges--;
      if (item->charges == 0) {
        item->otype = O_NONE;
        }
      perform_effect(item);
      }
    show_spot(player.x,player.y);
    show_player();
    show_side();
    } 
*/

  void use_item() { 
    OBJECT_REC* item;
    item = NULL;
    saveScreen();
    item = inventory(item);
    restoreScreen();
    show_spot(player.x,player.y);
    show_player();
    if (item != NULL && item->otype != O_NONE) {
      if (item->otype == O_FOOD && player.health > 100) {
        msg("Too full to eat any more",10);
        }
      else {
        if (item->charges != -1) item->charges--;
        if (item->charges == 0) item->otype = O_NONE;
        perform_effect(item);
        }
      } 
    graphmode();
    show_map();
    show_sm_map();
    discover();
    show_side();
    show_player();
    show_messages();
    clair = ' ';
    } /* void use_item() */

  void hunt() {
    int chance;
    int item_count;
    int item;
    int i;
    chance = 10;
    switch (player.map[player.x][player.y]) {
      case 2:chance = 25; break;
      case 3:chance = 20; break;
      case 4:chance = 0; break;
      case 6:chance = 5; break;
      case 8:chance = 5; break;
      case 9:chance = 17; break;
      }
    if (get_skill(4)>4 && get_skill(4)<10) chance = chance*2;
    if (get_skill(4)>9 && get_skill(4)<15) chance = chance*3;
    if (get_skill(4)>14) chance = chance*4;
    if (u_random(100)<chance) {
      item = -1;
      item_count = 0;
      while (hunting_items[item_count].item != 9999) item_count++;
      while (item < 0) {
        i = u_random(item_count);
        if (u_random(100000) <= hunting_items[i].percent) item = hunting_items[i].item;
        }
      inventory(find_linked_item(item));
      show_screen();
      add_skill(SK_SCOUT,1);
      }
    else {
      msg("Nothing found",14);
      }
  } /* void hunt() */

  void go_ship() {
    if (player.inship != ' ') {
      player.inship = ' ';
      player.map[player.x][player.y] = 12;
      show_spot(player.x,player.y);
      player.ship_x = player.x;
      player.ship_y = player.y;
      player.ship_r = player.region;
      }
    else if (player.map[player.x][player.y] == 12) {
      player.inship = '*';
      player.map[player.x][player.y] = 4;
      }
    show_land_player();
  } /* void go_ship() */

  void new_tardis(int i) {
    char invoke[33];
    char key;
    char buffer[80];
    if (has_intrinsic(A_TARD)) {
      player.tardis_x[i] = player.x;
      player.tardis_y[i] = player.y;
      player.tardis_r[i] = player.region;
      strcpy(invoke,"");
      promptNS("Desc ? _");
      key = 255;
      while (key != 13) {
        key = inkey();
        if (key>31) {
          invoke[strlen(invoke) + 1] = 0;
          invoke[strlen(invoke)] = key;
          clear_prompt();
          sprintf(buffer,"Desc ? %s_",invoke);
          promptNS(buffer);
          }
        if (key == 8 && strlen(invoke)>0) {
          invoke[strlen(invoke) - 1] = 0;
          clear_prompt();
          sprintf(buffer,"Desc ? %s_",invoke);
          promptNS(buffer);
          }
        }
      strcpy(player.tardis_d[i],invoke);
      clear_prompt();
      prompt("Tardis Programmed");
      }
  } /* void new_tardis(int i) */

  void tardis(int i) {
    int m_file;
    if (has_intrinsic(A_TARD))
      if (player.tardis_r[i] != 0) {
#ifdef MINGW
        m_file = open("temp01.$$$",O_RDWR | O_BINARY); 
#else
        m_file = open("temp01.$$$",O_RDWR); 
#endif
        if (m_file < 0) {
          printf("Fatal Error: Could not open temp01.$$$\n");
          exit(1); 
          }
        lseek(m_file,sizeof(KNOW_TYPE) * player.region,SEEK_SET);
        write(m_file,&(player.known),sizeof(KNOW_TYPE));
        player.region = player.tardis_r[i];
        lseek(m_file,sizeof(KNOW_TYPE) * player.region,SEEK_SET);
        read(m_file,&(player.known),sizeof(KNOW_TYPE));
        close(m_file);
        copyMap(&player.map,player.region);
        player.x = player.tardis_x[i];
        player.y = player.tardis_y[i];
        player.map_x = player.x-8;
        player.map_y = player.y-8;
        if (player.map_x<1) player.map_x = 1;
        if (player.map_y<1) player.map_y = 1;
        if (player.map_x>86) player.map_x = 86;
        if (player.map_y>86) player.map_y = 86;
        adjust_map();
        if (player.inship == ' ' && player.ship_r == player.region) {
              player.map[player.ship_x][player.ship_y] = 12;
          }
        if (player.region == 12) {
          if (player.gateway == ' ' && has_intrinsic(A_GATE))
            player.map[80][78] = 32;
          if (player.gateway == ' ' && has_intrinsic(A_GATE) &&
            has_intrinsic(A_GACT)) player.map[80][78] = 31;
          }
        show_map();
        show_sm_map();
        show_side();
        show_land_player();
        }
    } /* void tardis(int i) */

  void tardis_log() {
    int i;
    char buffer[80];
    textmode(3);
    textcolor(2); gotoxy(29,1);
    txt_writeln("Tardis Destination Log");
    gotoxy(23,3);
    txt_writeln("      Region   X   Y   Description");
    textcolor(14);
    for (i=1; i<=10; i++) {
      gotoxy(23,i+4);
      sprintf(buffer,"%2d      %2d    %2d  %2d   %s\n",i,
              player.tardis_r[i], player.tardis_x[i],
              player.tardis_y[i], player.tardis_d[i]);
      txt_write(buffer);
      }
    gotoxy(28,24); textcolor(12);
    txt_write("Press any key to continue");
    inkey();
    graphmode();
    show_map();
    show_sm_map();
    show_side();
    show_land_player();
  } /* void tardis_log() */

  void do_inventory() {
    saveScreen();
    inventory(NULL);
    restoreScreen();
    } /* void do_inventory() */

  void gps() {
    char buffer[20];
    sprintf(buffer,"Region    : %d",player.region);
    msg(buffer,15);
    sprintf(buffer,"X,Y       : %d,%d",player.x,player.y);
    msg(buffer,15);
    }


/* ******************************************* */
/* ***** Actual beginning of upland code ***** */
/* ******************************************* */
  while (keypressed()) key=inkey();
  in_upland = 'Y';
  player.d_level = 0;
  copyMap(&player.map,player.region);
#ifdef MINGW
  m_file = open("temp01.$$$",O_RDONLY | O_BINARY);
#else
  m_file = open("temp01.$$$",O_RDONLY);
#endif
  if (m_file < 0) {
    printf("Fatal Error: Could not open temp01.$$$\n");
    exit(1);
    }
  lseek(m_file,sizeof(KNOW_TYPE) * player.region,SEEK_SET);
  read(m_file,&(player.known),sizeof(KNOW_TYPE));
  close(m_file);
  player.x = player.land_x;
  player.y = player.land_y;
  player.map_x = player.x-8;
  player.map_y = player.y-8;
  adjust_map();
  if (player.inship == ' ' && player.ship_r == player.region) {
      player.map[player.ship_x][player.ship_y] = 12;
    }
  strcpy(player.d_name,regions[player.region-1].name);
  if (player.region == 12) {
    if (player.gateway == ' ' && has_intrinsic(A_GATE))
      player.map[80][78] = 32;
    if (player.gateway == ' ' && has_intrinsic(A_GATE) &&
      has_intrinsic(A_GACT)) player.map[80][78] = 31;
    }
  graphmode();
  show_land();
  show_sm_land();
  show_side();
  discover();
  show_land_player();
  exitf = 0;
  while (exitf == 0) {
    show_time();
    key = inkey();
    switch (key) {
      case 'Q':exitf = 3;
      case '8':move_up(); break;
      case '2':move_down(); break;
      case '4':move_left(); break;
      case '6':move_right(); break;
      case '7':move_up_left(); break;
      case '9':move_up_right(); break;
      case '1':move_down_left(); break;
      case '3':move_down_right(); break;
      case '>':enter_dungeon(); break;
      case '}':save_gear('N',-1); break;
      case ']':load_gear('N',-1); break;
      case '{':save_gear('Y',-1); break;
      case '[':load_gear('Y',-1); break;
      case 'e':eat(); break;
      case 'H':show_icons(); break;
      case 'h':hunt(); break;
      case 's':hunt(); break;
      case 'i':do_inventory(); break;
      case 'E':go_ship(); break;
      case '?':upland_help(); break;
      case 'S':
          player.land_x = player.x;
          player.land_y = player.y;
          if (player.effect[PE_HEROIC] >= 0) exitf = 4;
          else {
            save();
            graphmode();
            show_land();
            show_sm_land();
            show_side();
            show_land_player();
            }
          break;
      case 'u':use_item(); break;
      case 'v':view(player.map[x][y]); break;
      case 'X':exitf = 4; break;
      case 'R':
          disp_char();
          graphmode();
          show_land();
          show_sm_land();
          show_land_player();
          show_side();
          break;
      case '~':gps(); break;
      case 161:tardis(1); break;
      case 162:tardis(2); break;
      case 163:tardis(3); break;
      case 164:tardis(4); break;
      case 165:tardis(5); break;
      case 166:tardis(6); break;
      case 167:tardis(7); break;
      case 168:tardis(8); break;
      case 169:tardis(9); break;
      case 160:tardis(10); break;
      case 201:new_tardis(1); break;
      case 202:new_tardis(2); break;
      case 203:new_tardis(3); break;
      case 204:new_tardis(4); break;
      case 205:new_tardis(5); break;
      case 206:new_tardis(6); break;
      case 207:new_tardis(7); break;
      case 208:new_tardis(8); break;
      case 209:new_tardis(9); break;
      case 210:new_tardis(10); break;
      case 'T':if (has_intrinsic(A_TARD)) tardis_log();
      }
    discover();
    if (classes[player.class-1].flags & CF_MONK) check_monk_weapon();
    player.hp_count = player.hp_count-1;
    for (i=1; i<=19; i++) {
      if (player.invent[i].otype != O_NONE) {
        if ((i==I_NCK1 || i==I_NCK2) &&
            player.invent[i].otype == O_NECK &&
            player.invent[i].effect == E_INTR &&
            player.invent[i].control == A_HEAL) 
          player.hp_count -= player.invent[i].damage;
        else if ((i==I_RNG1 || i==I_RNG2 || i==I_RNG3 || i==I_RNG4) &&
            player.invent[i].otype == O_RING &&
            player.invent[i].effect == E_INTR &&
            player.invent[i].control == A_HEAL) 
          player.hp_count -= player.invent[i].damage;
        else if (i==I_SHLD &&
            player.invent[i].otype == O_SHLD &&
            player.invent[i].effect == E_INTR &&
            player.invent[i].control == A_HEAL) 
          player.hp_count -= player.invent[i].damage;
        else if (i==I_ARMR &&
            player.invent[i].otype == O_ARMR &&
            player.invent[i].effect == E_INTR &&
            player.invent[i].control == A_HEAL) 
          player.hp_count -= player.invent[i].damage;
        else if (i==I_ROBE &&
            player.invent[i].otype == O_ROBE &&
            player.invent[i].effect == E_INTR &&
            player.invent[i].control == A_HEAL) 
          player.hp_count -= player.invent[i].damage;
        else if (i==I_BOOT &&
            player.invent[i].otype == O_BOOT &&
            player.invent[i].effect == E_INTR &&
            player.invent[i].control == A_HEAL) 
          player.hp_count -= player.invent[i].damage;
        else if (i==I_HELM &&
            player.invent[i].otype == O_HELM &&
            player.invent[i].effect == E_INTR &&
            player.invent[i].control == A_HEAL)
          player.hp_count -= player.invent[i].damage;
        else if (player.invent[i].otype != O_NECK &&
                 player.invent[i].otype != O_RING &&
                 player.invent[i].otype != O_SHLD &&
                 player.invent[i].otype != O_ARMR &&
                 player.invent[i].otype != O_ROBE &&
                 player.invent[i].otype != O_BOOT &&
                 player.invent[i].otype != O_HELM &&
                 player.invent[i].effect == E_INTR &&
                 player.invent[i].control == A_HEAL)
               player.hp_count -= player.invent[i].damage;
          }
        }

    if (player.hp_count<1) {
      player.hp_count = 2;
      if (player.chp<player.mhp) player.chp = player.chp+1;
      show_side();
      }
    player.mana_count = player.mana_count-1;
    if (player.mana_count<1) {
      player.mana_count = 3;
      if (player.cmana<player.mmana) player.cmana = player.cmana+1;
      show_side();
      }
    take_time();
    check_encounter();
    if (player.chp<1) exitf = 6;
    if (player.health<=0) exitf = 6;
    if (has_intrinsic(A_COMP)) {
      i = 0;
      suggest = 0;
      sug_level = 999;
      if (player.effect[PE_COMPASS] > 0) {
        while (i >= 0) {
          if (links[i].quest == player.effect[PE_COMPASS]) {
            suggest = i;
            sug_level = links[i].quest;
            }
          i++;
          if (links[i].region > 90) i = -1;
          }
        } else {
        while (i >= 0) {
          if (player.quests[i] != 'Y' && links[i].quest > 0) {
            if (links[i].quest < sug_level) {
              suggest = i;
              sug_level = links[i].quest;
              }
            }
          i++;
          if (links[i].region > 90) i = -1;
          }
        }
      if (sug_level != 999) {
        x = compass(suggest);
/*
        if (abs(player.x-links[suggest].x)<4 && player.y<links[suggest].y) x = 92;
        else if (abs(player.x-links[suggest].x)<4 && player.y>links[suggest].y) x = 91;
        else if (player.x<links[suggest].x && abs(player.y-links[suggest].y)<4) x = 93;
        else if (player.x>links[suggest].x && abs(player.y-links[suggest].y)<4) x = 94;
        else if (player.x<links[suggest].x && player.y<links[suggest].y) x = 97;
        else if (player.x>links[suggest].x && player.y<links[suggest].y) x = 98;
        else if (player.x<links[suggest].x && player.y>links[suggest].y) x = 95;
        else if (player.x>links[suggest].x && player.y>links[suggest].y) x = 96;
        else x = 10;
*/
#ifdef ASCII
          putimage(400,675,select_sprite(10),0);
          putimage(400,675,select_sprite(x),0);
#else
        putimage(300,screen_height-27,select_sprite(10),0);
        putimage(300,screen_height-27,select_sprite(x),0);
#endif
        } else putimage(300,screen_height-27,select_sprite(10),0);
      }
    if (has_intrinsic(A_FOOD) && player.health < 100) player.health++;
    if (get_str() <= 0 || get_dex() <= 0 || get_int() <= 0 ||
        get_con() <= 0 || get_wis() <= 0 || get_chr() <= 0) exitf = 9;
    }
  if (exitf == 3) mod_exit = 3;
  if (exitf == 2) mod_exit = 2;
  if (exitf == 4) mod_exit = 4;
  if (exitf == 5) mod_exit = 5;
  if (exitf == 6) mod_exit = 6;
  if (exitf == 9) mod_exit = 9;
#ifdef MINGW
  m_file = open("temp01.$$$",O_WRONLY | O_BINARY);
#else
  m_file = open("temp01.$$$",O_WRONLY);
#endif
  if (m_file < 0) {
    printf("Fatal Error: Could not open temp01.$$$\n");
    exit(1);
    }
  lseek(m_file,sizeof(KNOW_TYPE) * player.region,SEEK_SET);
  write(m_file,&(player.known),sizeof(KNOW_TYPE));
  close(m_file);
  player.land_x = player.x;
  player.land_y = player.y;
  in_upland = 'N';
}

