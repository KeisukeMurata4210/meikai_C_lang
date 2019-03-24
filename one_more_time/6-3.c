/* 現在の日付・時刻を表示（その２） */
# include <time.h>
# include <stdio.h>

int main(void)
{
  time_t current = time(NULL);

  printf("現在の日付・時刻：%s", asctime(localtime(&current)));
  /* asctime()：引数のtm構造体型ポインタを文字列（＝文字配列）に変換する。 
  改行文字とナル文字が自動で入る */
  return 0;
}