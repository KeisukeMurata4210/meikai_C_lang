# include <stdio.h>

void sum_dif(int x, int y, int *sum, int *dif) {
  *sum = x + y;
  *dif = x - y;
}

int main(void) {
  int a = 5, b = 3, p = 1, m = 1;
  sum_dif(a, b, &p, &m);
  printf("p:%d, m:%d\n", p, m);
  return 0;
}