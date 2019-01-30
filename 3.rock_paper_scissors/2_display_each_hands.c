# include <time.h>
# include <stdio.h>
# include <stdlib.h>

int main(void) {
  int human;
  int comp;
  int judge;
  int retry;// もう一度？

  printf("じゃんけんゲーム開始！\n");
  do {
    srand(time(NULL)); // 乱数の種を渡す。 ループ内で種を渡さないと、同じ手を出し続けてしまう
    comp = rand() % 3; // 0~2

    do {
      printf("\n\aじゃんけんポン…(0)グー (1) チョキ (2)パー：");
      scanf("%d", &human);
    } while(human < 0 || human > 2); // 正しい値が入力されるまで繰り返す

    printf("私は");
    switch (comp){
      case 0:
        printf("グー");
        break;
      case 1:
        printf("チョキ");
        break;
      case 2:
        printf("パー");
        break;
    }
    printf("で、あなたは");
    switch (human){
      case 0:
        printf("グー");
        break;
      case 1:
        printf("チョキ");
        break;
      case 2:
        printf("パー");
        break;
    }
    printf("です。\n");

    judge = (human - comp + 3) % 3;

    switch (judge){
      case 0:
        printf("引き分けです。");
        break;
      case 1:
        printf("あなたの負けです。");
        break;
      case 2:
        printf("あなたの勝ちです。");
    }
    printf("もう一度しますか…(0)いいえ (1)はい：");
    scanf("%d", &retry);
  } while(retry == 1);
  
  return 0;
}