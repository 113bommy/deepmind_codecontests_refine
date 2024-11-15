#include <bits/stdc++.h>
int N, x, i, j, flag;
int Mul(int x, int y, int p) {
  int z = 1;
  for (; y; y >>= 1) {
    if (y & 1) z = (long long)z * x % p;
    x = (long long)x * x % p;
  }
  return z;
}
int main() {
  scanf("%d%d", &N, &x);
  for (i = 2; i * i <= N + 1; ++i)
    if ((N + 1) % i == 0) {
      printf("-1\n");
      return 0;
    }
  for (i = x - 1; i; --i) {
    flag = 1;
    for (j = 2; j * j <= N; ++j)
      if (N % j == 0) {
        if (Mul(i, j, N + 1) == 1) {
          flag = 0;
          break;
        }
        if (Mul(i, N / j, N + 1) == 1) {
          flag = 0;
          break;
        }
      }
    if (flag) {
      printf("%d\n", i);
      return 0;
    }
  }
  printf("-1\n");
  return 0;
}
