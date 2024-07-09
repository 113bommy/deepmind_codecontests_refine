#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 6;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  for (; c < '0' || '9' < c; c = getchar())
    if (c == '-') f = -1;
  for (; '0' <= c && c <= '9'; c = getchar()) x = (x << 3) + (x << 1) + c - '0';
  return x * f;
}
vector<pair<int, int> > p;
int n;
void divide(int l, int r) {
  if (l >= r) return;
  int m = r + l >> 1;
  divide(l, m - 1), divide(m + 1, r);
  for (int i = l; i <= r; i++)
    if (i != m) {
      p.push_back(make_pair(p[m].first, p[i].second));
    }
}
int main() {
  scanf("%d", &n);
  for (int i = 1, first, second; i <= n; i++) {
    scanf("%d%d", &first, &second);
    p.push_back(make_pair(first, second));
  }
  sort(p.begin(), p.end());
  divide(0, p.size());
  sort(p.begin(), p.end());
  int sz = unique(p.begin(), p.end()) - p.begin();
  printf("%d\n", sz);
  for (int i = 0; i < sz; i++) printf("%d %d\n", p[i].first, p[i].second);
  return 0;
}
