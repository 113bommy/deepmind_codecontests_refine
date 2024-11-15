#include <bits/stdc++.h>
using namespace std;
priority_queue<pair<int, int>, vector<pair<int, int> >,
               greater<pair<int, int> > >
    q;
int cnt[30001], ans[120001], pos;
struct data {
  int a, b, c, idx;
  data(int _a, int _b, int _c, int _i) : a(_a), b(_b), c(_c), idx(_i) {}
};
vector<data> r[30001];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 4; j++) {
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c);
      r[i].push_back(data(a, b, c, i * 4 - 4 + j));
    }
    cnt[i] = 8;
    q.push(pair<int, int>(8, i));
  }
  while (!q.empty()) {
    pair<int, int> f = q.top();
    q.pop();
    int idx = f.second;
    if (cnt[idx] < 9 && r[idx].size()) {
      data rl = r[idx].back();
      r[idx].pop_back();
      cnt[rl.a]++;
      cnt[rl.b]--;
      cnt[rl.c]--;
      ans[++pos] = rl.idx;
      q.push(pair<int, int>(cnt[rl.a], rl.a));
      q.push(pair<int, int>(cnt[rl.b], rl.b));
      q.push(pair<int, int>(cnt[rl.c], rl.c));
    }
  }
  printf("YES\n");
  for (int i = 4 * n; i >= 1; i--) printf("%d ", ans[i]);
  return 0;
}
