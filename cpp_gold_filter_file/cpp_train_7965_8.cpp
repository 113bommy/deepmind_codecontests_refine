#include <bits/stdc++.h>
using namespace std;
long long n, m1, m2, count_a, count_b, count_A, count_B, i, ans;
string s;
int main() {
  cin >> n;
  int a[n];
  for (i = 0; i < n; i++) cin >> a[i];
  cin >> s;
  for (i = 0; i < n; i++)
    if (s[i] == 'A')
      count_A += a[i];
    else
      count_B += a[i];
  ans = max(count_B, count_A);
  for (i = 0; i < n; i++) {
    if (s[i] == 'A')
      count_a += a[i];
    else
      count_b += a[i];
    m1 = count_a - count_b + count_B;
    m2 = count_b - count_a + count_A;
    ans = max(ans, max(m1, m2));
  }
  cout << ans;
  return 0;
}
