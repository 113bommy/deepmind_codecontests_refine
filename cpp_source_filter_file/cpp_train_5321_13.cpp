#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
const int MAXN = 1007;
const double EPS = 1e-8;
void solve() {
  int n;
  cin >> n;
  double c, tm;
  cin >> c >> tm;
  vector<pair<int, int> > a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  sort(a.rbegin(), a.rend());
  double dp[n + 1][n * 10 + 7];
  for (int j = 0; j <= n; j++) {
    for (int k = 0; k <= n * 10; k++) {
      dp[j][k] = INF;
    }
  }
  dp[0][0] = 0.0;
  vector<double> coefs(1, 1.0);
  for (int i = 0; i < MAXN; i++) {
    coefs.push_back(coefs.back() * 0.9);
  }
  for (int i = 0; i < n; i++) {
    int add = a[i].second, diff = a[i].first;
    for (int cnt = n; cnt >= 0; cnt--) {
      for (int sum = n * 10; sum >= 0; sum--) {
        if (dp[cnt][sum] == INF) continue;
        dp[cnt + 1][sum + add] =
            min(dp[cnt + 1][sum + add],
                dp[cnt][sum] + (1.0 / coefs[cnt + 1]) * (double)diff);
      }
    }
  }
  for (int sum = n * 10; sum >= 0; sum--) {
    double mink = INF;
    for (int cnt = 0; cnt <= n; cnt++) {
      mink = dp[cnt][sum];
      if (abs(mink - INF) < EPS) continue;
      double lt = 0, rt = tm - 10.0 * cnt;
      if (rt < 0) continue;
      for (int i = 0; i < 100; i++) {
        double m1 = lt + (rt - lt) / 3;
        double m2 = m1 + (rt - lt) / 3;
        if (mink / (1 + c * m1) + m1 < mink / (1 + c * m2) + m2) {
          rt = m2;
        } else {
          lt = m1;
        }
      }
      double val = mink / (1 + c * lt) + lt + 10.0 * cnt;
      if (val < tm + EPS) {
        cout << sum << "\n";
        return;
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout.precision(20);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }
}
