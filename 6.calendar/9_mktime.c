# include <time.h>
# include <stdio.h>

/* year年month月day日の曜日を求める */
int dayofweek(int year, int month, int day) {
  struct tm t;
  t.tm_year  = year - 1900;/* 年を調整 */
  t.tm_mon   = month -1;   /* 月を調整 */
  t.tm_mday  = day;        /* 日 */
  t.tm_hour  = 0;          /* 時 */
  t.tm_min   = 0;          /* 分 */
  t.tm_sec   = 0;          /* 秒 */
  t.tm_isdst = -1;         /* 夏時間 */

  if (mktime(&t) == (time_t)-1) // mktime()：localtime()と逆のことをする + 曜日（tm_wday）と年内経過日数（tm_yday）を引数のtmに設定する
    return -1;
  return t.tm_wday;
}

int main(void) {
  int y, m, d, w;
  char *ws[] = {"日", "月", "火", "水", "木", "金", "土"};

  printf("曜日を求めます。\n");
  printf("年："); scanf("%d", &y);
  printf("月："); scanf("%d", &m);
  printf("日："); scanf("%d", &d);

  w = dayofweek(y, m, d);  // mktime()の副作用を使って曜日を取得

  if (w != -1)
    printf("それは%s曜日です。\n", ws[w]);
  else
    printf("求められませんでした。\n");

  return 0;
}

/*
文字列 char型の配列　char型ポインター で表す
→配列とポインタが同じような仕組みだから？

22行目はchar型ポインターの配列　＝ char型配列の配列
*/