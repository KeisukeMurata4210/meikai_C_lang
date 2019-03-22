/* bcopy：ファイルのコピー */
# include <stdio.h>

# define BSIZE  1024   /* この大きさに分割してコピー */

int main(int argc, char *argv[])
{
  int n;
  FILE *src, *dst;
  unsigned char buf[BSIZE];

  if (argc != 3) {
    fprintf(stderr, "パラメータが不正です。\n");
    fprintf(stderr, "bcopy コピー元ファイル名　コピー先ファイル名\n");
  } else {
    if ((src = fopen(*++argv, "rb")) == NULL) {       /* rbは既存ファイルを開く。存在しないときエラー */
      fprintf(stderr, "ファイル%sがオープンできません。\n", *argv);
      return 1;
    } else if ((dst = fopen(*++argv, "wb")) == NULL) { /* wbは書き込み用にファイル開く。ない時は新規作成。 */
      fprintf(stderr, "ファイル%sがオープンできません。\n", *argv);
      fclose(src);/* srcだけ閉める　←　srcを開いた後dstをひらけなかった時の処理だから、 */
      return 1;
    } else {
      while ((n = fread(buf, BSIZE, 1, src)) > 0)
        fwrite(buf, n, 1, dst);
      fclose(src);
      fclose(dst);
    }
  }
  return 0;
}