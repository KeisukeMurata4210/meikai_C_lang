# include <time.h>
# include <stdio.h>
# include <stdlib.h>

# define LEVEL_MIN    2  // 最少レベル（数値の個数）
# define LEVEL_MAX    5  // 最大レベル（数値の個数） 
# define MAX_RECORD   10 // ポイントを記録するステージ数

int sleep(unsigned long x) {
  clock_t c1 = clock(), c2;
  do {
    if ((c2 = clock()) == (clock_t)-1)
      return 0;
  } while(100.0 * (c2 - c1) / CLOCKS_PER_SEC < x);
  return 1;
}

int main(void) {
  int i, j, stage, stage2;
  int level;
  int success;
  int point[MAX_RECORD];
  int retry;
  clock_t start, end;

  srand(time(NULL));

  printf("数値を記憶して１を加えた値を入力しましょう。\n");
  do {
    printf("挑戦するレベル（%d ~ %d）：", LEVEL_MIN, LEVEL_MAX);
    scanf("%d", &level);
  } while(level < LEVEL_MIN || level > LEVEL_MAX);

  success = stage = 0;

  start = clock();
  do {
    int no[LEVEL_MAX];
    int x[LEVEL_MAX];
    int match = 0;
    printf("\n第%dステージ開始!!\n", stage + 1);
    for (i = 0; i < level; i++) { // 設定したレベル回、数字を表示
      no[i] = rand() % 90 + 10;
      printf("%d ", no[i]);
    }
    fflush(stdout);
    sleep(100 * level);
    printf("\r%*s\r", 3 * level, ""); // 3をかけるのは、（間の空欄＋2桁の数字）* レベル分の表示数
    fflush(stdout);

    for (i = 0; i < level; i++) {
      printf("%d回目の数：", i + 1);
      scanf("%d", &x[i]);
    }

    for (i = 0; i < level; i++) {
      if (x[i] != no[i] + 1)
        printf("× ");
      else {
        printf("○ ");
        match++;                     //インクリメントを忘れずに
      }
    }
    putchar('\n');
    for (i = 0; i < level; i++) {
      printf("%2d ", no[i]);
    }
    printf(" … %d個正解です。\n", match);

    point[stage++ % MAX_RECORD] = match;
    success += match;

    printf("続けますか？ （yes…1/no…0）：");
    scanf("%d", &retry);
  } while(retry == 1);
  end = clock();

  printf("\n■□ 成績 □■\n");
  stage2 = stage - MAX_RECORD;
  if (stage2 < 0) stage2 = 0;
  for (i = level; i >= 1; i--) {   // グラフの行数
    for (j = stage2; j < stage; j++) { // jの値が、-5~5、6~14　などのように、stage数によって循環する
      if (point[j % MAX_RECORD] >= i)
        printf(" ★ ");
      else
        printf("   ");
    }
    putchar('\n');
  }
  printf("------------------------------------------\n");

  for (j = stage2; j < stage; j++) {
    printf(" %2d ", j + 1);
  }
  putchar('\n');

  printf("%d個中%d個正解しました。\n", level * stage, success);
  printf("%.lf秒でした。\n", (double)(end - start) / CLOCKS_PER_SEC);
  
  return 0;
}


/* 
6 / 5 = 1 + 1
6 = 5 * 1 + 1
-6 / 5
-6 = 5 * -1 + (-1)
-6 = 5 * (-2) + 4

-5 / 10
-5 = 10 * (-1) + 5

-1 / 10
-1 = 10 * (-1) + 9

余りは負にしないようにする。間違いではないけど。
 */