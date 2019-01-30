# include <stdio.h>
# include <stdlib.h>

void make4digits(int x[]) {
  int i, j, val;
  for (i = 0; i < 4; i++) { // for文1つだけだと、乱数といえど重複の可能性がある
    do {
      val = rand() % 10; // 0~9
      for (j = 0; j < i; j++) { // 既に生成した数に一致した乱数ならもう一度
        if (val == x[j]) break; // 重複していればその時点の値のまま、jはインクリメントされない
      }
    } while(j < i); // 一つも重複がなければj == iになる
    x[i] = val;
  }
}

int main(void) {
  int x[4];
  make4digits(x);//種を渡してないから毎回同じ乱数が返ってくる
  printf("%d%d%d%d\n", x[0], x[1], x[2], x[3]);
  return 0;
}