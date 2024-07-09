#include <bits/stdc++.h>
using namespace std;
const int MaxN = 10005;
int a[MaxN], b[MaxN];
int N, C;
long long sol(long long d, long long C) {
  long long ret = 0;
  double temp;
  for (int i = 0; i < N; i++) {
    temp = ret + floor(1.0 * a[i] * d / b[i]);
    if (temp > C) return C + 1;
    ret = (long long)(temp + 0.5);
  }
  return ret;
}
long long getA(long long C) {
  long long L = 1, R = 1LL << 60;
  long long mid;
  if (sol(L, C) > C) return L - 1;
  while (L < R) {
    mid = (L + R + 1) >> 1;
    if (sol(mid, C) <= C) {
      L = mid;
    } else {
      R = mid - 1;
    }
  }
  return L;
}
int main() {
  while (scanf("%d%d", &N, &C) == 2) {
    C -= N;
    for (int i = 0; i < N; i++) {
      scanf("%d%d", &a[i], &b[i]);
    }
    printf("%I64d\n", getA(C) - getA(C - 1));
  }
  return 0;
}
