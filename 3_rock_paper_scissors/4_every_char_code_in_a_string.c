# include <ctype.h>
# include <stdio.h>
# include <limits.h>

/* 文字列内の文字を16進数と2進数で表示 */
void strdump(const char *s) {             // 文字列は文字型の配列だから、引数で渡されるのは1文字目のアドレス
  while (*s) { // sが「\0」でない間繰り返す
    int i;
    unsigned char x = (unsigned char)*s;

    printf("%c  ", isprint(x) ? x : ' ');
    printf("%0*X  ", (CHAR_BIT + 3) / 4, x);//16進数 CHAR_BITは、その環境での「1バイトのビット数」
    for (i = CHAR_BIT -1; i >= 0; i--) {
      putchar(((x >> i) & 1U) ? '1' : '0');
    }
    putchar('\n');
    s++; // ポインタのインクリメントは、メモリ上の次のアドレスへ移動する（＝2文字目3文字目…に移動する）
  }
}

int main(void) {
  puts("漢字");         strdump("漢字");          putchar('\n');
  puts("12日本語ABC");  strdump("12日本語ABC");    putchar('\n');
  return 0;
}

/* 
文字コードの細かい話は飛ばそう
*/