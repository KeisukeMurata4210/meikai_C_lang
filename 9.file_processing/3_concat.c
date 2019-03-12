/* concat：ファイルのコピー */
# include <stdio.h>

/* srcからの入力をdstへ出力 */
void copy(FILE *src, FILE *dst)
{
  int ch;
  while((ch = fgetc(src)) != EOF)
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

*/