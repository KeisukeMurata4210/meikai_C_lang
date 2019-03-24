# include <time.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define CNO     4/* 選択肢の数 */
# define swap(type, x, y) do {type t = x; x = y; y = t;} while(0)

int QNO;      /* 単語の数 */
char **jptr;  /* 日本語単語へのポインタ配列 */
char **eptr;  /* 英語単語へのポインタ配列 */

void print_cand(const int c[], int sw)
{
  int i;
  for (i = 0; i < CNO; i++)
    printf("（%d）%s ", i, sw ? jptr[c[i]] : eptr[c[i]]);/* ()に表示されるのはiだから、配列とは関係ない */
  printf("：");
  /* (0)(1)(2)(3)＝cの添字＝cのその添字の値が出力する単語を決める */
  /* 何番めを正解にする、と決めておく　→　その番号に紐づく単語を英語、日本語の両方から取得すれば、英語・日本語は一対一で対応しているから、正解を出せる */
  /* 正解を探すのではなく、「並び順を揃えることで正解を取得できる」 */
}

int make_cand(int c[], int n)
{
  int i, j, x;

  c[0] = n;/* 一旦は先頭を正解にしておく */

  for (i = 1; i < CNO; i++) {
    do {
      x = rand() % QNO;
      for (j = 0; j < i; j++)
        if (c[j] == x)
          break;   /* もし乱数xと既存のcの要素で重複があればもう一度 */
    } while (i != j);
    c[i] = x;    /* 重複しないxを作れたらcの最新の要素として代入 */
  }

  j = rand() % CNO;
  if (j != 0)
    swap(int, c[0], c[j]);
  return j;/* cの何番面の要素が「正解の添字」かを返す */
}

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
  int nq, pq;      /* 問題の番号・前回の問題番号（単語リスト配列の添字を決める配列の値） */
  int na;          /* 正解の番号 */
  int sw;          /* 問題の単語（0:日本語 / 1:英語） */
  int retry;       /* 再挑戦する？？ */
  int cand[CNO];   /* 選択肢 */

  if (read_tango() == 1) {
    printf("\a単語ファイルの読み込みに失敗しました。\n");
    return 1;
  }
  srand(time(NULL));

  pq = QNO; /* 前回の問題番号（存在しない数） */
  do {
    int no;

    do {/* 出題する単語の番号を決定 */
      nq = rand() % QNO;
    } while (nq == pq);

    na = make_cand(cand, nq);/* 選択肢を生成 */
    sw = rand() % 2;

    printf("%sはどれですか？\n", sw ? eptr[nq] : jptr[nq]);

    do {
      print_cand(cand, sw);/* 選択肢を表示 */
      scanf("%d", &no);
      if (no != na)
        puts("\a違います。");
    } while(no != na);
    puts("正解です。");

    pq = nq;

    printf("もう一度？　0-いいえ / 1-はい：");
    scanf("%d", &retry);
  } while (retry == 1);
  return 0;
}