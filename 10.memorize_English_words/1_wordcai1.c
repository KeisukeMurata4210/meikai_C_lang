/* 英単語学習ソフト（試作版：日本語の単語/英語の単語をランダムに表示） */
# include <time.h>
# include <stdio.h>
# include <stdlib.h>

# define QND   12  /* 単語の数 */

/* 日本語 */
char *jptr[] = {
  "動物", "車", "花", "家", "机", "本",
  "椅子", "父", "母", "愛", "平和", "雑誌"
};

/* 英語 */
char *eptr[]