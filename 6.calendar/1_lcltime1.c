# include <time.h>
# include <stdio.h>

/* 日付、時刻を表示 */
void put_date(const struct tm *timer) {
  char *wday_name[] = {"日", "月", "火", "水", "木", "金", "土"};

  printf("%4d年%02d月%02d日（%s）%02d時%02d分%02d秒",
          timer->tm_year + 1900, // この2箇所はひとまずお作法として覚えておこう
          timer->tm_mon + 1,
          timer->tm_mday,
          wday_name[timer->tm_wday],
          timer->tm_hour,
          timer->tm_min,
          timer->tm_sec
        );
}

int main(void) {
  time_t current;
  struct tm *timer;  // 構造体tmは time.h の中で宣言されている。tm *型のポインタ変数を定義
  
  time(&current);    // time()は暦時刻（システム内での時刻形式=time_t型）を取得し、引数のポインタと戻り値の両方に返す
  timer = localtime(&current);  // 暦時刻を引数にとり、現地の時刻に変換する。tm型で受け取るようだ

  printf("現在の日付・時刻は");
  put_date(timer);
  printf("です。\n");

  return 0;
}