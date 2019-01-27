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
  int cnt = 0;   // 何文字目が先頭か
  char name[] = "BohYoh ";// 表示する文字列
  int name_len = strlen(name);  // nameの文字数

  while (1) { //以下を無限に繰り返す
    putchar('\r'); //カーソルを行の先頭にする
    for (i = 0; i < name_len; i++) {
      if (cnt + i < name_len)
        putchar(name[cnt + i]);
      else
        putchar(name[cnt + i - name_len]);
    }
    fflush(stdout);
    sleep(500);

    if (cnt < name_len - 1)
      cnt++;
    else
      cnt = 0;
  }
  return 0;
}
/* 
左方向のテロップでは、cnt（先頭文字）は
0 1 2 3 4 5 6 0 と循環する
右方向にするには、
0 6 5 4 3 2 1 0 と循環させる
*/