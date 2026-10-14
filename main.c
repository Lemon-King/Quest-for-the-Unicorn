/*
 *******************************************************************
 *** This software is copyright 1985-2007 by Michael H Riley     ***
 *** You have permission to use, modify, copy, and distribute    ***
 *** this software so long as this copyright notice is retained. ***
 *** This software may not be used in commercial applications    ***
 *** without express written permission from the author.         ***
 *******************************************************************
*/

#define MAIN

#include "header.h"

int main(int argc,char** argv) {
  int i,j;
  int loadgame;
#ifdef DEBUG
  debug_tab = 0;
#endif
  in_arena = 'N';
  combat_mode = 's';
  score1 = 0;
  score2 = 0;
  wizardmode = 'N';
  u_randomize();
  soundon = 'Y';
  restock = 'N';
  loadgame = 0;
  bottom = 10;
  for (i=0; i<NUM_MSG; i++) {
    strcpy(messages[i],"");
    msg_clr[i] = 15;
    }
  for (i=1; i<argc; i++) {
    if (argv[i][0] != '-') {
      loadgame = 1;
      strcpy(loadname,argv[i]);
      }
    }
  i=0;
  while (objects[i].otype < 999) i++;
  NO_OF_OBJECTS = i;
  TOTAL_OBJECTS = i;
printf("Object Count: %d\n",i);
  i=0;
  while (gen[i].region < 99) i++;
  NO_OF_GENS = i;
printf("Message Count: %d\n",i);
  i=0;
  while (lore[i].region < 99) i++;
  NO_OF_LORE = i;
printf("Lore Count: %d\n",i);
  i=0;
  while (recipes[i].object < 999) i++;
printf("Recipe Count: %d\n",i);
/*
  for (i=1; i<=paramcount; i++)
    {
      if copy(paramstr(i),1,1)<>'/' then
        {
          loadgame = 1;
          loadname = paramstr(i);
        }
      if paramstr(i)='/E' then screen = 'E';
      if paramstr(i)='/e' then screen = 'E';
      if paramstr(i)='/V' then screen = 'V';
      if paramstr(i)='/v' then screen = 'V';
      if paramstr(i)='/h' then screen = 'M';
      if paramstr(i)='/H' then screen = 'M';
      if paramstr(i)='/q' then soundon = 'N';
      if paramstr(i)='/Q' then soundon = 'N';
      if paramstr(i)='/b' then bones = 'Y';
      if paramstr(i)='/B' then bones = 'Y';
      if paramstr(i)='/R' then restock = 'Y';
      if paramstr(i)='/r' then restock = 'Y';
      if paramstr(i)='/C' then combat_mode = 'F';
      if paramstr(i)='/c' then combat_mode = 'F';
      if copy(paramstr(i),1,3)='/D:' then bottom = mval(copy(paramstr(i),4,12));
      if copy(paramstr(i),1,3)='/d:' then bottom = mval(copy(paramstr(i),4,12));
      if paramstr(i)='/Z' then real_time = 'Y';
      if paramstr(i)='/z' then real_time = 'Y';
      if paramstr(i)='/f' then fix_rec = 'Y';
    }
*/
  graphics = ' ';
  read_sprites();
/*
  m_file = open("unicorn.spl",O_RDONLY);
  if (m_file < 0) {
    printf("Fatal Error: Could not open unicorn.spl\n");
    exit(1);
    }
  for (i=1; i<=NO_OF_SPELLS; i++) {
    lseek(m_file,sizeof(SPELL_REC) * i,SEEK_SET);
    read(m_file,&(spells[i]),sizeof(SPELL_REC));
    }
  close(m_file);
*/
  init_graph();
  title();
  show_scores();
  if (loadgame == 1) {
    textmode(3); gotoxy(1,1); textcolor(10);
    txt_write("Loading Game . . .");
    load(loadname);
    if (player.d_level>0) mod_exit = 2;
      else mod_exit = 1;
    disp_char();
    }
  else {
    make_char();
    for (i=1; i<=100; i++)
      for (j=1; j<=100; j++)
        player.known[i][j] = 0;
      mod_exit = 1;
    }
  exit_flag = ' ';
  while (exit_flag == ' ') {
    if (mod_exit == 1) up_land();
    if (mod_exit == 2) cave();
    if (mod_exit == 3) exit_flag = '*';
    if (mod_exit == 4) exit_flag = 'S';
    if (mod_exit == 5) cave();
    if (mod_exit == 6) exit_flag = 'D';
    }
  if (exit_flag == 'S') save();
  textmode(3);
  if (exit_flag == 'D') {
    textcolor(12);
    gotoxy(27,12);
    txt_writeln("Sorry but you have died!!");
    delay(2500);
    }
  check_scores();
  if (score1>0 || score2>0) show_scores();
  textmode(3);
  unlink("temp01.$$$");
  return 0;
  }

#ifdef WIN32
int APIENTRY WinMain(HINSTANCE hInstance,
                                         HINSTANCE hPrevInstance,
                                         LPSTR     lpCmdLine,
                                         int       nCmdShow) {
        int argc;
                char **argv;
                char buffer[1024];
                char *pBuffer;
        rcs_initWin32(hInstance);
                strcpy(buffer,"elf");
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

        main(argc,argv);
        return 0;
}
#endif

