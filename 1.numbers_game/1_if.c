# include <stdio.h>

int main(void) {
  int no;
  int ans = 7;

  printf("0~9の整数を当ててください。\n\nいくつかな：");
  scanf("%d", &no);
  if (no > ans) {
    printf("\aもっと小さいよ\n"); // \aでビープ音が出る！！
  } else if (no < ans) {
    printf("\aもっと大きいよ\n");
  } else {
    printf("\a正解です\n");
  }
  return 0;
}