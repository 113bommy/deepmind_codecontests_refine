#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10;
bool flag[2000010];
int a[maxn], b[2 * maxn];
int n, m, cc;
int main() {
  for (int i = 2; i <= 2000000; i++)
    if (!flag[i]) {
      b[cc++] = i;
      for (int j = i * 2; j <= 2000000; j += i) flag[j] = 1;
    }
  scanf("%d%d", &n, &m);
  m--;
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  sort(a, a + n);
  if (m == 1) {
    printf("0\n");
    return 0;
  }
  if (a[0] == 1) {
    printf("1\n");
    return 0;
  }
  for (int i = 0, j = 0; i < n; i++)
    if (a[i] == b[j]) {
      if (b[j] + (b[j] & 1) >= m) {
        printf("%d\n", j + 1);
        return 0;
      }
      j++;
    }
  printf("-1\n");
}
