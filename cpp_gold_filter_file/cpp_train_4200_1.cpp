#include <bits/stdc++.h>
int br[100000], bb[100000], c[100000];
int main() {
  int n, m, a, b, i, j, max = 0, k;
  scanf("%i%i%i%i", &n, &m, &a, &b);
  for (i = 0; i < n; i++) scanf("%i", &br[i]);
  i = 0;
  for (j = 0; j < m; j++) {
    scanf("%i", &k);
    while (i < n && br[i] + b < k) i++;
    if (i == n) break;
    if (br[i] - a <= k && br[i] + b >= k) {
      bb[max] = ++i;
      c[max++] = j + 1;
    }
  }
  printf("%i\n", max);
  for (i = 0; i < max; i++) printf("%i %i\n", bb[i], c[i]);
  return 0;
}
