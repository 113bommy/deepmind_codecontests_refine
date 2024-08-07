#include <bits/stdc++.h>
using namespace std;
int ans = 1e9, h[15], n, a, b;
vector<int> T, T2;
void dfs(int x, int times) {
  if (times >= ans) return;
  if (x == n) {
    if (h[x] < 0) {
      T2 = T;
      ans = times;
    }
    return;
  }
  for (int i = 0;
       i <= max(h[x - 1] / b + 1, max(h[x] / a + 1, h[x + 1] / b + 1)); i++) {
    if (h[x - 1] < b * i) {
      h[x - 1] -= b * i;
      h[x] -= a * i;
      h[x + 1] -= b * i;
      for (int j = 0; j < i; j++) T.push_back(x);
      dfs(x + 1, times + i);
      for (int j = 0; j < i; j++) T.pop_back();
      h[x - 1] += b * i;
      h[x] += a * i;
      h[x + 1] += b * i;
    }
  }
}
int main() {
  scanf("%d%d%d", &n, &a, &b);
  for (int i = 1; i <= n; i++) scanf("%d", &h[i]);
  dfs(2, 0);
  cout << ans << endl;
  for (int i = 0; i < T2.size(); i++) cout << T2[i] << " ";
  cout << endl;
}
