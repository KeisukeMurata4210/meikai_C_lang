/* 英単語学習ソフト（make_cand()のみ改修） */
# include <time.h>
# include <stdio.h>
# include <stdlib.h>

# define QNO  12  /* 単語の数 */
# define CNO   4  /* 選択肢の数 */
# define swap(type, x, y)    do {type t = x; x = y; y = t;} while(0)

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
/*   int i;
  c[0] = n;
  for (i = 1; i < CNO; i++)
    c[i] = rand() % QNO;
  return 0; */

  int i, j, x;
  c[0] = n;   /* まず先頭に正解を入れます */
  for (i = 1; i < CNO; i++) { /* 乱数xを生成して配列cの添字1以降入れていく */
    do {
      x = rand() % QNO;
      for (j = 0; j < i; j++) /* 乱数xとすでに生成された配列cの要素とを一つずつ検証していく */
        if (c[j] == x)
          break;
    } while (i != j);  /* breakするとここの条件に飛び、もう一度xを生成し直す */
    c[i] = x;
  }

  j = rand() % CNO;
  if (j != 0)
    swap(int, c[0], c[j]);  /* jが0の時はシャッフルされないが、0という結果自体がシャッフルして得た値なのでOK */
    /* ↑ 配列c（選択肢）の正解の位置が、0からjになる */
  return j;/* j：正解の選択肢の番号＝配列c（選択肢）の添字　→　cの値が単語リストの添字担になっている */
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