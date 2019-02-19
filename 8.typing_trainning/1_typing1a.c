# include <time.h>
# include <ctype.h>
# include <stdio.h>
# include <string.h>
# include "getputch.h"

int main(void)
{
  int i;
  char *str = "How do you do?";
  int len = strlen(str);
  clock_t start, end;

  init_getputch();

  printf("このとおりタイプしてください。\n");
  printf("%s\n", str);
  fflush(stdout);

  start = clock();
  for (i = 0; i < len; i++) {
    int ch;
    do {  // すごい、１文字ずつループするんだ
      ch = getch();
      if (isprint(ch)) {
        putch(ch);   // 入力したキーを表示して
        if (ch != str[i]) // 間違っていたらカーソルを元に戻す
          putch('\b');
      }
    }while(ch != str[i]);
  }
  end = clock();

  term_getputch();
  printf("\n%.lf秒でした。\n", (double)(end - start) / CLOCKS_PER_SEC);
  
  return 0;
}