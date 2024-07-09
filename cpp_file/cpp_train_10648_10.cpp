#include <bits/stdc++.h>
const int inf = 1e9;
int a[200005], f[200005], val[200005];
int N;
std ::vector<int> vec[200005];
int ans = 0, mp = 0;
const int blc = sqrt(200005);
int g[200005 * 2];
void add(int x) {
  --val[f[a[x]]];
  ++f[a[x]];
  ++val[f[a[x]]];
  if (val[mp + 1] > 0) {
    ++mp;
  }
}
void mul(int x) {
  --val[f[a[x]]];
  --f[a[x]];
  ++val[f[a[x]]];
  if (val[mp] == 0) {
    --mp;
  }
}
void solve(int x, int y) {
  int cur = N;
  for (int i = 0; i <= 2 * N; ++i) {
    g[i] = inf;
  }
  g[N] = 0;
  for (int i = 1; i <= N; ++i) {
    if (a[i] == x) {
      ++cur;
    }
    if (a[i] == y) {
      --cur;
    }
    if (g[cur] == inf) {
      g[cur] = i;
    } else {
      ans = std ::max(ans, i - g[cur]);
    }
  }
}
int main() {
  std ::cin >> N;
  for (int i = 1; i <= N; ++i) {
    scanf("%d", &a[i]);
    vec[a[i]].push_back(i);
    ++f[a[i]];
  }
  int x = 0;
  for (int i = 1; i <= N; ++i) {
    if (f[i] > f[x]) {
      x = i;
    }
  }
  for (int i = 1; i <= N; ++i) {
    if (x == i) {
      continue;
    }
    if (f[i] == f[x]) {
      std ::cout << N << std ::endl;
      return 0;
    }
  }
  vec[x].push_back(N + 1);
  std ::reverse(vec[x].begin(), vec[x].end());
  vec[x].push_back(0);
  std ::reverse(vec[x].begin(), vec[x].end());
  for (int i = 1; i <= N; ++i) {
    if (i == x) {
      continue;
    }
    if (vec[i].size() > blc) {
      solve(i, x);
    }
  }
  for (int i = 1; i <= std ::min(blc, (int)vec[x].size()); ++i) {
    int l = 1, r = 0;
    for (int j = 1; j <= N; ++j) {
      f[j] = 0;
    }
    mp = 0;
    for (int j = i; j < (int)vec[x].size(); ++j) {
      for (; r < vec[x][j] - 1; add(++r))
        ;
      for (; l < vec[x][j - i] + 1; mul(l++))
        ;
      if (val[mp] >= 2) {
        ans = std ::max(ans, r - l + 1);
      }
    }
  }
  std ::cout << ans;
  return 0;
}
