# include <stdio.h>

int main(void) {
  int i;
  int x;

  printf("何段表示しますか：");
  scanf("%d", &x);

  for (i = 1; i <= x; i++) {
    printf("%*d\n", i, i % 10); // * を埋め込むと、引数で桁数を指定できる
  }
  return 0;
}