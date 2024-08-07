#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000")
using namespace std;
const long double pi = acos(-1.0);
const int N = 2500;
int s[N + 1][N + 1], n, m, K, upbarrier[7], downbarrier[7];
char ch;
long long ans = 0, res = 0;
inline int sum(int x1, int x2, int y1, int y2) {
  return s[x2][y2] - s[x1][y2] - s[x2][y1] + s[x1][y1];
}
void go(int x1, int x2, int y1, int y2, bool dir) {
  if ((x1 == x2) || (y1 == y2)) return;
  if ((x1 + 1 == x2) && (y1 + 1 == y2)) {
    ans += (int)(sum(x1, x2, y1, y2) == K);
    return;
  }
  if (dir) {
    int m = (x1 + x2) / 2;
    go(x1, m, y1, y2, !dir);
    go(m, x2, y1, y2, !dir);
    for (int i = y1; i < y2; ++i) {
      downbarrier[0] = upbarrier[0] = m;
      for (int k = 1; k <= K + 1; ++k) {
        upbarrier[k] = x1;
        downbarrier[k] = x2;
      }
      for (int j = i + 1; j <= y2; ++j) {
        for (int k = 1; k <= K + 1; ++k) {
          while (sum(upbarrier[k], m, i, j) >= k) ++upbarrier[k];
        }
        for (int k = 1; k <= K + 1; ++k) {
          while (sum(m, downbarrier[k], i, j) >= k) --downbarrier[k];
        }
        for (int k = 0; k <= K; ++k)
          ans += (upbarrier[k] - upbarrier[k + 1]) *
                 (downbarrier[K - k + 1] - downbarrier[K - k]);
      }
    }
  } else {
    int m = (y1 + y2) / 2;
    go(x1, x2, y1, m, !dir);
    go(x1, x2, m, y2, !dir);
    for (int i = x1; i < x2; ++i) {
      downbarrier[0] = upbarrier[0] = m;
      for (int k = 1; k <= K + 1; ++k) {
        upbarrier[k] = y1;
        downbarrier[k] = y2;
      }
      for (int j = i + 1; j <= x2; ++j) {
        for (int k = 1; k <= K + 1; ++k) {
          while (sum(i, j, upbarrier[k], m) >= k) ++upbarrier[k];
        }
        for (int k = 1; k <= K + 1; ++k) {
          while (sum(i, j, m, downbarrier[k]) >= k) --downbarrier[k];
        }
        for (int k = 0; k <= K; ++k)
          ans += (upbarrier[k] - upbarrier[k + 1]) *
                 (downbarrier[K - k + 1] - downbarrier[K - k]);
      }
    }
  }
}
int main() {
  double start = clock();
  scanf("%d%d%d", &n, &m, &K);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      scanf(" %c", &ch);
      s[i + 1][j + 1] = s[i + 1][j] + s[i][j + 1] - s[i][j] + (ch - '0');
    }
  go(0, n, 0, m, false);
  printf("%I64d\n", ans);
  return 0;
}
