# include <stdio.h>

int main(int argc, char **argv) {
  int i = 0;
  while (argc-- > 0)
    printf("argv[%d] = \"%s\"\n", i++, *argv++);
}
/* 
char *argv[]を
char **argv
と書けるのはなぜ？どういう仕組み？
ただ単に「ポインターへのポインター」っていう理解でいいか。
 */