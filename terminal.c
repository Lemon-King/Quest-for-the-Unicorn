/*
 *******************************************************************
 *** This software is copyright 1985-2007 by Michael H Riley     ***
 *** You have permission to use, modify, copy, and distribute    ***
 *** this software so long as this copyright notice is retained. ***
 *** This software may not be used in commercial applications    ***
 *** without express written permission from the author.         ***
 *******************************************************************
*/

#define TERMINAL

#include <librcs.h>
#include <sys/time.h>
#include <sys/timeb.h>

#include "header.h"

int cursor_x;
int cursor_y;
int text_color;
int g_color;
rcs_Event key_event;

void gc_color(rcs_GC* gc,int clr) {
#ifdef DEBUG
  printf("%*sEntering: gc_color(gc,%d)\n",debug_tab,"",clr);
  debug_tab += 2;
#endif
  switch (clr) {
    case 0:rcs_namedForeground(display,*gc,"black"); break;
    case 1:rcs_namedForeground(display,*gc,"blue"); break;
    case 2:rcs_namedForeground(display,*gc,"green"); break;
    case 3:rcs_namedForeground(display,*gc,"cyan"); break;
    case 4:rcs_namedForeground(display,*gc,"red"); break;
    case 5:rcs_namedForeground(display,*gc,"purple"); break;
    case 6:rcs_namedForeground(display,*gc,"brown"); break;
    case 7:rcs_namedForeground(display,*gc,"gray50"); break;
    case 8:rcs_namedForeground(display,*gc,"gray25"); break;
    case 9:rcs_namedForeground(display,*gc,"light blue"); break;
    case 10:rcs_namedForeground(display,*gc,"light green"); break;
    case 11:rcs_namedForeground(display,*gc,"light cyan"); break;
    case 12:rcs_namedForeground(display,*gc,"red1"); break;
    case 13:rcs_namedForeground(display,*gc,"purple1"); break;
    case 14:rcs_namedForeground(display,*gc,"yellow"); break;
    case 15:rcs_namedForeground(display,*gc,"white"); break;
    }
#ifdef DEBUG
  printf("%*sExiting: gc_color()\n",debug_tab,"");
  debug_tab -= 2;
#endif
  }

void init_graph() {
  int i;
  rcs_GC gc;
  display = rcs_openDisplay(":0.0");
  window = rcs_createWindow(display,rcs_rootWindow(display),0,0,640,480);
  rcs_showWindow(display,window);
  rcs_setWindowName(display,window,"Quest for the Unicorn");
  screen = rcs_createPixmap(display,window,640,480);
  screenSave = rcs_createPixmap(display,window,640,480);
  gc = rcs_openGC(display,window);
  rcs_namedForeground(display,gc,"black");
  rcs_drawFilledBox(display,window,gc,0,0,640,480);
  rcs_drawFilledBox(display,screen,gc,0,0,640,480);
  rcs_closeGC(display,gc);
  for (i=0; i<16; i++) {
    colors[i] = rcs_openGC(display,window);
    gc_color(&(colors[i]),i);
    }
  }

void saveScreen() {
  rcs_GC gc;
  gc = rcs_openGC(display,window);
  rcs_copyArea(display,screen,screenSave,gc,0,0,640,480,0,0);
  rcs_closeGC(display,gc);
  }

void restoreScreen() {
  rcs_GC gc;
  gc = rcs_openGC(display,window);
  rcs_copyArea(display,screenSave,screen,gc,0,0,640,480,0,0);
  rcs_copyArea(display,screenSave,window,gc,0,0,640,480,0,0);
  rcs_closeGC(display,gc);
  }

void draw(int x1,int y1,int x2,int y2,int clr) {
  rcs_GC gc;
  gc = rcs_openGC(display,window);
  gc_color(&gc,clr);
  rcs_drawLine(display,window,gc,x1,y1,x2,y2);
  rcs_drawLine(display,screen,gc,x1,y1,x2,y2);
  rcs_closeGC(display,gc);
  }

void graphmode() {
  rcs_GC gc;
#ifdef DEBUG
  printf("%*sEntering: graphmode()\n",debug_tab,"");
  debug_tab += 2;
#endif
  gc = rcs_openGC(display,window);
  rcs_namedForeground(display,gc,"black");
  rcs_drawFilledBox(display,window,gc,0,0,640,480);
  rcs_drawFilledBox(display,screen,gc,0,0,640,480);
  rcs_closeGC(display,gc);
#ifdef DEBUG
  printf("%*sExiting: graphmode()\n",debug_tab,"");
  debug_tab -= 2;
#endif
  }

void textmode(int mode) {
  rcs_GC gc;
#ifdef DEBUG
  printf("%*sEntering: graphmode(%d)\n",debug_tab,"",mode);
  debug_tab += 2;
#endif
  gc = rcs_openGC(display,window);
  rcs_namedForeground(display,gc,"black");
  rcs_drawFilledBox(display,window,gc,0,0,640,480);
  rcs_drawFilledBox(display,screen,gc,0,0,640,480);
  rcs_closeGC(display,gc);
#ifdef DEBUG
  printf("%*sExiting: graphmode()\n",debug_tab,"");
  debug_tab -= 2;
#endif
  }

void textcolor(int color) {
#ifdef DEBUG
  printf("%*sEntering: textcolor(%d)\n",debug_tab,"",color);
  debug_tab += 2;
#endif
  text_color = color;
#ifdef DEBUG
  printf("%*sExiting: textcolor()\n",debug_tab,"");
  debug_tab -= 2;
#endif
  }

void gotoxy(int x,int y) {
#ifdef DEBUG
  printf("%*sEntering: gotoxy(%d,%d)\n",debug_tab,"",x,y);
  debug_tab += 2;
#endif
  cursor_x = x - 1;
  cursor_y = y - 1;
#ifdef DEBUG
  printf("%*sExiting: gotoxy()\n",debug_tab,"");
  debug_tab -= 2;
#endif
  }

void txt_write(char* buffer) {
  int i;
  char b2[2];
  rcs_GC gc;
  rcs_GC black;
#ifdef DEBUG
  printf("%*sEntering: txt_write(\"%s\")\n",debug_tab,"",buffer);
  debug_tab += 2;
#endif
  gc = rcs_openGC(display,window);
  black = rcs_openGC(display,window);
  rcs_namedForeground(display,gc,"black");
  gc_color(&gc,text_color);
  b2[1] = 0;
  for (i=0; i<strlen(buffer); i++) {
    b2[0] = buffer[i];
    rcs_drawFilledBox(display,window,black,cursor_x*8,cursor_y*19,8,19);
    rcs_drawFilledBox(display,screen,black,cursor_x*8,cursor_y*19,8,19);
    rcs_drawString(display,window,gc,cursor_x * 8,10+cursor_y * 19,b2);
    rcs_drawString(display,screen,gc,cursor_x * 8,10+cursor_y * 19,b2);
    cursor_x++;
    if (cursor_x == 80) {
      cursor_x = 0;
      cursor_y++;
      if (cursor_y > 24) cursor_y = 24;
      }
    }
  rcs_closeGC(display,gc);
  rcs_closeGC(display,black);
#ifdef DEBUG
  printf("%*sExiting: txt_write()\n",debug_tab,"");
  debug_tab -= 2;
#endif
  }

void txt_writeln(char* buffer) {
#ifdef DEBUG
  printf("%*sEntering: txt_writeln(\"%s\")\n",debug_tab,"",buffer);
  debug_tab += 2;
#endif
  txt_write(buffer);
  cursor_y++;
  cursor_x = 0;
  if (cursor_y > 24) cursor_y = 24;
#ifdef DEBUG
  printf("%*sExiting: txt_writeln()\n",debug_tab,"");
  debug_tab -= 2;
#endif
  }

int keypressed() {
  rcs_GC    gc;
  rcs_Event event;
  event = rcs_pollEvent(display);
  if (event.type == EVENT_EXPOSE) {
    gc = rcs_openGC(display,window);
    rcs_copyArea(display,screen,window,gc,event.d1,event.d2,event.d3,event.d4,
                                          event.d1,event.d2);
    rcs_closeGC(display,gc);
    }
  if (event.type == EVENT_KEY_PRESS) {
    key_event = event;
    return -1;
    }
  return 0;
  }

int keytrans(int n) {
  switch (n) {
    case KEY_UP:return '8';
    case KEY_DOWN:return '2';
    case KEY_LEFT:return '4';
    case KEY_RIGHT:return '6';
    case KEY_KP_UP:return '8';
    case KEY_KP_DOWN:return '2';
    case KEY_KP_LEFT:return '4';
    case KEY_KP_RIGHT:return '6';
    case KEY_HOME:return '7';
    case KEY_KP_HOME:return '7';
    case KEY_END:return '1';
    case KEY_KP_END:return '1';
    case KEY_PAGE_UP:return '9';
    case KEY_KP_PAGE_UP:return '9';
    case KEY_PAGE_DN:return '3';
    case KEY_KP_PAGE_DN:return '3';
    }
  return n;
  }

int readkey() {
  rcs_GC    gc;
  rcs_Event event;
  char      flag;
  flag = ' ';
  if (key_event.type == EVENT_KEY_PRESS) {
    key_event.type = EVENT_NONE;
    return keytrans(key_event.d1);
    }
  while (flag == ' ') {
    event = rcs_getEvent(display);
    if (event.type == EVENT_EXPOSE) {
      gc = rcs_openGC(display,window);
      rcs_copyArea(display,screen,window,gc,event.d1,event.d2,event.d3,event.d4,
                                            event.d1,event.d2);
      rcs_closeGC(display,gc);
      }
    if (event.type == EVENT_KEY_PRESS) {
      if (event.d1 != KEY_SHIFT_L && event.d1 != KEY_SHIFT_R)
        return keytrans(event.d1);
      }
    }
  return 0;
  }

void clrscr() {
  rcs_GC gc;
#ifdef DEBUG
  printf("%*sEntering: clrscr()\n",debug_tab,"");
  debug_tab += 2;
#endif
  gc = rcs_openGC(display,window);
  rcs_namedForeground(display,gc,"black");
  rcs_drawFilledBox(display,window,gc,0,0,640,480);
  rcs_drawFilledBox(display,screen,gc,0,0,640,480);
  rcs_closeGC(display,gc);
#ifdef DEBUG
  printf("%*sExiting: clrscr()\n",debug_tab,"");
  debug_tab -= 2;
#endif
  }

void putpixel(int x,int y,int clr) {
  rcs_GC gc;
#ifdef DEBUG
  printf("%*sEntering: putpixel(%d,%d,%d)\n",debug_tab,"",x,y,clr);
  debug_tab += 2;
#endif
  gc = rcs_openGC(display,window);
  rcs_openGC(display,window);
  gc_color(&gc,clr);
  rcs_drawPoint(display,window,gc,x,y);
  rcs_drawPoint(display,screen,gc,x,y);
  rcs_closeGC(display,gc);
#ifdef DEBUG
  printf("%*sExiting: putpixel()\n",debug_tab,"");
  debug_tab -= 2;
#endif
  }

void setfillstyle(int st,int clr) {
#ifdef DEBUG
  printf("%*sEntering: setfillstyle(%d,%d)\n",debug_tab,"",st,clr);
  debug_tab += 2;
#endif
  g_color = clr;
#ifdef DEBUG
  printf("%*sExiting: setfillstyle()\n",debug_tab,"");
  debug_tab -= 2;
#endif
  }

void bar(int x1,int y1,int x2,int y2) {
  rcs_GC gc;
#ifdef DEBUG
  printf("%*sEntering: bar(%d,%d,%d,%d)\n",debug_tab,"",x1,y1,x2,y2);
  debug_tab += 2;
#endif
  gc = rcs_openGC(display,window);
  gc_color(&gc,g_color);
  rcs_drawFilledBox(display,window,gc,x1,y1,x2-x1,y2-y1);
  rcs_drawFilledBox(display,screen,gc,x1,y1,x2-x1,y2-y1);
  rcs_closeGC(display,gc);
#ifdef DEBUG
  printf("%*sExiting: bar()\n",debug_tab,"");
  debug_tab -= 2;
#endif
  }

void setcolor(int clr) {
#ifdef DEBUG
  printf("%*sEntering: setcolor(%d)\n",debug_tab,"",clr);
  debug_tab += 2;
#endif
  g_color = clr;
#ifdef DEBUG
  printf("%*sExiting: setcolor()\n",debug_tab,"");
  debug_tab -= 2;
#endif
  }

void settextstyle(int a,int b,int c) {
  }

void outtextxy(int x,int y,char* buffer) {
  rcs_GC gc;
#ifdef DEBUG
  printf("%*sEntering: outtextxy(%d,%d,\"%s\")\n",debug_tab,"",x,y,buffer);
  debug_tab += 2;
#endif
  gc = rcs_openGC(display,window);
  gc_color(&gc,g_color);
  rcs_drawString(display,window,gc,x,y,buffer);
  rcs_drawString(display,screen,gc,x,y,buffer);
  rcs_closeGC(display,gc);
#ifdef DEBUG
  printf("%*sExiting: outtextxy()\n",debug_tab,"");
  debug_tab -= 2;
#endif
  }

void putimage(int x,int y,char** img,int typ) {
  rcs_GC gc;
#ifdef DEBUG
  printf("%*sEntering: putimage(%d,%d,char**,%d)\n",debug_tab,"",x,y,typ);
  debug_tab += 2;
#endif
  gc = rcs_openGC(display,window);
  rcs_drawPixmap(display,window,gc,x,y,img);
  rcs_drawPixmap(display,screen,gc,x,y,img);
  rcs_closeGC(display,gc);
#ifdef DEBUG
  printf("%*sExiting: putimage()\n",debug_tab,"");
  debug_tab -= 2;
#endif
  }

void delay(int tm) {
  int sec;
  struct timeval ts,te;
  sec = tm / 1000;
  tm -= (sec * 1000);
  gettimeofday(&te,NULL);
  te.tv_sec += sec;
  te.tv_usec += (tm * 1000);
  while (te.tv_usec >= 1000000) {
    te.tv_sec++;
    te.tv_usec -= 1000000;
    }
  gettimeofday(&ts,NULL);
  while (ts.tv_sec < te.tv_sec || ts.tv_usec < te.tv_usec) {
    gettimeofday(&ts,NULL);
    }
/*
  rcs_delay(tm/100);
*/
  }

void p_read(char* buffer) {
  int temp_x,temp_y;
  char key;
  strcpy(buffer,"");
  key = 0;
  temp_x = cursor_x;
  temp_y = cursor_y;
  gotoxy(temp_x+1,temp_y+1);
  txt_write("_");
  while (key != 13) {
    key = inkey();
    if (key > 31) {
      buffer[strlen(buffer) + 1] = 0;
      buffer[strlen(buffer)] = key;
      gotoxy(temp_x+1,temp_y+1);
      txt_write(buffer);
      txt_write("_");
      }
    if (key == 8 && strlen(buffer) > 0) {
      buffer[strlen(buffer) - 1] = 0;
      gotoxy(temp_x+1,temp_y+1);
      txt_write(buffer);
      txt_write("_ ");
      }
    }
  gotoxy(temp_x+1,temp_y+1);
  txt_write(buffer);
  txt_write("  ");
  cursor_x = temp_x;
  cursor_y = temp_y;
  }

void readln(char* buffer) {
  p_read(buffer);
  cursor_y++;
  cursor_x = 0;
  if (cursor_y > 24) cursor_y = 24;
  }

