#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
  int n;
  cin >> n;
  vector<int> v;
  int j = 1;
  int c = 1;
  for (int i = 1; i < n; i++) {
    int k = (c + j) % n;
    v.push_back(k);
    c = k;
    j++;
  }
  for (auto &e : v) {
    cout << e << " ";
  }
  cout << endl;
}
