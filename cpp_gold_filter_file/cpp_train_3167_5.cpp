#include <bits/stdc++.h>
using namespace std;
int n, m, p;
int a[2 * 100005];
int b[2 * 100005];
map<int, int> m1, m2;
vector<int> ans;
void P(int start) {
  int i, k = 0, j, f = 0;
  m2.clear();
  while (start <= n) {
    k++;
    if (m1[a[start]] != 0) m2[a[start]]++;
    if (m1[a[start]] != 0 && m1[a[start]] >= m2[a[start]]) {
      f++;
    }
    if (k == m) {
      if (f == m) {
        ans.push_back(start - p * (m - 1));
      }
      j = start - p * (m - 1);
      k--;
      if (m1[a[j]] != 0) m2[a[j]]--;
      if (m2[a[j]] < m1[a[j]]) f--;
    }
    start = start + p;
  }
}
int main() {
  scanf("%d %d %d", &n, &m, &p);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= m; i++) {
    scanf("%d", &b[i]);
    m1[b[i]]++;
  }
  for (int i = 1; i <= p; i++) {
    P(i);
  }
  int len = ans.size();
  printf("%d\n", len);
  sort(ans.begin(), ans.end());
  for (int i = 0; i < len; i++) printf("%d ", ans[i]);
  return 0;
}
