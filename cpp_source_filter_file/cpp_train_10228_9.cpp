#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int TESTS = 1;
  cin >> TESTS;
  while (TESTS--) {
    long long n, k;
    cin >> n >> k;
    if (n >= k && n % 2 == k % 2)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
