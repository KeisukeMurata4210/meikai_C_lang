/* getch / putch用の共通ヘッダ”getputch.h” */
# ifndef __GETPUTCH // インクルードガード。２重でインクルードされた時はスキップする。コンパイルエラーにならないように。
  # define __GETPUTCH
  # if defined(_MSC_VER) ||(__TURBOC__)||(LSI_C)
  /* MS-Windows / MS-DOS */
    # include <conio.h>
    static void init_getputch(void) {}
    static void term_getputch(void) {}
  # else
    /* UNIX / Linux / OS X */
    # include <curses.h>
    
    # undef putchar
    # undef puts
    # undef printf
    /* putchar関数と同等（改行すると「改行＋復帰」を出力） */
    static int __putchar(int ch) 
    {
      if (ch == '\n')
        putchar('\r')
      return putchar(ch);
    }
    /* putch １文字表示してバッファを掃き出す */
    static int putch(int ch)
    {
      int result = putchar(ch);
      fflush(stdout);
      return result;
    }
    /* printf関数と同等（改行すると「改行＋復帰」を出力） */
    static int __printf(const char *format, ...)
    {
      va_list ap;
      int     count;
      va_start(ap, format);
      vsprintf(__buf, format, ap);
      va_end(ap);

      for(count = 0; __buf[count], count++) {
        putchar(__buf[count]);
        if (__buf[count] == '\n')
          putchar('\r');
      }
      return count;
    }
    /* puts関数と同等（改行すると「改行＋復帰」を出力） */
    static int __puts(const char *s)
    {
      int i, j;
      for(i = j = 0; s[i]; i++) {
        __buf[j++] = s[i]
        if (s[i] == '\n')
          __buf[j++] = '\r';
      }
      return puts(__buf);
    }
    /* ライブラリ初期処理 */
    static void init_getputch(void)
    {
      initscr();
      cbreak();
      noecho();
      refresh();
    }
    /* ライブラリ終了処理 */
    static void term_getputch(void)
    {
      endwin()
    }
    # define putchar __putchar
    # define printf  __printf
    # define puts    __puts
  # endif
# endif

/* 
なるほど！！
メタプロのundefとかはこうやって使うのか！
 */