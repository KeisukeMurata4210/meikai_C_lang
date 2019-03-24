/* 現在の日付・時刻を表示（その３：ctime()を利用） */
# include <time.h>
# include <stdio.h>

int main(void)
{
  time_t current = time(NULL);

  printf("現在の日付・時刻：%s", ctime(&current));
  /* ctime(&current) ＝ asctime(localtime(&current)) 
    tm構造体型ポインタに変換する手間を省ける */
  return 0;
}