# include <stdio.h>

int main(void) {
  int i;
  char a[][6] = {
    "Super", "X", "TRY"
  };

  for (i = 0; i < 3; i++) {
    printf("%s\n", a[i]);
  }
}

/*
2次元配列
一つ目の添字は「●行目」を表す
二つ目の添字は「●列目」を表す
a[0][0] a[0][1] a[0][2] a[0][3]
a[1][0] a[1][1] a[1][2] a[1][3]
a[2][0] a[2][1] a[2][2] a[2][3]
*/