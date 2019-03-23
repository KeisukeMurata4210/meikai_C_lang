/* 文字列の配列を動的に確保（２次元配列） */
# include <stdio.h>
# include <stdlib.h>

int main(void)
{
  int num;        /* 文字列の個数 */
  char (*p)[15];  /* 文字数は定数15　「長さ15の文字配列、へのポインタ」p　＝　指し示す領域の種類が「長さ15の文字配列」ということ */

  printf("文字列は何個：");
  scanf("%d", &num);

  p = (char (*)[15])malloc(num * 15); /* 「長さ15の文字配列、へのポインタ」型にキャスト　記憶域の一単位が15byteだから、num * 15 */
  /* 領域15の固まりをnum個分確保する */
  if (p == NULL)
    puts("記憶域の確保に失敗しました。");
  else {
    int i;
    for (i = 0; i < num; i++) {
      printf("p[%d]：", i);
      scanf("%s", p[i]);  /* ポインタp（＝mallocで確保した一単位つまり、「長さ15の文字配列（＝文字列一つ）」を指す） */
    }
    for (i = 0; i < num; i++)
      printf("p[%d] = %s\n", i, p[i]);
    free(p);
  }
  return 0;
}