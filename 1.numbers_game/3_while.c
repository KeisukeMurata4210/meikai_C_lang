# include <stdio.h>

int main(void) {
  int no;
  int ans = 7;

  printf("0~9の整数を当ててください。\n\n");

  while(1) {   // 無限ループを作るときは「1」を入れる慣例みたい
    printf("いくつかな：");
    scanf("%d", &no);

    if (no > ans) {
      printf("\aもっと小さいよ\n"); 
    } else if (no < ans) {
      printf("\aもっと大きいよ\n");
    } else {
      break;// これを追加
    }
  }
  printf("\a正解です\n");
  
  return 0;
}