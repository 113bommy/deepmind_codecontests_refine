#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
char p[1000005], s[205];
int a, b, K, cnt;
int vis[2005][205];
char ch[2005], ans[2005];
bool flag;
bool check(int x, int k) {
  while (x <= a && k <= b) {
    if (p[x] != s[k]) return 0;
    x += K;
    k += cnt;
  }
  if (x <= a || k <= b) return 0;
  return 1;
}
bool dfs(int x, int k) {
  if (k > cnt) {
    for (int i = x + 1; i <= K; i++) ch[i] = '0';
    return 1;
  }
  if (x > K || vis[x][k] == cnt) return 0;
  vis[x][k] = cnt;
  if (dfs(x + 1, k)) {
    ch[x] = '0';
    return 1;
  } else if (check(x, k)) {
    ch[x] = '1';
    if (dfs(x + 1, k + 1)) return 1;
    ch[x] = '0';
  }
  return 0;
}
int main() {
  gets(p + 1);
  a = strlen(p + 1);
  gets(s + 1);
  b = strlen(s + 1);
  K = read();
  ans[1] = 'z';
  int t1 = a / K + 1, t2 = a / K;
  for (cnt = 1; cnt <= b; cnt++) {
    if (b < cnt * t2 || b > cnt * t1) continue;
    if (dfs(1, 1) && strcmp(ch + 1, ans + 1) < 0) {
      flag = 1;
      copy(ch + 1, ch + K + 1, ans + 1);
    }
  }
  if (!flag)
    puts("0");
  else
    for (int i = 1; i <= K; i++) printf("%c", ans[i]);
  return 0;
}
