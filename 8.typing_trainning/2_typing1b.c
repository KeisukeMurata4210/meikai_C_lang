# include <time.h>
# include <stdio.h>
# include <string.h>
# include "getputch.h"

int main(void)
{
  int i;
  char *str = "How do you do?";
  int len = strlen(str);
  clock_t start, end;

  init_getputch();
  printf("このとおりにタイプしてください。\n");

  start = clock();
  for (i = 0; i < len; i++) {
    printf("%s \r", &str[i]); // 添字iの位置から最後までを表示した後、カーソルを一文字めの位置に戻す。→入力するにつれて添字が上がっていく
    fflush(stdout);
    while (getch() != str[i])
      ;
  }
  end = clock();
  term_getputch();
  printf("\r%.lf秒でした。\n", (double)(end - start) / CLOCKS_PER_SEC);
  return 0;
}