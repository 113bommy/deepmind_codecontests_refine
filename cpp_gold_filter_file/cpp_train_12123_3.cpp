#include <bits/stdc++.h>
using namespace std;
const int Maxn = 3e3 + 5;
int p[Maxn], n, m, k;
bool isv[Maxn];
void dfs(int i) {
  for (int j = i; !isv[j]; j = p[j]) {
    isv[j] = true;
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
  scanf("%d", &m);
  m = n - m;
  for (int i = 1; i <= n; i++)
    if (!isv[i]) {
      dfs(i);
      k++;
    }
  memset(isv, false, sizeof(isv));
  printf("%d\n", (int)abs(m - k));
  if (k > m) {
    dfs(1);
    for (int i = 2; i <= n && k > m; i++) {
      if (!isv[i]) {
        printf("%d %d ", 1, i);
        k--;
        dfs(i);
      }
    }
  }
  if (k < m) {
    for (int i = 1; i <= n && k < m; i++) {
      vector<int> pos(n + 1, -1);
      int cur = 0;
      for (int j = p[i]; j != i; j = p[j]) {
        pos[j] = cur++;
      }
      pos[i] = cur;
      cur = 0;
      for (int j = i + 1; j <= n && k < m; j++) {
        if (pos[j] >= cur) {
          printf("%d %d ", i, j);
          k++;
          cur = pos[j] + 1;
          swap(p[i], p[j]);
        }
      }
    }
  }
  return 0;
}
