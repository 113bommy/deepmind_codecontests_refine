#include <bits/stdc++.h>
int main() {
  int n, K;
  scanf("%d%d", &n, &K);
  int tot = (n * n - n) / 2;
  if (tot <= K) {
    printf("no solution\n");
    return 0;
  }
  int x = 0, y = 0;
  for (int i = 0; i < n; i++) {
    printf("%d %d\n", 0, y);
    y += 2;
  }
  return 0;
}
