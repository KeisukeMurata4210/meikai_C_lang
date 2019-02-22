# include <time.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "getputch.h"

# define NO     30 /* 練習回数 */
# define KTYPE  16 /* ブロック数 */

int main(void)
{
	char *kstr[] = {"12345",  "67890-^\\",	/* 第1段         */
				          "!\"#$%", "&'() =~|",		/* 第1段 [Shift] */
                  "qwert",  "yuiop@[",		/* 第2段         */
                  "QWERT",  "YUIOP`{",		/* 第2段 [Shift] */
                  "asdfg",  "hjkl;:]",		/* 第3段         */
                  "ASDFG",  "HJKL+*}",		/* 第3段 [Shift] */
                  "zxcvb",  "nm,./\\",		/* 第4段         */
                  "ZXCVB",  "NM<> _",			/* 第4段 [Shift] */
					        };
  int i, stage;
  clock_t start, end;

  init_getputch();
  srand(time(NULL));

  printf("キー位置連想タイピング練習を始めます。\n");
  printf("？で隠された文字をタイプしてください。\n");
  printf("スペースキーで開始します。\n");
  fflush(stdout);
  while(getch() != ' ')
    ;
  start = clock();
  for (stage = 0; stage < NO; stage++) {
    int k, p, key;
    char temp[10];
    do {
      k = rand() % KTYPE;
      p = rand() % strlen(kstr[k]);
      key = kstr[k][p];
    } while(key == ' ');
    strcpy(temp, kstr[k]);
    temp[p] = '?';
    printf("%s", temp);
    fflush(stdout);
    while(getch() != key)
      ;
    putchar('\n');
  }
  end = clock();
  term_getputch();
  printf("%.lf秒でした。\n", (double)(end - start) / CLOCKS_PER_SEC);
  return 0;
}