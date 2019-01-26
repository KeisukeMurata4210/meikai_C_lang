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
  printf("My name is BohYoh.");
  fflush(stdout);

  sleep(2000);
  printf("\rHow do you do?     ");
  fflush(stdout);

  sleep(2000);
  printf("\rThanks.            \n");

  return 0;
}
/* 
\rでカーソルを行の先頭に戻してから次を表示させることで、
書き換えているように「見せている」だけ
*/