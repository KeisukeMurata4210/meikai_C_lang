# include <time.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "getputch.h"

# define QND  12  // 問題数

# define swap(type, x, y)  do {type t = x; x = y; y = t; }while(0)

int main(void)
{
  char *str[QND] = {"book", "computer", "default", "comfort",
                    "monday", "power", "light", "music",
                    "programming", "dog", "video", "include"};
  int i, stage;
  int qno[QND];
  clock_t start, end;

  init_getputch();
  srand(time(NULL));

  for (i = 0; i < QND; i++)
    qno[i] = i;

  for (i = QND -1; i > 0; i--) {
    int j = rand() % (i + 1);
    if (i != j)
      swap(int, qno[i], qno[j]);
  }

  printf("タイピング練習を始めます。\n");
  printf("スペースキーで開始します。\n");
  while(getch() != ' ')
    ;
  start = clock();
}