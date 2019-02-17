# include <stdio.h>
# include <stdarg.h>

/* 警告を発する書式付き出力関数 */
int aprintf(const char *format, ...)
{
  int     count;
  va_list ap;

  putchar('\a');
  va_start(ap, format);
  count = vprintf(format, ap);// vprintf：可変長引数を、第一引数のフォーマットに従ってコンソールに出力する
  va_end(ap);
  return count;
}

int main(void) 
{
  aprintf("Hello!\n");
  aprintf("%d %ld %.2f\n", 2, 3L, 3.14);
  return 0;
}
/* 
vfprintfは、vprintfと同じ内容をファイルに出力する。
 */