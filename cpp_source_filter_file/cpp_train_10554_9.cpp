#include <bits/stdc++.h>
using namespace std;
vector<int> e[111111];
int n, i, x, y;
long long sz[111111], ans;
void dfs(int u, int fa) {
  sz[u] = 1;
  long long tmp = 0;
  for (vector<int>::iterator it = e[u].begin(); it != e[u].end(); it++)
    if (*it != fa) {
      dfs(*it, u);
      tmp += sz[u] * sz[*it];
      sz[u] += sz[*it];
    }
  ans -= tmp * (tmp + 2 * sz[u] * (n - sz[u]));
}
int main() {
  cin >> n;
  for (i = 1; i < n; i++) {
    cin >> x >> y;
    e[x].push_back(y);
    e[y].push_back(x);
  }
  ans = n * (n - 1) / 2;
  ans *= ans;
  dfs(1, 0);
  cout << ans << endl;
}
