#include <bits/stdc++.h>
int main() {
  int n, t, p, i, j, l, r, len, dp, cp;
  int cnt[10];
  char s[105];
  char str[105];
  scanf("%d%d", &n, &t);
  scanf("%s", s + 1);
  for (p = 1; p <= t; p++) {
    memset(cnt, 0, sizeof(cnt));
    dp = 1;
    cp = 1;
    scanf("%d%d", &l, &r);
    for (i = l; i <= r; i++) {
      str[i - l + 1] = s[i];
    }
    str[r - l + 2] = '\0';
    len = strlen(str) - 1;
    for (;;) {
      if (str[cp] == '<') {
        dp = -1;
        cp--;
        if (str[cp] == '<' || str[cp] == '>') {
          for (j = cp + 1; j <= len - 1; j++) {
            str[j] = str[j + 1];
          }
          len--;
        }
      } else if (str[cp] == '>') {
        dp = 1;
        cp++;
        if (str[cp] == '<' || str[cp] == '>') {
          for (j = cp - 1; j <= len - 1; j++) {
            str[j] = str[j + 1];
          }
          len--;
          cp--;
        }
      } else if (str[cp] == '0') {
        cnt[0]++;
        for (j = cp; j <= len - 1; j++) {
          str[j] = str[j + 1];
        }
        if (dp == -1) cp--;
        len--;
      } else {
        cnt[str[cp] - '0']++;
        str[cp] = str[cp] - 1;
        cp += dp;
      }
      if (cp > len || cp < 1) break;
    }
    for (i = 0; i < 9; i++) printf("%d ", cnt[i]);
    printf("%d\n", cnt[9]);
  }
  return 0;
}
