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
      case '\t':/* タブ文字 */
        num = width - (pos - 1) % width;/* numは空白文字を入れる個数。posは「n文字目」でも、「n文字目」を含めて空白を何文字入れるかを求めようとしているから -1 する */
        for ( ; num > 0; num--) {
          fputc(' ', dst);
          pos++;
        }
        break;
      case '\n':/* 改行文字 */
        fputc(ch, dst); pos = 1; break;
      default:
        fputc(ch, dst); pos++;   break;
    }
  }
}

int main(int argc, char *argv[])
{
  int width = 8;/* 引数を与えなければタブは8桁ごとの位置になる */
  FILE *fp;

  if (argc < 2)
    detab(stdin, stdout, width);  /* 標準入力　→　標準出力 */
  else {
    while (--argc > 0) {
      if (**(++argv) == '-') { /* すごい！！　オプションの「-」ってこうやって検出してるんだ！ */
        if (*++(*argv) == 't')
          width = atoi(++*argv);
        else {
          fputc("パラメータが不正です。\n", stderr);
          return 1;
        }
      } else if()
    }
  }
}