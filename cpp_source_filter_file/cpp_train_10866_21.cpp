#include <bits/stdc++.h>
using namespace std;
int n, m, a[100005], l[100005], r[100005], b, c;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    l[i] = 1 + (a[i] <= a[i - 1] ? l[i - 1] : 0);
  }
  for (int i = n; i >= 1; i--) r[i] = 1 + (a[i] <= a[i + 1] ? r[i + 1] : 0);
  while (m--) {
    cin >> b >> c;
    if (r[b] + l[c] == c - b + 1)
      printf("Yes\n");
    else
      printf("No\n");
  }
}
