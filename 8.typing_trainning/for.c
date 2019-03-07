# include <stdio.h>

int main(void)
{
  int i;
  for (i = 0; i < 0; i++) {
    printf("実行されるか？\n");
    /* 実行されない。１回目は真になるような条件式でないと、一回も実行されない */
  }
}