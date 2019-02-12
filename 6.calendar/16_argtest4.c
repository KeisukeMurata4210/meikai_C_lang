# include <stdio.h>

int main(int argc, char **argv) {
  int i = 0;
  while (*argv)  // argcを使わなくとも、argvの末尾は空ポインター（＝番兵）でfalseになるため終了条件にできる
    printf("argv[%d] = \"%s\"\n", i++, *argv++);

  return 0;
}