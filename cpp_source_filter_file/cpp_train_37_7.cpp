#include <bits/stdc++.h>
using namespace std;
const int N = 1000006;
int l[N], f[N], num[N];
string s[N];
int main() {
  int i, n, r, c;
  ios_base::sync_with_stdio(false);
  cin >> n >> r >> c;
  for (i = 0; i < n; ++i) {
    cin >> s[i];
    l[i] = s[i].size();
  }
  l[n] = N;
  int a = 0, b = 0;
  int tmp = l[0];
  while (a <= n) {
    if (tmp <= c) {
      b++;
      tmp += l[b] + 1;
    } else
      f[a] = b - 1, tmp -= l[a] + 1, a++;
  }
  for (i = 0; i <= n; ++i) num[i] = i;
  int rr = r;
  while (r > 0) {
    if (r & 1)
      for (i = 0; i <= n; ++i) num[i] = f[num[i]];
    r >>= 1;
    for (i = 0; i <= n; ++i) f[i] = f[f[i]];
  }
  int now = 0;
  for (i = 0; i < n; ++i)
    if (num[i] - i > num[now] - now) now = i;
  for (i = 0; i < rr; ++i) {
    int tmp = -1;
    while (tmp + l[now] + 1 <= c) {
      if (tmp >= 0) cout << " ";
      cout << s[now];
      tmp += l[now] + 1;
      now++;
    }
    cout << "\n";
  }
  return 0;
}
