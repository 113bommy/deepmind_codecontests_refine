#include <bits/stdc++.h>
using namespace std;
long long a[1000001], n;
int main() {
  cin >> n;
  long long x;
  long long ans, ans1 = 0;
  for (int i = 0; i < n; i++) {
    cin >> x;
    a[x]++;
    if (ans1 <= a[x]) {
      ans1 = a[x];
      ans = x;
    }
  }
  cout << ans << endl;
}
