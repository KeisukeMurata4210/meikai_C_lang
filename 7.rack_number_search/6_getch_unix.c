/*
gcc ファイル名 -lcurses
*/
# include <curses.h>
# include <ctype.h>
# include <stdio.h>

int main(void)
{
  int ch;
  int retry;

  initscr();//スクリーン作成とライブラリ初期化。cursesライブラリを使う最初に呼び出す
  cbreak();//行バッファリング（改行文字に達した時点でデータを送り出す）を行わない
  noecho();//タイプされたキーを画面に表示させない
  refresh();//画面を消去する

  do {
    printf("\rキーを押してください。");
    fflush(stdout);

    ch = getch();
    printf("\n\r押されたキーは%cで値は%dです。\n\r", isprint(ch) ? ch : ' ', ch);

    printf("もう一度？ (Y / N) ：");
    fflush(stdout);
    retry = getch();
    if (isprint(retry))
      putchar(retry);
    
    putchar('\n');
    fflush(stdout);
  } while(retry == 'Y' || retry == 'y');
  endwin(); // cursesライブラリを使う最後に呼び出す
  return 0;
}
/*
Cursesライブラリだと
・改行してもカーソルは移動しないため、\n\rと書く必要がある
・バッファ
*/