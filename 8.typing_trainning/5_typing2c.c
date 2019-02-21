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
  clock_t start, end;

  init_getputch();
  srand(time(NULL));

  for (i = QND -1; i > 0; i--) {
    int j = rand() % (i + 1); // 0~i
    if (i != j)
      swap(char *, str[i], str[j]);  // str自体を並び替える
  }

  printf("タイピング練習を始めます。\n");
  printf("スペースキーで開始します。\n");
  while(getch() != ' ')
    ;
  start = clock();
  for (stage = 0; stage < QND; stage++) {
    int len = strlen(str[stage]); // こっちも文字列から直接長さを取得する
    for (i = 0; i < len; i++) {
      printf("%s \r", &str[stage][i]);
      fflush(stdout);
      while(getch() != str[stage][i])
        ;
    }
  }
  end = clock();
  term_getputch();
  printf("\r%.lf秒でした。\n", (double)(end - start) / CLOCKS_PER_SEC);
  return 0;
}