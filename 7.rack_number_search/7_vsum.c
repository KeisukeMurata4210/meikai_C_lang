# include <stdio.h>
# include <stdarg.h>

/* 第一引数に応じてそれ以降の引数の和を求める */
double vsum(int sw, ...)
{
  double sum = 0.0;
  va_list ap;

  va_start(ap, sw);/* 可変個引数をapにまとめる 。この時点ではポインタapはswを指している */
  switch (sw) {
    case 0: sum += va_arg(ap, int);// va_argを呼び出すたびに、アドレスが隣に移っていく
            sum += va_arg(ap, int);// → どの型の変数がどういう順番で渡されたか知っておく必要がある。
            break;
    case 1: sum += va_arg(ap, int);
            sum += va_arg(ap, long);
            break;
    case 2: sum += va_arg(ap, int);
            sum += va_arg(ap, long);
            sum += va_arg(ap, double);
            break;
  }
  va_end(ap);/* 最後に呼び出す */

  return sum;
}

int main(void)
{
  printf("10 + 2          = %.2f\n", vsum(0, 10, 2));
  printf("57 + 300000L    = %.2f\n", vsum(1, 57, 300000L));
  printf("98 + 2L + 3.14  = %.2f\n", vsum(2, 98, 2L, 3.14));
  return 0;
}

/* 
va_startマクロ

va_list型：　<stdarg.h>で定義されている
            複数の引数を一つの変数として扱う型　実際はポインタらしい

サンプルコードでは、第一引数によって引数のタイプがわかるようになっている。
 →ロジックを知らないと使えない、という点で、オブジェクト指向ではNGだろうな。

どの型の変数がどういう順番で渡されたか知っておく必要がある。
　→　Cは大規模開発に向かないとか、オブジェクト指向は大規模開発に向いているとかいうのはこういうところなのかな。
 */