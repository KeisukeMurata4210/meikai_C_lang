/* カウントダウン後にプログラム実行時間を表示 */
# include <time.h>
# include <stdio.h>

int sleep(unsigned long x)
{
  clock_t c1 = clock(), c2;
  do {
    if ((c2 = clock()) == (clock_t)-1) /* エラーはclock_t型の-1を返す */
      return 0;
  } while (1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x); /* 経過時間がx（1秒）を超えない限り、無限ループ */
  return 1;
}

int main(void)
{
  int i;
  clock_t c;/* clock()の戻り値がclock_t型 */

  for (i = 10; i > 0; i--) {
    printf("\r%2d", i);
    fflush(stdout);
    sleep(1000); /* 1秒休止 */
  }
  printf("\r\aFIRE!!\n");
  c = clock();
  printf("プログラム開始から%.lf秒経過しました。\n", (double)c / CLOCKS_PER_SEC);
  return 0;
}