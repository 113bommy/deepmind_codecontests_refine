#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, i, j, sum = 0, m;
  vector<int> v;
  cin >> a;
  m = a / 2 + 1;
  for (i = 1; i <= a; i++) {
    for (j = 1; j <= a; j++) {
      cin >> b;
      if (i == j || i + j == a + 1 || i == m || j == m) v.push_back(b);
    }
  }
  sort(v.begin(), v.end());
  unique((v.begin(), v.end()), v.end());
  for (i = 0; i < v.size(); i++) {
    sum += v[i];
  }
  cout << sum << endl;
  return 0;
}
