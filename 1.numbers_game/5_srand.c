/* 
rand関数は「種」と呼ばれる基準値に演算をして乱数を生成する。
デフォルトでは種は1なので、種を実行のたびに変えないと同じ乱数を同じ順番で生成してしまう。
srand関数で種を指定する
*/
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

int main(void) {
  int retry;

  srand(time(NULL));//乱数の種を渡す

  printf("この処理系では0~%dまでの乱数が生成できます。\n", RAND_MAX);

  do {
    printf("\n乱数%dを生成しました。",rand());

    printf("もう一度？…(0)いいえ (1)はい：");
    scanf("%d", &retry);
  } while(retry == 1);
  
  return 0;
}