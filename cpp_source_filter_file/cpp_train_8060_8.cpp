#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  cin >> n >> k;
  long long a[n];
  for (long long i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  cout << a[n - k + 1];
  return 0;
}
