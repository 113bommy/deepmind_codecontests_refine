#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using D = double;
using uint = unsigned int;
template <typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int treesize = 1 << 19;
const int maxn = 300005;
pair2<int> tree[2 * treesize];
int p[maxn], q[maxn], wh[maxn];
int answer[maxn];
int n;
pair2<int> combine(const pair2<int> &a, const pair2<int> &b) {
  if (a.first < a.first + a.second + b.first)
    return {a.first, a.second + b.first + b.second};
  return {a.first + a.second + b.first, b.second};
}
void add(int cur, int cl, int cr, int x, int t) {
  if (cl > x || cr < x) return;
  if (cl == cr) {
    if (t == 1)
      tree[cur] = {0, 1};
    else
      tree[cur] = {-1, 0};
    return;
  }
  int cm = (cl + cr) / 2;
  add(cur * 2, cl, cm, x, t);
  add(cur * 2 + 1, cm + 1, cr, x, t);
  tree[cur] = combine(tree[cur * 2], tree[cur * 2 + 1]);
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &p[i]);
    p[i]--;
    wh[p[i]] = 2 * i;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &q[i]);
    q[i]--;
    q[i] = 2 * q[i] + 1;
  }
  int cur = n - 1;
  for (int i = 0; i < n; i++) {
    while (tree[1].second == 0) {
      add(1, 0, treesize - 1, wh[cur], 1);
      cur--;
    }
    answer[i] = cur + 1;
    add(1, 0, treesize - 1, q[i], -1);
  }
  for (int i = 0; i < n; i++) printf("%d ", answer[i] + 1);
  printf("\n");
  return 0;
}
