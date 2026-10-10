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

void write_font(int x,int y,int color,char* line) {
#ifndef ASCII
  byte letter;
  int  i;
#endif

  void small_a(int x,int y,int color) {
    draw(x+2,y+6,x+5,y+6,color);
    draw(x+1,y+7,x+2,y+7,color);
    draw(x+5,y+7,x+6,y+7,color);
    draw(x+2,y+8,x+6,y+8,color);
    draw(x+0,y+9,x+1,y+9,color);
    draw(x+5,y+9,x+7,y+9,color);
    plot(x+3,y+9,color);
    draw(x+1,y+10,x+4,y+10,color);
    draw(x+6,y+10,x+7,y+10,color);
  }

  void small_b(int x,int y,int color) {
    draw(x+2,y+2,x+3,y+2,color);
    draw(x+0,y+3,x+2,y+3,color);
    draw(x+1,y+4,x+2,y+4,color);
    draw(x+1,y+5,x+2,y+5,color);
    draw(x+1,y+6,x+5,y+6,color);
    draw(x+1,y+7,x+2,y+7,color);
    draw(x+4,y+7,x+7,y+7,color);
    draw(x+1,y+8,x+2,y+8,color);
    draw(x+5,y+8,x+6,y+8,color);
    draw(x+0,y+9,x+2,y+9,color);
    draw(x+5,y+9,x+7,y+9,color);
    draw(x+2,y+10,x+4,y+10,color);
  }

  void small_c(int x,int y,int color) {
    draw(x+2,y+6,x+5,y+6,color);
    draw(x+0,y+7,x+2,y+7,color);
    draw(x+5,y+7,x+7,y+7,color);
    draw(x+1,y+8,x+2,y+8,color);
    draw(x+0,y+9,x+2,y+9,color);
    draw(x+5,y+9,x+6,y+9,color);
    draw(x+2,y+10,x+5,y+10,color);
  }

  void small_d(int x,int y,int color) {
    draw(x+0,y+2,x+2,y+2,color);
    draw(x+2,y+3,x+3,y+3,color);
    draw(x+3,y+4,x+4,y+4,color);
    draw(x+4,y+5,x+5,y+5,color);
    draw(x+2,y+6,x+7,y+6,color);
    draw(x+0,y+7,x+2,y+7,color);
    draw(x+5,y+7,x+6,y+7,color);
    draw(x+1,y+8,x+2,y+8,color);
    draw(x+5,y+8,x+6,y+8,color);
    draw(x+0,y+9,x+2,y+9,color);
    draw(x+5,y+9,x+6,y+9,color);
    draw(x+2,y+10,x+4,y+10,color);
    draw(x+6,y+10,x+7,y+10,color);
  }

  void small_e(int x,int y,int color) {
    draw(x+2,y+6,x+5,y+6,color);
    draw(x+0,y+7,x+2,y+7,color);
    draw(x+4,y+7,x+6,y+7,color);
    draw(x+1,y+8,x+4,y+8,color);
    draw(x+0,y+9,x+2,y+9,color);
    plot(x+6,y+9,color);
    draw(x+1,y+10,x+5,y+10,color);
  }

  void small_f(int x,int y,int color) {
    draw(x+3,y+2,x+5,y+2,color);
    plot(x+7,y+2,color);
    draw(x+1,y+3,x+3,y+3,color);
    draw(x+5,y+3,x+6,y+3,color);
    draw(x+2,y+4,x+3,y+4,color);
    draw(x+2,y+5,x+3,y+5,color);
    draw(x+1,y+6,x+5,y+6,color);
    draw(x+2,y+7,x+3,y+7,color);
    draw(x+2,y+8,x+3,y+8,color);
    draw(x+1,y+9,x+5,y+9,color);
    draw(x+3,y+10,x+4,y+10,color);
  }

  void small_g(int x,int y,int color) {
    draw(x+2,y+6,x+5,y+6,color);
    draw(x+0,y+7,x+2,y+7,color);
    draw(x+5,y+7,x+7,y+7,color);
    draw(x+1,y+8,x+2,y+8,color);
    draw(x+5,y+8,x+6,y+8,color);
    draw(x+0,y+9,x+2,y+9,color);
    plot(x+5,y+9,color);
    draw(x+2,y+10,x+5,y+10,color);
    draw(x+5,y+11,x+6,y+11,color);
    draw(x+0,y+12,x+3,y+12,color);
    draw(x+5,y+12,x+7,y+12,color);
    draw(x+2,y+13,x+5,y+13,color);
  }

  void small_h(int x,int y,int color) {
    draw(x+2,y+2,x+3,y+2,color);
    draw(x+0,y+3,x+2,y+3,color);
    draw(x+1,y+4,x+2,y+4,color);
    draw(x+1,y+5,x+2,y+5,color);
    draw(x+1,y+6,x+2,y+6,color);
    draw(x+4,y+6,x+5,y+6,color);
    draw(x+1,y+7,x+3,y+7,color);
    draw(x+5,y+7,x+7,y+7,color);
    draw(x+1,y+8,x+2,y+8,color);
    draw(x+5,y+8,x+6,y+8,color);
    draw(x+0,y+9,x+2,y+9,color);
    draw(x+5,y+9,x+6,y+9,color);
    draw(x+1,y+10,x+3,y+10,color);
    draw(x+5,y+10,x+7,y+10,color);
    plot(x+4,y+11,color);
    draw(x+4,y+12,x+5,y+12,color);
    plot(x+3,y+13,color);
  }

  void small_i(int x,int y,int color) {
    draw(x+3,y+3,x+5,y+3,color);
    draw(x+2,y+4,x+4,y+4,color);
    draw(x+3,y+6,x+5,y+6,color);
    draw(x+2,y+7,x+4,y+7,color);
    draw(x+3,y+8,x+4,y+8,color);
    draw(x+3,y+9,x+6,y+9,color);
    draw(x+4,y+10,x+5,y+10,color);
  }

  void small_j(int x,int y,int color) {
    draw(x+4,y+2,x+6,y+2,color);
    draw(x+3,y+3,x+5,y+3,color);
    draw(x+4,y+5,x+5,y+5,color);
    draw(x+3,y+6,x+6,y+6,color);
    draw(x+4,y+7,x+5,y+7,color);
    draw(x+4,y+8,x+5,y+8,color);
    draw(x+4,y+9,x+5,y+9,color);
    draw(x+4,y+10,x+6,y+10,color);
    draw(x+4,y+11,x+6,y+11,color);
    draw(x+3,y+12,x+5,y+12,color);
    draw(x+2,y+13,x+3,y+13,color);
  }

  void small_k(int x,int y,int color) {
    draw(x+2,y+2,x+3,y+2,color);
    draw(x+0,y+3,x+2,y+3,color);
    draw(x+1,y+4,x+2,y+4,color);
    plot(x+5,y+4,color);
    draw(x+1,y+5,x+2,y+5,color);
    draw(x+4,y+5,x+6,y+5,color);
    draw(x+1,y+6,x+3,y+6,color);
    draw(x+6,y+6,x+7,y+6,color);
    draw(x+1,y+7,x+6,y+7,color);
    draw(x+1,y+8,x+2,y+8,color);
    draw(x+4,y+8,x+5,y+8,color);
    draw(x+0,y+9,x+3,y+9,color);
    draw(x+5,y+9,x+7,y+9,color);
    draw(x+2,y+10,x+3,y+10,color);
    plot(x+6,y+10,color);
  }

  void small_l(int x,int y,int color) {
    draw(x+4,y+2,x+5,y+2,color);
    draw(x+2,y+3,x+5,y+3,color);
    draw(x+3,y+4,x+4,y+4,color);
    draw(x+3,y+5,x+4,y+5,color);
    draw(x+3,y+6,x+4,y+6,color);
    draw(x+3,y+7,x+4,y+7,color);
    draw(x+3,y+8,x+4,y+8,color);
    draw(x+2,y+9,x+6,y+9,color);
    draw(x+3,y+10,x+5,y+10,color);
  }

  void small_m(int x,int y,int color) {
    draw(x+0,y+6,x+1,y+6,color);
    draw(x+5,y+6,x+6,y+6,color);
    plot(x+3,y+6,color);
    draw(x+0,y+7,x+7,y+7,color);
    draw(x+0,y+8,x+1,y+8,color);
    draw(x+3,y+8,x+4,y+8,color);
    draw(x+6,y+8,x+7,y+8,color);
    draw(x+0,y+9,x+1,y+9,color);
    draw(x+3,y+9,x+4,y+9,color);
    draw(x+6,y+9,x+7,y+9,color);
    draw(x+0,y+10,x+1,y+10,color);
    draw(x+3,y+10,x+4,y+10,color);
    draw(x+6,y+10,x+7,y+10,color);
  }

  void small_n(int x,int y,int color) {
    draw(x+0,y+6,x+1,y+6,color);
    draw(x+4,y+6,x+6,y+6,color);
    draw(x+0,y+7,x+3,y+7,color);
    draw(x+5,y+7,x+7,y+7,color);
    draw(x+1,y+8,x+2,y+8,color);
    draw(x+5,y+8,x+6,y+8,color);
    draw(x+1,y+9,x+3,y+9,color);
    draw(x+5,y+9,x+7,y+9,color);
    draw(x+0,y+10,x+2,y+10,color);
    draw(x+5,y+10,x+6,y+10,color);
  }

  void small_o(int x,int y,int color) {
    draw(x+3,y+6,x+5,y+6,color);
    draw(x+0,y+7,x+2,y+7,color);
    draw(x+5,y+7,x+7,y+7,color);
    draw(x+1,y+8,x+2,y+8,color);
    draw(x+5,y+8,x+6,y+8,color);
    draw(x+0,y+9,x+2,y+9,color);
    draw(x+5,y+9,x+7,y+9,color);
    draw(x+2,y+10,x+4,y+10,color);
  }

  void small_p(int x,int y,int color) {
    draw(x+1,y+6,x+2,y+6,color);
    draw(x+4,y+6,x+6,y+6,color);
    draw(x+0,y+7,x+3,y+7,color);
    draw(x+5,y+7,x+7,y+7,color);
    draw(x+1,y+8,x+2,y+8,color);
    draw(x+5,y+8,x+6,y+8,color);
    draw(x+1,y+9,x+3,y+9,color);
    draw(x+5,y+9,x+7,y+9,color);
    draw(x+0,y+10,x+6,y+10,color);
    draw(x+1,y+11,x+2,y+11,color);
    draw(x+1,y+12,x+3,y+12,color);
    draw(x+0,y+13,x+1,y+13,color);
  }

  void small_q(int x,int y,int color) {
    draw(x+3,y+6,x+5,y+6,color);
    draw(x+0,y+7,x+2,y+7,color);
    draw(x+5,y+7,x+7,y+7,color);
    draw(x+1,y+8,x+2,y+8,color);
    draw(x+5,y+8,x+6,y+8,color);
    draw(x+0,y+9,x+2,y+9,color);
    draw(x+5,y+9,x+6,y+9,color);
    draw(x+2,y+10,x+6,y+10,color);
    draw(x+5,y+11,x+6,y+11,color);
    draw(x+5,y+12,x+7,y+12,color);
    draw(x+4,y+13,x+6,y+13,color);
  }

  void small_r(int x,int y,int color) {
    draw(x+1,y+6,x+2,y+6,color);
    draw(x+4,y+6,x+5,y+6,color);
    draw(x+0,y+7,x+7,y+7,color);
    draw(x+1,y+8,x+2,y+8,color);
    plot(x+6,y+8,color);
    draw(x+1,y+9,x+3,y+9,color);
    draw(x+0,y+10,x+2,y+10,color);
  }

  void small_s(int x,int y,int color) {
    draw(x+2,y+6,x+6,y+6,color);
    draw(x+1,y+7,x+3,y+7,color);
    plot(x+5,y+7,color);
    draw(x+2,y+8,x+5,y+8,color);
    plot(x+1,y+9,color);
    draw(x+4,y+9,x+6,y+9,color);
    draw(x+0,y+10,x+5,y+10,color);
  }

  void small_t(int x,int y,int color) {
    draw(x+4,y+3,x+5,y+3,color);
    draw(x+3,y+4,x+4,y+4,color);
    draw(x+1,y+5,x+6,y+5,color);
    draw(x+3,y+6,x+4,y+6,color);
    draw(x+3,y+7,x+4,y+7,color);
    draw(x+3,y+8,x+4,y+8,color);
    draw(x+2,y+9,x+5,y+9,color);
    draw(x+4,y+10,x+6,y+10,color);
  }

  void small_u(int x,int y,int color) {
    draw(x+1,y+6,x+2,y+6,color);
    draw(x+4,y+6,x+6,y+6,color);
    draw(x+0,y+7,x+2,y+7,color);
    draw(x+5,y+7,x+7,y+7,color);
    draw(x+1,y+8,x+2,y+8,color);
    draw(x+5,y+8,x+6,y+8,color);
    draw(x+0,y+9,x+7,y+9,color);
    draw(x+2,y+10,x+3,y+10,color);
    draw(x+5,y+10,x+6,y+10,color);
  }

  void small_v(int x,int y,int color) {
    draw(x+1,y+6,x+2,y+6,color);
    draw(x+5,y+6,x+6,y+6,color);
    draw(x+0,y+7,x+2,y+7,color);
    draw(x+4,y+7,x+7,y+7,color);
    draw(x+1,y+8,x+2,y+8,color);
    draw(x+5,y+8,x+6,y+8,color);
    draw(x+1,y+9,x+7,y+9,color);
    draw(x+3,y+10,x+4,y+10,color);
  }

  void small_w(int x,int y,int color) {
    draw(x+0,y+6,x+1,y+6,color);
    draw(x+3,y+6,x+4,y+6,color);
    draw(x+6,y+6,x+7,y+6,color);
    draw(x+3,y+7,x+4,y+7,color);
    draw(x+3,y+8,x+4,y+8,color);
    plot(x+1,y+7,color); plot(x+1,y+8,color);
    plot(x+6,y+7,color); plot(x+6,y+8,color);
    draw(x+0,y+9,x+7,y+9,color);
    draw(x+1,y+10,x+2,y+10,color);
    draw(x+4,y+10,x+5,y+10,color);
  }

  void small_x(int x,int y,int color) {
    draw(x+1,y+6,x+2,y+6,color);
    draw(x+6,y+6,x+7,y+6,color);
    draw(x+0,y+7,x+3,y+7,color);
    draw(x+5,y+7,x+6,y+7,color);
    draw(x+3,y+8,x+4,y+8,color);
    draw(x+1,y+9,x+2,y+9,color);
    draw(x+4,y+9,x+7,y+9,color);
    draw(x+0,y+10,x+1,y+10,color);
    draw(x+5,y+10,x+6,y+10,color);
  }

  void small_y(int x,int y,int color) {
    draw(x+1,y+6,x+2,y+6,color);
    draw(x+5,y+6,x+6,y+6,color);
    draw(x+0,y+7,x+2,y+7,color);
    draw(x+5,y+7,x+7,y+7,color);
    draw(x+1,y+8,x+2,y+8,color);
    draw(x+5,y+8,x+6,y+8,color);
    draw(x+0,y+9,x+6,y+9,color);
    draw(x+2,y+10,x+3,y+10,color);
    draw(x+5,y+10,x+6,y+10,color);
    draw(x+6,y+11,x+7,y+11,color);
    draw(x+1,y+12,x+6,y+12,color);
    draw(x+2,y+13,x+4,y+13,color);
    plot(x+0,y+13,color);
  }

  void small_z(int x,int y,int color) {
    draw(x+1,y+6,x+3,y+6,color);
    draw(x+5,y+6,x+6,y+6,color);
    draw(x+0,y+7,x+1,y+7,color);
    draw(x+3,y+7,x+4,y+7,color);
    draw(x+1,y+8,x+4,y+8,color);
    draw(x+1,y+9,x+2,y+9,color);
    draw(x+5,y+9,x+6,y+9,color);
    draw(x+0,y+10,x+1,y+10,color);
    draw(x+3,y+10,x+5,y+10,color);
  }

  void big_a(int x,int y,int color) {
    draw(x+1,y+2,x+4,y+2,color);
    draw(x+0,y+3,x+1,y+3,color);
    draw(x+3,y+3,x+5,y+3,color);
    draw(x+3,y+4,x+5,y+4,color);
    draw(x+1,y+5,x+6,y+5,color);
    draw(x+0,y+6,x+1,y+6,color);
    draw(x+5,y+6,x+6,y+6,color);
    plot(x+3,y+6,color);
    draw(x+2,y+7,x+6,y+7,color);
    draw(x+5,y+8,x+6,y+8,color);
    plot(x+2,y+8,color);
    draw(x+1,y+9,x+2,y+9,color);
    draw(x+5,y+9,x+7,y+9,color);
    draw(x+2,y+10,x+3,y+10,color);
    draw(x+5,y+10,x+6,y+10,color);
    plot(x+0,y+10,color);
  }

  void big_b(int x,int y,int color) {
    draw(x+1,y+2,x+2,y+2,color);
    plot(x+4,y+2,color);
    draw(x+3,y+3,x+6,y+3,color);
    draw(x+0,y+4,x+1,y+4,color);
    draw(x+3,y+4,x+4,y+4,color);
    draw(x+6,y+4,x+7,y+4,color);
    draw(x+3,y+5,x+4,y+5,color);
    draw(x+6,y+5,x+7,y+5,color);
    plot(x+1,y+5,color);
    draw(x+0,y+6,x+1,y+6,color);
    draw(x+3,y+6,x+5,y+6,color);
    draw(x+3,y+7,x+6,y+7,color);
    plot(x+1,y+7,color);
    draw(x+5,y+8,x+7,y+8,color);
    plot(x+0,y+8,color);
    plot(x+2,y+8,color);
    draw(x+2,y+9,x+3,y+9,color);
    draw(x+5,y+9,x+7,y+9,color);
    draw(x+1,y+10,x+2,y+10,color);
    draw(x+4,y+10,x+6,y+10,color);
  }

  void big_c(int x,int y,int color) {
    int i;
    draw(x+5,y+2,x+6,y+2,color);
    plot(x+2,y+2,color);
    plot(x+1,y+3,color);
    draw(x+3,y+3,x+7,y+3,color);
    draw(x+0,y+4,x+3,y+4,color);
    plot(x+5,y+4,color);
    plot(x+7,y+4,color);
    for (i=5; i<=7; i++)
      {
        draw(x+0,y+i,x+1,y+i,color);
        plot(x+3,y+i,color);
        plot(x+5,y+i,color);
      }
    draw(x+0,y+8,x+2,y+8,color);
    plot(x+5,y+8,color);
    plot(x+7,y+8,color);
    draw(x+1,y+9,x+2,y+9,color);
    plot(x+6,y+9,color);
    draw(x+3,y+10,x+5,y+10,color);
  }

  void big_d(int x,int y,int color) {
    draw(x+0,y+1,x+1,y+1,color);
    draw(x+1,y+2,x+6,y+2,color);
    draw(x+3,y+3,x+7,y+3,color);
    draw(x+1,y+4,x+3,y+4,color);
    draw(x+6,y+4,x+7,y+4,color);
    draw(x+0,y+5,x+7,y+5,color);
    draw(x+1,y+6,x+3,y+6,color);
    draw(x+6,y+6,x+7,y+6,color);
    draw(x+0,y+7,x+1,y+7,color);
    draw(x+3,y+7,x+7,y+7,color);
    draw(x+6,y+8,x+7,y+8,color);
    plot(x+3,y+8,color);
    draw(x+1,y+9,x+4,y+9,color);
    draw(x+6,y+9,x+7,y+9,color);
    draw(x+0,y+10,x+1,y+10,color);
    draw(x+4,y+10,x+6,y+10,color);
  }

  void big_e(int x,int y,int color) {
    draw(x+0,y+2,x+2,y+2,color);
    draw(x+5,y+2,x+7,y+2,color);
    draw(x+2,y+3,x+6,y+3,color);
    plot(x+2,y+4,color);
    plot(x+4,y+4,color);
    draw(x+1,y+5,x+2,y+5,color);
    draw(x+4,y+5,x+7,y+5,color);
    draw(x+0,y+6,x+6,y+6,color);
    draw(x+1,y+7,x+2,y+7,color);
    plot(x+4,y+7,color);
    plot(x+0,y+8,color);
    plot(x+4,y+8,color);
    draw(x+2,y+9,x+6,y+9,color);
    draw(x+0,y+10,x+2,y+10,color);
    draw(x+5,y+10,x+7,y+10,color);
  }

  void big_f(int x,int y,int color) {
    draw(x+0,y+2,x+2,y+2,color);
    draw(x+5,y+2,x+7,y+2,color);
    draw(x+3,y+3,x+7,y+3,color);
    draw(x+2,y+4,x+3,y+4,color);
    plot(x+5,y+4,color);
    draw(x+1,y+5,x+3,y+5,color);
    draw(x+5,y+5,x+7,y+5,color);
    draw(x+0,y+6,x+2,y+6,color);
    draw(x+4,y+6,x+5,y+6,color);
    draw(x+1,y+7,x+2,y+7,color);
    draw(x+4,y+7,x+5,y+7,color);
    plot(x+2,y+8,color);
    draw(x+4,y+8,x+5,y+8,color);
    draw(x+0,y+9,x+4,y+9,color);
    draw(x+2,y+10,x+3,y+10,color);
  }

  void big_g(int x,int y,int color) {
    draw(x+5,y+2,x+6,y+2,color);
    plot(x+2,y+2,color);
    draw(x+4,y+3,x+7,y+3,color);
    plot(x+1,y+3,color);
    draw(x+0,y+4,x+1,y+4,color);
    draw(x+3,y+4,x+4,y+4,color);
    plot(x+6,y+4,color);
    draw(x+0,y+5,x+1,y+5,color);
    plot(x+3,y+5,color);
    plot(x+5,y+5,color);
    draw(x+0,y+6,x+1,y+6,color);
    draw(x+3,y+6,x+4,y+6,color);
    plot(x+6,y+6,color);
    draw(x+0,y+7,x+1,y+7,color);
    draw(x+3,y+7,x+4,y+7,color);
    draw(x+6,y+7,x+7,y+7,color);
    draw(x+0,y+8,x+1,y+8,color);
    draw(x+6,y+8,x+7,y+8,color);
    plot(x+3,y+8,color);
    draw(x+1,y+9,x+2,y+9,color);
    draw(x+6,y+9,x+7,y+9,color);
    draw(x+3,y+10,x+5,y+10,color);
  }

  void big_h(int x,int y,int color) {
    int i;
    draw(x+0,y+2,x+2,y+2,color);
    draw(x+5,y+2,x+6,y+2,color);
    draw(x+3,y+3,x+4,y+3,color);
    draw(x+6,y+3,x+7,y+3,color);
    for (i=4; i<=8; i++)
      {
        plot(x+0,y+i,color);
        draw(x+2,y+i,x+3,y+i,color);
      }
    draw(x+4,y+6,x+7,y+6,color);
    plot(x+6,y+5,color);
    draw(x+5,y+7,x+6,y+7,color);
    draw(x+5,y+8,x+6,y+8,color);
    draw(x+5,y+9,x+6,y+9,color);
    draw(x+0,y+10,x+2,y+10,color);
    draw(x+5,y+10,x+7,y+10,color);
    draw(x+2,y+11,x+3,y+11,color);
    plot(x+5,y+11,color);
    plot(x+6,y+12,color);
    draw(x+5,y+13,x+6,y+13,color);
  }

  void big_i(int x,int y,int color) {
    int i;
    draw(x+1,y+2,x+3,y+2,color);
    draw(x+5,y+2,x+7,y+2,color);
    for (i=3; i<=9; i++)
      {
        draw(x+3,y+i,x+4,y+i,color);
        plot(x+6,y+i,color);
      }
    draw(x+1,y+6,x+2,y+6,color);
    draw(x+1,y+10,x+2,y+10,color);
    draw(x+5,y+10,x+7,y+10,color);
  }

  void big_j(int x,int y,int color) {
    int i;
    draw(x+1,y+2,x+2,y+2,color);
    plot(x+4,y+2,color);
    plot(x+7,y+2,color);
    plot(x+0,y+3,color);
    draw(x+2,y+3,x+3,y+3,color);
    for (i=3; i<=9; i++) draw(x+5,y+i,x+6,y+i,color);
    draw(x+2,y+5,x+3,y+5,color);
    draw(x+1,y+6,x+3,y+6,color);
    draw(x+2,y+7,x+3,y+7,color);
    draw(x+0,y+9,x+2,y+9,color);
    draw(x+1,y+10,x+4,y+10,color);
  }

  void big_k(int x,int y,int color) {
    draw(x+0,y+2,x+3,y+2,color);
    draw(x+5,y+2,x+7,y+2,color);
    draw(x+5,y+3,x+7,y+3,color);
    plot(x+1,y+4,color);
    plot(x+3,y+4,color);
    plot(x+5,y+4,color);
    draw(x+0,y+5,x+1,y+5,color);
    draw(x+3,y+5,x+4,y+5,color);
    draw(x+0,y+6,x+1,y+6,color);
    draw(x+3,y+6,x+5,y+6,color);
    plot(x+1,y+7,color);
    plot(x+3,y+7,color);
    draw(x+5,y+7,x+6,y+7,color);
    plot(x+0,y+8,color);
    draw(x+5,y+8,x+6,y+8,color);
    draw(x+1,y+9,x+3,y+9,color);
    draw(x+5,y+9,x+6,y+9,color);
    draw(x+0,y+10,x+3,y+10,color);
    draw(x+6,y+10,x+7,y+10,color);
  }

  void big_l(int x,int y,int color) {
    draw(x+0,y+2,x+2,y+2,color);
    draw(x+5,y+2,x+6,y+2,color);
    plot(x+4,y+3,color);
    draw(x+6,y+3,x+7,y+3,color);
    plot(x+1,y+4,color);
    draw(x+3,y+4,x+4,y+4,color);
    draw(x+0,y+5,x+1,y+5,color);
    draw(x+3,y+5,x+4,y+5,color);
    draw(x+0,y+6,x+1,y+6,color);
    draw(x+3,y+6,x+4,y+6,color);
    draw(x+0,y+7,x+1,y+7,color);
    plot(x+3,y+7,color);
    plot(x+0,y+8,color);
    draw(x+3,y+9,x+7,y+9,color);
    draw(x+0,y+10,x+2,y+10,color);
    draw(x+4,y+10,x+6,y+10,color);
  }

  void big_m(int x,int y,int color) {
    int i;
    plot(x+2,y+2,color);
    draw(x+4,y+2,x+5,y+2,color);
    plot(x+7,y+2,color);
    draw(x+1,y+3,x+7,y+3,color);
    for (i=4; i<=9; i++) draw(x+4,y+i,x+5,y+i,color);
    for (i=4; i<=9; i++) plot(x+7,y+i,color);
    for (i=4; i<=6; i++) draw(x+0,y+i,x+2,y+i,color);
    plot(x+2,y+7,color); plot(x+2,y+8,color);
    draw(x+1,y+9,x+2,y+9,color);
    draw(x+0,y+10,x+1,y+10,color);
    draw(x+3,y+10,x+7,y+10,color);
  }

  void big_n(int x,int y,int color) {
    int i;
    draw(x+1,y+2,x+2,y+2,color);
    draw(x+5,y+2,x+7,y+2,color);
    plot(x+0,y+3,color);
    for (i=3; i<=9; i++) plot(x+2,y+i,color);
    for (i=3; i<=9; i++) plot(x+6,y+i,color);
    for (i=3; i<=5; i++) plot(x+3,y+i,color);
    for (i=5; i<=7; i++) plot(x+4,y+i,color);
    for (i=7; i<=9; i++) plot(x+5,y+i,color);
    draw(x+1,y+10,x+3,y+10,color);
    draw(x+6,y+10,x+7,y+10,color);
  }

  void big_o(int x,int y,int color) {
    int i;
    plot(x+2,y+2,color);
    plot(x+4,y+2,color);
    plot(x+6,y+2,color);
    draw(x+1,y+3,x+2,y+3,color);
    draw(x+4,y+3,x+7,y+3,color);
    draw(x+0,y+4,x+4,y+4,color);
    draw(x+6,y+4,x+7,y+4,color);
    for (i=5; i<=8; i++)
      {
        draw(x+0,y+i,x+1,y+i,color);
        plot(x+4,y+i,color);
        draw(x+6,y+i,x+7,y+i,color);
      }
    plot(x+1,y+9,color);
    plot(x+4,y+9,color);
    plot(x+6,y+9,color);
    draw(x+2,y+10,x+5,y+10,color);
  }

  void big_p(int x,int y,int color) {
    int i;
    for (i=2; i<=12; i++) draw(x+1,y+i,x+2,y+i,color);
    for (i=3; i<=8; i++) draw(x+5,y+i,x+6,y+i,color);
    draw(x+1,y+3,x+7,y+3,color);
    draw(x+1,y+8,x+7,y+8,color);
    plot(x+5,y+2,color);
    plot(x+5,y+9,color);
    plot(x+0,y+2,color);
    plot(x+0,y+5,color);
    plot(x+0,y+9,color);
    plot(x+0,y+12,color);
  }

  void big_q(int x,int y,int color) {
    int i;
    plot(x+2,y+2,color);
    plot(x+4,y+2,color);
    plot(x+6,y+2,color);
    plot(x+1,y+3,color);
    draw(x+4,y+3,x+7,y+3,color);
    draw(x+0,y+4,x+4,y+4,color);
    draw(x+6,y+4,x+7,y+4,color);
    for (i=5; i<=7; i++)
      {
        draw(x+0,y+i,x+1,y+i,color);
        plot(x+4,y+i,color);
        draw(x+6,y+i,x+7,y+i,color);
      }
    draw(x+0,y+8,x+2,y+8,color);
    plot(x+4,y+8,color);
    draw(x+6,y+8,x+7,y+8,color);
    draw(x+1,y+9,x+2,y+9,color);
    plot(x+4,y+9,color);
    plot(x+6,y+9,color);
    draw(x+3,y+10,x+5,y+10,color);
    draw(x+5,y+11,x+7,y+11,color);
  }

  void big_r(int x,int y,int color) {
    draw(x+0,y+2,x+3,y+2,color);
    plot(x+6,y+2,color);
    plot(x+2,y+3,color);
    draw(x+4,y+3,x+7,y+3,color);
    plot(x+1,y+4,color);
    draw(x+3,y+4,x+4,y+4,color);
    draw(x+6,y+4,x+7,y+4,color);
    draw(x+0,y+5,x+1,y+5,color);
    plot(x+3,y+5,color);
    draw(x+5,y+5,x+6,y+5,color);
    draw(x+0,y+6,x+4,y+6,color);
    plot(x+0,y+7,color);
    plot(x+2,y+7,color);
    draw(x+4,y+7,x+5,y+7,color);
    plot(x+2,y+8,color);
    draw(x+5,y+8,x+6,y+8,color);
    plot(x+2,y+9,color);
    draw(x+4,y+9,x+6,y+9,color);
    draw(x+0,y+10,x+3,y+10,color);
    draw(x+6,y+10,x+7,y+10,color);
  }

  void big_s(int x,int y,int color) {
    draw(x+2,y+2,x+4,y+2,color);
    plot(x+6,y+2,color);
    draw(x+0,y+3,x+1,y+3,color);
    draw(x+5,y+3,x+6,y+3,color);
    draw(x+1,y+4,x+3,y+4,color);
    plot(x+6,y+4,color);
    plot(x+0,y+5,color);
    draw(x+3,y+5,x+5,y+5,color);
    draw(x+1,y+6,x+2,y+6,color);
    draw(x+4,y+6,x+6,y+6,color);
    draw(x+2,y+7,x+4,y+7,color);
    draw(x+6,y+7,x+7,y+7,color);
    plot(x+3,y+8,color);
    draw(x+6,y+8,x+7,y+8,color);
    draw(x+1,y+9,x+4,y+9,color);
    draw(x+6,y+9,x+7,y+9,color);
    draw(x+0,y+10,x+1,y+10,color);
    draw(x+4,y+10,x+5,y+10,color);
  }

  void big_t(int x,int y,int color) {
    int i;
    for (i=2; i<=7; i++) draw(x+3,y+i,x+4,y+i,color);
    for (i=2; i<=9; i++) plot(x+6,y+i,color);
    draw(x+1,y+2,x+2,y+2,color);
    draw(x+0,y+3,x+1,y+3,color);
    plot(x+1,y+4,color);
    draw(x+6,y+2,x+7,y+2,color);
    plot(x+5,y+3,color);
    plot(x+0,y+5,color);
    plot(x+0,y+6,color);
    draw(x+0,y+7,x+1,y+7,color);
    draw(x+0,y+8,x+1,y+8,color);
    plot(x+3,y+8,color);
    draw(x+1,y+9,x+2,y+9,color);
    draw(x+6,y+9,x+7,y+9,color);
    draw(x+2,y+10,x+5,y+10,color);
  }

  void big_u(int x,int y,int color) {
    int i;
    for (i=3; i<=10; i++) draw(x+1,y+i,x+2,y+i,color);
    for (i=2; i<=9; i++) draw(x+5,y+i,x+6,y+i,color);
    draw(x+0,y+2,x+1,y+2,color);
    draw(x+0,y+9,x+7,y+9,color);
    draw(x+6,y+10,x+7,y+10,color);
    plot(x+0,y+6,color);
    plot(x+7,y+3,color);
    plot(x+4,y+4,color);
    plot(x+4,y+6,color);
    draw(x+1,y+10,x+3,y+10,color);
  }

  void big_v(int x,int y,int color) {
    int i;
    for (i=2; i<=9; i++) draw(x+1,y+i,x+2,y+i,color);
    for (i=2; i<=9; i++) draw(x+5,y+i,x+6,y+i,color);
    draw(x+0,y+9,x+3,y+9,color);
    draw(x+5,y+9,x+7,y+9,color);
    draw(x+3,y+10,x+5,y+10,color);
    plot(x+0,y+2,color);
    plot(x+3,y+3,color);
    plot(x+0,y+6,color);
    plot(x+4,y+2,color);
    plot(x+7,y+3,color);
  }

  void big_w(int x,int y,int color) {
    int i;
    for (i=1; i<=10; i++) plot(x+1,y+i,color);
    for (i=2; i<=9; i++) draw(x+3,y+i,x+4,y+i,color);
    for (i=2; i<=9; i++) plot(x+6,y+i,color);
{    draw(x+1,y+3,x+6,y+3,color);     }
    plot(x+0,y+2,color);
    plot(x+7,y+2,color);
    plot(x+0,y+6,color);
    plot(x+7,y+10,color);
    draw(x+0,y+10,x+2,y+10,color);
    draw(x+4,y+10,x+5,y+10,color);
  }

  void big_x(int x,int y,int color) {
    draw(x+1,y+2,x+2,y+2,color);
    draw(x+6,y+2,x+7,y+2,color);
    plot(x+0,y+3,color);
    draw(x+2,y+3,x+3,y+3,color);
    draw(x+5,y+3,x+6,y+3,color);
    plot(x+3,y+4,color);
    plot(x+5,y+4,color);
    draw(x+3,y+5,x+4,y+5,color);
    draw(x+1,y+6,x+7,y+6,color);
    draw(x+3,y+7,x+4,y+7,color);
    plot(x+2,y+8,color);
    draw(x+4,y+8,x+5,y+8,color);
    plot(x+1,y+9,color);
    draw(x+5,y+9,x+6,y+9,color);
    draw(x+0,y+10,x+1,y+10,color);
    draw(x+6,y+10,x+7,y+10,color);
  }

  void big_y(int x,int y,int color) {
    int i;
    for (i=3; i<=8; i++) draw(x+1,y+i,x+2,y+i,color);
    for (i=2; i<=8; i++) draw(x+5,y+i,x+6,y+i,color);
    draw(x+0,y+2,x+1,y+2,color);
    plot(x+3,y+3,color);
    plot(x+7,y+2,color);
    plot(x+0,y+6,color);
    draw(x+2,y+9,x+5,y+9,color);
    draw(x+2,y+10,x+3,y+10,color);
    draw(x+3,y+11,x+6,y+11,color);
    plot(x+7,y+12,color);
  }

  void big_z(int x,int y,int color) {
    draw(x+1,y+2,x+7,y+2,color);
    draw(x+1,y+3,x+2,y+3,color);
    plot(x+6,y+3,color);
    plot(x+0,y+4,color);
    plot(x+5,y+4,color);
    draw(x+1,y+5,x+6,y+5,color);
    draw(x+3,y+6,x+4,y+6,color);
    draw(x+0,y+7,x+5,y+7,color);
    draw(x+1,y+8,x+2,y+8,color);
    plot(x+7,y+8,color);
    plot(x+1,y+9,color);
    draw(x+3,y+9,x+7,y+9,color);
    draw(x+0,y+10,x+3,y+10,color);
    draw(x+5,y+10,x+6,y+10,color);
  }

  void period(int x,int y,int color) {
    draw(x+3,y+9,x+5,y+9,color);
    draw(x+2,y+10,x+4,y+10,color);
  }

  void comma(int x,int y,int color) {
    draw(x+3,y+9,x+4,y+9,color);
    draw(x+3,y+10,x+5,y+10,color);
    plot(x+5,y+11,color);
    plot(x+4,y+12,color);
  }

  void question(int x,int y,int color) {
    draw(x+2,y+2,x+6,y+2,color);
    draw(x+6,y+3,x+7,y+3,color);
    plot(x+1,y+3,color);
    draw(x+1,y+4,x+2,y+4,color);
    draw(x+6,y+4,x+7,y+4,color);
    draw(x+5,y+5,x+6,y+5,color);
    plot(x+4,y+6,color);
    plot(x+3,y+7,color);
    draw(x+3,y+9,x+4,y+9,color);
    draw(x+3,y+10,x+4,y+10,color);
  }

  void rune_a(int x,int y,int color) {
    int i;
    for (i=3; i<=9; i++) plot(x+1,y+i,color);
    for (i=7; i<=9; i++) plot(x+5,y+i,color);
    plot(x+2,y+4,color);
    plot(x+3,y+5,color);
    plot(x+4,y+6,color);
    draw(x+0,y+10,x+2,y+10,color);
    draw(x+4,y+10,x+6,y+10,color);
  }

  void rune_b(int x,int y,int color) {
    int i;
    for (i=2; i<=9; i++) plot(x+1,y+i,color);
    plot(x+2,y+2,color);
    plot(x+3,y+3,color);
    plot(x+4,y+4,color);
    plot(x+3,y+5,color);
    plot(x+2,y+6,color);
    plot(x+2,y+7,color);
    plot(x+3,y+8,color);
    draw(x+4,y+9,x+5,y+9,color);
    draw(x+0,y+10,x+2,y+10,color);
  }

  void rune_c(int x,int y,int color) {
    int i;
    for (i=4; i<=9; i++) plot(x+2,y+i,color);
    draw(x+1,y+2,x+2,y+2,color);
    draw(x+4,y+2,x+5,y+2,color);
    draw(x+2,y+7,x+3,y+7,color);
    plot(x+4,y+5,color);
    plot(x+4,y+6,color);
    draw(x+0,y+10,x+2,y+10,color);
    draw(x+4,y+4,x+5,y+4,color);
  }

  void rune_d(int x,int y,int color) {
    int i;
    for (i=3; i<=9; i++) plot(x+1,y+i,color);
    plot(x+0,y+2,color);
    plot(x+2,y+3,color);
    plot(x+5,y+5,color);
    draw(x+3,y+4,x+4,y+4,color);
    plot(x+2,y+6,color);
    plot(x+3,y+7,color);
    plot(x+4,y+8,color);
    plot(x+5,y+7,color);
    draw(x+0,y+10,x+1,y+10,color);
  }

  void rune_e(int x,int y,int color) {
    int i;
    for (i=2; i<=10; i++) plot(x+1,y+i,color);
    for (i=2; i<=10; i++) plot(x+5,y+i,color);
    plot(x+0,y+10,color);
    plot(x+4,y+10,color);
    plot(x+6,y+2,color);
    plot(x+2,y+3,color);
    plot(x+3,y+4,color);
    plot(x+4,y+5,color);
  }

  void rune_f(int x,int y,int color) {
    int i;
    for (i=2; i<=9; i++) plot(x+5,y+i,color);
    draw(x+4,y+10,x+6,y+10,color);
    plot(x+4,y+2,color);
    plot(x+3,y+3,color);
    plot(x+2,y+4,color);
    plot(x+3,y+5,color);
    plot(x+4,y+6,color);
  }

  void rune_g(int x,int y,int color) {
    int i;
    for (i=2; i<=9; i++) plot(x+1,y+i,color);
    draw(x+3,y+2,x+4,y+2,color);
    draw(x+6,y+2,x+7,y+2,color);
    draw(x+2,y+4,x+3,y+4,color);
    draw(x+2,y+6,x+4,y+6,color);
    draw(x+0,y+10,x+2,y+10,color);
    plot(x+0,y+2,color);
    plot(x+4,y+3,color);
    plot(x+6,y+3,color);
    plot(x+6,y+4,color);
    plot(x+5,y+5,color);
  }

  void rune_h(int x,int y,int color) {
    int i;
    for (i=2; i<=6; i++) plot(x+3,y+i,color);
    plot(x+4,y+2,color);
    plot(x+2,y+8,color);
    plot(x+1,y+9,color);
    plot(x+5,y+8,color);
    plot(x+6,y+9,color);
    draw(x+3,y+7,x+4,y+7,color);
    draw(x+0,y+10,x+1,y+10,color);
    draw(x+6,y+10,x+7,y+10,color);
  }

  void rune_i(int x,int y,int color) {
    int i;
    for (i=4; i<=10; i++) plot(x+4,y+i,color);
    draw(x+4,y+2,x+5,y+2,color);
    draw(x+3,y+4,x+4,y+4,color);
    draw(x+3,y+10,x+5,y+10,color);
  }

  void rune_j(int x,int y,int color) {
    int i;
    for (i=2; i<=10; i++) plot(x+1,y+i,color);
    for (i=8; i<=10; i++) plot(x+i-6,y+i,color);
    for (i=5; i<=10; i++) plot(x+i-3,y+i,color);
    draw(x+0,y+2,x+1,y+2,color);
    draw(x+0,y+10,x+1,y+10,color);
    draw(x+6,y+10,x+7,y+10,color);
  }

  void rune_l(int x,int y,int color) {
    int i;
    for (i=2; i<=10; i++) plot(x+3,y+i,color);
    draw(x+2,y+2,x+4,y+2,color);
    draw(x+2,y+10,x+4,y+10,color);
    draw(x+2,y+6,x+4,y+6,color);
    plot(x+5,y+5,color);
    plot(x+6,y+4,color);
    plot(x+6,y+3,color);
    plot(x+1,y+7,color);
    plot(x+0,y+8,color);
    plot(x+0,y+9,color);
  }

  void rune_m(int x,int y,int color) {
    int i;
    for (i=2; i<=10; i++) plot(x+1,y+i,color);
    draw(x+0,y+2,x+2,y+2,color);
    draw(x+0,y+10,x+2,y+10,color);
    plot(x+3,y+3,color);
    plot(x+4,y+4,color);
    plot(x+3,y+5,color);
    plot(x+2,y+6,color);
    plot(x+3,y+7,color);
    plot(x+4,y+8,color);
    plot(x+3,y+9,color);
    plot(x+2,y+10,color);
  }

  void rune_n(int x,int y,int color) {
    int i;
    for (i=2; i<=10; i++) plot(x+3,y+i,color);
    draw(x+2,y+3,x+4,y+3,color);
    draw(x+2,y+4,x+4,y+4,color);
    draw(x+2,y+10,x+4,y+10,color);
    plot(x+1,y+5,color);
    plot(x+0,y+6,color);
    plot(x+5,y+5,color);
    plot(x+6,y+6,color);
  }

  void rune_o(int x,int y,int color) {
    int i;
    for (i=4; i<=10; i++) plot(x+i-4,y+i,color);
    for (i=4; i<=10; i++) plot(x+11-i,y+i,color);
    draw(x+0,y+4,x+2,y+4,color);
    draw(x+5,y+4,x+7,y+4,color);
    draw(x+0,y+10,x+1,y+10,color);
    draw(x+6,y+10,x+7,y+10,color);
  }

  void rune_p(int x,int y,int color) {
    int i;
    for (i=2; i<=10; i++) plot(x+1,y+i,color);
    draw(x+0,y+2,x+2,y+2,color);
    draw(x+0,y+10,x+1,y+10,color);
    plot(x+3,y+3,color);
    plot(x+4,y+4,color);
    plot(x+3,y+5,color);
    plot(x+2,y+6,color);
  }

  void rune_q(int x,int y,int color) {
    int i;
    for (i=2; i<=10; i++) plot(x+6,y+i,color);
    draw(x+6,y+2,x+7,y+2,color);
    draw(x+6,y+10,x+7,y+10,color);
    draw(x+5,y+3,x+6,y+3,color);
    plot(x+4,y+4,color);
    plot(x+3,y+5,color);
    plot(x+2,y+4,color);
    plot(x+1,y+3,color);
    plot(x+0,y+4,color);
  }

  void rune_r(int x,int y,int color) {
    int i;
    for (i=2; i<=10; i++) plot(x+1,y+i,color);
    for (i=2; i<=4; i++) plot(x+5,y+i,color);
    for (i=8; i<=10; i++) plot(x+5,y+i,color);
    draw(x+2,y+6,x+3,y+6,color);
    draw(x+1,y+0,x+2,y+0,color);
    draw(x+5,y+0,x+6,y+0,color);
    plot(x+0,y+2,color);
    plot(x+4,y+5,color);
    plot(x+4,y+7,color);
    plot(x+0,y+10,color);
  }

  void rune_s(int x,int y,int color) {
    int i;
    for (i=2; i<=6; i++) plot(x+i-1,y+i,color);
    for (i=6; i<=10; i++) plot(x+11-i,y+i,color);
    draw(x+1,y+0,x+2,y+0,color);
    draw(x+5,y+0,x+6,y+0,color);
    plot(x+0,y+2,color);
    plot(x+0,y+10,color);
  }

  void rune_t(int x,int y,int color) {
    int i;
    for (i=4; i<=10; i++) plot(x+1,y+i,color);
    draw(x+1,y+2,x+2,y+2,color);
    draw(x+5,y+2,x+6,y+2,color);
    draw(x+3,y+6,x+4,y+6,color);
    plot(x+2,y+5,color);
    plot(x+5,y+5,color);
    plot(x+0,y+10,color);
  }

  void rune_u(int x,int y,int color) {
    int i;
    for (i=4; i<=6; i++) plot(x+i-1,y+i,color);
    for (i=4; i<=6; i++) plot(x+7-i,y+i,color);
    for (i=6; i<=10; i++) plot(x+i-5,y+i,color);
    for (i=6; i<=10; i++) plot(x+11-i,y+i,color);
    plot(x+0,y+10,color);
    plot(x+6,y+10,color);
  }

  void rune_v(int x,int y,int color) {
    int i;
    for (i=2; i<=10; i++) plot(x+6,y+i,color);
    draw(x+2,y+9,x+3,y+9,color);
    draw(x+5,y+10,x+7,y+10,color);
    plot(x+5,y+2,color);
    plot(x+4,y+3,color);
    plot(x+3,y+4,color);
    plot(x+4,y+5,color);
    plot(x+5,y+6,color);
    plot(x+5,y+7,color);
    plot(x+4,y+8,color);
  }

  void rune_w(int x,int y,int color) {
    int i;
    for (i=8; i<=10; i++) plot(x+3,y+i,color);
    draw(x+2,y+10,x+4,y+10,color);
    plot(x+3,y+4,color);
    plot(x+4,y+5,color);
    plot(x+5,y+6,color);
    plot(x+4,y+7,color);
    plot(x+2,y+5,color);
    plot(x+1,y+6,color);
    plot(x+2,y+7,color);
  }

  void rune_x(int x,int y,int color) {
    int i;
    for (i=5; i<=10; i++) plot(x+3,y+i,color);
    for (i=7; i<=10; i++) plot(x+i-4,y+i,color);
    for (i=7; i<=10; i++) plot(x+10-i,y+i,color);
    draw(x+3,y+3,x+4,y+3,color);
    draw(x+6,y+3,x+7,y+3,color);
    draw(x+2,y+10,x+4,y+10,color);
  }

  void rune_y(int x,int y,int color) {
    int i;
    for (i=2; i<=8; i++) plot(x+0,y+i,color);
    for (i=2; i<=10; i++) plot(x+6,y+i,color);
    for (i=2; i<=8; i++) plot(x+8-i,y+i,color);
    plot(x+1,y+2,color);
    plot(x+7,y+10,color);
  }

  void rune_z(int x,int y,int color) {
    int i;
    for (i=2; i<=10; i++) plot(x+6,y+i,color);
    draw(x+2,y+6,x+3,y+6,color);
    draw(x+2,y+9,x+3,y+9,color);
    plot(x+7,y+2,color);
    plot(x+7,y+10,color);
    plot(x+4,y+5,color);
    plot(x+4,y+8,color);
    plot(x+5,y+3,color);
    plot(x+5,y+4,color);
    plot(x+5,y+6,color);
    plot(x+5,y+7,color);
  }

  void draw_0(int x,int y,int color) {
    draw(x+1,y+3,x+1,y+9,color);
    draw(x+2,y+3,x+2,y+9,color);
    draw(x+5,y+3,x+5,y+9,color);
    draw(x+6,y+3,x+6,y+9,color);
    draw(x+0,y+3,x+7,y+3,color);
    draw(x+0,y+9,x+7,y+9,color);
    draw(x+3,y+2,x+4,y+2,color);
    draw(x+3,y+10,x+4,y+10,color);
    plot(x+4,y+4,color);
    plot(x+3,y+8,color);
  }

  void draw_1(int x,int y,int color) {
    draw(x+4,y+3,x+4,y+10,color);
    draw(x+5,y+4,x+5,y+10,color);
    draw(x+2,y+9,x+7,y+9,color);
    draw(x+2,y+4,x+3,y+4,color);
    plot(x+3,y+3,color);
  }

  void draw_2(int x,int y,int color) {
    draw(x+1,y+3,x+5,y+3,color);
    draw(x+0,y+4,x+2,y+4,color);
    plot(x+0,y+5,color);
    draw(x+4,y+4,x+6,y+4,color);
    draw(x+4,y+5,x+6,y+5,color);
    draw(x+3,y+6,x+5,y+6,color);
    draw(x+2,y+7,x+3,y+7,color);
    plot(x+1,y+8,color);
    plot(x+0,y+9,color);
    draw(x+2,y+9,x+7,y+9,color);
    plot(x+8,y+8,color);
    draw(x+0,y+10,x+1,y+10,color);
    draw(x+4,y+10,x+6,y+10,color);
  }

  void draw_3(int x,int y,int color) {
    draw(x+2,y+2,x+3,y+2,color);
    draw(x+1,y+3,x+7,y+3,color);
    draw(x+0,y+4,x+1,y+4,color);
    draw(x+5,y+4,x+6,y+4,color);
    draw(x+5,y+5,x+7,y+5,color);
    draw(x+3,y+6,x+5,y+6,color);
    draw(x+5,y+7,x+7,y+7,color);
    draw(x+5,y+8,x+7,y+8,color);
    draw(x+4,y+9,x+7,y+9,color);
    draw(x+0,y+8,x+1,y+8,color);
    draw(x+1,y+9,x+2,y+9,color);
    draw(x+1,y+10,x+3,y+10,color);
  }

  void draw_4(int x,int y,int color) {
    draw(x+4,y+2,x+4,y+10,color);
    draw(x+5,y+2,x+5,y+10,color);
    draw(x+3,y+3,x+7,y+3,color);
    plot(x+6,y+4,color); plot(x+2,y+4,color); plot(x+1,y+5,color);
    draw(x+0,y+6,x+1,y+6,color);
    draw(x+0,y+7,x+6,y+7,color);
    draw(x+2,y+9,x+6,y+9,color);
  }

  void draw_5(int x,int y,int color) {
    draw(x+1,y+2,x+6,y+2,color);
    draw(x+1,y+3,x+5,y+3,color);
    plot(x+6,y+1,color); plot(x+1,y+4,color);
    draw(x+1,y+5,x+5,y+5,color);
    draw(x+3,y+6,x+7,y+6,color);
    draw(x+5,y+7,x+5,y+9,color);
    draw(x+6,y+7,x+6,y+9,color);
    plot(x+7,y+9,color);
    draw(x+0,y+8,x+1,y+8,color);
    draw(x+1,y+9,x+3,y+9,color);
    draw(x+2,y+10,x+4,y+10,color);
  }

  void draw_6(int x,int y,int color) {
    draw(x+3,y+2,x+4,y+2,color);
    draw(x+0,y+3,x+7,y+3,color);
    draw(x+4,y+4,x+6,y+4,color);
    draw(x+1,y+4,x+1,y+9,color);
    draw(x+2,y+4,x+2,y+9,color);
    draw(x+0,y+9,x+2,y+9,color);
    draw(x+3,y+10,x+4,y+10,color);
    draw(x+4,y+6,x+7,y+6,color);
    draw(x+5,y+7,x+5,y+9,color);
    draw(x+6,y+7,x+6,y+9,color);
    plot(x+7,y+9,color); plot(x+3,y+7,color);
  }

  void draw_7(int x,int y,int color) {
    draw(x+2,y+2,x+3,y+2,color);
    draw(x+1,y+3,x+7,y+3,color);
    draw(x+3,y+6,x+4,y+6,color);
    draw(x+2,y+7,x+2,y+10,color);
    draw(x+3,y+7,x+3,y+10,color);
    draw(x+4,y+9,x+5,y+9,color);
    plot(x+0,y+4,color); plot(x+7,y+2,color);
    plot(x+6,y+4,color); plot(x+5,y+5,color);
  }

  void draw_8(int x,int y,int color) {
    int i;
    i = 3;
    while (i<10) {
        draw(x+0,y+i,x+2,y+i,color);
        draw(x+5,y+i,x+7,y+i,color);
        i = i+2;
      }
    draw(x+3,y+2,x+4,y+2,color);
    draw(x+2,y+6,x+5,y+6,color);
    draw(x+3,y+10,x+4,y+10,color);
    draw(x+1,y+4,x+2,y+4,color);
    draw(x+1,y+8,x+2,y+8,color);
    draw(x+5,y+4,x+6,y+4,color);
    draw(x+5,y+8,x+6,y+8,color);
    plot(x+3,y+5,color);
  }

  void draw_9(int x,int y,int color) {
    draw(x+3,y+2,x+4,y+2,color);
    draw(x+0,y+3,x+2,y+3,color);
    draw(x+0,y+5,x+3,y+5,color);
    draw(x+1,y+4,x+2,y+4,color);
    draw(x+2,y+6,x+4,y+6,color);
    draw(x+5,y+3,x+5,y+8,color);
    draw(x+6,y+3,x+6,y+8,color);
    plot(x+7,y+3,color);
    draw(x+0,y+9,x+7,y+9,color);
    draw(x+1,y+8,x+2,y+8,color);
    draw(x+3,y+10,x+4,y+10,color);
  }

  void colon(int x,int y,int color) {
    draw(x+3,y+4,x+4,y+4,color);
    draw(x+2,y+5,x+3,y+5,color);
    draw(x+3,y+8,x+4,y+8,color);
    draw(x+2,y+9,x+3,y+9,color);
  }

  void dollar(int x,int y,int color) {
    draw(x+4,y+1,x+4,y+11,color);
    draw(x+2,y+2,x+6,y+2,color);
    draw(x+1,y+3,x+2,y+3,color);
    draw(x+2,y+4,x+4,y+4,color);
    draw(x+6,y+3,x+7,y+3,color); plot(x+6,y+4,color);
    draw(x+5,y+5,x+5,y+6,color);
    draw(x+1,y+6,x+2,y+6,color);
    draw(x+2,y+7,x+3,y+7,color);
    plot(x+1,y+5,color); plot(x+3,y+5,color);
    draw(x+6,y+6,x+6,y+10,color);
    draw(x+7,y+7,x+7,y+9,color);
    draw(x+0,y+10,x+1,y+10,color);
    draw(x+1,y+9,x+3,y+9,color);
    draw(x+3,y+10,x+6,y+10,color);
  }

  void left(int x,int y,int color) {
    draw(x+6,y+2,x+7,y+2,color);
    draw(x+4,y+3,x+5,y+3,color);
    draw(x+3,y+4,x+3,y+9,color);
    draw(x+2,y+5,x+2,y+8,color);
    plot(x+4,y+4,color); plot(x+1,y+5,color);
    plot(x+1,y+8,color); plot(x+4,y+9,color);
    draw(x+4,y+10,x+5,y+10,color);
    draw(x+6,y+11,x+7,y+11,color);
  }

  void right(int x,int y,int color) {
    draw(x+1,y+2,x+2,y+2,color);
    draw(x+3,y+3,x+4,y+3,color);
    draw(x+5,y+4,x+5,y+9,color);
    draw(x+6,y+5,x+6,y+8,color);
    plot(x+4,y+4,color); plot(x+7,y+5,color);
    plot(x+7,y+8,color); plot(x+4,y+9,color);
    draw(x+3,y+10,x+4,y+10,color);
    draw(x+1,y+11,x+2,y+11,color);
  }

  void number(int x,int y,int color) {
    draw(x+0,y+4,x+7,y+4,color);
    draw(x+0,y+8,x+6,y+8,color);
    draw(x+0,y+9,x+0,y+10,color);
    draw(x+1,y+5,x+1,y+10,color);
    draw(x+2,y+2,x+2,y+7,color);
    draw(x+3,y+2,x+3,y+3,color);
    draw(x+3,y+9,x+3,y+10,color);
    draw(x+4,y+5,x+4,y+10,color);
    draw(x+5,y+2,x+5,y+7,color);
    draw(x+6,y+2,x+6,y+3,color);
  }

#ifdef ASCII
  textcolor(7);
  gotoxy(x/9,y/19);
  txt_write(line);
#else
  open_display();
  for (i=0; i<=strlen(line); i++)
    {
      letter = line[i];
      switch (letter) {
        case 'a': small_a(x,y,color); break;
        case 'b': small_b(x,y,color); break;
        case 'c': small_c(x,y,color); break;
        case 'd': small_d(x,y,color); break;
        case 'e': small_e(x,y,color); break;
        case 'f': small_f(x,y,color); break;
        case 'g': small_g(x,y,color); break;
        case 'h': small_h(x,y,color); break;
        case 'i': small_i(x,y,color); break;
        case 'j': small_j(x,y,color); break;
        case 'k': small_k(x,y,color); break;
        case 'l': small_l(x,y,color); break;
        case 'm': small_m(x,y,color); break;
        case 'n': small_n(x,y,color); break;
        case 'o': small_o(x,y,color); break;
        case 'p': small_p(x,y,color); break;
        case 'q': small_q(x,y,color); break;
        case 'r': small_r(x,y,color); break;
        case 's': small_s(x,y,color); break;
        case 't': small_t(x,y,color); break;
        case 'u': small_u(x,y,color); break;
        case 'v': small_v(x,y,color); break;
        case 'w': small_w(x,y,color); break;
        case 'x': small_x(x,y,color); break;
        case 'y': small_y(x,y,color); break;
        case 'z': small_z(x,y,color); break;
        case 'A': big_a(x,y,color); break;
        case 'B': big_b(x,y,color); break;
        case 'C': big_c(x,y,color); break;
        case 'D': big_d(x,y,color); break;
        case 'E': big_e(x,y,color); break;
        case 'F': big_f(x,y,color); break;
        case 'G': big_g(x,y,color); break;
        case 'H': big_h(x,y,color); break;
        case 'I': big_i(x,y,color); break;
        case 'J': big_j(x,y,color); break;
        case 'K': big_k(x,y,color); break;
        case 'L': big_l(x,y,color); break;
        case 'M': big_m(x,y,color); break;
        case 'N': big_n(x,y,color); break;
        case 'O': big_o(x,y,color); break;
        case 'P': big_p(x,y,color); break;
        case 'Q': big_q(x,y,color); break;
        case 'R': big_r(x,y,color); break;
        case 'S': big_s(x,y,color); break;
        case 'T': big_t(x,y,color); break;
        case 'U': big_u(x,y,color); break;
        case 'V': big_v(x,y,color); break;
        case 'W': big_w(x,y,color); break;
        case 'X': big_x(x,y,color); break;
        case 'Y': big_y(x,y,color); break;
        case 'Z': big_z(x,y,color); break;
        case '.': period(x,y,color); break;
        case ',': comma(x,y,color); break;
        case '?': question(x,y,color); break;
        case '0': draw_0(x,y,color); break;
        case '1': draw_1(x,y,color); break;
        case '2': draw_2(x,y,color); break;
        case '3': draw_3(x,y,color); break;
        case '4': draw_4(x,y,color); break;
        case '5': draw_5(x,y,color); break;
        case '6': draw_6(x,y,color); break;
        case '7': draw_7(x,y,color); break;
        case '8': draw_8(x,y,color); break;
        case '9': draw_9(x,y,color); break;
        case ':': colon(x,y,color); break;
        case '$': dollar(x,y,color); break;
        case '(': left(x,y,color); break;
        case ')': right(x,y,color); break;
        case '#': number(x,y,color); break;
      }
      switch (letter) {
        case 193:
        case 225:rune_a(x,y,color); break;
        case 194:
        case 226:rune_b(x,y,color); break;
        case 195:
        case 227:rune_c(x,y,color); break;
        case 196:
        case 228:rune_d(x,y,color); break;
        case 197:
        case 229:rune_e(x,y,color); break;
        case 198:
        case 230:rune_f(x,y,color); break;
        case 199:
        case 231:rune_g(x,y,color); break;
        case 200:
        case 232:rune_h(x,y,color); break;
        case 201:
        case 233:rune_i(x,y,color); break;
        case 202:
        case 234:rune_j(x,y,color); break;
        case 203:
        case 235:rune_c(x,y,color); break;
        case 204:
        case 236:rune_l(x,y,color); break;
        case 205:
        case 237:rune_m(x,y,color); break;
        case 206:
        case 238:rune_n(x,y,color); break;
        case 207:
        case 239:rune_o(x,y,color); break;
        case 208:
        case 240:rune_p(x,y,color); break;
        case 209:
        case 241:rune_q(x,y,color); break;
        case 210:
        case 242:rune_r(x,y,color); break;
        case 211:
        case 243:rune_s(x,y,color); break;
        case 212:
        case 244:rune_t(x,y,color); break;
        case 213:
        case 245:rune_u(x,y,color); break;
        case 214:
        case 246:rune_v(x,y,color); break;
        case 215:
        case 247:rune_w(x,y,color); break;
        case 216:
        case 248:rune_x(x,y,color); break;
        case 217:
        case 249:rune_y(x,y,color); break;
        case 218:
        case 250:rune_z(x,y,color); break;
      }
    x = x+9;
  }
  close_display();
#endif
}

