# include <stdio.h>

int main(int argc, char **argv) {
  int i = 0;
  char c;

  while (argc-- > 0) {
    printf("argv[%d]=\"", i++);
    while (c = *(*argv)++) // 文字列のナル文字（\0）が代入されればfalseになる
      putchar(c);          // ⇨ １文字ずつ出力している
    argv++;                // 一つの文字列（＝コンソール入力された文字列）を出力し終えたらループし、次の文字列
    printf("\"\n");
  }

  return 0;
}