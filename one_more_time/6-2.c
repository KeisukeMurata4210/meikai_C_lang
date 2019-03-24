/* 現在の日付・時刻を協定世界時で表示 */
# include <time.h>
# include <stdio.h>

void put_date(const struct tm *timer)
{
  char *wday_name[] = {"日", "月", "火", "水", "木", "金", "土"};

  printf("%4d年%02d月%02d日（%s）%02d時%02d分%02d秒",
          timer->tm_year + 1900,  /* 年は1900からの差分になっているため */
          timer->tm_mon + 1,      /* 1月からの差分（0~11）になっているため */
          timer->tm_mday,
          wday_name[timer->tm_wday],/* 日曜から数えて0~6 */
          timer->tm_hour,
          timer->tm_min,
          timer->tm_sec
  );
}

int main(void)
{
  time_t current;
  struct tm *timer;

  time(&current);
  timer = gmtime(&current);/* UTCになる。使い方はlocaltime()と同じ */

  printf("現在の日時・時刻は");
  put_date(timer);
  printf("です。\n");

  return 0;
}