#include <bits/stdc++.h>
using namespace std;
int option(int a, int b) { return a > b; }
int main() {
  vector<int> v;
  int n, a, e, max, min;
  cin >> n >> a >> e;
  v.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end(), option);
  for (int i = 0; i < a; i++) {
    max = v[a - 1];
  }
  for (int i = a; i < n; i++) {
    min = v[a];
  }
  cout << max - min;
  return 0;
}
