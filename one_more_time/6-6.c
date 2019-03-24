/* 現在の日付・時刻を表示（その３：ctime()を利用） */
# include <time.h>
# include <stdio.h>

char *asctime2(const struct tm *timeptr)
{
  const char wday_name[7][3] = {/* ポインタ配列でなく２次元配列 */
    "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"
  };

  const char mon_name[12][3] = {
    "Jan", "Feb", "Mar", "Apr", "May", "Jun",
    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
  };

  static char result[25];/* asctime2()を抜け出しても値を保持するよう、staticにする */

  sprintf(/* sprintf()：stdoutではなく第一引数の文字配列に書き込む */
    result,
    "%.3s %.3s %02d %02d:%02d:%02d %4d",
    wday_name[timeptr->tm_wday],
    mon_name[timeptr->tm_mon],
    timeptr->tm_mday,
    timeptr->tm_hour,
    timeptr->tm_min,
    timeptr->tm_sec,
    timeptr->tm_year + 1900
  );

  return result;
}

char *ctime2(const time_t *timer)
{
  return asctime2(localtime(timer));
}

int main(void)
{
  time_t current = time(NULL);

  printf("現在の日付・時刻：%s", ctime2(&current));
  /* ctime(&current) ＝ asctime(localtime(&current)) 
    tm構造体型ポインタに変換する手間を省ける */
  return 0;
}