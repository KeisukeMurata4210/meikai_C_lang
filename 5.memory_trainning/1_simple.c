# include <time.h>
# include <stdio.h>
# include <stdlib.h>

# define MAX_STAGE  10

/* xミリ秒経過するのを待つ */
int sleep(unsigned long x) {  // signedはマイナスを含める、unsignedはプラスのみ、付かないのはどちらかの形式
  clock_t c1 = clock(), c2;
  do {
    if ((c2 = clock()) == (clock_t)-1) // 時間を取得できないときはclock_t型の-1を返す
      return 0;
  } while(100.0 * (c2 - c1) / CLOCKS_PER_SEC < x);//xミリ秒経過するまでループ
  return 1;
}

int main(void) {
  int stage;
  int success = 0;   // 正解数
  clock_t start, end; // 開始時間、終了時間

  srand(time(NULL));//乱数の種

  printf("４桁の数値を記憶しましょう。\n");

  start = clock();
  for (stage = 0; stage < MAX_STAGE; stage++) {  // ゲームを10回繰り返す
    int x;                         //読み込んだ値
    int no = rand() % 9000 + 1000; //記憶する値

    printf("%d", no);
    fflush(stdout);
    sleep(300); // 0.3秒表示

    printf("\r入力せよ：");
    fflush(stdout);
    scanf("%d", &x);

    if (x != no)
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