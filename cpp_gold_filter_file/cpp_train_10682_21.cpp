#include <bits/stdc++.h>
using namespace std;
int main() {
  long n, k, t;
  cin >> n >> k >> t;
  if (t <= k)
    cout << t;
  else if (t > k and t <= n) {
    cout << k;
  } else if (t > n)
    cout << k - t + n;
}
