# include <time.h>
# include <stdio.h>
# include <stdlib.h>

int main(void) {
  int stage;
  int a, b, c; // 加算する数字
  int x;       // 読み込んだ値
  int n;       // 余白の幅
  clock_t start, end; // 開始、終了時間

  srand(time(NULL)); // 乱数の種

  printf("視野拡大暗算トレーニング開始！！\n");
  
  start = clock();
  for (stage = 0; stage < 10; stage++) {
    a = 10 + rand() % 90; // 10~99
    b = 10 + rand() % 90; // 10~99
    c = 10 + rand() % 90; // 10~99
    n = rand() % 17; // 0~16

    printf("%d%*s+%*s%d%*s+%*s%d：", a, n, "", n, "", b, n, "", n, "", c);// *と引数で桁数を指定　＋ 引数をループのたびにランダム生成
    do {
      scanf("%d", &x);
      if (x == a + b + c)
        break;
      printf("\a違います。再入力してください：");
    } while(1);
  }
  end = clock();

  printf("%.lf秒かかりました。\n", (double)(end - start) / CLOCKS_PER_SEC);
  return 0;
}