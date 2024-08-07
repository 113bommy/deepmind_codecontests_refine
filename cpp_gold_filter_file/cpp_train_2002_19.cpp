#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
const int N = 500;
int a[N][N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<string> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    for (int j = 0; j < m; j++) {
      a[i][j] = (s[i][j] == '1');
    }
  }
  long long ans = 0;
  for (int l = 0; l < n; l++) {
    vector<int> mid(m);
    vector<int> vl(m), vr(m);
    for (int r = l + 2; r < n; r++) {
      for (int j = 1; j + 1 < m; j++) {
        if (a[r - 2][j] && a[r - 1][j] && a[r][j] && a[r - 1][j - 1] &&
            a[r - 1][j + 1]) {
          mid[j]++;
        }
      }
      auto x = mid;
      x.erase(x.begin());
      x.pop_back();
      vector<int> p(x.size() + 1);
      int s = 0;
      for (int i = 0; i < (int)x.size(); i++) {
        s += x[i];
        p[i + 1] = s;
      }
      for (int l = 0; l < (int)x.size(); l++) {
        int vl = l, vr = (int)p.size();
        while (vl < vr - 1) {
          int vm = (vl + vr) / 2;
          if (p[vm] - p[l] >= k) {
            vr = vm;
          } else {
            vl = vm;
          }
        }
        ans += (int)p.size() - vr;
      }
    }
  }
  cout << ans << endl;
}
