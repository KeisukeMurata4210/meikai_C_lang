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
      for ( ; ntab > 0; --ntab) /* 空白文字でない時点でタブのカウントがあれば、dstに出力 ifの分岐ではなく終了条件で分岐させるのはおもしろいな */
        fputc('\t', dst);
      if (ch == '\t')               /* 入力自体がタブ文字なら、空白文字のカウントをゼロにする */
        count = 0;
      else {
        for ( ; count > 0; count--)
          fputc(' ', dst);         /* タブ区切りの空白のみタブに変換する。区切りと関係ない空白はそのまま出力する */
      }
      fputc(ch, dst);
      if (ch == '\n')
        pos = 0;
      else if (ch == '\t')
        pos += width - (pos - 1) % width - 1; /* 次の入力位置からタブ区切りまで何文字あるか */
    }
  }
}

int main(int argc, char *argv[])
{
  int width = 8;
  FILE *fp;

  if (argc < 2)
    entab(stdin, stdout, width); /* 標準入力　→　標準出力 */
  else {
    while (--argc > 0) {
      if (**(++argv) == '-') {
        if (*++(*argv) == 't')
          width = atoi(++*argv);
        else {
          fputs("パラメータが不正です。\n", stderr);
          return 1;
        }
      } else if ((fp = fopen(*argv, "r")) == NULL) {
        fprintf(stderr, "ファイル%sが正しくオープンできません。\n", *argv);
        return 1;
      } else {
        entab(fp, stdout, width); /* ストリームfp　→　標準出力 */
        fclose(fp);
      }
    }
  }
  return 0;
}
/*
**(++argv)：
*はポインタ参照先の値にアクセスする演算子。
最初の*で文字列の先頭アドレスに飛び、二つ目の*で先頭アドレスの値を取得する。
→ 最初の一文字を取得する（「-t6」の「-」）

*++(*argv) ：
（）内の*で文字列の先頭アドレスに飛び、++で文字列の2番目のアドレスに移動したあと、その2番目アドレスの値を*で取得する
→ 上と同じ文字列の2文字目を取得する（「-t6」の「t」）

++*argv：
*で文字列の先頭アドレスに飛び、++で2番目のアドレスに移動する。
atoiは文字列を数値に変換する、引数は文字列（＝文字配列の先頭のアドレス）
　++*argvは、**(++argv)のインクリメントも含めて数字の文字列を取得している（-t6なら6、-t12なら12を取得し、数値に変換する）
*/