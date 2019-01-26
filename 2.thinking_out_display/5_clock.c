# include <stdio.h>
# include <time.h>

// xミリ秒経過するのを待つ
int sleep(unsigned long x) {
  clock_t c1 = clock(), c2;  // clock()プログラム開始からの経過時間を「クロック数で」返す　＝ 1秒あたりのクロック数で割れば、秒での時間が出る
  do {
    if ((c2 = clock()) == (clock_t)-1) { // clock関数は、時間を取得できない表現できない場合は「(clock_t)-1」を返す
      return 0;
    }
  } while(1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x);
  return 1;
}

int main(void) {
  int     i;
  clock_t c;
  for (i = 10; i > 0; i--) {
    printf("\r%2d", i);
    fflush(stdout);
    sleep(1000);
  }
  printf("\r\aFIRE!!\n");
  c = clock();
  printf("プログラム開始から%.1f秒経過しました。\n", (double)c / CLOCKS_PER_SEC); // CLOCKS_PER_SEC 1秒あたりのクロック数を返すマクロ

  return 0;
}

/*
%.1f：実数（float型）を、小数点第一位まで表示する
*/