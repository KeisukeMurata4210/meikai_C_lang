# include <stdio.h>

# define MAX    10  // 配列の要素数は10までとする

int main(void) {
  int i;
  int a[MAX];  // 読み込んだ値を格納する配列
  int cnt = 0; // 読み込んだ個数
  int retry;   // もう一度？

  printf("整数を入力してください。\n");
  printf("入力できるのは最大で%d個です。\n", MAX);

  do { 
    if (cnt >= MAX) { // 10個以上の要素を入力されたら
      for (i = 0; i < MAX -1; i++) {
        a[i] = a[i + 1];    // 一つずつ左にずらしてスペースを作る。一番古い値は捨てる
      }
    }
    printf("%d個目の整数：", cnt + 1);
    scanf("%d", &a[cnt < MAX ? cnt : MAX - 1]); // 11回目以降なら、10個目（＝MAX-1 =9）に代入する
    cnt++;

    printf("続けますか？（ yes…1 / no…0 ）：");
    scanf("%d", &retry);
  } while(retry == 1);

  if (cnt <= MAX) {  // 入力が10より少なければ普通に表示する
    for (i = 0; i < cnt; i++)
      printf("%2d個目　： %d\n", i + 1, a[i]);
  } else {
    for (i = 0; i < cnt; i++)
      printf("%2d個目　： %d\n", cnt - MAX + i + 1, a[i]); // 10より多ければ、多い分だけ「○個目」の表示を変える
  }
  return 0;
}