# include <time.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define CNO     4/* 選択肢の数 */
# define swap(type, x, y) do {type t = x; x = y; y = t;} while(0)

int QNO;
char **jptr;
char **eptr;


int read_tango(void)
{
  int i;
  FILE *fp;

  if ((fp = fopen("TANGO", "r")) == NULL) return 1;/* 単語を別ファイルにするのは面白い */

  fscanf(fp, "%d", &QNO);   /* 単語数をQNOに格納 */

  if ((jptr = calloc(QNO, sizeof(char *))) == NULL) return 1; /* まず記憶域を確保 */
  if ((eptr = calloc(QNO, sizeof(char *))) == NULL) return 1;

  for (i = 0; i < QNO; i++) {
    char etemp[1024];
    char jtemp[1024];

    fscanf(fp, "%s%s", etemp, jtemp);/* TANGO　では、英単語　日本語　の順で並んでいる */
    if ((eptr[i] = malloc(strlen(etemp) + 1)) == NULL) return 1;
    if ((jptr[i] = malloc(strlen(etemp) + 1)) == NULL) return 1;
    strcpy(eptr[i], etemp);
    strcpy(jptr[i], jtemp);
  }
  fclose(fp);

  return 0;
}

int main(void)
{
  int i;
  int nq, pq;      /* 問題の番号・前回の問題番号 */
  int na;          /* 正解の番号 */
  int sw;          /* 問題の単語（0:日本語 / 1:英語） */
  int retry;       /* 再挑戦する？？ */
  int cand[CNO];   /* 選択肢の番号 */

  if (read_tango() == 1) {

  }
}