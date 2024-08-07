#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> tab;
struct Point {
  int x, y;
  int u;
  bool operator<(const Point &b) const {
    if (y == b.y) return u < b.u;
    return y < b.y;
  }
} p[200000 + 10];
int last[200000 + 10], ct[200000 + 10], lastct[200000 + 10];
long long ans[200000 + 10];
int main() {
  scanf("%d%d", &n, &k);
  k--;
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &p[i].x, &p[i].y);
    p[i].u = 1;
    p[i + n].x = p[i].x;
    p[i + n].y = p[i].y + k + 1;
    p[i + n].u = -1;
    tab.push_back(p[i].x);
    tab.push_back(p[i].x + k + 1);
  }
  sort(tab.begin(), tab.end());
  tab.erase(unique(tab.begin(), tab.end()), tab.end());
  sort(p + 1, p + 1 + n * 2);
  for (int i = 1; i <= n * 2; i++) {
    int j = lower_bound(tab.begin(), tab.end(), p[i].x) - tab.begin();
    while (j < tab.size() - 1 && tab[j] < p[i].x + k + 1) {
      ans[ct[j]] += (long long)(p[i].y - last[j]) * (tab[j + 1] - tab[j]);
      ct[j] += p[i].u;
      last[j] = p[i].y;
      j++;
    }
  }
  printf("%I64d", ans[1]);
  for (int i = 2; i <= n; i++) printf(" %I64d", ans[i]);
  printf("\n");
  return 0;
}
