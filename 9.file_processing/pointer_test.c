# include <stdio.h>

int main(void)
{
  int **a;/* ポインタのポインタを入れるときは「int **」型にする */
  int *b;
  int c = 3;

  a = &b;
  b = &c;

  printf("%d\n", **a);/* ポインタを辿って値にたどり着けないとエラーになる。*aを指定するとエラー。 */
  printf("%d\n", *b);
  return 0;
}