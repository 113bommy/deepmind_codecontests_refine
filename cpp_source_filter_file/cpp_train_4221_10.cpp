#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e+9 + 7;
int main() {
  long long n, i = 0, j;
  string s;
  cin >> n;
  for (; n; n /= 16)
    if ((n % 16) == 1) ++i;
  cout << i;
  return 0;
}
