# include <time.h>
# include <stdio.h>
# include <stdlib.h>

# define MAX_STAGE   10
# define swap(type, x, y)  do {type t = x; x = y; y = t; } while (0)

int main(void) 
{
  int i, j, stage;
  int dgt[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int a[10]; // 一個多くする
  double jikan;
  clock_t start, end;

  srand(time(NULL));

  printf("ダブっている数字を入力してください。\n");

  start = clock();
  for (stage = 0; stage < MAX_STAGE; stage++) {
    int x = rand() % 9; // 0~8
    int no;

    i = j = 0;
    while (i < 9) { // ここだけが違う。乱数xと同じ場合さらにもう一度
      a[j++] = dgt[i];
      if (i == x)
        a[j++] = dgt[i];
      i++;
    }

    for (i = 9; i > 0; i--) {  // シャッフルの個数も増える
      int j = rand() % (i + 1); // 0~i
      if (i != j)
        swap(int, a[i], a[j]);
    }

    for (i = 0; i < 10; i++) // 表示の個数も増える
      printf("%d ", a[i]);
    printf("：");

    do {
      scanf("%d", &no);
    } while(no != dgt[x]);
  }
  end = clock();

  jikan = (double)(end - start) / CLOCKS_PER_SEC;
  printf("%.lf秒かかりました。\n", jikan);
  
  if (jikan > 25.0)
    printf("阿保が。\n");
  else if (jikan > 20.0)
    printf("少し鈍いですね。\n");
  else if (jikan > 17.0)
    printf("まあまあですね。\n");
  else
    printf("素早いですね。\n");
  return 0;
}