#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
const int MOD = 1000000007;
struct Node {
  int p, e;
  void input() { scanf("%d %d", &p, &e); }
  bool operator<(const Node &n) const { return p > n.p; }
} a[N];
int n, k;
int main() {
  scanf("%d %d", &n, &k);
  k--;
  for (int i = 0; i < n; i++) {
    a[i].input();
  }
  int ans = 1 << 30;
  sort(a, a + n);
  for (int d = -2; d < 3; d++) {
    int score = a[k].p + d, ret = 0, before = 0;
    priority_queue<int, vector<int>, less<int> > large;
    priority_queue<int, vector<int>, greater<int> > small;
    for (int i = 0; i < n; i++) {
      if (a[i].p <= score && a[i].p >= score - 1) {
        large.push(a[i].e);
      } else {
        if (a[i].p > score) before++;
        small.push(a[i].e);
      }
    }
    if (before > k) continue;
    while (!large.empty()) {
      if (before < k) {
        small.push(large.top());
        before++;
      } else {
        score--;
        ret += large.top();
      }
      large.pop();
    }
    while (score > 0 && !small.empty()) {
      ret += small.top();
      small.pop();
      score--;
    }
    if (score <= 0) ans = min(ans, ret);
  }
  if (ans == 1 << 30) ans = -1;
  printf("%d\n", ans);
  return 0;
}
