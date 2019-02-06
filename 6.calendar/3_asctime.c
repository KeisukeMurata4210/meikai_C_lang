# include <time.h>
# include <stdio.h>

int main(void) {
  time_t current = time(NULL); // 現在の時刻を取得

  printf("現在の日時・時刻：%s", asctime(localtime(&current)));

  return 0;
}

/*
localtime()：time_t *型を受け取り、現在地のtm型構造体に変換する
asctime()  ：tm型構造体を受け取り、表示形式を整える
「/n/0」が自動で入るため、文字列の途中に組み込むことはできない。
*/