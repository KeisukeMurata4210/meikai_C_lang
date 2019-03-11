# include <time.h>
# include <float.h>
# include <ctype.h>
# include <stdio.h>
# include <stdlib.h>
# include "getputch.h"

# define MAX_STAGE    10
# define swap(type, x, y)   do {type t = x; x = y; y = t} while(0)

char dtfile[] = "LACKNUM.DAT";/* ファイル名 */

/* 前回のトレーニング情報を取得・表示して最高得点を返す */
double get_data(void)
{
  FILE *fp;     /* fopen()はFILEへのポインタを返すからFILE*型 */
  double best;  /* 最高得点 */

  if ((fp = fopen(dtfile, "r")) == NULL) { /* なるほど！　ファイルがなければ初めての起動 */
    printf("本プログラムを実行するのは初めてですね。\n\n");
    best = DBL_MAX; /* float.h で定義されたマクロ。double型で表現できる最大値 */
  } else {
    int year, month, day, h, m, s;

    fscanf(fp, "%d%d%d%d%d%d", &year, &month, &day, &h, &m, &s);/* fscanfはファイルからの読み込み。指定した形式で、第3引数以降の変数に代入される */
    fscanf(fp, "%lf", &best);
    printf("前回の終了は%d年%d月%d日%d時%d分%d秒でした。\n", year, month, day, h, m, s);/* 最後の行から読み込まれるらしい */
    printf("これまでの最高得点（最短所要時間）は%.lfです。\n\n", best);
    fclose(fp);
  }
  return best;
}