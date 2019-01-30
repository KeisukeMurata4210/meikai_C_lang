# include <time.h>
# include <stdio.h>
# include <stdlib.h>

int main(void) {
  int i;
  int human;
  int comp;
  int judge;
  int retry;
  char *hd[] = {"グー", "チョキ", "パー"};  //ポインタ配列で手

  srand(time(NULL)); // 乱数の種
  printf("じゃんけんゲーム開始！！\n");

  do {
    comp = rand() % 3; // 0~2
    do {
      printf("\n\aじゃんけんぽん…");
      for (i = 0; i < 3; i++) {
        printf(" (%d)%s", i, hd[i]); // グーチョキパーが配列になったため、ループで手の種類を出力する
      }
      printf("：");  //改行を入れずに
      scanf("%d", &human);
    } while(human < 0 || human >2); //正しい範囲で入力されるまで繰り返す

    printf("私は%sで、あなたは%sです。\n", hd[comp], hd[human]);

    judge = (human - comp + 3) % 3;

    switch (judge) {
      case 0: puts("引き分けです。");    break;
      case 1: puts("あなたの負けです。"); break;
      case 2: puts("あなたの勝ちです。"); break;
    }

    printf("もう一度しますか…(0)いいえ (1)はい：");
    scanf("%d", &retry);
  } while(retry == 1);

  return 0;
}