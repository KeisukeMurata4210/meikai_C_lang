# include <time.h>
# include <stdio.h>
# include <stdlib.h>

int main(void) {
  int a, b, c, d;
  int x;
  time_t start, end;

  srand(time(NULL));  // time()関数はtime_t型（暦時刻）を返すんだよね。

  a = rand() % 100;
  b = rand() % 100;
  c = rand() % 100;
  d = rand() % 100;

  printf("%d + %d + %d + %dは何ですか：", a, b, c, d);

  start = time(NULL);
  while(1) {
    scanf("%d", &x);
    if (x == a + b + c + d)
      break;
    printf("\a違いますよ!!\n再入力してください：");
  }
  end = time(NULL);
  printf("%.0lf秒かかりました。\n", difftime(end, start)); // time_t型２つを引数として与え、秒単位のdouble型で返ってくる。1つ目 - 2つ目
  return 0;
}