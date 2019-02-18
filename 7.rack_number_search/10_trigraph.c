# include <time.h>
# include <ctype.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include "getputch.h"

# define MAX_STAGE  20
# define swap(type, x, y)    do {type t = x; x = y; y = t;} while(0)

int main(void)
{
  char *qstr[] = {"0123456789",
                  "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
                  "abcdefghijklmnopqrstuvwxyz"
                  };
  int chmax[] = {10, 26, 26};
  int i, stage;
  int key;         // 読み込んだキー
  double jikan;
  clock_t start, end;

  init_getputch();
  srand(time(NULL));

  printf(" 連続する三つの数字あるいは英字から\n");
  printf(" 隠されている文字を入力してください。\n");
  printf(" たとえば A ? C： と表示されたらBを\n");
  printf("      ば 4 5 ?： と表示されたら6を\n");
  printf(" 入力します。\n");
  printf("★スペースキーで開始します。\n");
  while (getch() != ' ')
    ;

  start = clock();
  for (stage = 0; stage < MAX_STAGE; stage++) {
    int qtype = rand() % 3; /* 0:数字 / 1:英大文字 / 2:英小文字 */
    int nhead = rand() % (chmax[qtype] -2); // 先頭文字の添字
    int x     = rand() % 3; // 3文字のどれを?にするか
    putchar('\r');

  }
}