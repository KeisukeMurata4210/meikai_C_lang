# include <stdio.h>

int main(void) {
  double x;
  double *pd;
  char   *pc = &x; // int*型からchar*型へ暗黙のキャスト
  pc++;
  pd = (double *)pc; // char *型からdouble *型へキャスト

  printf("pc = %p\n", pc);
  printf("pd = %p\n", pd);
  return 0;
}

/*
型によってサイズが異なる
double 8
char   1 
など。
→ポインタをキャストすると指し示すアドレスが変わってしまう可能性を明示したほうがいい
　→暗黙のキャストはあまり良くない
*/