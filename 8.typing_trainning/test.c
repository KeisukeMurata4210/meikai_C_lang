# include <stdio.h>

typedef enum {Term, KeyPos, KeyPosComp, Clang, Conversation, InValid} Menu;

int main(void)
{
  Menu menu;
  int a = 1;
  printf("%d\n", a);
  menu = (Menu)a;
  printf("%d\n", a);


  switch (menu)
  {
    case Term:
      printf("Term\n");
      break;
    case KeyPos:
      printf("KeyPos\n");
      break;
    default:
      break;
  }
  return 0;
}
/*
内部的には整数と同じ。← case 1:を追加するとエラーが出た。
swichはenumをサポートする仕様になっているのかな。← defaultを追加しないと警告が出た。

Menu.Term と書かなくてもいいのは、switchにenumを使うときの特殊な書き方として認められているからだろう。
*/