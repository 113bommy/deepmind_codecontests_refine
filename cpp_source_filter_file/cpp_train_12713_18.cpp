#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  cin >> n >> k;
  cout << (2 * n + k - 1) / k + (5 * n + k - 1) + (8 * n + k - 1);
  return 0;
}
