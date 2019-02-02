# include <stdio.h>

int main(void) {
  int a = 0;
  printf("%d\n", a++);      // => 0
  printf("%d\n", a++ % 10); // => 1
  printf("%d\n\n", a);      // => 2

  a = 0;
  printf("%d\n", ++a);      // => 1
  printf("%d\n", ++a % 10); // => 2
  printf("%d\n", a);        // => 2
  return 0;
}
/* 
前置演算子は、他の演算が終わった後にインクリメントされる
後置演算子は、まずインクリメントしてから他の演算を行う
*/