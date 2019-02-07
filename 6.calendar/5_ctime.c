# include <time.h>
# include <stdio.h>

char *asctime2(const struct tm *timeptr);

int main(void) {
  time_t current = time(NULL); // 現在の時刻を取得

  printf("現在の日時・時刻は%sです。\n", ctime(&current)); // localtime()でtm型構造体にしなくても、直接、暦時刻を文字列に変換できる。
                                                       // ただし改行文字が入ってしまう。
  return 0;
}