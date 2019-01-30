# include <stdio.h>
# include <stdlib.h>

int main(void) {
  char temp[20];

  printf("整数を入力してください：");
  scanf("%s", temp);

  printf("%dと入力しましたね。\n", atoi(temp));//文字列を整数に変換する 数値の型によって　atof atol　など
  return 0;
}
/* 
・この方法でも、atoi()を使っても先頭の0がなくなる。
・変換できないときは処理系に依存し、0が返ってくるとは限らない
・しかも入力した0なのか変換できないという意味の0なのか区別できない
*/