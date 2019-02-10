# include <stdio.h>
# include <stdlib.h>
# include <string.h>

/* ここは同じ */
int mday[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int dayofweek(int year, int month, int day) {
  if (month == 1 || month == 2) {
    year--;
    month += 12;
  }
  return (year + year/4 - year/100 + year/400 + (13*month + 8)/5 + day) % 7;
}

int is_leap(int year) {
  return year % 4 == 0 && year % 100 != 0 && year % 400 == 0;
}

int monthdays(int year, int month) {
  if (month-- != 2)
    return mday[month];
  return mday[month] + is_leap(year);
}

int make_calendar(int y, int m, char s[7][22]) {
  int i, k;
  int wd = dayofweek(y, m, 1);/* y年m月1日の曜日 */
  int mdays = monthdays(y, m);/* y年m月の日数 */
  char tmp[4];

  sprintf(s[0], "%10d / %02d     ", y, m); // タイトル（年 / 月）
  for (k = 1; k < 7; k++)
    s[k][0] = '\0'; // 何で１番目にEOS？？
}



/*
1ヶ月分のカレンダーは7行22列
それを３ヶ月分なので3次元配列
3*7*12
*/

/*
int nums1[3][5] = {{0, 1, 2, 3, 4},
						       {1, 2, 3, 4, 5},
						       {2, 3, 4, 5, 6}};
[①][②][]…
①配列の、②配列の、③…
*/