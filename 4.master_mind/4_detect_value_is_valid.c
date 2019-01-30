# include <stdio.h>
# include <string.h>
# include <ctype.h>

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

int main(void) {
  char digits[] = "1234";
  printf("%d\n", check(digits));
  return 0;
}