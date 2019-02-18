# include <ctype.h>
# include <time.h>
# include <stdio.h>
# include <stdlib.h>
# include "getputch.h"

# define MAX_STAGE  10
# define swap(type, x, y)    do {type t = x; x = y; y = t;} while(0)

int main(void)
{
  int i, j, x, stage;
  int dgt[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int a[10];
  double jikan;
  clock_t start, end;

  init_getputch();
  srand(time(NULL));

  printf("ダブっている数字を入力してください。\n");
  printf("スペースキーで開始します。\n");
  fflush(stdout);
  while (getch() != ' ') // スペースを入力されるまで無限ループ
    ;
  start = clock();
  for (stage = 0; stage < MAX_STAGE; stage++) {
    int x = rand() % 9;  // 0~8
    int no;

    i = j = 0;
    while (i < 9) {
      a[j++] = dgt[i];
      if (i == x)
        a[j++] = dgt[i];
      i++;
    }
    for (i = 9; i > 0; i--) {
      int j = rand() % (i + 1);
      if (i != j)
        swap(int, a[i], a[j]);
    }
    for (i = 0; i < 10; i++)
      printf("%d ", a[i]);
    printf("：");
    fflush(stdout);
    do {
      no = getch(); //押されたキーの値を取得
      if (isprint(no)) {// 表示可能であれば
        putch(no);//押されたキーを表示
        if (no != dgt[x] + '0') // 正解でなければ
          putch('\b');      // カーソルを戻し、次の入力で上書きされるようにする。
        else
          printf("\n");    // 改行する
        fflush(stdout);
      }
    } while(no != dgt[x] + '0'); // 正解するまで繰り返す
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