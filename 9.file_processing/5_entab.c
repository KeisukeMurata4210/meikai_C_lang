/* entab：空白文字を水平タブ文字に変換する */
# include <stdio.h>
# include <stdlib.h>

/* srcからの入力の空白文字をタブ化してdstへ出力 */
void entab(FILE *src, FILE *dst, int width)
{
  int ch;
  int count = 0;
  int ntab  = 0;
  int pos   = 1;
}

int main(int argc, char *argv[])
{
  int width = 8;
  FILE *fp;

  if (argc < 2)
    entab(stdin, stdout, width); /* 標準入力　→　標準出力 */
}