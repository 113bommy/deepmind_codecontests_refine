#include <bits/stdc++.h>
using namespace std;
int n;
int x[1000000];
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> x[i];
  sort(x, x + n);
  int sol = x[n - 1] - x[0];
  int p = n / 2 - 1;
  for (int i = 0; i <= p; i++) sol = min(sol, x[n - 1 - (p - i)] - x[i]);
  cout << sol << endl;
}
