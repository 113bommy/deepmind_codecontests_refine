#include <bits/stdc++.h>
const int N = 100010;
const int inf = 0x3f3f3f3f;
using namespace std;
int a[N], b[N], c[N], d[N];
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < m; i++) scanf("%d%d%d", a + i, b + i, c + i);
  long long ret = 0;
  for (int i = 0; i < k; i++) {
    scanf("%d", d + i);
    for (int j = 0; j < m; j++) {
      if (a[j] <= d[i] && d[i] <= b[j]) ret += c[j] + d[i] - a[j];
    }
  }
  cout << ret << endl;
  return 0;
}
