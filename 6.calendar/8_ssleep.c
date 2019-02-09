# include <time.h>
# include <stdio.h>
# include <stdlib.h>


/* int sleep(unsigned long x) { 
  clock_t c1 = clock(), c2;
  do {
    if ((c2 = clock()) == (clock_t)-1)
      return 0;
  } while(100.0 * (c2 - c1) / CLOCKS_PER_SEC < x);
  return 1;
} */

/* ミリ秒じゃなくて秒 */
int ssleep(double x) {
  time_t t1 = time(NULL), t2; // clock_tではなくtime_tにする
  do {
    if ((t2 = time(NULL)) == (time_t)-1)// 取得できないとき-1が返ってくるのはclock()と同じ
      return 0;
  } while(difftime(t2, t1) < x); // difftimeで差分を取れる。単位は秒。 0.●秒 → 次の1秒までなので、最大で1秒近い誤差が生じる。
  return 1;
}

int main(void) {
  double x = 3;
  ssleep(x);
  printf("3秒経ちました。\n");
  return 0;
}