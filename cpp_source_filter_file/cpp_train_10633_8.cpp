#include <bits/stdc++.h>
using namespace std;
int a[501][501], b[501][501];
int main(int argc, char **argv) {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &b[i][j]);
    }
  }
  for (int s = 0; s <= n - 1 + m - 1; s++) {
    multiset<int> sa, sb;
    for (int i = 0; i < n; i++) {
      int j = s - i;
      if (j >= 0) {
        sa.insert(a[i][j]);
        sb.insert(b[i][j]);
      }
    }
    if (sa != sb) {
      puts("NO");
      return 0;
    }
  }
  puts("YES");
  return 0;
}
