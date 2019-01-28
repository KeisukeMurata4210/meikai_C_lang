# include <ctype.h>
# include <stdio.h>
# include <limits.h>

int main(void) {
  int i;

  for (i = 0; i <= CHAR_MAX; i++) {
    switch (i){
      case '\a': printf("\\a"); break; // \aなども文字コードに含まれている
      case '\b': printf("\\b"); break;
      case '\f': printf("\\f"); break;
      case '\n': printf("\\n"); break;
      case '\r': printf("\\r"); break;
      case '\t': printf("\\t"); break;
      case '\v': printf("\\v"); break;
      default  : printf(" %c", isprint(i) ? i : ' '); // isprint：引数が空白文字を含んでいる（文字コードに対応してない）かどうか判定 falseなら0
    }
    printf(" %02X\n", i);  // %c：一文字、%d：10進数、%x：16進数、%o：8進数
  }
  return 0;
}