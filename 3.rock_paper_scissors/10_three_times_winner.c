# include <time.h>
# include <stdio.h>
# include <stdlib.h>

int human;
int comp;
int win_no;
int lose_no;
int draw_no;

char *hd[] = {"グー", "チョキ", "パー"};  //ポインタ配列で手

/* 初期処理 */
void initialize(void) {
  win_no  = 0;
  lose_no = 0;
  draw_no = 0;

  srand(time(NULL));
  printf("じゃんけんゲーム開始！！\n");
}

/* じゃんけん実行（手の読み込み/生成） */
void jyanken(void) {
  int i;
  comp = rand() % 3;//乱数を生成
  do {
      printf("\n\aじゃんけんぽん…");
      for (i = 0; i < 3; i++) {
        printf(" (%d)%s", i, hd[i]); // グーチョキパーが配列になったため、ループで手の種類を出力する
      }
      printf("：");  //改行を入れずに
      scanf("%d", &human);
    } while(human < 0 || human >2); //正しい範囲で入力されるまで繰り返す
}

/* 勝ち/負け/引き分け回数を更新 */
void count_no(int result) {
  switch (result){
    case 0: draw_no++; break;
    case 1: lose_no++; break;
    case 2: win_no++;  break;
  }
}

/* 判定結果を表示 */
void disp_result(int result) {
  switch (result){
    case 0: puts("引き分けです。");    break;
    case 1: puts("あなたの負けです。"); break;
    case 2: puts("あなたの勝ちです。"); break;
  }
}

/* 再挑戦するかを確認 */
int confirm_retry(void) {
  int x;
  printf("もう一度しますか…(0)いいえ (1)はい：");
  scanf("%d", &x);
  return x;
}

int main(void) {
  int judge;
  int retry;

  initialize();  //初期処理

  do {
    jyanken();  // じゃんけん実行

    printf("私は%sで、あなたは%sです。\n", hd[comp], hd[human]); //コンピュータと人間の手を表示

    judge = (human - comp + 3) % 3; // 勝敗を判定

    count_no(judge); // 勝ち負け引き分けの回数を更新

    disp_result(judge); // 判定結果を表示

    retry = confirm_retry(); //再挑戦するかを確認
  } while(win_no < 3 && lose_no < 3);
  printf("%d勝%d敗%d分けでした。\n", win_no, lose_no, draw_no);

  return 0;
}