#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(3*n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  
  sort(a.begin(), a.begin() + N);
  for (int j = 0; j < (n+2)/3; ++j) a[n] ^= a[i] ^ a[i + n/3] ^ a[i + n/3*2];
  cout << (a[n] ? "No" : "Yes");
  return 0;
}
	