#include <bits/stdc++.h>
using namespace std;
long long A[100005];
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
int main() {
  long long n;
  long long i;
  cin >> n;
  for (i = 0; i < n; i++) cin >> A[i];
  sort(A, A + n);
  long long g, s, num;
  s = num = 0;
  for (i = 0; i < n; i++) {
    s += A[i] * i - num;
    num += A[i];
  }
  s = s * 2;
  s += num;
  g = gcd(s, n);
  cout << s / g << " " << n / g << endl;
  return 0;
}
