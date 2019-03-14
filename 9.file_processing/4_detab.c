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
          fputs("パラメータが不正です。\n", stderr);
          return 1;
        }
      } else if((fp = fopen(*argv, "r")) == NULL) {/* argvはすでに2回インクリメントされているから、ファイル名になる */
        fprintf(stderr, "ファイル%sが正しくオープンできません。\n", *argv);
        return 1;
      } else {
        detab(fp, stdout, width); /* ストリームfp　→　標準出力 */
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


fputc()は一文字ずつ
fputs()は文字列丸ごと
*/