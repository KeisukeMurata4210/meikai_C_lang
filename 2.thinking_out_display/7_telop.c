# include <time.h>
# include <stdio.h>
# include <string.h>

// xミリ秒経過するのを待つ
int sleep(unsigned long x) {
  clock_t c1 = clock(), c2;
  do {
    if ((c2 = clock()) == (clock_t)-1) {
      return 0;
    }
  } while(1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x);
  return 1;
}

int main(void) {
  int i;
  char name[] = "BohYoh Shibata";// 表示する文字列
  int name_len = strlen(name);  // nameの文字数

  while (1) { //以下を無限に繰り返す
    for (i = 0; i < name_len; i++) {// 先頭から１文字ずつ表示
      putchar(name[i]);
      fflush(stdout);
      sleep(500);
    }
    for (i = 0; i < name_len; i++) {//全て表示し終わった後、末尾から１文字ずつ消去
      printf("\b \b");
      fflush(stdout);
      sleep(500);
    }
  }
  return 0;
}