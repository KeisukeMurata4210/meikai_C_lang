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
  int qno[QND]; // 出題順序
  clock_t start, end;

  init_getputch();
  srand(time(NULL));

  for (i = 0; i < QND; i++) // 出題順序＝strの添字を準備する。
    qno[i] = i;

  for (i = QND -1; i > 0; i--) {
    int j = rand() % (i + 1); // 0~i
    if (i != j)
      swap(int, qno[i], qno[j]);  // strの添字を並び替える => 出題順序が並び変わる
  }

  printf("タイピング練習を始めます。\n");
  printf("スペースキーで開始します。\n");
  while(getch() != ' ')
    ;
  start = clock();
  for (stage = 0; stage < QND; stage++) {
    int len = strlen(str[qno[stage]]); // 添字にqno[stage]を指定すると、並び替えられた順番でstrの文字列を取り出せる
    for (i = 0; i < len; i++) {
      printf("%s \r", &str[qno[stage]][i]); // iのループのたび、book ook ok と表示されていく

      fflush(stdout);
      while(getch() != str[qno[stage]][i])
        ;
    }
  }
  end = clock();
  term_getputch();
  printf("\r%.lf秒でした。\n", (double)(end - start) / CLOCKS_PER_SEC);
  return 0;
}