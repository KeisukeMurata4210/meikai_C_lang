# include <time.h>
# include <float.h>
# include <ctype.h>
# include <stdio.h>
# include <stdlib.h>
# include "getputch.h"

# define MAX_STAGE    10
# define swap(type, x, y)   do {type t = x; x = y; y = t;} while(0)

char dtfile[] = "LACKNUM.DAT";/* ファイル名 */

/* 前回のトレーニング情報を取得・表示して最高得点を返す */
double get_data(void)
{
  FILE *fp;     /* fopen()はFILEへのポインタを返すからFILE*型 */
  double best;  /* 最高得点 */

  if ((fp = fopen(dtfile, "r")) == NULL) { /* なるほど！　ファイルがなければ初めての起動 */
    printf("本プログラムを実行するのは初めてですね。\n\n");
    best = DBL_MAX; /* float.h で定義されたマクロ。double型で表現できる最大値 */
  } else {
    int year, month, day, h, m, s;

    fscanf(fp, "%d%d%d%d%d%d", &year, &month, &day, &h, &m, &s);/* fscanfはファイルからの読み込み。指定した形式で、第3引数以降の変数に代入される */
    fscanf(fp, "%lf", &best);
    printf("前回の終了は%d年%d月%d日%d時%d分%d秒でした。\n", year, month, day, h, m, s);/* 最後の行から読み込まれるらしい */
    printf("これまでの最高得点（最短所要時間）は%.lfです。\n\n", best);
    fclose(fp);
  }
  return best;
}

/* 今回のトレーニング情報を書き込む */
void put_data(double best)
{
  FILE *fp;
  time_t t = time(NULL);
  struct tm *local = localtime(&t);

  if ((fp = fopen(dtfile, "w")) == NULL)
    printf("エラー発生!!");
  else {
    fprintf(fp, "%d %d %d %d %d %d\n",
                local->tm_year + 1900, local->tm_mon + 1, local->tm_mday,
                local->tm_hour,        local->tm_min,     local->tm_sec);
    fprintf(fp, "%f\n", best);
    fclose(fp);
  }
}

/* トレーニングを実行して得点（所要時間）を返す */
double go(void)
{
  int i, j, stage;
  int dgt[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int a[8];
  double jikan;  /* 時間 */
  clock_t start, end;

  printf("欠けている数字を入力してください。\n");
  printf("スペースキーで開始します。\n");
  while (getch() != ' ')
    ;

  srand(time(NULL));
  start = clock();
  for (stage = 0; stage < MAX_STAGE; stage++) {
    int x = rand() % 9; /* 0 ~ 8 */
    int no;             /* 読み込んだ値 */

    i = j = 0;
    while (i < 9) { /* dgt[x]を飛ばしてコピー */
      if (i != x)
        a[j++] = dgt[i];
      i++;
    }
    for (i = 7; i > 0; i--) { /* 配列aをシャッフル */
      int j = rand() % (i + 1); /* 0 ~ i */
      if (i != j)/* ex)7のとき、添字7と添字6以下をシャッフル。これを繰り返す */
        swap(int, a[i], a[j]);
    }
    for (i = 0; i < 8; i++)/* 全要素を表示 */
      printf("%d", a[i]);
    printf("：");
    fflush(stdout);
    do {
      no = getch();
      if (isprint(no)) {        /* 表示可能なら */
        putch(no);
        if (no != dgt[x] + '0') /* 不正解なら */
          putch('\b');          /* カーソルを戻す */
        else
          printf("\n");         /* 正解なら改行 */
        fflush(stdout);
      }
    } while (no != dgt[x] + '0');
  }
  end = clock();

  jikan = (double)(end - start) / CLOCKS_PER_SEC;
  printf("%.lf秒かかりました。\n", jikan);

  if (jikan > 25.0)
    printf("鈍すぎます。\n");
  else if (jikan > 20.0)
    printf("少し鈍いですね。\n");
  else if (jikan > 17.0)
    printf("まあまあですね。\n");
  else
    printf("素早いですね。\n");

  return jikan;
}


int main(void)
{
  int retry;        /* もう一度 */
  double score;     /* 得点（所要時間） */
  double best;      /* 最高得点（最短所要時間） */

  best = get_data();  /* 前回までの最高得点を得る */

  init_getputch();
  srand(time(NULL));

  do {
    score = go();/* トレーニング実行 */
    if (score < best) {
      printf("最高得点（所要時間）を更新しました!!\n");
      best = score;  /* 更新 */
    }
    printf("もう一度しますか…（0）いいえ （1）はい");
    scanf("%d", &retry);
  } while (retry == 1);

  put_data(best);
  term_getputch();
  return 0;
}