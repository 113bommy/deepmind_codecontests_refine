#include <bits/stdc++.h>
using namespace std;
struct node {
  int lengh, cost;
} a[100010];
int n, b[205], ans;
int k, sum, z, g, x;
bool cmp(node x, node y) { return x.lengh > y.lengh; }
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i].lengh);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i].cost);
    b[a[i].cost]++;
  }
  sort(a, a + n, cmp);
  ans = 10000000000;
  x = 0;
  for (int i = 0; i < n; i++) {
    sum = a[i].cost;
    b[a[i].cost]--;
    g = 1;
    z = 0;
    while (a[i].lengh == a[i + 1].lengh) {
      i++;
      sum += a[i].cost;
      b[a[i].cost]--;
      g++;
    }
    k = max(0, n - i - g);
    for (int j = 1; j <= 200; j++) {
      z += min(k, b[j]) * j;
      k -= min(k, b[j]);
    }
    ans = min(ans, x + z);
    x += sum;
  }
  printf("%d", ans);
  return 0;
}
