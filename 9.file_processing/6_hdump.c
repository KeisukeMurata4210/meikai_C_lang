/* hdump：ファイルのダンプ */
# include <ctype.h>
# include <stdio.h>
# include <limits.h>

/* ストリームsrcの内容をdstへダンプ */
void hdump(FILE *src, FILE *dst)
{
  int n;
  unsigned long count = 0;
  unsigned char buf[16];

  while ((n = fread(buf, 1, 16, src)) > 0) {/* ストリームsrcから、最大16個で大きさ1のデータを配列bufに読み取る。戻り値は読み取った要素の個数 */
    int i;
    fprintf(dst, "%08lX ", count);  /* アドレス　　%lX：long/unsigned longを16進数で出力する */
    for (i = 0; i < n; i++)
      fprintf(dst, "%0*X ", (CHAR_BIT + 3) / 4, (unsigned)buf[i]); /* %X：整数を16進数で出力する　%x %Xの違いは出力を小文字にするか大文字にするか */
      /* 「*」は表示する桁数を指定できる↑  「CHAR_BIT」はその環境での１バイトのビット数 ひとまずこの計算はそういうものと割り切ろう */
    if (n < 16)
      for (i = n; i < 16; i++) fputs("  ", dst);
    
  }


}

int main(int argc, char *argv[])
{
  FILE *fp;
  if (argc < 2)
    hdump(stdin, stdout);   /* 標準入力　→　標準出力 */
}

/*
unsigned → 正の整数のみ
signed   → 正負

fread()：
*/