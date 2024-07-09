#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  long long int t;
  cin >> n >> t;
  vector<long double> a(n);
  vector<long double> b(n);
  vector<long double> p(n);
  long double mxb = 0;
  long double mxa = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i] >> p[i];
    if (b[i] * p[i] > mxb) {
      mxb = b[i] * p[i];
    }
    if (a[i] * p[i] > mxa) {
      mxa = a[i] * p[i];
    }
  }
  long double ans = 0;
  for (int i = 0; i < n; i++) {
    long double currans = 0;
    long double pp = 1 - p[i];
    long double qq = p[i];
    currans =
        qq * (mxb * (pow(pp, t) - t * pp + t - 1) / ((pp - 1) * (pp - 1)));
    currans += qq * (a[i] * (pow(pp, t) - pp) / ((pp - 1) * (pp)));
    currans += pow(pp, t - 1) * mxa;
    ans = max(ans, currans);
  }
  printf("%.15Lf", ans);
  return 0;
}
