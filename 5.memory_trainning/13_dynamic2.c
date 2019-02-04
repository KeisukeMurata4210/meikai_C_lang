# include <stdio.h>
# include <stdlib.h>

int main(void) {
  int *x;

  x = calloc(1, sizeof(int));

  if (x == NULL)
    puts("記憶域の確保に失敗しました。");
  else {
    printf("*xに格納する値");
    scanf("%d", &x); // 誤り　ポインタが格納されているアドレスと、そのポインタが指し示すアドレスは違う => 別の領域にアクセスしてしまう。配列と同じ
    printf("*x = %d\n", *x);
    free(x); // 解放
  }
  return 0;
}

/*
ヒープ：空き領域
*/