# include <time.h>
# include <stdio.h>

char *asctime2(const struct tm *timeptr);

int main(void) {
  time_t current = time(NULL); // 現在の時刻を取得
  char *result;

  printf("現在の日時・時刻：");
  result = *asctime2(localtime(&current));
  printf("%p\n", result);

  return 0;
}

/* ここから */
char *asctime2(const struct tm *timeptr) {
  const char wday_name[7][3] = {
    "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"
  };
  const char mon_name[12][3] = {
    "Jan", "Feb", "Mar", "Apr", "May", "Jun",
    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
  };
  static char result[25];

  sprintf(result, "%.3s %.3s %02d %02d:%02d:%02d %4d",
          wday_name[timeptr->tm_wday], mon_name[timeptr->tm_mon],
          timeptr->tm_mday, timeptr->tm_hour, timeptr->tm_min,
          timeptr->tm_sec, timeptr->tm_year + 1900);
  return result;
}