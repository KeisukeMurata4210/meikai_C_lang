# include <stdio.h>

# define MAX    10  // 配列の要素数は10までとする

int main(void) {
  int i;
  int a[MAX];  // 読み込んだ値を格納する配列
  int cnt = 0; // 読み込んだ個数
  int retry;   // もう一度？

  printf("整数を入力してください。\n");
  printf("入力できるのは最大で%d個です。\n", MAX);

  do {  // 入力はおなじみdo-while
    printf("%d個目の整数：", cnt + 1);
    scanf("%d", &a[cnt++]); // cnt++ の戻り値は cnt

    if (cnt == MAX)
      break;
    
    printf("続けますか？（ yes…1 / no…0 ）：");
    scanf("%d", &retry);
  } while(retry == 1);

  for (i = 0; i < cnt; i++) {
    printf("%2d個目　： %d\n", i + 1, a[i]);
  }
  return 0;
}