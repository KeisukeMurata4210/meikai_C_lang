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

  pt = malloc(strlen(str) + 1); /* 記憶域を動的に確保　EOS忘れずに */
  if (pt) {
    strcpy(pt, st);
  }
}