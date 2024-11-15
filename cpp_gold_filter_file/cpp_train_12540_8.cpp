#include <bits/stdc++.h>
using namespace std;
string s, p;
int ls, lp;
int dp[4005][4005];
int a[4005];
void init() {
  memset(a, 0, sizeof(a));
  for (int b = 1; b < ls; b++) {
    int i = 1, j = b;
    while (j < ls) {
      if (s[j] == p[i])
        i++, j++;
      else
        j++;
      if (i == lp) {
        a[b] = j - b;
        break;
      }
    }
  }
}
int main() {
  cin >> s >> p;
  s = ' ' + s;
  p = ' ' + p;
  ls = s.length(), lp = p.length();
  init();
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < ls; i++)
    for (int j = 0; j < ls; j++) {
      dp[i + 1][j] = max(dp[i][j], dp[i + 1][j]);
      if (a[i + 1])
        dp[i + a[i + 1]][j + a[i + 1] - (lp - 1)] =
            max(dp[i + a[i + 1]][j + a[i + 1] - (lp - 1)], dp[i][j] + 1);
    }
  for (int i = 1; i < ls; i++) {
    dp[ls - 1][i] = max(dp[ls - 1][i], dp[ls - 1][i - 1]);
  }
  int flag = (ls == 2001);
  for (int i = 1; i < ls - 1; i++) {
    char ch[] = "1abxx";
    if (s[i] != ch[i % 4 + 1]) flag = 0;
  }
  int MAX = dp[ls - 1][ls - 1];
  for (int i = 0; i < ls; i++) {
    if (flag) cout << dp[ls - 1][i] << endl;
    if (dp[ls - 1][i] < MAX)
      printf("%d ", dp[ls - 1][i]);
    else
      printf("%d ", min(MAX, (ls - 1 - i) / (lp - 1)));
  }
  printf("\n");
  return 0;
}
