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

void view(int floor) {
  int  i = 0,x,y;
  int  key;
  char buffer[255];
/*
  char mflag;
  int  xdir,ydir;
  get_dir(&xdir,&ydir);
  x = player.x;
  y = player.y;
  mflag = ' ';
  while (mflag == ' ') {
    x += xdir;
    y += ydir;
    if (player.map[x][y] != floor) mflag = '*';
    if (player.map[x][y] > 800 && player.map[x][y] < 899) mflag = ' ';
    if (player.map[x][y] == 15) mflag = ' ';
    }
  target(100,-1,0);
  x = target_x;
  y = target_y;
*/
  setcolor(15);
  msg("Press <ESC> to end view mode",15);
  x = player.x - player.map_x;
  y = player.y - player.map_y;
  key = 0;
  show_sprite(x,y,100);
  while (key != 13 && key != 27) {
    key = inkey();
    show_spot(x + player.map_x,y + player.map_y);
    show_player();
    switch (key) {
      case '2': y++;
                if (y>TILES_Y) y = TILES_Y;
                break;
      case '8': y--;
                if (y < 1) y = 1;
                break;
      case '6': x++;
                if (x>TILES_X) x = TILES_X;
                break;
      case '4': x--;
                if (x < 1) x = 1;
                break;
      case '7': x--; y--;
                if (x < 1) x = 1;
                if (y < 1) y = 1;
                break;
      case '9': x++; y--;
                if (x>TILES_X) x = TILES_X;
                if (y < 1) y = 1;
                break;
      case '1': x--; y++;
                if (x < 1) x = 1;
                if (y>TILES_Y) y = TILES_Y;
                break;
      case '3': x++; y++;
                if (x>TILES_X) x = TILES_X;
                if (y>TILES_Y) y = TILES_Y;
                break;

      }
    show_sprite(x,y,100);
#ifdef ASCII
    gotoxy(40,25);
    txt_write("                                      ");
    gotoxy(40,25);
#else
    outtextxyclr(screen_width-160, screen_height-15,"                                      ");
#endif
    if (los(player.x,player.y,x+player.map_x,y+player.map_y,'Y')) {
      setcolor(CLR_YELLOW);
      strcpy(buffer,"");
    if (player.map[x+player.map_x][y+player.map_y] >= 600 && player.map[x+player.map_x][y+player.map_y] <= 699) strcpy(buffer,"Forbidding");
    else if (player.map[x+player.map_x][y+player.map_y] >= 700 && player.map[x+player.map_x][y+player.map_y] <= 799) strcpy(buffer,"Phase Door");
    else switch (player.map[x+player.map_x][y+player.map_y]) {
      case  1:strcpy(buffer,"Plains"); break;
      case  2:strcpy(buffer,"Forest"); break;
      case  3:strcpy(buffer,"Mountains"); break;
      case  4:strcpy(buffer,"Water"); break;
      case  5:strcpy(buffer,"City"); break;
      case  6:strcpy(buffer,"Swamp"); break;
      case  8:strcpy(buffer,"Desert"); break;
      case  9:strcpy(buffer,"Hills"); break;
      case 10:strcpy(buffer,"Darkness"); break;
      case 11:strcpy(buffer,"Dungeon Entrance"); break;
      case 12:strcpy(buffer,"Your Ship"); break;
      case 13:strcpy(buffer,"Ship"); break;
      case 14:strcpy(buffer,"Dock"); break;
      case 16:strcpy(buffer,"Cactus"); break;
      case 17:strcpy(buffer,"Village"); break;
      case 18:strcpy(buffer,"Rock"); break;
      case 19:strcpy(buffer,"Pass"); break;
      case 20:strcpy(buffer,"Tree"); break;
      case 21:strcpy(buffer,"Wall"); break;
      case 22:strcpy(buffer,"Closed Door"); break;
      case 23:strcpy(buffer,"Open Door"); break;
      case 24:strcpy(buffer,"Down Stairs"); break;
      case 25:strcpy(buffer,"Up Stairs"); break;
      case 26:strcpy(buffer,"Chair"); break;
      case 27:strcpy(buffer,"Table"); break;
      case 28:strcpy(buffer,"Merchant"); break;
      case 29:strcpy(buffer,"Bed"); break;
      case 30:strcpy(buffer,"Shelves"); break;
      case 31:strcpy(buffer,"Gateway"); break;
      case 32:strcpy(buffer,"Gateway"); break;
      case 33:strcpy(buffer,"Jammed Door"); break;
      case 36:strcpy(buffer,"Sleeping"); break;
      case 38:strcpy(buffer,"Wall of Fire"); break;
      case 39:strcpy(buffer,"Wall of Water"); break;
      case 40:strcpy(buffer,"Disarmed Trap"); break;
      case 41:strcpy(buffer,"Forbidding"); break;
      case 42:strcpy(buffer,"Phase Door"); break;
      case 79:strcpy(buffer,"Gold"); break;
      case 84:strcpy(buffer,"Torch"); break;
      case 99:strcpy(buffer,"Food"); break;
      case 176:strcpy(buffer,"Rock"); break;
      case 178:strcpy(buffer,"Rock"); break;
      case 536:strcpy(buffer,"Gacha Machine"); break;
      case 901:strcpy(buffer,"Altar"); break;
      case 902:strcpy(buffer,"Dull Altar"); break;
      case 903:strcpy(buffer,"Dull Runestone"); break;
      case 904:strcpy(buffer,"Blue Runestone"); break;
      case 905:strcpy(buffer,"Red Runestone"); break;
      case 906:strcpy(buffer,"Purple Runestone"); break;
      case 907:strcpy(buffer,"White Runestone"); break;
      case 908:strcpy(buffer,"Yellow Runestone"); break;
      case 909:strcpy(buffer,"Green Runestone"); break;
      case 910:strcpy(buffer,"Cyan Runestone"); break;
      case 951:strcpy(buffer,"Armed Trap"); break;
      case 952:strcpy(buffer,"Armed Trap"); break;
      case 953:strcpy(buffer,"Armed Trap"); break;
      case 954:strcpy(buffer,"Armed Trap"); break;
      case 955:strcpy(buffer,"Armed Trap"); break;
      case 956:strcpy(buffer,"Armed Trap"); break;
      case 957:strcpy(buffer,"Armed Trap"); break;
      case 958:strcpy(buffer,"Armed Trap"); break;
      case 959:strcpy(buffer,"Armed Trap"); break;
      case 960:strcpy(buffer,"Armed Trap"); break;
      case 961:strcpy(buffer,"Armed Trap"); break;
      }
    if (player.map[x+player.map_x][y+player.map_y] >= 1000) {
      strcpy(buffer,get_name(&(player.map_objects[player.map[x+player.map_x][y+player.map_y] - 1000])));
      itemColor(&(player.map_objects[player.map[x+player.map_x][y+player.map_y] - 1000]));
      }
    if (player.map[x+player.map_x][y+player.map_y] < 0 ||
        (player.map[x+player.map_x][y+player.map_y] > 299 && player.map[x+player.map_x][y+player.map_y] < 400) ||
        (player.map[x+player.map_x][y+player.map_y] > 399 && player.map[x+player.map_x][y+player.map_y] < 500)) {
      if (player.map[x+player.map_x][y+player.map_y] < 0) i = player.monster[1][0-player.map[x+player.map_x][y+player.map_y]].sprite;
      if (player.map[x+player.map_x][y+player.map_y] > 299 && player.map[x+player.map_x][y+player.map_y] < 400)
        i = player.party[player.map[x+player.map_x][y+player.map_y] - 300].sprite;
      if (player.map[x+player.map_x][y+player.map_y] > 399 && player.map[x+player.map_x][y+player.map_y] < 500)
        i = player.monster[player.map[x+player.map_x][y+player.map_y] - 400][a_mon].sprite;
      switch (i) {
        case  101:strcpy(buffer,"Air Elemental"); break;
        case  102:strcpy(buffer,"Insectoid"); break;
        case  103:strcpy(buffer,"Rodent"); break;
        case  104:strcpy(buffer,"Large Animal"); break;
        case  105:strcpy(buffer,"Beholder Like"); break;
        case  106:strcpy(buffer,"Blob"); break;
        case  107:strcpy(buffer,"Blob"); break;
        case  108:strcpy(buffer,"Roper"); break;
        case  109:strcpy(buffer,"Bulette"); break;
        case  110:strcpy(buffer,"Centipede Type"); break;
        case  111:strcpy(buffer,"Fire Elemental"); break;
        case  112:strcpy(buffer,"Water Elemental"); break;
        case  113:strcpy(buffer,"Earth Elemental"); break;
        case  114:strcpy(buffer,"Efreeti"); break;
        case  115:strcpy(buffer,"Gargoyle Like"); break;
        case  116:strcpy(buffer,"Gelletanous Cube"); break;
        case  117:strcpy(buffer,"Griffon"); break;
        case  118:strcpy(buffer,"Ghost Like"); break;
        case  119:strcpy(buffer,"Harpy"); break;
        case  120:strcpy(buffer,"Dog Like"); break;
        case  121:strcpy(buffer,"Dwarf Like"); break;
        case  122:strcpy(buffer,"Hydra"); break;
        case  123:strcpy(buffer,"Orc Like"); break;
        case  124:strcpy(buffer,"Lamia"); break;
        case  125:strcpy(buffer,"Skeleton"); break;
        case  126:strcpy(buffer,"Lizard Like"); break;
        case  127:strcpy(buffer,"Manticore"); break;
        case  128:strcpy(buffer,"Medusa"); break;
        case  129:strcpy(buffer,"Mind Flayer"); break;
        case  130:strcpy(buffer,"Minotaur"); break;
        case  131:strcpy(buffer,"Horse Like"); break;
        case  132:strcpy(buffer,"Unicorn"); break;
        case  133:strcpy(buffer,"Pegasus"); break;
        case  134:strcpy(buffer,"Frog"); break;
        case  135:strcpy(buffer,"Giant"); break;
        case  136:strcpy(buffer,"Mummy Like"); break;
        case  137:strcpy(buffer,"Naga"); break;
        case  138:strcpy(buffer,"Nightmare"); break;
        case  139:strcpy(buffer,"Nymph Like"); break;
        case  140:strcpy(buffer,"Sprite Like"); break;
        case  141:strcpy(buffer,"Purple Worm"); break;
        case  142:strcpy(buffer,"Scorpian"); break;
        case  143:strcpy(buffer,"Snake Like"); break;
        case  144:strcpy(buffer,"Sphinx"); break;
        case  145:strcpy(buffer,"Spider"); break;
        case  146:strcpy(buffer,"Umber Hulk"); break;
        case  147:strcpy(buffer,"Will-o-Wisp"); break;
        case  148:strcpy(buffer,"Centaur"); break;
        case  149:strcpy(buffer,"Demogorgon"); break;
        case  150:strcpy(buffer,"Orcus"); break;
        case  151:strcpy(buffer,"Succubus"); break;
        case  152:strcpy(buffer,"Demon Like"); break;
        case  153:strcpy(buffer,"Dragon"); break;
        case  154:strcpy(buffer,"Dragon"); break;
        case  155:strcpy(buffer,"Dragon"); break;
        case  156:strcpy(buffer,"Dragon"); break;
        case  157:strcpy(buffer,"Dragon"); break;
        case  158:strcpy(buffer,"Dragon"); break;
        case  159:strcpy(buffer,"Dragon"); break;
        case  160:strcpy(buffer,"Dalek"); break;
        case  161:strcpy(buffer,"Female Humanoid"); break;
        case  162:strcpy(buffer,"Male Humanoid"); break;
        case  163:strcpy(buffer,"Fighter"); break;
        case  164:strcpy(buffer,"Cleric"); break;
        case  165:strcpy(buffer,"Wizard"); break;
        case  166:strcpy(buffer,"Dark Magi"); break;
        case  331:strcpy(buffer,"Sirine"); break;
        case  333:strcpy(buffer,"Orc Warchief"); break;
        case  334:strcpy(buffer,"Dragon Queen"); break;
        case  335:strcpy(buffer,"Count Tralin"); break;
        case  336:strcpy(buffer,"Forest Elemental"); break;
        case  337:strcpy(buffer,"Lamia Queen"); break;
        case  338:strcpy(buffer,"Kobold Lord"); break;
        case  339:strcpy(buffer,"Kobold"); break;
        case  340:strcpy(buffer,"Caldnar"); break;
        case  341:strcpy(buffer,"Elanther"); break;
        case  342:strcpy(buffer,"Summoned Snake"); break;
        }
      }
      } else strcpy(buffer,"Out of sight");
    if (strlen(buffer) > 38) buffer[38] = 0;
#ifdef ASCII
    gotoxy(40,25);
    txt_write(buffer);
#else
    outtextxyclr(screen_width-160, screen_height-15,buffer);
    flush();
#endif
    }
#ifdef ASCII
  gotoxy(40,25);
  txt_write("                                      ");
#else
  outtextxyclr(screen_width-160, screen_height-15,"                                      ");
#endif
  show_spot(x + player.map_x,y + player.map_y);
  show_player();
  }
