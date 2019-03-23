/* 英単語学習ソフト（問題点：常に正解が（0）になる） */
# include <time.h>
# include <stdio.h>
# include <stdlib.h>

# define QNO  12  /* 単語の数 */
# define CNO   4  /* 選択肢の数 */

/* 日本語 */
char *jptr[] = {
  "動物", "車", "花", "家", "机", "本",
  "椅子", "父", "母", "愛", "平和", "雑誌",
};

/* 英語 */
char *eptr[] = {
  "animal", "car", "flower", "house", "desk", "book",
  "chair", "father", "mother", "love", "peace", "magazine",
};

/* 選択肢を表示 */
void print_cand(const int c[], int sw)
{
  int i;

  for (i = 0; i < CNO; i++)
    printf("(%d) %s  ", i, sw ? jptr[c[i]] : eptr[c[i]]);/* 配列cに添字が入っているから */
}

/* 選択肢を生成して正解の添字を返す */
int make_cand(int c[], int n)
{
  int i;
  c[0] = n; /* 先頭に正解の問題番号を入れる */
  for (i = 1; i < CNO; i++)
    c[i] = rand() % QNO;/* それ以外は単語の数を超えない範囲の乱数　かつ　添字なので-1 */
  return 0;  /* ↑正解の番号と被らないのかな？　これこそが問題点！！　よく気づけた（どや） */
}

int main(void)
{
  int nq, pq;    /* 問題の番号・前回の問題番号 */
  int na;        /* 正解の番号 */
  int sw;        /* 問題の言語（0:日本語 / 1:英語） */
  int retry;     /* 再挑戦するか？ */
  int cand[CNO]; /* 選択肢の番号 */

  srand(time(NULL));

  pq = QNO;/* 前回の問題番号（存在しない番号） */
  do {
    int no;
    do {                  /* 出題する単語の番号を決定 */
      nq = rand() % QNO;
    } while (nq == pq);

    na = make_cand(cand, nq);  /* 選択肢を生成 参照渡し */
    sw = rand() % 2;

    printf("%sはどれですか？\n", sw ? eptr[nq] : jptr[nq]);/* print_cand()と逆になっている */

    do {
      print_cand(cand, sw);   /* 選択肢を表示 さりげなく参照渡しになってる */
      scanf("%d", &no);
      if (no != na)
        puts("\a違います。");
    } while (no != na);
    puts("正解です。");

    pq = nq;

    printf("もう一度？　0-いいえ / 1-はい：");
    scanf("%d", &retry);
  } while (retry == 1);
  return 0;
}