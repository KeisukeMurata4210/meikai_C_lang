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
  int chmax[] = {10, 26, 26};//文字数を覚えておく
  int i, stage;
  int key;         // 読み込んだキー
  double jikan;
  clock_t start, end;

  init_getputch();
  srand(time(NULL));

  printf(" 連続する三つの数字あるいは英字から\n");
  printf(" 隠されている文字を入力してください。\n");
  printf(" たとえば A ? C： と表示されたらBを\n");
  printf("         4 5 ?： と表示されたら6を\n");
  printf(" 入力します。\n");
  printf("★スペースキーで開始します。\n");
  fflush(stdout);//この仕組みはまた今度
  while (getch() != ' ')
    ;

  start = clock();
  for (stage = 0; stage < MAX_STAGE; stage++) {
    int qtype = rand() % 3; /* 0:数字 / 1:英大文字 / 2:英小文字 */
    int nhead = rand() % (chmax[qtype] -2); // 先頭文字の添字　chmaxで文字数を取得し、３文字表示だから最大値は-2した値。その値一つ手前までのランダムにすれば先頭文字の添字を取れる
    int x     = rand() % 3; // 3文字のどれを?にするか
    putchar('\r');
    for (i = 0; i< 3; i++) {
      if (i != x)
        printf(" %c", qstr[qtype][nhead + i]);
      else
        printf(" ?");
    }
    printf(" ： ");
    fflush(stdout);

    do {
      key = getch();
      if (isprint(key)) {
        putch(key);
        if (key != qstr[qtype][nhead + x])
          putch('\b');//カーソルを一つもどす
      }
    } while(key != qstr[qtype][nhead + x]);
  }
  end = clock();

  jikan = (double)(end - start) / CLOCKS_PER_SEC;
  printf("%.lf秒かかりました。\n", jikan);
  
  if (jikan > 25.0)
    printf("阿保が。\n");
  else if (jikan > 20.0)
    printf("少し鈍いですね。\n");
  else if (jikan > 17.0)
    printf("まあまあですね。\n");
  else
    printf("素早いですね。\n");

  term_getputch();
  return 0;
}