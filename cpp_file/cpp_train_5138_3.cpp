#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
int n;
int a[3][200111], sz[3];
vector<pair<int, int> > save;
int main() {
  while (scanf("%d", &n) == 1) {
    for (int i = (1), _b = (n); i <= _b; i++) {
      scanf("%d%d", &sz[i], &a[i][1]);
      int x, y, m;
      scanf("%d%d%d", &x, &y, &m);
      for (int j = (2), _b = (sz[i]); j <= _b; j++) {
        a[i][j] = (a[i][j - 1] * (long long)x + y) % m;
      }
    }
    int x = 1, y = 1, res = 0, last = -1, type;
    save.clear();
    while (x <= sz[1] || y <= sz[2]) {
      int cur;
      if (x > sz[1])
        cur = a[type = 2][y++];
      else if (y > sz[2])
        cur = a[type = 1][x++];
      else if (a[1][x] >= last && a[2][y] >= last) {
        if (a[1][x] < a[2][y])
          cur = a[type = 1][x++];
        else
          cur = a[type = 2][y++];
      } else if (a[1][x] >= last)
        cur = a[type = 1][x++];
      else if (a[2][y] >= last)
        cur = a[type = 2][y++];
      else {
        if (a[1][x] < a[2][y])
          cur = a[type = 1][x++];
        else
          cur = a[type = 2][y++];
      }
      if (cur < last) ++res;
      last = cur;
      save.push_back(make_pair(cur, type));
    }
    printf("%d\n", res);
    for (int i = 0, _a = (save.size()); i < _a; i++)
      printf("%d %d\n", save[i].first, save[i].second);
  }
  return 0;
}
