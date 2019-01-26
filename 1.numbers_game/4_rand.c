# include <stdio.h>
# include <stdlib.h>

int main(void) {
  int retry;

  printf("この処理系では0~%dまでの乱数が生成できます。\n", RAND_MAX);//このマクロはstdlib.hで定義されている

  do {
    printf("\n乱数%dを生成しました。",rand());//これもstdlib.h。乱数を生成する 実行するたび、同じ数値が同じ順番で生成されている！

    printf("もう一度？…(0)いいえ (1)はい：");
    scanf("%d", &retry);
  } while(retry == 1);
  
  return 0;
}