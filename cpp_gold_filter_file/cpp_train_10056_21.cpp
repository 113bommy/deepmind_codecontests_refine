#include <bits/stdc++.h>
using namespace std;
vector<long long> vec;
int n;
vector<int> a, b, res;
bool possible(int t) {
  int tinit = t;
  vector<int> aux = a, bux = b;
  if (aux[0] < t) {
    return false;
  }
  bux[1] += aux[0] - t;
  for (int i = 1; i < 41; i++) {
    if (bux[i] > t) {
      return false;
    }
    if (aux[i] > t) {
      bux[i + 1] += aux[i] - t;
    } else if (aux[i] < t) {
      bux[i] -= t - aux[i];
      bux[i] = max(bux[i], 0);
      t = aux[i];
    }
    bux[i + 1] += bux[i];
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  vec.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> vec[i];
  }
  a.resize(42);
  b.resize(42);
  for (int i = 0; i < 42; i++) {
    a[i] = 0;
    b[i] = 0;
  }
  int pot = 0;
  for (int i = 0; i < vec.size(); i++) {
    while (vec[i] > (1LL << pot)) {
      pot++;
    }
    if (vec[i] == (1LL << pot)) {
      a[pot]++;
    } else {
      b[pot]++;
    }
  }
  res.clear();
  for (int i = 1; i <= n; i++) {
    if (possible(i)) {
      res.push_back(i);
    }
  }
  if (res.empty()) {
    cout << -1 << endl;
  } else {
    for (int i = 0; i < res.size(); i++) {
      if (i == res.size() - 1) {
        cout << res[i] << endl;
      } else {
        cout << res[i] << " ";
      }
    }
  }
  return 0;
}
