# include <stdio.h>

int main(int argc, char *argv[]) {
  int i;

  for (i = 0; i < argc; i++)
    printf("argv[%d] = \"%s\"\n", i, argv[i]);
  
  return 0;
}
/* 
argc = argument count プログラム名とプログラム仮引数を合わせた個数で、0から数える
argv = argument vector コマンドラインから与えた文字列。実際はその文字列へのポインタ、の配列。argv[0]がプログラム名。

文字列へのポインタは、文字配列の先頭へのポインタ！

実行環境によって表示形式などの違いが出る
argvの末尾には空のポインタが格納されている
 */