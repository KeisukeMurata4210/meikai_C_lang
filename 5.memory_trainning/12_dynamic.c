# include <stdio.h>
# include <stdlib.h>

int main(void) {
  int *x;

  x = calloc(1, sizeof(int)); // 要素数とサイズを指定する。戻り値は先頭のポインタ。

  if (x == NULL)
    puts("記憶域の確保に失敗しました。");
  else {
    *x = 57;
    printf("*x = %d\n", *x);
    free(x); // 解放
  }
  return 0;
}