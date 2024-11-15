#include <bits/stdc++.h>
using namespace std;
bool query(pair<int, int> a, pair<int, int> b) {
  printf("? %d %d %d %d\n", a.first + 1, a.second + 1, b.first + 1,
         b.second + 1);
  fflush(stdout);
  bool ans;
  scanf("%hhd", &ans);
  return ans;
}
bool query(int x1, int y1, int x2, int y2) { return query({x1, y1}, {x2, y2}); }
bool ans[51][51];
int n;
void solve_black() {
  ans[0][0] = 1;
  for (int i = 2; i < n; i += 2)
    ans[0][i] = !ans[0][i - 2] ^ query(0, i - 2, 0, i),
    ans[i][0] = !ans[i - 2][0] ^ query(i - 2, 0, i, 0);
  for (int i = 1; i < n; ++i)
    for (int j = 1 + (!(i & 1)); j < n; j += 2)
      ans[i][j] = !ans[i - 1][j - 1] ^ query(i - 1, j - 1, i, j);
}
void solve_white() {
  ans[0][1] = 0;
  for (int i = 3; i < n; i += 2)
    ans[0][i] = !ans[0][i - 2] ^ query(0, i - 2, 0, i),
    ans[i - 1][1] = !ans[i - 3][1] ^ query(i - 3, 1, i - 1, 1);
  ans[n - 1][1] = !ans[n - 3][1] ^ query(n - 3, 1, n - 1, 1);
  for (int i = 1; i < n; i += 2)
    ans[i][0] = !ans[i + 1][1] ^ query(i, 0, i + 1, 1);
  for (int i = 1; i < n; ++i)
    for (int j = 2 + (!(i & 1)); j < n; j += 2)
      ans[i][j] = !ans[i - 1][j - 1] ^ query(i - 1, j - 1, i, j);
}
void reverse_white() {
  for (int i = 0; i < n; ++i)
    for (int j = !(i & 1); j < n; j += 2) ans[i][j] = !ans[i][j];
}
void check_white() {
  for (int k = 0; k + 3 <= 2 * n - 2; ++k) {
    int cnt = 0;
    for (int _ = (k); _ < (k + 4); ++_) cnt += ans[(_ + 1) / 2][_ / 2];
    if (cnt % 2) continue;
    int r = k + 3;
    if (query((k + 1) / 2, k / 2, (r + 1) / 2, r / 2) !=
        (ans[(k + 1) / 2][k / 2] == ans[(r + 1) / 2][r / 2]))
      reverse_white();
    break;
  }
}
void out() {
  printf("!\n");
  for (int i = (0); i < (n); ++i) {
    for (int j = (0); j < (n); ++j) printf("%d", ans[i][j]);
    printf("\n");
  }
  fflush(stdout);
}
int main() {
  scanf("%d", &n);
  solve_black();
  solve_white();
  check_white();
  out();
}
