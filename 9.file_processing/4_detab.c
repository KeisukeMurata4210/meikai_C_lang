/* detab 水平タブ文字を展開する */
# include <stdio.h>
# include <stdlib.h>

/* srcからの入力をタブを展開してdstへ出力 */
void detab(FILE *src, FILE *dst, int width)
{
  int ch, pos = 1;
  while ((ch = fgetc(src)) != EOF) {
    int num;
    switch(ch) {
      case '\t':
        num = width - (pos - 1) % width;
    }
  }
}

int main(int argc, char *argv[])
{
  int width = 8;
  FILE *fp;

  if (argc < 2)
    detab(stdin, stdout, width);  /* 標準入力　→　標準出力 */
}