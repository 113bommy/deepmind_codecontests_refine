#include <bits/stdc++.h>
using namespace std;
long long A[3], B[3], N, t, lv[100001][3], mx, tt;
int main() {
  for (int i = 0; i < 3; ++i) scanf("%d", &A[i]);
  for (int i = 0; i < 3; ++i) scanf("%d", &B[i]);
  scanf("%I64d", &N);
  for (int i = 1; i <= N; ++i) {
    scanf("%I64d", &t);
    tt = t;
    if (i - A[0] >= 1 && lv[i - A[0]][0] > t) t = lv[i - A[0]][0];
    t += B[0];
    lv[i][0] = t;
    if (i - A[1] >= 1 && lv[i - A[1]][1] > t) t = lv[i - A[1]][1];
    t += B[1];
    lv[i][1] = t;
    if (i - A[2] >= 1 && lv[i - A[2]][2] > t) t = lv[i - A[2]][2];
    t += B[2];
    lv[i][2] = t;
    t -= tt;
    if (mx < t) mx = t;
  }
  printf("%I64d", mx);
  return 0;
}
