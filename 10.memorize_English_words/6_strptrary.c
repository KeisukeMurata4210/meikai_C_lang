/* 文字列の配列を動的に確保（ポインタの配列） */
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int main(void)
{
  int num;       /* 文字列の個数 */
  char **pt;     /* 「要素のポインタが指し示すアドレスが、さらに文字配列を指し示している」文字ポインタ型変数のpt */

  printf("文字列は何個：");
  scanf("%d", &num);

  pt = (char **)calloc(num, sizeof(char *));/* 要素一つ一つはただ単に文字ポインタ型だから、char *のサイズを取得する */
  /* ↑callocは0で初期化する */

  if (pt == NULL)
    puts("記憶域の確保に失敗しました。");
  else {
    int i;

    for (i = 0; i < num; i++)
      pt[i] = NULL;/* 0で初期化するならなぜNULLを入れる？？ */

    for (i = 0; i < num; i++) {
      char temp[128];

      printf("pt[%d]：", i);
      scanf("%s", temp); /* &が要らないのは文字列＝文字配列＝先頭のポインタだから */

      pt[i] = (char *)malloc(strlen(temp) + 1);/* tempで受け取った文字列分の記憶域を確保し、先頭ポインタをpt[i]に格納 */

      if (pt[i] != NULL)
        strcpy(pt[i], temp);/* char **型を引数として指定できる */
      else {
        puts("記憶域の確保に失敗しました。");
        goto Free;
      }
    }
    for (i = 0; i < num; i++)
      printf("pt[%d] = %s\n", i, pt[i]);
Free:
    for (i = 0; i < num; i++)/* 二重で動的確保をしているため、両方解放する */
      free(pt[i]);
    free(pt);
  }
  return 0;
}