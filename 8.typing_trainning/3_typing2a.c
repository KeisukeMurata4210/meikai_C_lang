# include <time.h>
# include <stdio.h>
# include <string.h>
# include "getputch.h"

# define QND   12  // 問題数

int main(void)
{
  char *str[QND] = {"book", "computer", "default", "comfort",
                    "monday", "power", "light", "music",
                    "programming", "dog", "video", "include"};
  int i, stage;
  clock_t start, end;

  init_getputch();
  printf("タイピング練習を始めます。\n");
  printf("スペースキーで開始します。\n");
  while(getch() != ' ')
    ;
  
  start = clock();
  for (stage = 0; stage < QND; stage++) {
    int len = strlen(str[stage]);
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