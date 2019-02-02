# include <stdio.h>

# define MAX    10  // 配列の要素数は10までとする

int main(void) {
  int i;
  int a[MAX];  // 読み込んだ値を格納する配列
  int cnt = 0; // 読み込んだ個数
  int retry;   // もう一度？

  printf("整数を入力してください。\n");

  do {
    printf("%d個目の整数：", cnt + 1);
    scanf("%d", &a[cnt++ % MAX]); // (cnt => 0~9) 10で割った余りなら、10以下ならその添字、11以上なら10を引いた余りが添字になるため、要素の移動がいらない

    printf("続けますか？（ yes…1 / no…0 ）：");
    scanf("%d", &retry);
  } while(retry == 1);

  i = cnt - MAX;
  if (i < 0) i = 0; // iの値を10からのオーバー分にする、なければ0

  for ( ; i < cnt; i++)
    printf("%2d個目 ：%d\n", i + 1, a[i % MAX]);

  return 0;
}

/* 
0~10：
0から入力個数までカウントする。
i を 10で割った余りはi自体になる。
1個目 ：a[0]
2個目 ：a[1]

11：
iは1。
ループ中のiは
1~10
(i + 1 =)2個目　：a[i % 10]

配列内の添え字が、10をオーバーした数によって循環する
*/