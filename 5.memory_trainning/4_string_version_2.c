# include <time.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define MAX_STAGE  10
# define LEVEL_MIN  3
# define LEVEL_MAX  20

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
  int success = 0;
  clock_t start, end;
  const char ltr[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                     "abcdefghijklmnopqrstuvwxyz";// ２つ続ければ自動で連結される

  srand(time(NULL));//乱数の種

  printf("英字記憶トレーニング\n");
  do {
    printf("挑戦するレベル（%d ~ %d）：", LEVEL_MIN, LEVEL_MAX);
    scanf("%d", &level);
  } while(level < LEVEL_MIN || level > LEVEL_MAX); 

  printf("%d桁の英字を記憶しましょう。\n", level);

  start = clock();
  for (stage = 0; stage < MAX_STAGE; stage++) {
    char mstr[LEVEL_MAX + 1];      // 記憶する文字列 +1はEOSのため
    char x[LEVEL_MAX * 2];       // 入力された文字列

    for (i = 0; i < level; i++){
      mstr[i] = ltr[rand() % strlen(ltr)]; // 取得する文字の位置に乱数を使う
    }
    mstr[level] = '\0';   // EOS忘れずに

    printf("%s", mstr);
    fflush(stdout);
    sleep(125 * level);

    printf("\r%*s\r入力せよ：", level, "");
    fflush(stdout);
    scanf("%s", x);

    if (strcmp(x, mstr) != 0)  // strcmpは文字列どうしを比較し、一致すれば0を返す
      printf("\a間違いです。\n");
    else {    // 2行以上の時は{}必須
      printf("正解です。\n");
      success++;
    }
  }
  end = clock();

  printf("%d回中%d回成功しました。\n", MAX_STAGE, success);
  printf("%.lf秒でした。\n", (double)(end - start) / CLOCKS_PER_SEC);
  return 0;
}