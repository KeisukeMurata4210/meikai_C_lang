# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# define MAX_STAGE 10

int main(void) {
  int i, stage, no, ans; // カウンタ、入力回数、読み込んだ値、答え
  int num[MAX_STAGE];//読み込んだ値の履歴

  srand(time(NULL));
  ans = 50 + rand() % 101;
  
  printf("50~150の整数を当ててください。\n\n");

  stage = 0;
  do {
    printf("残り%d回。いくつかな：", MAX_STAGE - stage);
    scanf("%d", &no);
    num[stage++] = no;  // i++は「i」を返し、++iは「i+1」を返す。つまり添字はstageになる！

    if (no > ans) {
      printf("\aもっと小さいよ\n"); 
    } else if (no < ans) {
      printf("\aもっと大きいよ\n");
    }
  } while(no != ans && stage < MAX_STAGE);

  if (no == ans) {
    printf("正解です\n");
    printf("%d回で当たりましたね\n", stage);
  } else {
    printf("残念。正解は%dでした。\n", ans);
  }

  puts("\n--- 入力履歴 ---");
  for (i = 0; i < stage; i++) {
    printf("%2d : %4d %+4d\n", i + 1, num[i], num[i] - ans);
  }
  return 0;
}