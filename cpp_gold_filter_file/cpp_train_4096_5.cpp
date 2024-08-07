#include <bits/stdc++.h>
using namespace std;
int arr[25], pos[25], m;
double ans, df, de, rf, re, rs, lf, le, ls;
double go() {
  double ret = 0;
  for (int i = 0; i < m; i++) {
    if (arr[i] == 1)
      ret += le * 2 * de;
    else if (arr[i] == 2)
      ret += lf * 2 * df;
    else {
      for (int j = 0; j < m; j++) {
        double dL = pos[i] - ls, dR = pos[i] + ls;
        if (arr[j] == 1) {
          dL = max(dL, pos[j] - le);
          dR = min(dR, pos[j] + le);
          if (dL <= dR) ret += (dR - dL) * de;
        } else if (arr[j] == 2) {
          dL = max(dL, pos[j] - lf);
          dR = min(dR, pos[j] + lf);
          if (dL <= dR) ret += (dR - dL) * df;
        }
      }
    }
  }
  return ret;
}
int main(void) {
  int nf, ne, ns;
  scanf("%d%d%d", &nf, &ne, &ns);
  scanf("%lf%lf%lf", &rf, &re, &rs);
  lf = rf > 1 ? sqrt(rf * rf - 1) : 0;
  le = re > 1 ? sqrt(re * re - 1) : 0;
  ls = rs > 1 ? sqrt(rs * rs - 1) : 0;
  scanf("%lf%lf", &df, &de);
  for (int i = 0; i < ns; i++) arr[m++] = 0;
  for (int i = 0; i < ne; i++) arr[m++] = 1;
  for (int i = 0; i < nf; i++) arr[m++] = 2;
  for (int i = 0; i < m; i++) pos[i] = i / 2;
  ans = 0;
  do {
    int f = 0;
    for (int i = 0; i + 2 < m; i += 2)
      if (arr[i] > arr[i + 1]) {
        sort(arr + (i + 2), arr + m);
        reverse(arr + (i + 2), arr + m);
        f = 1;
        break;
      }
    if (!f) ans = max(ans, go());
  } while (next_permutation(arr, arr + m));
  printf("%.9f\n", ans);
  return 0;
}
