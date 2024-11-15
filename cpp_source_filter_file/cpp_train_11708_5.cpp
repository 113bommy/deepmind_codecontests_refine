#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int n, m;
char str[N][N];
int a[N];
long long ans;
bool check() {
  for (int i = 1; i < m; ++i) {
    int wrong = 0;
    for (int j = 1; j <= n; ++j)
      if (str[i][j] != str[0][j]) wrong++;
    if (wrong != a[i]) return false;
  }
  return true;
}
void gen(int x, int cnt) {
  if (cnt == a[0]) {
    if (check()) ans++;
    return;
  }
  for (int i = x + 1; i <= n; ++i) {
    str[0][i] = 1 - str[0][i];
    gen(i, cnt + 1);
    str[0][i] = 1 - str[0][i];
  }
}
int main() {
  scanf("%d %d", &n, &m);
  ans = 0;
  for (int i = 0; i < m; ++i) {
    scanf("%s %d", str[i] + 1, &a[i]);
    for (int j = 1; j <= m; ++j) str[i][j] -= '0';
  }
  gen(0, 0);
  cout << ans << endl;
  return 0;
}
