/* concat：ファイルのコピー */
# include <stdio.h>

/* srcからの入力をdstへ出力 */
void copy(FILE *src, FILE *dst)
{
  int ch;
  while((ch = fgetc(src)) != EOF)/* fgetc()自体は一文字ずつだが、ループしてEOFに到達するまで出力する */
    fputc(ch, dst);
}


int main(int argc, char *argv[])
{
  FILE *fp;

  if (argc < 2)
    copy(stdin, stdout);  /* 標準入力　→　標準出力 */
  else {
    while(--argc > 0) {
      if ((fp = fopen(*++argv, "r")) == NULL) {
        fprintf(stderr, "ファイル%sが正しくオープンできません。\n", *argv);
        return 1;
      } else {
        copy(fp, stdout); /* ストリームfp　→　標準出力 */
        fclose(fp);
      }
    }
  }
  return 0;
}
/*
挙動
①引数なし　→　標準入力ストリームから文字を読み込んで、標準出力ストリームへコピーする
②引数１つ　→　引数のファイル名の中身をコンソール出力する
③引数複数　→　それぞれのファイルを連続してコンソール出力する

Cは周辺機器などもファイルとして扱う　→　stdout（出力ストリーム）というファイルポインタに書き込めばコンソールに出力される

fgetc()：ストリームからの1文字読み込み
標準入力ストリームへのポインタを引数にすれば、getchar()と同じ動作になる

fputc()：ストリームへの1文字出力。第一引数はint型で、それをunsigned char型に変換して書き込む

「> ファイル名」で、コンソールではなく指定したファイル名に書き込める
*/