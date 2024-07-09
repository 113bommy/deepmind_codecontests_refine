#include <bits/stdc++.h>
using namespace std;
const int maxint = -1u >> 1;
int b[10];
double l[10];
double A;
int n, k, ha;
double get_dp() {
  double ans = 0.0, B, p, q;
  int sum;
  for (int i = 0; i < (1 << n); i++) {
    B = 0.0;
    sum = 0;
    p = 1;
    for (int j = 0; j < n; j++) {
      if (i & (1 << j))
        p *= l[j];
      else
        p *= (1 - l[j]), sum++, B += b[j];
    }
    if (sum < ha) sum = 0;
    q = A / (A + B);
    if (sum) p *= q;
    ans += p;
  }
  return ans;
}
double ANS;
void dfs(int d, int candy) {
  if (d == n) {
    ANS = max(ANS, get_dp());
    return;
  }
  int r = int(l[d] * 10);
  for (int i = 0; i <= min(10 - r, candy); i++) {
    l[d] += i * 0.1;
    dfs(d + 1, candy - i);
    l[d] -= i * 0.1;
  }
}
int main() {
  scanf("%d %d %lf", &n, &k, &A);
  for (int i = 0; i < n; i++) scanf("%d %lf", b + i, l + i), l[i] /= 100.0;
  ha = n / 2 + n % 2;
  ANS = 0;
  dfs(0, k);
  printf("%.10lf\n", ANS);
  return 0;
}
