# include <stdio.h>
# include <stdlib.h>
# include <time.h>

int main(void) {
  int no, ans;

  srand(time(NULL));//乱数の種を渡す
  ans = 50 + rand() % 101;//「% 個数」で「0から数えてその個数分」までの乱数を生成。「初期値 +」で初期値と最大値をずらせる
  
  printf("50~150の整数を当ててください。\n\n");

  do {
    printf("いくつかな：");
    scanf("%d", &no);

    if (no > ans) {
      printf("\aもっと小さいよ\n"); 
    } else if (no < ans) {
      printf("\aもっと大きいよ\n");
    }
  } while(no != ans);
  printf("\a正解です\n");
  
  return 0;
}