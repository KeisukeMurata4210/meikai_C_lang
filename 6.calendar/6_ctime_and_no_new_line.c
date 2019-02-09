# include <time.h>
# include <stdio.h>

char *asctime2(const struct tm *timeptr);

char *ctime2(const time_t *timer);

int main(void) {
  time_t current = time(NULL); // 現在の時刻を取得

  printf("現在の日時・時刻は%sです。\n", ctime2(&current));

  return 0;
}

char *ctime2(const time_t *timer) {
  return asctime2(localtime(timer));
}

char *asctime2(const struct tm *timeptr) { // !!「*」はchar*型の戻り値という意味で、メソッド名ではない！！！！
  const char wday_name[7][3] = {
    "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" // 要素数1個の配列が7つ（7行）ある
  };
  const char mon_name[12][3] = {
    "Jan", "Feb", "Mar", "Apr", "May", "Jun",// 要素数1個の配列が12個（12行）ある
    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
  };
  static char result[25];

  sprintf(result, "%.3s %.3s %02d %02d:%02d:%02d %4d",
          wday_name[timeptr->tm_wday], mon_name[timeptr->tm_mon],
          timeptr->tm_mday, timeptr->tm_hour, timeptr->tm_min,
          timeptr->tm_sec, timeptr->tm_year + 1900);
  return result;
}