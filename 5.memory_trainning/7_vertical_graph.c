# include <time.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define MAX_STAGE  10
# define LEVEL_MIN  2
# define LEVEL_MAX  6

/* xミリ秒経過するのを待つ */
int sleep(unsigned long x) { 
  clock_t c1 = clock(), c2;
  do {
    if ((c2 = clock()) == (clock_t)-1)
      return 0;
  } while(100.0 * (c2 - c1) / CLOCKS_PER_SEC < x);
  return 1;
}

int main(void) {
  int i, stage;
  int level;
  int success;
  int score[MAX_STAGE]; // 全ステージの正解数
  clock_t start, end;

  srand(time(NULL));//乱数の種

  printf("プラスワントレーニング開始！！\n");
  printf("２桁の数値を記憶します。\n");
  printf("１を加えた値を入力してください。\n");

  do {
    printf("挑戦するレベル（%d ~ %d）：", LEVEL_MIN, LEVEL_MAX);
    scanf("%d", &level);
  } while(level < LEVEL_MIN || level > LEVEL_MAX);

  success = 0;
  start = clock();
  for (stage = 0; stage < MAX_STAGE; stage++) {
    int no[LEVEL_MAX];     // 記憶する数
    int x[LEVEL_MAX];      // 読み込んだ値
    int stage_success = 0; // このステージでの正解数

    printf("\n第%dステージ開始！！\n", stage + 1);

    for (i = 0; i < level; i++){
      no[i] = rand() % 90 + 10; // 2桁の乱数 10~99
      printf("%d ", no[i]);
    }
    fflush(stdout);
    sleep(level * 100); //0.10*level秒
    printf("\r%*s\r", 3 * level, "");
    fflush(stdout);

    for (i = 0; i < level; i++) { // 回答を入力
      printf("%d番目の数：", i + 1);
      scanf("%d", &x[i]); // 配列の要素は普通の変数だから、&がいる
    }

    for (i = 0; i < level; i++) { // 判定結果を表示
      if (x[i] != no[i] + 1)
        printf("× ");
      else {
        printf("○ ");
        stage_success++;
      }
    }
    putchar('\n');

    for (i = 0; i < level; i++) { // 改行して、正解の数値を表示
      printf("%2d ", no[i]);
    }

    printf(" … %d個正解です。\n", stage_success); // その回（ステージ）の正解数を表示
    score[stage] = stage_success;               // その回（ステージ）の正解数を記録
    success += stage_success;                   // 全体の正解数に足しこむ
  }
  end = clock();

  printf("%d個中%d個成功しました。\n", level * MAX_STAGE, success); // 10回全体の正解数を表示

  printf("\n■□ 成績 □■\n");
  for (i = level; i >= 1; i--) { // グラフの上から下へ　6文字目 5文字目 …
    for (stage = 0; stage < MAX_STAGE; stage++) { // それぞれに対して、1回目 2回目 …
      if (score[stage] >= i)   // 例えば２回目のスコアが3で、今のループが2文字目だった場合、score[stage]は3、iは2
        printf(" ★ ");
      else
        printf("   ");
    }
    putchar('\n');
  }
  printf("------------------------------------\n");
  for (stage = 1; stage <= MAX_STAGE; stage++) {
    printf(" %02d ", stage);    // 同じ列に回数を表示
  }
  putchar('\n');
  printf("%.lf秒でした。\n", (double)(end - start) / CLOCKS_PER_SEC);
  return 0;
}