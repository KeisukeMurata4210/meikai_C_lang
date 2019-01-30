# include <stdio.h>

int main(void) {
  int x;

  printf("整数を入力してください：");
  scanf("%d", &x);

  printf("%dと入力しましたね。\n", x);//先頭の0は無視される
  return 0;
}