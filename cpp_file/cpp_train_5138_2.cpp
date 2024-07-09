#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, count = 0;
  cin >> n;
  int max_i = 200005;
  int counter = 0;
  tuple<long long, long long, long long> data[max_i];
  for (int i = 0; i < n; i++) {
    long long k, a0, x, y, m, t = 0, a = 0;
    cin >> k >> a0 >> x >> y >> m;
    for (int j = 0; j < k; j++) {
      data[counter++] = make_tuple(t, a0, i);
      a = (a0 * x + y) % m;
      if (a < a0 && j != k - 1) {
        t++;
      }
      a0 = a;
    }
    count = max(count, t);
  }
  cout << count << endl;
  sort(data, data + counter);
  for (int i = 0; i < counter; i++) {
    cout << get<1>(data[i]) << " " << get<2>(data[i]) + 1 << endl;
  }
}
