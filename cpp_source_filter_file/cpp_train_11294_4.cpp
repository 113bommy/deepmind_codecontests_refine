#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int n, a[maxn];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    a[i] -= (n - i + 1);
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i < n; i++)
    if (a[i] == a[i + 1]) {
      puts(":(");
      return 0;
    }
  for (int i = 1; i <= n; i++) printf("%d ", a[i] + n - i + 1);
  return 0;
}
