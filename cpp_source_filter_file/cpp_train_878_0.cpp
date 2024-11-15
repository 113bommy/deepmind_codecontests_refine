#include <bits/stdc++.h>
using namespace std;
struct Box {
  int in, out, w, s, v, id;
  Box() {}
  bool operator<(Box b) const {
    if (in != b.in) return in < b.in;
    ;
    if (-out != -b.out) return -out < -b.out;
    ;
  }
};
vector<Box> v[505];
vector<int> beg[505];
Box a[505];
int ans[505];
int dp[505][1005];
int best(int b, int s) {
  ans[v[b].size()] = 0;
  for (int i = int(v[b].size()) - 1; i >= 0; i--) {
    ans[i] = ans[i + 1];
    int val = v[b][i].v, w = v[b][i].w, st = v[b][i].s, id = v[b][i].id,
        out = v[b][i].out;
    if (s >= w) {
      int Next =
          lower_bound(beg[b].begin(), beg[b].end(), out) - beg[b].begin();
      ans[i] = max(ans[i], val + dp[id][min(s - w, st)] + ans[Next]);
    }
  }
  return ans[0];
}
int main() {
  int n, S;
  cin >> n >> S;
  a[0].in = 0;
  a[0].out = 2 * n;
  a[0].w = 0;
  a[0].s = S;
  a[0].v = 0;
  n++;
  for (int i = 1; i < n; i++)
    cin >> a[i].in >> a[i].out >> a[i].w >> a[i].s >> a[i].v;
  sort(a, a + n);
  for (int i = 0; i < n; i++) a[i].id = i;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++)
      if (a[j].out <= a[i].out) {
        v[i].push_back(a[j]);
        beg[i].push_back(a[j].in);
      }
  }
  for (int s = 1; s <= S; s++)
    for (int i = n - 1; i >= 0; i--) dp[i][s] = best(i, s);
  cout << dp[0][S] << endl;
  return 0;
}
