#include <bits/stdc++.h>
using namespace std;
int n, a[300010], res[300010][55];
int dp(int id, int cs) {
  if (id == n) return 0;
  if (res[id][cs] != -1) return res[id][cs];
  int tk = min(cs, a[id]);
  int w = a[id] - tk + dp(id + 1, cs - tk);
  if (cs < 50) w = min(w, a[id] + dp(id + 1, cs + a[id] / 10));
  return res[id][cs] = w;
}
int main() {
  memset(res, -1, sizeof(res));
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    a[i] /= 100;
  }
  printf("%d00\n", dp(0, 0));
}
