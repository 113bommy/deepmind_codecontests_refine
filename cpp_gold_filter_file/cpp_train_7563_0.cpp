#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, t, p, v;
  cin >> n;
  n = n + 1;
  v = 0;
  if (n == 1)
    cout << "0" << endl;
  else if (n % 2 == 0) {
    cout << n / 2 << endl;
  } else {
    cout << n << endl;
  }
  return 0;
}
