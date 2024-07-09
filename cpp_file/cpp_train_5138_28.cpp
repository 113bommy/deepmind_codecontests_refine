#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, count = 0, ret = 0;
  cin >> n;
  vector<tuple<long long, long long, long long>> data;
  for (int i = 0; i < n; i++) {
    long long k, a0, x, y, m, t = 0, a = 0;
    cin >> k >> a0 >> x >> y >> m;
    for (int j = 0; j < k; j++) {
      data.push_back(make_tuple(t, a0, i));
      a = (a0 * x + y) % m;
      if (a < a0 && j != k - 1) {
        t++;
      }
      a0 = a;
    }
    ret = max(ret, t);
  }
  cout << ret << endl;
  sort(data.begin(), data.end());
  for (int i = 0; i < data.size(); i++) {
    cout << get<1>(data[i]) << " " << get<2>(data[i]) + 1 << endl;
  }
}
