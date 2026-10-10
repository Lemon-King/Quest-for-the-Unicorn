#ifndef ASCII

#include <stdio.h>
#include <string.h>
#include "graphics.h"

int red_mask;
int green_mask;
int blue_mask;
int red_shift;
int green_shift;
int blue_shift;

void rcs_buildColorMapping(rcs_Display* display) {
#ifndef WIN32
  Visual* visual;
  visual = DefaultVisual(display, DefaultScreen(display));
  red_mask = visual->red_mask;
  green_mask = visual->green_mask;
  blue_mask = visual->blue_mask;
  red_shift = 0;
  while (red_mask >= 0x10000) {
    red_mask >>= 1;
    red_shift--;
    }
  while (red_mask < 0x8000) {
    red_mask <<= 1;
    red_shift++;
    }
  green_shift = 0;
  while (green_mask >= 0x10000) {
    green_mask >>= 1;
    green_shift--;
    }
  while (green_mask < 0x8000) {
    green_mask <<= 1;
    green_shift++;
    }
  blue_shift = 0;
  while (blue_mask >= 0x10000) {
    blue_mask >>= 1;
    blue_shift--;
    }
  while (blue_mask < 0x8000) {
    blue_mask <<= 1;
    blue_shift++;
    }
#endif
  }

#ifdef WIN32
rcs_Display disp;
int _shiftState;
int _ctrlState;
int _capsState;

#include "rgb.h"

int _rcs_winTranslate(int key) {
        if (key >= 'A' && key <= 'Z') {
                if (_ctrlState == 1) key -= 64;
                else if ((_shiftState ^ ((GetKeyState(VK_CAPITAL))?1:0)) == 0) key+=32;
        }
        else if (key >= '0' && key <= '9') {
                if (_shiftState == 1) {
                        switch(key) {
                        case '1': key = '!'; break;
                        case '2': key = '@'; break;
                        case '3': key = '#'; break;
                        case '4': key = '$'; break;
                        case '5': key = '%'; break;
                        case '6': key = '^'; break;
                        case '7': key = '&'; break;
                        case '8': key = '*'; break;
                        case '9': key = '('; break;
                        case '0': key = ')'; break;
                        }
                }
        }
        else {
                if (_shiftState) {
                        switch(key) {
                        case 8: break;
                        case 9: break;
                        case 10: break;
                        case 13: break;
                        case 27: break;
                        case 32: break;
                        case 186: key = ':'; break;
                        case 187: key = '+'; break;
                        case 188: key = '<'; break;
                        case 189: key = '_'; break;
                        case 190: key = '>'; break;
                        case 191: key = '?'; break;
                        case 192: key = '~'; break;
                        case 219: key = '{'; break;
                        case 220: key = '|'; break;
                        case 221: key = '}'; break;
                        case 222: key = '"'; break;
                        default: key += 0xf000;
                        }
                } else {
                        switch(key) {
                        case 8: break;
                        case 9: break;
                        case 10: break;
                        case 13: break;
                        case 27: break;
                        case 32: break;
                        case 186: key = ';'; break;
                        case 187: key = '='; break;
                        case 188: key = ','; break;
                        case 189: key = '-'; break;
                        case 190: key = '.'; break;
                        case 191: key = '/'; break;
                        case 192: key = '`'; break;
                        case 219: key = '['; break;
                        case 220: key = '\\'; break;
                        case 221: key = ']'; break;
                        case 222: key = '\''; break;
                        default: key += 0xf000;
                        }
                }
        }
        return key;
}

int _rcs_isBitmap(rcs_Window w) {
  int i;
  if (disp.numPixmaps==0) return FALSE;
  for (i=0;i<disp.numPixmaps;i++)
    if (disp.pixmapIDs[i]==w) return TRUE;
  return FALSE;
  }

LRESULT CALLBACK rcs_WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
  switch (message) {
                case WM_DESTROY:PostQuitMessage(0);
                                      break;
          default:return DefWindowProc(hWnd, message, wParam, lParam);
    }
  return DefWindowProc(hWnd, message, wParam, lParam);
  return 0;
  }

void rcs_initWin32(HINSTANCE hInstance) {
        WNDCLASSEX wcex;
  disp.hInstance=hInstance;
  strcpy(disp.className,"rcsawlib");
  disp.numPixmaps=0;
  disp.pixmapIDs=NULL;

        wcex.cbSize = sizeof(WNDCLASSEX);

        wcex.style                      = CS_HREDRAW | CS_VREDRAW;
        wcex.lpfnWndProc        = (WNDPROC)rcs_WndProc;
        wcex.cbClsExtra         = 0;
        wcex.cbWndExtra         = 0;
        wcex.hInstance          = hInstance;
        wcex.hIcon                      = NULL;
        wcex.hCursor            = LoadCursor(NULL, IDC_ARROW);
        wcex.hbrBackground      = (HBRUSH)(COLOR_WINDOW+1);
        wcex.lpszMenuName       = NULL;
        wcex.lpszClassName      = disp.className;
        wcex.hIconSm            = NULL;

        if (!RegisterClassEx(&wcex)) {
          MessageBox(NULL, TEXT("Could not register window class."),
                     TEXT("Error"), MB_ICONERROR | MB_OK);
          }
        _shiftState = 0;
        _ctrlState = 0;
        _capsState = (GetKeyState(VK_CAPITAL)) ? 1 : 0;
  }

#endif

unsigned long rcs_RGBToPixel(int red, int green, int blue) {
  unsigned long pixel;
  if (red_shift < 0)
    pixel = (red & red_mask) << -red_shift;
  else
    pixel = (red & red_mask) >> red_shift;
  if (green_shift < 0)
    pixel |= (green & green_mask) << -green_shift;
  else
    pixel |= (green & green_mask) >> green_shift;
  if (blue_shift < 0)
    pixel |= (blue & blue_mask) << -blue_shift;
  else
    pixel |= (blue & blue_mask) >> blue_shift;
  return pixel;
  }

/* ************************ */
/* ***** Build Colors ***** */
/* ************************ */
#ifdef X
void  _rcs_buildColors(rcs_Display* d,unsigned long* colors,const char** data,int *none) {
  XColor clr1,clr2;
#endif
#ifdef WIN32
void  _rcs_buildColors(rcs_Display* d,COLORREF* colors,const char** data,int *none) {
#endif
  int        sizeX,sizeY,numColors;
  int        x,i;
  char       index,temp,index2;
  char       buffer[80];
  char       nbuffer[8];
  int        colorIndex;
  int        bytesPer;
  unsigned long        red,green,blue;
  *none=-1;
  sscanf(data[0],"%d %d %d %d",&sizeX,&sizeY,&numColors,&bytesPer);
  for (x=1;x<=numColors;x++) {
    if (bytesPer != 2) {
      sscanf(data[x],"%c %c %s",&index,&temp,buffer);
      colorIndex = index;
      } else {
      sscanf(data[x],"%c%c %c %s",&index,&index2,&temp,buffer);
      colorIndex = (index-32)*96 + (index2-32);
      }
    if (buffer[0] != '#') {
      if (strcmp(buffer,"None")==0) *none=index;
#ifdef X
      XAllocNamedColor(d,DefaultColormap(d,DefaultScreen(d)),buffer,
                       &clr1,&clr2);
      colors[colorIndex]=clr1.pixel;
#endif
#ifdef WIN32
      rcs_namedColor(buffer,&red,&green,&blue);
      colors[colorIndex]=RGB(red,green,blue);
#endif
      } else {
      for (i=0;i<4;i++) nbuffer[i]=buffer[i+1];
      nbuffer[4]=0;
      sscanf(nbuffer,"%lx",&red);
      for (i=0;i<4;i++) nbuffer[i]=buffer[i+5];
      nbuffer[4]=0;
      sscanf(nbuffer,"%lx",&green);
      for (i=0;i<4;i++) nbuffer[i]=buffer[i+9];
      nbuffer[4]=0;
      sscanf(nbuffer,"%lx",&blue);
#ifdef WIN32
      if (red>255) red/=256;
      if (blue>255) blue/=256;
      if (green>255) green/=256;
#endif
#ifdef X
//      colors[colorIndex].blue=blue;
//      colors[colorIndex].red=red;
//      colors[colorIndex].green=green;
//      colors[colorIndex].flags=DoRed | DoGreen | DoBlue;
//      XAllocColor(d,DefaultColormap(d,DefaultScreen(d)),&colors[colorIndex]);
      colors[colorIndex] = rcs_RGBToPixel(red, green, blue);
#endif
#ifdef WIN32
      colors[colorIndex]=RGB(red,green,blue);
#endif
      }
    }
  }

/* ******************** */
/* ***** Close GC ***** */
/* ******************** */
void rcs_closeGC(rcs_Display* d,rcs_GC gc) {
#ifdef X
  XFreeGC(d,gc);
#endif
#ifdef WIN32
  free(gc);
#endif
  }

/* ********************* */
/* ***** Copy Area ***** */
/* ********************* */
void rcs_copyArea(rcs_Display* d,rcs_Window src,rcs_Window dest,rcs_GC gc,int sx,int sy,int w,int h,int dx,int dy) {
#ifdef X
  XCopyArea(d,src,dest,gc,sx,sy,w,h,dx,dy);
#endif
#ifdef WIN32
  HDC dc;
  HDC ddc;
  if (_rcs_isBitmap(src)==TRUE) {
    dc=CreateCompatibleDC(0);
    SelectObject(dc,src);
    } else dc=GetDC(src);
  if (_rcs_isBitmap(dest)==TRUE) {
    ddc=CreateCompatibleDC(0);
    SelectObject(ddc,dest);
    } else ddc=GetDC(dest);
  BitBlt(ddc,dx,dy,w,h,dc,sx,sy,SRCCOPY);
  if (_rcs_isBitmap(src)==TRUE) DeleteDC(dc);
    else ReleaseDC(src,dc);
  if (_rcs_isBitmap(dest)==TRUE) DeleteDC(ddc);
    else ReleaseDC(dest,ddc);
#endif
  }

/* ************************* */
/* ***** Create Pixmap ***** */
/* ************************* */
rcs_Pixmap rcs_createPixmap(rcs_Display* d,rcs_Window win,int x,int y) {
  rcs_Pixmap ret;
#ifdef X
  XWindowAttributes attr;
  XGetWindowAttributes(d,win,&attr);
  ret=XCreatePixmap(d,win,x,y,attr.depth);
#endif
#ifdef WIN32
  HBITMAP    bitmap;
  HDC        dc;
  dc=GetDC(win);
  bitmap=CreateCompatibleBitmap(dc,x,y);
  ReleaseDC(win,dc);
  ret=(rcs_Pixmap)bitmap;
  if (disp.numPixmaps == 0) disp.pixmapIDs=(rcs_Window*)malloc(sizeof(rcs_Window));
    else disp.pixmapIDs=(rcs_Window*)realloc(disp.pixmapIDs,(sizeof(rcs_Window))*(disp.numPixmaps+1));
  disp.pixmapIDs[disp.numPixmaps++]=ret;
#endif
  return ret;
  }

/* ************************* */
/* ***** Create Window ***** */
/* ************************* */
rcs_Window  rcs_createWindow(rcs_Display* d,rcs_Window parent,int x,int y,int width,int height) {
  rcs_Window ret;
#ifdef X
  unsigned long mask;
  XSetWindowAttributes attr;
  attr.background_pixel=BlackPixel(d,DefaultScreen(d));
  mask=CWBackPixel;
  ret=XCreateWindow(d,parent,x,y,width,height,0,
                       CopyFromParent,
                       CopyFromParent,
                       CopyFromParent,
                       mask,&attr);
  XSelectInput(d,ret,ExposureMask | ButtonPressMask | ButtonReleaseMask |
               ButtonMotionMask | KeyPressMask | KeyReleaseMask |
               StructureNotifyMask | FocusChangeMask | EnterWindowMask |
               LeaveWindowMask | PointerMotionMask);
  ShiftState = 0;
  AltState = 0;
#endif
#ifdef WIN32
  
  if (parent == GetDesktopWindow()) {
    width += 3;
    height += 20;
    ret = CreateWindow(d->className, "rcsawlib", WS_OVERLAPPEDWINDOW,
       x, y, width, height, NULL, NULL, d->hInstance, NULL);
    }
  else {
    ret = CreateWindow(d->className, "rcsawlib", WS_CHILD,
       x, y, width, height, parent, NULL, d->hInstance, NULL);
    }
  if (!ret) MessageBox(NULL, TEXT("Hmmmmm"), TEXT("Error"), MB_ICONERROR | MB_OK);

#endif
  return ret;
  }

/* *************************** */
/* ***** Draw Filled Box ***** */
/* *************************** */
void rcs_drawFilledBox(rcs_Display* d,rcs_Window win,rcs_GC gc,
                  int x,int y,int w,int h) {
#ifdef X
  XFillRectangle(d,win,gc,x,y,w,h);
#endif
#ifdef WIN32
  HDC dc;
  HPEN pen;
  HBRUSH brush;
  RECT rect;
  rect.top=y;
  rect.left=x;
  rect.bottom=y+h;
  rect.right=x+w;
  if (_rcs_isBitmap(win)==TRUE) {
    dc=CreateCompatibleDC(0);
    SelectObject(dc,win);
    } else dc=GetDC(win);
  pen=CreatePen(PS_SOLID,0,gc->foreground);
  brush=CreateSolidBrush(gc->foreground);
  pen=(HPEN)SelectObject(dc,pen);
  FillRect(dc,&rect,brush);
  pen=(HPEN)SelectObject(dc,pen);
  DeleteObject(pen);
  DeleteObject(brush);
  if (_rcs_isBitmap(win)==TRUE) DeleteDC(dc);
    else ReleaseDC(win,dc);
#endif
  }

/* ********************* */
/* ***** Draw Line ***** */
/* ********************* */
void rcs_drawLine(rcs_Display* d,rcs_Window win,rcs_GC gc,int x1,int y1,int x2,int y2) {
#ifdef X
  XDrawLine(d,win,gc,x1,y1,x2,y2);
#endif
#ifdef WIN32
  HDC dc;
  HPEN pen;
  if (_rcs_isBitmap(win)==TRUE) {
    dc=CreateCompatibleDC(0);
    SelectObject(dc,win);
    } else dc=GetDC(win);
  pen=CreatePen(PS_SOLID,0,gc->foreground);
  pen=(HPEN)SelectObject(dc,pen);
  MoveToEx(dc,x1,y1,NULL);
  LineTo(dc,x2,y2);
  pen=(HPEN)SelectObject(dc,pen);
  DeleteObject(pen);
  if (_rcs_isBitmap(win)==TRUE) DeleteDC(dc);
    else ReleaseDC(win,dc);
#endif
  }

/* *********************** */
/* ***** Draw Pixmap ***** */
/* *********************** */
void  rcs_drawPixmap(rcs_Display* d,rcs_Window win,rcs_GC gc,int dx,int dy,const char** data) {
  int        sizeX,sizeY,numColors;
  int        x,y;
/*  char       index; */
  int        none;
  int        colorIndex;
  int        bytesPer;
#ifdef X
  unsigned long colors[10000];
#endif
#ifdef WIN32
  HDC        dc;
  HPEN       pen,oldPen;
  COLORREF   colors[10000];
#endif
  none=-1;
  _rcs_buildColors(d,colors,data,&none);
  sscanf(data[0],"%d %d %d %d",&sizeX,&sizeY,&numColors,&bytesPer);
#ifdef WIN32
  if (_rcs_isBitmap(win)==TRUE) {
    dc=CreateCompatibleDC(0);
    SelectObject(dc,win);
    } else dc=GetDC(win);
#endif
  for (y=0;y<sizeY;y++)
    for (x=0;x<sizeX;x++) {
      if (bytesPer != 2) colorIndex=data[y+numColors+1][x];
        else colorIndex = (data[y+numColors+1][x*2]-32) * 96 +
                          (data[y+numColors+1][x*2+1]-32);
      if (colorIndex != none) {
#ifdef X
        XSetForeground(d,gc,colors[colorIndex]);
        XDrawPoint(d,win,gc,x+dx,y+dy);
#endif
#ifdef WIN32
        pen=CreatePen(PS_SOLID,0,colors[colorIndex]);
        oldPen=(HPEN)SelectObject(dc,pen);
        MoveToEx(dc,x+dx,y+dy,NULL);
        LineTo(dc,x+1+dx,y+dy);
        oldPen=(HPEN)SelectObject(dc,oldPen);
        DeleteObject(oldPen);
#endif
        }
      }
#ifdef WIN32
  if (_rcs_isBitmap(win)==TRUE) DeleteDC(dc);
    else ReleaseDC(win,dc);
#endif    
  }

/* ********************** */
/* ***** Draw Point ***** */
/* ********************** */
void rcs_drawPoint(rcs_Display* d,rcs_Window win,rcs_GC gc,int x,int y) {
#ifdef X
  XDrawPoint(d,win,gc,x,y);
#endif
#ifdef WIN32
  HDC dc;
  HPEN pen;
  if (_rcs_isBitmap(win)==TRUE) {
    dc=CreateCompatibleDC(0);
    SelectObject(dc,win);
    } else dc=GetDC(win);
  pen=CreatePen(PS_SOLID,0,gc->foreground);
  pen=(HPEN)SelectObject(dc,pen);
  MoveToEx(dc,x,y,NULL);
  LineTo(dc,x+1,y);
  pen=(HPEN)SelectObject(dc,pen);
  DeleteObject(pen);
  if (_rcs_isBitmap(win)==TRUE) DeleteDC(dc);
    else ReleaseDC(win,dc);
#endif
  }

/* *********************** */
/* ***** Draw String ***** */
/* *********************** */
void rcs_drawString(rcs_Display* d,rcs_Window win,rcs_GC gc,int x,int y,char* buffer,int clr) {
#ifdef X
  if (clr) XDrawImageString(d,win,gc,x,y,buffer,strlen(buffer));
  else     XDrawString(d,win,gc,x,y,buffer,strlen(buffer));
#endif
#ifdef WIN32
  HDC dc;
  HPEN pen;
  RECT rect;
  int  height;
  rect.top=y;
  rect.left=x;
  rect.bottom=20;
  rect.right=20;
  if (_rcs_isBitmap(win)==TRUE) {
    dc=CreateCompatibleDC(0);
    SelectObject(dc,win);
    } else dc=GetDC(win);
  pen=CreatePen(PS_SOLID,0,gc->foreground);
  pen=(HPEN)SelectObject(dc,pen);
  SelectObject(dc,gc->font);
  SetBkColor(dc,gc->background);
  SetTextColor(dc,gc->foreground);
  SetBkMode(dc,TRANSPARENT);
  height=DrawText(dc,buffer,strlen(buffer),&rect,DT_CALCRECT);
  rect.top-=height;
  DrawText(dc,buffer,strlen(buffer),&rect,DT_TOP);
  pen=(HPEN)SelectObject(dc,pen);
  DeleteObject(pen);
  if (_rcs_isBitmap(win)==TRUE) DeleteDC(dc);
    else ReleaseDC(win,dc);
#endif
  }

/* ***************** */
/* ***** Flush ***** */
/* ***************** */
void rcs_Flush(rcs_Display* d) {
#ifdef X
  XFlush(d);
#endif
  }

/* ********************* */
/* ***** Get Event ***** */
/* ********************* */
rcs_Event rcs_getEvent(rcs_Display* d) {
  rcs_Event ret;
#ifdef X
  XEvent event;
  KeySym key;
  XComposeStatus status;
  char tmp[10];
  XNextEvent(d,&event);
  switch (event.type) {
    case FocusIn:     ret.type=EVENT_FOCUSIN;
                      ret.d3=event.xcrossing.mode;
                      ret.d4=event.xcrossing.focus;
                      ret.window=event.xcrossing.window;
                      break;
    case FocusOut:    ret.type=EVENT_FOCUSOUT;
                      ret.d3=event.xcrossing.mode;
                      ret.d4=event.xcrossing.focus;
                      ret.window=event.xcrossing.window;
                      break;
    case EnterNotify: ret.type=EVENT_ENTER;
                      ret.d1=event.xcrossing.x;
                      ret.d2=event.xcrossing.y;
                      ret.d3=event.xcrossing.mode;
                      ret.d4=event.xcrossing.focus;
                      ret.window=event.xcrossing.window;
                      break;
    case LeaveNotify: ret.type=EVENT_LEAVE;
                      ret.d1=event.xcrossing.x;
                      ret.d2=event.xcrossing.y;
                      ret.d3=event.xcrossing.mode;
                      ret.d4=event.xcrossing.focus;
                      ret.window=event.xcrossing.window;
                      break;
    case ConfigureNotify:
                      ret.type=EVENT_CONFIGURE;
                      ret.d1=event.xconfigure.x;
                      ret.d2=event.xconfigure.y;
                      ret.d3=event.xconfigure.width;
                      ret.d4=event.xconfigure.height;
                      ret.window=event.xconfigure.window;
                      break;
    case MotionNotify:ret.type=EVENT_MOTION;
                      ret.d1=event.xmotion.state;
                      ret.d2=event.xmotion.x;
                      ret.d3=event.xmotion.y;
                      ret.window=event.xmotion.window;
                      break;
    case ButtonPress:ret.type=EVENT_BUTTON_PRESS;
                     ret.window=event.xbutton.window;
                     ret.d1=event.xbutton.button;
                     ret.d2=event.xbutton.x;
                     ret.d3=event.xbutton.y;
                     break;
    case ButtonRelease:ret.type=EVENT_BUTTON_RELEASE;
                     ret.window=event.xbutton.window;
                     ret.d1=event.xbutton.button;
                     ret.d2=event.xbutton.x;
                     ret.d3=event.xbutton.y;
                     break;
    case Expose:ret.type=EVENT_EXPOSE;
                ret.window=event.xexpose.window;
                ret.d1=event.xexpose.x;
                ret.d2=event.xexpose.y;
                ret.d3=event.xexpose.width;
                ret.d4=event.xexpose.height;
                ret.d5=event.xexpose.count;
                break;
    case KeyRelease:ret.type=EVENT_KEY_RELEASE;
                  ret.window=event.xkey.window;
                  XLookupString((XKeyEvent*)&event,tmp,10,&key,&status);
                  ret.d1=key;
                  switch (ret.d1) {
                    case XK_Return:ret.d1=13; break;
                    case XK_Escape:ret.d1=27; break;
                    case XK_Shift_L: ShiftState = 0; break;
                    case XK_Shift_R: ShiftState = 0; break;
                    case XK_Alt_L: AltState = 0; break;
                    case XK_Alt_R: AltState = 0; break;
                    case XK_Control_L: CtrlState = 0; ret.d1 = 0; break;
                    case XK_Control_R: CtrlState = 0; ret.d1 = 0; break;
                    case XK_F1:
                    case XK_F2:
                    case XK_F3:
                    case XK_F4:
                    case XK_F5:
                    case XK_F6:
                    case XK_F7:
                    case XK_F8:
                    case XK_F9:
                    case XK_F10:if (ShiftState) ret.d1 |= 0x10000;
                                if (AltState) ret.d1 |= 0x20000;
                                if (CtrlState) ret.d1 |= 0x40000;
                    }
                  break;
    case KeyPress:ret.type=EVENT_KEY_PRESS;
                  ret.window=event.xkey.window;
                  XLookupString((XKeyEvent*)&event,tmp,10,&key,&status);
                  ret.d1=key;
                  switch (ret.d1) {
                    case XK_Return:ret.d1=13; break;
                    case XK_Escape:ret.d1=27; break;
                    case XK_Shift_L: ShiftState = -1; break;
                    case XK_Shift_R: ShiftState = -1; break;
                    case XK_Alt_L: AltState = -1; break;
                    case XK_Alt_R: AltState = -1; break;
                    case XK_Control_L: CtrlState = -1; ret.d1 = 0; break;
                    case XK_Control_R: CtrlState = -1; ret.d1 = 0; break;
                    case XK_F1:
                    case XK_F2:
                    case XK_F3:
                    case XK_F4:
                    case XK_F5:
                    case XK_F6:
                    case XK_F7:
                    case XK_F8:
                    case XK_F9:
                    case XK_F10:if (ShiftState) ret.d1 |= 0x10000;
                                if (AltState) ret.d1 |= 0x20000;
                                if (CtrlState) ret.d1 |= 0x40000;
                               break;
                    }
                  break;
    }
#endif
#ifdef WIN32
  MSG msg;
  RECT rect;

  ret.type=EVENT_NONE;
  if (GetMessage(&msg, NULL, 0, 0) == 0) {
	  ret.type = EVENT_QUIT;
	  return ret;
  }
  if (msg.message == WM_SYSCOMMAND && msg.wParam == SC_CLOSE) {
	  ret.type = EVENT_CLOSE;
      ret.window = msg.hwnd;
	  return ret;
  }
  if (msg.message == WM_DESTROY) {
	  ret.type = EVENT_CLOSE;
      ret.window = msg.hwnd;
	  return ret;
  }
  if (msg.message == WM_CLOSE) {
	  ret.type = EVENT_CLOSE;
      ret.window = msg.hwnd;
	  return ret;
  }
  if (msg.message == WM_MOVE) {
    ret.type = EVENT_CONFIGURE;
	ret.window = msg.hwnd;
    ret.d1 = LOWORD(msg.lParam);
	ret.d2 = HIWORD(msg.lParam);
	ret.d3 = 0;
	ret.d4 = 0;
  }
    if (msg.message == WM_MOUSEMOVE) {
      ret.type=EVENT_MOTION;
      ret.window=msg.hwnd;
      ret.d1=1;
      ret.d2=msg.lParam & 0xffff;
      ret.d3=msg.lParam >> 16;
      }
    if (msg.message == WM_LBUTTONDOWN) {
      ret.type=EVENT_BUTTON_PRESS;
      ret.window=msg.hwnd;
      ret.d1=1;
      ret.d2=msg.lParam & 0xffff;
      ret.d3=msg.lParam >> 16;
      }
    else if (msg.message == WM_RBUTTONDOWN) {
      ret.type=EVENT_BUTTON_PRESS;
      ret.window=msg.hwnd;
      ret.d1=2;
      ret.d2=msg.lParam & 0xffff;
      ret.d3=msg.lParam >> 16;
      }
    else if (msg.message == WM_LBUTTONUP) {
      ret.type=EVENT_BUTTON_RELEASE;
      ret.window=msg.hwnd;
      ret.d1=1;
      ret.d2=msg.lParam & 0xffff;
      ret.d3=msg.lParam >> 16;
      }
    else if (msg.message == WM_RBUTTONUP) {
      ret.type=EVENT_BUTTON_RELEASE;
      ret.window=msg.hwnd;
      ret.d1=2;
      ret.d2=msg.lParam & 0xffff;
      ret.d3=msg.lParam >> 16;
      }
    else if (msg.message == WM_PAINT) {
      ret.type=EVENT_EXPOSE;
      ret.window=msg.hwnd;
      GetUpdateRect(ret.window,&rect,FALSE);
      ret.d1=rect.left;
      ret.d2=rect.top;
      ret.d3=rect.right-rect.left;
      ret.d4=rect.bottom-rect.top;
      ret.d5=0;
      }
    if (msg.message == WM_KEYDOWN) {
	  ret.type=EVENT_KEY_PRESS;
      ret.window=msg.hwnd;
      ret.d1=msg.wParam;
	  if (ret.d1 == VK_SHIFT) {
		  ret.d1 += 0xf000;
		  _shiftState = 1;
	  }
	  if (ret.d1 == VK_CONTROL) {
		  ret.d1 += 0xf000;
		  _ctrlState = 1;
	  }
	  if (ret.d1 == VK_CAPITAL) {
		  ret.d1 += 0xf000;
		  _capsState ^= 1;
	  }
      ret.d1 = _rcs_winTranslate(ret.d1);
	}
    if (msg.message == WM_KEYUP) {
	  ret.type=EVENT_KEY_RELEASE;
      ret.window=msg.hwnd;
      ret.d1=msg.wParam;
	  if (ret.d1 == VK_SHIFT) {
		  ret.d1 += 0xf000;
		  _shiftState = 0;
	  }
	  if (ret.d1 == VK_CONTROL) {
		  ret.d1 += 0xf000;
		  _ctrlState = 0;
	  }
      ret.d1 = _rcs_winTranslate(ret.d1);
	}
/*
	TranslateMessage(&msg);

    if (msg.message == WM_CHAR) {
      ret.type=EVENT_KEY_PRESS;
      ret.window=msg.hwnd;
      ret.d1=msg.wParam;
      }
*/
		DispatchMessage(&msg);
      
#endif
  return ret;
  }

/* **************************** */
/* ***** Named Background ***** */
/* **************************** */
void rcs_namedBackground(rcs_Display* d,rcs_GC gc,const char* color) {
#ifdef X
  XColor clr,exact;
  XAllocNamedColor(d,DefaultColormap(d,DefaultScreen(d)),color,
                   &clr,&exact);
  XSetBackground(d,gc,clr.pixel);
#endif
#ifdef WIN32
  int red,green,blue;
  rcs_namedColor(color,&red,&green,&blue);
  gc->background=RGB(red,green,blue);
#endif
  }

/* **************************** */
/* ***** Named Foreground ***** */
/* **************************** */
void rcs_namedForeground(rcs_Display* d,rcs_GC gc,const char* color) {
#ifdef X
  XColor clr,exact;
  XAllocNamedColor(d,DefaultColormap(d,DefaultScreen(d)),color,
                   &clr,&exact);
  XSetForeground(d,gc,clr.pixel);
#endif
#ifdef WIN32
  int red,green,blue;
  rcs_namedColor(color,&red,&green,&blue);
  gc->foreground=RGB(red,green,blue);
#endif
  }

/* ************************ */
/* ***** Open Display ***** */
/* ************************ */
rcs_Display *rcs_openDisplay(char* display_name) {
#ifdef X
  return XOpenDisplay(display_name);
#endif
#ifdef WIN32
  return &disp;
#endif
  }

/* ******************* */
/* ***** Open GC ***** */
/* ******************* */
rcs_GC rcs_openGC(rcs_Display* d,rcs_Window win) {
#ifdef X
  unsigned long mask;
  XGCValues     values;
  mask=0;
  mask=GCForeground | GCBackground;
  values.foreground=BlackPixel(d,DefaultScreen(d));
  values.background=WhitePixel(d,DefaultScreen(d));
  return XCreateGC(d,win,mask,&values);
#endif
#ifdef WIN32
  rcs_GC ret;
        ret=(rcs_GC)malloc(sizeof(struct _GC));
  ret->foreground=RGB(0,0,0);
  ret->background=RGB(255,255,255);
  ret->font=(HFONT)GetStockObject(SYSTEM_FONT);
  return ret;
#endif
  }

/* ********************** */
/* ***** Poll Event ***** */
/* ********************** */
rcs_Event rcs_pollEvent(rcs_Display* d) {
  rcs_Event ret;
#ifdef X
  if (XPending(d)>0) return rcs_getEvent(d);
#endif
#ifdef WIN32
  MSG msg;
  if (PeekMessage(&msg, NULL, 0, 0,PM_NOREMOVE)!=0) return rcs_getEvent(d);
#endif
  ret.type=EVENT_NONE;
  return ret;
  }

void  rcs_getDisplaySize(rcs_Display* d,int* width,int* height) {
#ifdef X
  *height = XDisplayHeight(d,DefaultScreen(d));
  *width = XDisplayWidth(d,DefaultScreen(d));
#endif
  }

/* *********************** */
/* ***** Root Window ***** */
/* *********************** */
rcs_Window rcs_rootWindow(rcs_Display* d) {
#ifdef X
  return DefaultRootWindow(d);
#endif
#ifdef WIN32
  return GetDesktopWindow();
#endif
  }

/* *************************** */
/* ***** Set Window Name ***** */
/* *************************** */
void rcs_setWindowName(rcs_Display* d,rcs_Window w,char* name) {
#ifdef X
  XTextProperty text;
  XStringListToTextProperty(&name,1,&text);
  XSetWMName(d,w,&text);
#endif
#ifdef WIN32
  SetWindowText(w,name);
#endif
  }

/* *********************** */
/* ***** Show Window ***** */
/* *********************** */
void rcs_showWindow(rcs_Display* d,rcs_Window win) {
#ifdef X
  XMapWindow(d,win);
  XFlush(d);
#endif
#ifdef WIN32
  ShowWindow(win,SW_SHOW);
  UpdateWindow(win);
#endif
  }

#endif

