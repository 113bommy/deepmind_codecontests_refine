#include <bits/stdc++.h>
int main() {
  int n, r;
  scanf("%d%d", &n, &r);
  long long int sum = 0;
  int v[2000000];
  int sz = (1 << n);
  for (int i = 0; i < sz; i++) {
    scanf("%d", v + i);
    sum += v[i];
  }
  double ans = sum;
  printf("%.10lf\n", ans / sz);
  for (int i = 0; i < r; i++) {
    int idx, c;
    scanf("%d%d", &idx, &c);
    sum += c - v[idx];
    v[idx] = c;
    ans = sum;
    printf("%.10lf\n", ans / sz);
  }
  return 0;
}
