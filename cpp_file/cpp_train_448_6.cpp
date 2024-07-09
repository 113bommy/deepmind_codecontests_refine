#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; ++i) cin >> A[i];
  int m = 0;
  for (int i = 0; i < n - 1; ++i) {
    m += A[i];
    cout << m << "\n";
    int t = log2(n - i - 1);
    A[i + pow(2, t)] += A[i];
  }
  return 0;
}
