/* 英単語学習ソフト（試作版：日本語の単語/英語の単語をランダムに表示） */
# include <time.h>
# include <stdio.h>
# include <stdlib.h>

# define QNO   12  /* 単語の数 */

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

int main(void)
{
  int nq, pq;  /* 問題番号、前回の問題番号 */
  int sw;      /* 0:日本語 / 1:英語 */
  int retry;   /* 再挑戦するか？ */

  srand(time(NULL));

  pq = QNO;   /* 前回の問題番号（存在しない番号） */
  do {
    do { /* 同じ単語を連続して出題しない */
      nq = rand() % QNO;
    } while (nq == pq);
    sw = rand() % 2;/* 日本語 or 英語 */
    printf("%s\n", sw ? eptr[nq] : jptr[nq]);  /* C言語では0がfalse、それ以外はtrue */
    pq = nq;

    printf("もう一度？ 0-いいえ 1-はい：");
    scanf("%d", &retry);
  } while (retry == 1);
  return 0;
}