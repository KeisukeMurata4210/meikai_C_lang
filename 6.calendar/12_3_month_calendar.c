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
  return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

int monthdays(int year, int month) {
  if (month-- != 2)
    return mday[month];
  return mday[month] + is_leap(year);
}

/* y年m月のカレンダーを２次元配列sに格納 */
int make_calendar(int y, int m, char s[7][22]) {
  int i, k;
  int wd = dayofweek(y, m, 1);/* y年m月1日の曜日 */
  int mdays = monthdays(y, m);/* y年m月の日数 */
  char tmp[4];

  sprintf(s[0], "%10d / %02d      ", y, m); // タイトル（年 / 月）
  for (k = 1; k < 7; k++)
    s[k][0] = '\0'; // EOSじゃなくて空文字
  
  k = 1;
  sprintf(s[k], "%*s", 3 * wd, "");// 第１日の左側を空欄で埋める

  for (i = 1; i <= mdays; i++){
    sprintf(tmp, "%3d", i); // tmp=1日分の文字列 "  1"など
    strcat(s[k], tmp);      // 順番に引っ付けていく
    if (++wd % 7 == 0)      // 土曜日になったら次の行に
      k++;
  }

  if (wd % 7 == 0)
    k--;
  else {
    for (wd %= 7; wd < 7; wd++) //土曜日でなければ行が全て埋まっていない→次の月の始まりがズレる ので空欄で埋める
      strcat(s[k], "   ");
  }
  while (++k < 7)
    sprintf(s[k], "%21s", ""); // 21個の空欄で、空欄のみの行を追加する。
}

/* ３次元配列sbufに格納されたカレンダーを横にn個並べて表示 */
void print(char sbuf[3][7][22], int n) {
  int i, j;

  for (i = 0; i < n; i++)
    printf("%s   ", sbuf[i][0]); // タイトルを表示
  putchar('\n');
  for (i = 0; i < n; i++)
    printf(" 日 月 火 水 木 金 土   ");
  putchar('\n');
  for (i = 0; i < n; i++)
    printf("----------------------  ");
  putchar('\n');
  for (i = 1; i < 7; i++) {
    for (j = 0; j < n; j++)
      printf("%s   ", sbuf[j][i]);
    putchar('\n');
  }
  putchar('\n');
}

/* y1年m1月からy2年m2月までのカレンダーを表示 */
void put_calendar(int y1, int m1, int y2, int m2) {
  int y = y1;
  int m = m1;
  int n = 0;
  char sbuf[3][7][22];     // カレンダー文字列のバッファ

  while (y <= y2) {
    if (y == y2 && m > m2) break;
    make_calendar(y, m, sbuf[n++]);
    if (n == 3) {
      print(sbuf, n);// ここで、3ヶ月ずつ区切って出力するよう制御する！！
      n = 0;
    }
    m++;
    if (m == 13 && y < y2) {
      y++;
      m = 1;
    }
  }
  if (n)
    print(sbuf, n);
}

int main(void) {
  int y1, m1, y2, m2;

  printf("カレンダーを表示します。\n");
  printf("開始年月を入力せよ。\n");
  printf("年："); scanf("%d", &y1);
  printf("月："); scanf("%d", &m1);

  printf("終了年月を入力せよ。\n");
  printf("年："); scanf("%d", &y2);
  printf("月："); scanf("%d", &m2);

  putchar('\n');

  put_calendar(y1, m1, y2, m2);

  return 0;
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