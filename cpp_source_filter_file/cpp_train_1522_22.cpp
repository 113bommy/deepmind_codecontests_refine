#include <bits/stdc++.h>
int p[100000], np;
bool prime[100000];
int x, s;
void dfs(int lev, int m, int c) {
  int i;
  if (c % 2 == 0)
    s += x / m;
  else
    s -= x / m;
  for (i = 0; i <= lev; i++) {
    if ((long long)m * p[i] <= x)
      dfs(i - 1, m * p[i], c + 1);
    else
      break;
  }
  return;
}
int cal2(int a, int k) {
  int i;
  for (i = 0; i < np; i++)
    if (p[i] == k) break;
  x = a;
  s = 0;
  dfs(i - 1, 1, 0);
  return s;
}
int cal(int a, int k) {
  int i;
  for (i = 2; (long long)i * i <= k; i++)
    if (k % i == 0) return 0;
  return cal2(a / k, k);
}
int main() {
  int a, b, k, i, j;
  memset(prime, 0, sizeof(prime));
  np = 0;
  for (i = 2; i < 100000; i++) {
    if (prime[i] == 0) {
      p[np] = i;
      np++;
      for (j = i + i; j < 100000; j++) prime[j] = 1;
    }
  }
  scanf("%d %d %d", &a, &b, &k);
  printf("%d\n", cal(b, k) - cal(a - 1, k));
  return 0;
}
