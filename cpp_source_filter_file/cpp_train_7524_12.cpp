#include <bits/stdc++.h>
int st[100010][29], tt[29];
char s[100010], t[29];
int main() {
  int ret, ls, lt, i, j, tag;
  memset(st, 0, sizeof(st));
  memset(tt, 0, sizeof(tt));
  scanf("%s%s", s, t);
  ls = strlen(s);
  lt = strlen(t);
  for (i = 0; i < lt; i++) tt[t[i] - 'a']++;
  for (i = 0; i < ls; i++) {
    for (j = 0; j < 26; j++) st[i + 1][j] = st[i][j];
    if (s[i] == '?') continue;
    st[i + 1][s[i] - 'a'] = st[i][s[i] - 'a'] + 1;
  }
  for (ret = i = 0; i <= ls - lt; i++) {
    for (tag = j = 0; j < 26; j++)
      if (st[i + lt][j] - st[i][j] > tt[j]) tag = 1;
    if (tag == 0) ret++;
  }
  printf("%d\n", ret);
  return 0;
}
