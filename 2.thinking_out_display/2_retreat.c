# include <stdio.h>
# include <time.h>

// xミリ秒経過するのを待つ
int sleep(unsigned long x) {
  clock_t c1 = clock(), c2;
  do {
    if ((c2 = clock()) == (clock_t)-1) {
      return 0;
    }
  } while(1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x);
  return 1;
}

int main(void) {
  int i;
  printf("ABCDEFG");
  for (i = 0; i < 7; i++) {
    sleep(1000); // 1秒ごとに
    printf("\b \b"); // 後ろから１文字ずつ　カーソル位置を一つ戻して空白で上書きし、さらに一つ戻る、の繰り返し
    fflush(stdout); // バッファを吐き出す
  }
  return 0;
}

/*
関数sleepは、xミリ秒だけ時間を潰す関数　詳細はあとで
fflush関数もまたあとで
*/