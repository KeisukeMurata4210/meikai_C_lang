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
  for ( ; (ch = fgetc(src)) != EOF; pos++) {/* 入力ファイルから一文字取得する。それがEOFになるまで繰り返す。 */
    if (ch == ' ') {
      if (pos % width != 0)
        count++;   /* 空白文字でかつタブの区切りでないとき、空白文字として加算 */
      else {
        count = 0;
        ntab++;   /* 空白文字でかつタブの区切りのとき、タブとして加算 */
      }
    } else {
      for ( ; ntab > 0; --ntab) /* 空白文字でない時点でタブのカウントがあれば、dstに出力 */
        fputc('\t', dst);
      if (ch == '\t')               /* 入力自体がタブ文字なら、空白文字のカウントをゼロにする */
        count = 0;
      else {
        for ( ; count > 0; count--)
          fputc(' ', dst);         /* なぜここで空白文字を出力する？ */
      }
      fputc(ch, dst);
      if (ch == '\n')
        pos = 0;
      else if (ch == '\t')
        pos += width - (pos - 1) % width - 1;
    }
  }
}

int main(int argc, char *argv[])
{
  int width = 8;
  FILE *fp;

  if (argc < 2)
    entab(stdin, stdout, width); /* 標準入力　→　標準出力 */
}