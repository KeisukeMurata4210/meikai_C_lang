/* 文字列の配列を動的に確保（２次元配列） */
# include <stdio.h>
# include <stdlib.h>

int main(void)
{
  int num;        /* 文字列の個数 */
  char (*p)[15];  /* 文字数は定数15　この（）は何なんだ？？ */

  printf("文字列は何個：");
  scanf("%d", &num);

  p = (char (*)[15])malloc(num * 15); /* 要素の一つ一つのデータ型が「charポインタ型で要素数15」だよ、とキャストしているのか？？ */
  if (p == NULL)
    puts("記憶域の確保に失敗しました。");
  else {
    int i;
    for (i = 0; i < num; i++) {
      printf("p[%d]：", i);
      scanf("%s", p[i]);
    }
    for (i = 0; i < num; i++)
      printf("p[%d] = %s\n", i, p[i]);
    free(p);
  }
  return 0;
}