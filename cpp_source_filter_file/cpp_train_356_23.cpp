#include <bits/stdc++.h>
using namespace std;
int n, k, cur = 0;
double E[2][405];
int main() {
  int i, j;
  scanf("%d %d", &n, &k);
  for (i = n; i >= 1; i--) {
    cur ^= 1;
    for (j = 1; j < 405; j++) {
      E[cur][j] = E[cur ^ 1][j] * (1.0 * j / (j + 1)) + j / 2.0;
      E[cur][j] += (E[cur ^ 1][j + 1] + j) * (1.0 / (j + 1));
      E[cur][j] = E[cur][j] * 1.0 / k + 1.0 * E[cur ^ 1][j] * (k - 1) / k;
    }
  }
  printf("%.9lf", E[cur][1] * k);
  return 0;
}
