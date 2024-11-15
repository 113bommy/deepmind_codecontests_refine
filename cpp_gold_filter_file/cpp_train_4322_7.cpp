#include <bits/stdc++.h>
using namespace std;
double dp[2010][2010][2][2];
int a[2010];
pair<int, int> le[2010], ri[2010];
int ll[2010][2], rr[2010][2];
int h;
double p, q;
double go(int l, int r, int Li, int Ri) {
  if (l > r) return 0;
  if (dp[l][r][Li][Ri] > -1) {
    return dp[l][r][Li][Ri];
  }
  int L = ll[l][Li], R = rr[r][Ri];
  double res = 0;
  int d;
  if (L < le[l].second) {
    d = h;
  } else {
    d = a[l] - L;
  }
  res += 0.5 * p * (d + go(l + 1, r, 0, Ri));
  if (R > ri[r].second) {
    d = h;
  } else {
    d = R - a[r];
  }
  res += 0.5 * q * (d + go(l, r - 1, Li, 1));
  if (ri[l].second > R) {
    d = R - a[l];
  } else {
    d = ri[l].second - a[l];
  }
  res += 0.5 * q * (d + go(ri[l].first + 1, r, 1, Ri));
  if (le[r].second < L) {
    d = a[r] - L;
  } else {
    d = a[r] - le[r].second;
  }
  res += 0.5 * p * (d + go(l, le[r].first - 1, Li, 0));
  return dp[l][r][Li][Ri] = res;
}
int main() {
  int n;
  scanf("%d%d%lf", &n, &h, &p);
  q = 1 - p;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  sort(a, a + n);
  for (int i = 0; i < n; i++) {
    le[i] = make_pair(0, a[0] - h);
    ri[i] = make_pair(i, a[i] + h);
  }
  for (int i = n - 2; i >= 0; i--) {
    if (a[i] + h > a[i + 1]) {
      ri[i] = ri[i + 1];
    } else {
      ri[i] = make_pair(i, a[i] + h);
    }
  }
  for (int i = 1; i < n; i++) {
    if (a[i] - h < a[i - 1]) {
      le[i] = le[i - 1];
    } else {
      le[i] = make_pair(i, a[i] - h);
    }
  }
  ll[0][0] = ll[0][1] = -1001001001;
  for (int i = 1; i < n; i++) {
    ll[i][0] = a[i - 1];
    ll[i][1] = ri[i - 1].second;
  }
  rr[n - 1][0] = rr[n - 1][1] = 1001001001;
  for (int i = n - 2; i >= 0; i--) {
    rr[i][1] = a[i + 1];
    rr[i][0] = le[i + 1].second;
  }
  for (int i = 0; i < 2010; i++) {
    for (int j = 0; j < 2010; j++) {
      for (int k = 0; k < 2; k++) {
        for (int l = 0; l < 2; l++) {
          dp[i][j][k][l] = -1;
        }
      }
    }
  }
  printf("%.12f\n", go(0, n - 1, 0, 1));
  return 0;
}
