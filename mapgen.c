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

#define SECRET_CHANCE  10

typedef struct {
  int x;
  int y;
  int width;
  int height;
  int hits;
  } ROOM;

ROOM rooms[20];
int walls;
int floors;
int doors;
int secrets;
int roomlinks;

void clearMap(MAP_TYPE* map) {
  int x,y;
#ifdef DEBUG
  sprintf(debugbuffer,"%*sclearMap begin\n",debug_tab,"");
  debug_tab += 2;
  debugLog(debugbuffer);
#endif
  for (x=0; x<100; x++) 
    for (y=0; y<100; y++)
      (*map)[x][y] = walls;
#ifdef DEBUG
  sprintf(debugbuffer,"%*sExiting\n",debug_tab,"");
  debug_tab -= 2;
  debugLog(debugbuffer);
#endif
  }

void addRoom(int n,int rx,int ry,int mx,int my,MAP_TYPE* map) {
  int x,y;
  int px,py;
#ifdef DEBUG
  sprintf(debugbuffer,"%*saddRoom begin n=%d,rx=%d,ry=%d,mx=%d,my=%d\n",debug_tab,"",n,rx,ry,mx,my);
  debug_tab += 2;
  debugLog(debugbuffer);
#endif
  rooms[n].width = 7+Rcs_Random(10);
  rooms[n].height = 7+Rcs_Random(10);
  px = mx - rooms[n].width-4;
  py = my - rooms[n].height-4;
  rooms[n].x = rx + 2 + Rcs_Random(px);
  rooms[n].y = ry + 2 + Rcs_Random(py);
  for (x=rooms[n].x; x<rooms[n].x+rooms[n].width; x++)
    for (y=rooms[n].y; y<rooms[n].y+rooms[n].height; y++)
      (*map)[x][y] = floors;
  rooms[n].hits = 0;
#ifdef DEBUG
  sprintf(debugbuffer,"%*sExiting\n",debug_tab,"");
  debug_tab -= 2;
  debugLog(debugbuffer);
#endif
  }

int tooCloseVertical(int x,int y,MAP_TYPE* map) {
  if (x < 4 || y < 4 || x > 95 || y > 95) return -1;
  if ((*map)[x][y-1] != walls || (*map)[x][y-2] != walls) return -1;
  if ((*map)[x][y+1] != walls || (*map)[x][y+2] != walls) return -1;
  return 0;
  }

int tooCloseHorizontal(int x,int y,MAP_TYPE* map) {
  if (x < 4 || y < 4 || x > 95 || y > 95) return -1;
  if ((*map)[x-1][y] != walls || (*map)[x-2][y] != walls) return -1;
  if ((*map)[x+1][y] != walls || (*map)[x+2][y] != walls) return -1;
  return 0;
  }

int checkPath(int sx,int sy,int dx,int dy,MAP_TYPE* map) {
  int x,y;
  if (sx == dx) {
    if (dy < sy) { y = sy; sy = dy; dy = y; }
    for (y=sy; y<=dy; y++)
      if (tooCloseHorizontal(sx,y,map)) return 0;
    } else {
    if (dx < sx) { x = sx; sx = dx; dx = x; }
    for (x=sx; x<=dx; x++)
      if (tooCloseVertical(x,sy,map)) return 0;
    }
  return -1;
  }

int digTunnel(int sx,int sy,int dx,int dy,int check,MAP_TYPE* map) {
  int i;
  if (check)
    if (checkPath(sx,sy,dx,dy,map) == 0) return 0;
  if (sy == dy) {
    if (dx < sx) { i = sx; sx = dx; dx = i; }
    for (i=sx; i<=dx; i++) (*map)[i][dy] = floors;
    } else {
    if (dy < sy) { i = sy; sy = dy; dy = i; }
    for (i=sy; i<=dy; i++) (*map)[dx][i] = floors;
    }
  if (check) {
    if (Rcs_Random(100) < SECRET_CHANCE) (*map)[sx][sy] = secrets;
    else if (Rcs_Random(100) < 80) (*map)[sx][sy] = doors;
    if (Rcs_Random(100) < SECRET_CHANCE) (*map)[dx][dy] = secrets;
    else if (Rcs_Random(100) < 80) (*map)[dx][dy] = doors;
    }
  return -1;
  }

int digLTunnel(int sx,int sy,int mx,int my,int dx,int dy,MAP_TYPE* map) {
  if (checkPath(sx,sy,mx,my,map) == 0 || checkPath(mx,my,dx,dy,map) == 0) return 0;
  digTunnel(sx,sy,mx,my,0,map);
  digTunnel(mx,my,dx,dy,0,map);
  if (Rcs_Random(100) < SECRET_CHANCE) (*map)[sx][sy] = secrets;
  else if (Rcs_Random(100) < 80) (*map)[sx][sy] = doors;
  if (Rcs_Random(100) < SECRET_CHANCE) (*map)[dx][dy] = secrets;
  else if (Rcs_Random(100) < 80) (*map)[dx][dy] = doors;
  return -1;
  }

int digUTunnel(int sx,int sy,int mx,int my,int nx,int ny,int dx,int dy,MAP_TYPE* map) {
  if (checkPath(sx,sy,mx,my,map) == 0) return 0;
  if (checkPath(mx,my,nx,ny,map) == 0) return 0;
  if (checkPath(nx,ny,dx,dy,map) == 0) return 0;
  digTunnel(sx,sy,mx,my,0,map);
  digTunnel(mx,my,nx,ny,0,map);
  digTunnel(nx,ny,dx,dy,0,map);
  if (Rcs_Random(100) < SECRET_CHANCE) (*map)[sx][sy] = secrets;
  else if (Rcs_Random(100) < 80) (*map)[sx][sy] = doors;
  if (Rcs_Random(100) < SECRET_CHANCE) (*map)[dx][dy] = secrets;
  else if (Rcs_Random(100) < 80) (*map)[dx][dy] = doors;
  return -1;
  }

int horizontal(int room1,int room2,MAP_TYPE* map) {
  int y;
  int x;
  int retries;
  int sx,sy,mx,my,dx,dy;
  int flag;
#ifdef DEBUG
  sprintf(debugbuffer,"%*shorizontal begin room1=%d, room2=%d\n",debug_tab,"",room1,room2);
  debug_tab += 2;
  debugLog(debugbuffer);
#endif
  if (room2 < room1) {
    x = room1; room1 = room2; room2 = x;
    }
  /* ************************************************ */
  /* ***** Attempt connection from edge to edge ***** */
  /* ************************************************ */
  retries = 25;
  flag = 0;
  while (flag == 0 && retries > 0) {
    y = rooms[room1].y + Rcs_Random(rooms[room1].height);
    if (y >= rooms[room2].y && y < rooms[room2].y + rooms[room2].height)
      flag = digTunnel(rooms[room1].x+rooms[room1].width,y,rooms[room2].x-1,y,-1,map);
    retries--;
    }
  if (flag != 0) {
#ifdef DEBUG
    sprintf(debugbuffer,"%*sExiting flag=%d\n",debug_tab,"",flag);
    debug_tab -= 2;
    debugLog(debugbuffer);
#endif
    return -1;
    }

  /* **************************************************** */
  /* ***** Attempt to dig l tunnel to connect rooms ***** */
  /* **************************************************** */
  retries = 25;
  flag = 0;
  while (flag == 0 && retries > 0) {
    switch (Rcs_Random(2)) {
      case 0:                       /* Right edge to bottom */
          sx = rooms[room1].x+rooms[room1].width;
          sy = rooms[room1].y + Rcs_Random(rooms[room1].height);
          dy = rooms[room2].y + rooms[room2].height;
          dx = rooms[room2].x + Rcs_Random(rooms[room2].width);
          mx = dx;
          my = sy;
          flag = digLTunnel(sx,sy,mx,my,dx,dy,map);
          break;
      case 1:                      /* Top edge to left */
          sx = rooms[room1].x + Rcs_Random(rooms[room1].width);
          sy = rooms[room1].y - 1;
          dx = rooms[room2].x - 1;
          dy = rooms[room2].y + Rcs_Random(rooms[room2].height);
          mx = sx;
          my = dy;
          flag = digLTunnel(sx,sy,mx,my,dx,dy,map);
          break;
      case 2:                      /* Right edge to top */
          sx = rooms[room1].x+rooms[room1].width;
          sy = rooms[room1].y + Rcs_Random(rooms[room1].height);
          dy = rooms[room2].y - 1;
          dx = rooms[room2].x + Rcs_Random(rooms[room2].width);
          mx = dx;
          my = sy;
          flag = digLTunnel(sx,sy,mx,my,dx,dy,map);
          break;
      case 3:                      /* Bottom edge to left */
          sx = rooms[room1].x + Rcs_Random(rooms[room1].width);
          sy = rooms[room1].y + rooms[room1].height;
          dx = rooms[room2].x - 1;
          dy = rooms[room2].y + Rcs_Random(rooms[room2].height);
          mx = sx;
          my = dy;
          flag = digLTunnel(sx,sy,mx,my,dx,dy,map);
          break;
      }
    retries--;
    }
  if (flag != 0) {
#ifdef DEBUG
    sprintf(debugbuffer,"%*sExiting flag=%d\n",debug_tab,"",flag);
    debug_tab -= 2;
    debugLog(debugbuffer);
#endif
     return -1;
     }
  /* ********************************************* */
  /* ***** Attempt U tunnel to connect rooms ***** */
  /* ********************************************* */
  retries = 25;
  flag = 0;
  while (flag == 0 && retries > 0) {
    if (Rcs_Random(2) == 0) {             /* Try on top */
      sx = rooms[room1].x + Rcs_Random(rooms[room1].width);
      sy = rooms[room1].y - 1;
      dx = rooms[room2].x + Rcs_Random(rooms[room2].width);
      dy = rooms[room2].y - 1;
      my = (rooms[room1].y < rooms[room2].y) ? rooms[room1].y - Rcs_Random(15) : rooms[room2].y - Rcs_Random(15);
      flag = digUTunnel(sx,sy,sx,my,dx,my,dx,dy,map);
      } else {                          /* Try on bottom */
      sx = rooms[room1].x + Rcs_Random(rooms[room1].width);
      sy = rooms[room1].y + rooms[room1].height;
      dx = rooms[room2].x + Rcs_Random(rooms[room2].width);
      dy = rooms[room2].y + rooms[room2].height;
      my = (rooms[room1].y > rooms[room2].y) ? rooms[room1].y + Rcs_Random(15) : rooms[room2].y + Rcs_Random(15);
      flag = digUTunnel(sx,sy,sx,my,dx,my,dx,dy,map);
      }
    retries--;
    }
#ifdef DEBUG
  sprintf(debugbuffer,"%*sExiting flag=%d\n",debug_tab,"",flag);
  debug_tab -= 2;
  debugLog(debugbuffer);
#endif
  if (flag != 0) return -1;
  return 0;
  }


int vertical(int room1,int room2,MAP_TYPE* map) {
  int x;
  int retries;
  int sx,sy,mx,my,dx,dy;
  int flag;
#ifdef DEBUG
  sprintf(debugbuffer,"%*svertical begin room1=%d, room2=%d\n",debug_tab,"",room1,room2);
  debug_tab += 2;
  debugLog(debugbuffer);
#endif
  if (room2 < room1) {
    x = room1; room1 = room2; room2 = x;
    }
  /* ************************************************ */
  /* ***** Attempt connection from edge to edge ***** */
  /* ************************************************ */
  retries = 25;
  flag = 0;
  while (flag == 0 && retries > 0) {
    x = rooms[room1].x + Rcs_Random(rooms[room1].width);
    if (x >= rooms[room2].x && x < rooms[room2].x + rooms[room2].width)
      flag = digTunnel(x,rooms[room1].y+rooms[room1].height,x,rooms[room2].y-1,-1,map);
    retries--;
    }
  if (flag != 0) {
#ifdef DEBUG
  sprintf(debugbuffer,"%*sExiting flag=%d\n",debug_tab,"",flag);
  debug_tab -= 2;
  debugLog(debugbuffer);
#endif
     return -1;
     }
  /* **************************************************** */
  /* ***** Attempt to dig l tunnel to connect rooms ***** */
  /* **************************************************** */
  retries = 25;
  flag = 0;
  while (flag == 0 && retries > 0) {
    switch (Rcs_Random(2)) {
      case 0:                       /* Right edge to top */
          sx = rooms[room1].x+rooms[room1].width;
          sy = rooms[room1].y + Rcs_Random(rooms[room1].height);
          dx = rooms[room2].x + Rcs_Random(rooms[room2].width);
          dy = rooms[room2].y - 1;
          mx = dx;
          my = sy;
          flag = digLTunnel(sx,sy,mx,my,dx,dy,map);
          break;
      case 1:                      /* Left edge to top */
          sx = rooms[room1].x - 1;
          sy = rooms[room1].y + Rcs_Random(rooms[room1].height);
          dx = rooms[room2].x + Rcs_Random(rooms[room2].width);
          dy = rooms[room2].y - 1;
          mx = dx;
          my = sy;
          flag = digLTunnel(sx,sy,mx,my,dx,dy,map);
          break;
      case 2:                      /* Bottom edge to left */
          sx = rooms[room1].x + Rcs_Random(rooms[room1].width);
          sy = rooms[room1].y + rooms[room1].height;
          dx = rooms[room2].x + rooms[room2].width;
          dy = rooms[room2].y + Rcs_Random(rooms[room2].height);
          mx = dx;
          my = sy;
          flag = digLTunnel(sx,sy,mx,my,dx,dy,map);
          break;
      case 3:                      /* Bottom edge to right */
          sx = rooms[room1].x + Rcs_Random(rooms[room1].width);
          sy = rooms[room1].y + rooms[room1].height;
          dx = rooms[room2].x - 1;
          dy = rooms[room2].y + Rcs_Random(rooms[room2].height);
          mx = dx;
          my = sy;
          flag = digLTunnel(sx,sy,mx,my,dx,dy,map);
          break;
      }
    retries--;
    }
  if (flag != 0) {
#ifdef DEBUG
  sprintf(debugbuffer,"%*sExiting flag=%d\n",debug_tab,"",flag);
  debug_tab -= 2;
  debugLog(debugbuffer);
#endif
    return -1;
    }
  /* ********************************************* */
  /* ***** Attempt U tunnel to connect rooms ***** */
  /* ********************************************* */
  retries = 25;
  flag = 0;
  while (flag == 0 && retries > 0) {
    if (Rcs_Random(2) == 0) {             /* Try on left */
      sx = rooms[room1].x - 1;
      sy = rooms[room1].y + Rcs_Random(rooms[room1].height);
      dx = rooms[room2].x  - 1;
      dy = rooms[room2].y + Rcs_Random(rooms[room2].height);
      mx = (rooms[room1].x < rooms[room2].x) ? rooms[room1].x - Rcs_Random(15) : rooms[room2].x - Rcs_Random(15);
      flag = digUTunnel(sx,sy,mx,sy,mx,dy,dx,dy,map);
      } else {                          /* Try on right */
      sx = rooms[room1].x + rooms[room1].width;
      sy = rooms[room1].y + Rcs_Random(rooms[room1].height);
      dx = rooms[room2].x + rooms[room2].width;
      dy = rooms[room2].y + Rcs_Random(rooms[room2].height);
      mx = (sx > dx) ? sx + Rcs_Random(15) : dx + Rcs_Random(15);
      flag = digUTunnel(sx,sy,mx,sy,mx,dy,dx,dy,map);
      }
    retries--;
    }
#ifdef DEBUG
  sprintf(debugbuffer,"%*sExiting flag=%d\n",debug_tab,"",flag);
  debug_tab -= 2;
  debugLog(debugbuffer);
#endif
  if (flag != 0) return -1;
  return 0;
  }

int connectRoom(int num,MAP_TYPE* map) {
  int x,y;
  int dx,dy;
  int dnum;
#ifdef DEBUG
  sprintf(debugbuffer,"%*sconnectRoom begin num=%d\n",debug_tab,"",num);
  debug_tab += 2;
  debugLog(debugbuffer);
#endif
  x = num % 4;
  y = num / 4;
  if (Rcs_Random(2) == 0) {
    dx = Rcs_Random(4);
    while (dx == x) dx = Rcs_Random(4);
    dy = y;
    } else {
    dy = Rcs_Random(4);
    while (dy == y) dy = Rcs_Random(4);
    dx = x;
    }
  dnum = dy * 4 + dx;
  if (dy == y) {
    if (horizontal(num,dnum,map)) {
      rooms[num].hits |= (1 << dnum);
      rooms[dnum].hits |= (1 << num);
      }
    } else {
    if (vertical(num,dnum,map)) {
      rooms[num].hits |= (1 << dnum);
      rooms[dnum].hits |= (1 << num);
      }
    }
#ifdef DEBUG
  sprintf(debugbuffer,"%*sExiting\n",debug_tab,"");
  debug_tab -= 2;
  debugLog(debugbuffer);
#endif
  return 0;
  }

void checkLinks(int n) {
  int i;
  roomlinks |= (1 << n);
  for (i=0; i<16; i++) {
    if ((roomlinks & (1 << i)) == 0) {
      if ((rooms[n].hits & (1 << i)) != 0) checkLinks(i);
      }
    }
  }

void attemptRemainingLinks(int room,MAP_TYPE* map) {
  int i;
  int j;
  char flag;
#ifdef DEBUG
  sprintf(debugbuffer,"%*sattemptRemainingLinks begin room=%d\n",debug_tab,"",room);
  debug_tab += 2;
  debugLog(debugbuffer);
#endif
  roomlinks = 0;
  checkLinks(room);
  for (i=0; i<16; i++)
    if ((roomlinks & (1 << i)) == 0) {
      flag = 'N';
      j = 0;
      while (flag == 'N' && j < 16) {
        if ((roomlinks & (1 << j)) != 0) {
          if (horizontal(i,j,map)) {
            rooms[i].hits |= (1 << j);
            rooms[j].hits |= (1 << i);
            flag = 'Y';
            }
          else if (vertical(i,j,map)) {
            rooms[i].hits |= (1 << j);
            rooms[j].hits |= (1 << i);
            flag = 'Y';
            }
          }
        j++;
        }
      if (flag == 'Y') {
        roomlinks = 0;
        checkLinks(room);
        }
      }
#ifdef DEBUG
  sprintf(debugbuffer,"%*sExiting\n",debug_tab,"");
  debug_tab -= 2;
  debugLog(debugbuffer);
#endif
  }

int generateMap(MAP_TYPE* map) {
  int i;
  int rx,ry;
  int retries;
#ifdef DEBUG
  sprintf(debugbuffer,"%*sgenerateMap begin\n",debug_tab,"");
  debug_tab += 2;
  debugLog(debugbuffer);
#endif
  clearMap(map);
  rx = 1; ry = 1;
  for (i=0; i<16; i++) {
    addRoom(i,rx,ry,25,25,map);
    rx += 25;
    if (rx >= 100) {
      rx = 1;
      ry += 25;
      }
    }
  for (i=0; i<16; i++) connectRoom(i,map);
  retries = 25;
  roomlinks = 0;
  while (roomlinks != 0xffff && retries > 0) {
    attemptRemainingLinks(0,map);
    retries--;
    }
#ifdef DEBUG
  sprintf(debugbuffer,"%*sExiting roomlinks=%x\n",debug_tab,"",roomlinks);
  debug_tab -= 2;
  debugLog(debugbuffer);
#endif
  return (roomlinks == 0xffff) ? -1 : 0;
  }




void mapgen(int depth,int floor,int* treasurex,int* treasurey,
            int *upx, int *upy, int *downx, int *downy,
            MAP_TYPE* map,KNOW_TYPE* known) {
  int i;
  int x,y;
  char flag;
#ifdef DEBUG
  sprintf(debugbuffer,"%*smapgen begin: floor=%d\n",debug_tab,"",floor);
  debug_tab += 2;
  debugLog(debugbuffer);
#endif
  for (x=1; x<=100; x++)
    for (y=1; y<=100; y++) {
      (*known)[x][y] = 0;
      }
  walls = 21;
  floors = floor;
  dungeon_floor = floor;
  dungeon_wall = walls;
  doors = 22;
  secrets = 21;
  i = 0;
  while (i == 0) {
    i = generateMap(map);
    }
  i = Rcs_Random(16);
  *treasurex = rooms[i].x + (rooms[i].width / 2);
  *treasurey = rooms[i].y + (rooms[i].height / 2);

  /* ************************************ */
  /* ***** Place walls on map edges ***** */
  /* ************************************ */
  for (x=1; x<=100; x++) {
    (*map)[x][1] = 21;
    (*map)[x][2] = 21;
    (*map)[x][99] = 21;
    (*map)[x][100] = 21;
    }
  for (y=1; y<=100; y++) {
    (*map)[1][y] = 21;
    (*map)[2][y] = 21;
    (*map)[99][y] = 21;
    (*map)[100][y] = 21;
    }

  for (x=1; x<=100; x++)
    for (y=1; y<=100; y++)
      if ((*map)[x][y] == 22) {
        flag = ' ';
        if ((*map)[x-1][y] != floor && (*map)[x+1][y] != floor)
          flag = '*';
        if ((*map)[x][y-1] != floor && (*map)[x][y+1] != floor)
          flag = '*';
        if (flag == ' ') (*map)[x][y] = floor;
        }


  /* ******************************************* */
  /* ***** Determine location of up stairs ***** */
  /* ******************************************* */
  *upx = Rcs_Random(80) + 10;
  *upy = Rcs_Random(80) + 10;
  while ((*map)[*upx][*upy] != floor ||
         (abs(*treasurex-*upx) < 20 && abs(*treasurey-*upy) < 20)) {
    *upx = Rcs_Random(80) + 10;
    *upy = Rcs_Random(80) + 10;
    }
  (*map)[*upx][*upy] = S_UPSTAIR;
  /* ********************************************* */
  /* ***** Determine location of down stairs ***** */
  /* ********************************************* */
  *downx = Rcs_Random(80) + 10;
  *downy = Rcs_Random(80) + 10;
  while ((*map)[*downx][*downy] != floor ||
         (abs(*downx-*upx) < 20 && abs(*downy-*upy) < 20)) {
    *downx = Rcs_Random(80) + 10;
    *downy = Rcs_Random(80) + 10;
    }
  /* *********************************************** */
  /* ***** Place down stairs on gateway levels ***** */
  /* *********************************************** */
  if (player.gateway == '*' && depth < 5) {
    (*map)[*downx][*downy] = S_DNSTAIR;
    }
  /* *************************************************** */
  /* ***** Place down stairs on non-gateway levels ***** */
  /* *************************************************** */
  if (player.gateway != '*' && depth < player.effect[PE_DEPTH]) {
    (*map)[*downx][*downy] = S_DNSTAIR;
    }

/* ********************************************** */
/* ***** Check for existance of a runestone ***** */
/* ********************************************** */
  if (Rcs_Random(5) == 2) {
    x = Rcs_Random(80) + 10;
    y = Rcs_Random(80) + 10;
    while ((*map)[x][y] != floor) {
      x = Rcs_Random(80) + 10;
      y = Rcs_Random(80) + 10;
      }
    i = Rcs_Random(100);
    if (i < 50) (*map)[x][y] = 905;
    else if (i < 75) (*map)[x][y] = 904;
    else if (i < 80) (*map)[x][y] = 906;
    else if (i < 85) (*map)[x][y] = 907;
    else if (i < 90) (*map)[x][y] = 908;
    else if (i < 95) (*map)[x][y] = 909;
    else (*map)[x][y] = 910;
    (*map)[x][y] = 904 + Rcs_Random(7);
  }

  /* ************************************* */
  /* ***** Check for a Gacha Machine ***** */
  /* ************************************* */
  if (Rcs_Random(100) == 50) {
    x = Rcs_Random(80) + 10;
    y = Rcs_Random(80) + 10;
    while ((*map)[x][y] != floor) {
      x = Rcs_Random(80) + 10;
      y = Rcs_Random(80) + 10;
      }
    (*map)[x][y] = 536;
    }

  /* **************************** */
  /* ***** Place some traps ***** */
  /* **************************** */
  for (i=1; i<=(player.d_level / 3 + player.diff * 2 + 5); i++) {
    x = Rcs_Random(80) + 10;
    y = Rcs_Random(80) + 10;
    while ((*map)[x][y] != floor) {
      x = Rcs_Random(80) + 10;
      y = Rcs_Random(80) + 10;
      }
    if (player.gateway == '*') (*map)[x][y] = 800 + Rcs_Random(7) + 1;
      else (*map)[x][y] = 800 + Rcs_Random(8) + 1;
    }


#ifdef DEBUG
  sprintf(debugbuffer,"%*sExiting\n",debug_tab,"");
  debug_tab -= 2;
  debugLog(debugbuffer);
#endif
  }
