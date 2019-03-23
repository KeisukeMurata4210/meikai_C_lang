/* 文字列を動的に確保 */
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int main(void)
{
  char st[16];
  char *pt;

  printf("文字列stを入力してください：");
  scanf("%s", st);

  pt = malloc(strlen(st) + 1); /* malloc()：指定された大きさの記憶域を確保して、先頭へのポインタを返す　EOS忘れずに */
  if (pt) {
    strcpy(pt, st);/* 引数2を引数1にコピー　！！引数はどちらもアドレス！！ */
    printf("その文字列の複製ptを作りました。\n");
    printf("st = %s\n", st); /* ポインタ変数だから、&をつけなくてもポインタ取得 */
    printf("pt = %s\n", pt);
    free(pt);   /* malloc()で確保した記憶域はfree()で解放する */
  }
  return 0;
}