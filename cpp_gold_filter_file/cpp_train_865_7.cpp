#include <bits/stdc++.h>
using namespace std;
int s[111111];
int p[111111];
int t[111111];
int main() {
  int n, m, c;
  cin >> n >> m >> c;
  for (int i = 1; i <= n; i++) scanf("%d", &s[i]);
  for (int i = 1; i <= m; i++) scanf("%d", &p[i]);
  int sum = 0;
  for (int i = 1; i <= m; i++) sum += p[i];
  for (int i = 1; i <= n; i++) t[i] = sum;
  int a = sum;
  for (int i = 1; i <= m; i++) a -= p[i], t[i] -= a;
  a = sum;
  for (int i = 1; i <= m; i++) a -= p[m + 1 - i], t[n + 1 - i] -= a;
  for (int i = 1; i <= n; i++)
    printf("%d%c", (s[i] + t[i]) % c, i == n ? '\n' : ' ');
  return 0;
}
