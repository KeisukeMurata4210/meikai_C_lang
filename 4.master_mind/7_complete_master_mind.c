# include <time.h>
# include <ctype.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

/* （1）相異なる4つの数字を生成して配列xに格納 */
void make4digits(int x[]) {
  int i, j, val;
  for (i = 0; i < 4; i++) { // for文1つだけだと、乱数といえど重複の可能性がある
    do {
      val = rand() % 10; // 0~9
      for (j = 0; j < i; j++) { // 既に生成した数に一致した乱数ならもう一度
        if (val == x[j]) break; // 重複していればその時点の値のまま、jはインクリメントされない
      }
    } while(j < i); // 一つも重複がなければj == iになる
    x[i] = val;
  }
}

/* （4）入力された文字列の妥当性チェック */
int check(const char s[]) {
  int i, j;

  if (strlen(s) != 4) {
    return 1; // 4文字じゃない
  }
  for (i = 0; i < 4; i++) {
    if (!isdigit(s[i]))
      return 2; // 数字以外
    for (j = 0; j < i; j++) {
      if (s[i] == s[j])
        return 3; // 重複がある
    }
  }
  return 0;  //妥当
}

/* （5）ヒット/ブローの判定 */
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

/* （new）判定結果を表示 */
void print_result(int snum, int spos) {
  if (spos == 4) {
    printf("正解です!!");
  } else if (snum == 0) {
    printf("     それらの数字は全く含まれていません。\n");
  } else {
    printf("     それらの数字中%d個の文字が含まれています。\n", snum);
    if (spos == 0)
      printf("     ただし位置も合っている数字はありません。\n");
    else
      printf("     その中の%d個は位置もあっています。\n", spos);
  }
  putchar('\n');
}

int main(void) {
  int try_no = 0;  //入力回数
  int chk;         //入力された文字列のチェック結果
  int hit;         //位置も数字も当たっている個数
  int blow;        //数字は当たって位置は当たっていない個数
  int no[4];       //当てる数字。compが生成
  char buff[4];    //入力された数字の文字列を格納
  clock_t start, end; // 開始、終了時間

  srand(time(NULL)); // 乱数の種

  puts("■ マスターマインドをしましょう。");
  puts("■ 四つの数字の並びを当ててください。");
  puts("■ 同じ数字が複数個含まれることはありません。");
  puts("■ 4307のように連続して入力してください。");
  puts("■ スペース文字などを入力してはいけません。\n");

  make4digits(no);  // 4つの数字の並びを生成　　配列は先頭要素のポインタ

  start = clock();  //開始
  do {
    do {
      printf("入力してください：");
      scanf("%s", buff);

      chk = check(buff); // 妥当かどうかチェック
      switch(chk) {
        case 1: puts("\aきちんと４文字で入力してください。");    break;
        case 2: puts("\a数字以外の文字を入力しないでください。"); break;
        case 3: puts("\a同一の文字を複数入力しないでください。"); break;
      }
    } while(chk != 0); // 妥当な値が入力されるまで入力を繰り返す
    try_no++; // 妥当な値が入力されれば回数をカウント
    judge(buff, no, &hit, &blow);
    print_result(hit + blow, hit);
  } while(hit < 4); // 正解するまでゲームを繰り返す
  end = clock();

  printf("%d回かかりました。\n所要時間は%.lf秒でした。\n", try_no, (double)(end - start) / CLOCKS_PER_SEC);
  return 0;
}