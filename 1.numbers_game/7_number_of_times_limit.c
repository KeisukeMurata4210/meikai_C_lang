# include <stdio.h>
# include <stdlib.h>
# include <time.h>

int main(void) {
  int no, ans;
  const int MAX_STAGE = 3; //3回まで入力できる
  int remain = MAX_STAGE;   // 残り回数

  srand(time(NULL));//乱数の種を渡す
  ans = 50 + rand() % 101;//「% 個数」で「0から数えてその個数分」までの乱数を生成。「初期値 +」で初期値と最大値をずらせる
  
  printf("50~150の整数を当ててください。\n\n");

  do {
    printf("いくつかな：");
    scanf("%d", &no);
    remain--;

    if (no > ans) {
      printf("\aもっと小さいよ\n"); 
    } else if (no < ans) {
      printf("\aもっと大きいよ\n");
    }
  } while(no != ans && remain > 0);
  if (no == ans) {
    printf("正解です\n");
    printf("%d回で当たりましたね\n", MAX_STAGE - remain);
  } else {
    printf("残念。正解は%dでした。\n", ans);
  }
  return 0;
}