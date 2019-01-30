# include <stdio.h>

void judge(const char s[], const int no[], int *hit, int *blow) {
  int i, j;

  *hit = *blow = 0;
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      if (s[i] == '0' + no[j]) { // しらみつぶしにプレイヤー入力文字列（s）とコンピュータ生成数字（no）を照合する
        if (i == j) // その内桁の位置も合っているならhit
          (*hit)++;
        else        // 桁の位置は違うのならblow
          (*blow)++; 
      }
    }
  }
}

int main(void) {
  return 0;
}