#include <bits/stdc++.h>
using namespace std;
const int N = 1100;
int n, m, l[N], u[N], dd, ll;
double d[N][N], p = 1;
vector<pair<int, int> > el;
vector<int> eld;
int main() {
  int i, j, x;
  cin >> n >> m;
  for (i = 1; i <= m; ++i) {
    cin >> l[i];
    for (j = 1; j <= l[i]; ++j) {
      cin >> x;
      el.push_back(pair<int, int>(x, i));
    }
  }
  sort(el.begin(), el.end());
  dd = el[el.size() - n].first;
  for (i = el.size() - 1; el[i].first != dd; --i) {
    p = p * (u[el[i].second] + 1) / (l[el[i].second] ? l[el[i].second] : 1);
    ++u[el[i].second];
    --l[el[i].second];
  }
  ll = i - el.size() + n + 1;
  for (; i >= 0 && el[i].first == dd; --i) eld.push_back(el[i].second);
  d[0][0] = p;
  for (j = 0; j < eld.size(); ++j)
    for (i = 0; i <= j; ++i) {
      d[i + 1][j + 1] += d[i][j] * (i + 1.0) / (j + 1.0) * (u[eld[j]] + 1) /
                         (l[eld[j]] ? l[eld[j]] : 1);
      d[i][j + 1] += d[i][j] * (j - i + 1.0) / (j + 1.0);
    }
  cout << setprecision(10) << fixed << d[ll][eld.size()];
  return 0;
}
