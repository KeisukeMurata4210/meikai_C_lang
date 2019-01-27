# include <stdio.h>

int main(void) {
  int i, j;
  int x;

  printf("何段表示しますか：");
  scanf("%d", &x);

  for (i = 1; i <= x; i++) {
    for (j = 1; j < i; j++){
      putchar(' ');
    }
    printf("%d\n", i % 10);
  }
  return 0;
}