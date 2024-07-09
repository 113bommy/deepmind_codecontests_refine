#include <bits/stdc++.h>
using namespace std;
long long Digits(long long a) { return (floor(log10(a)) + 1); }
long long BMod(long long B, long long P, long long M) {
  long long R = 1;
  B = B % M;
  while (P) {
    if (P & 1) R = (R * B) % M;
    P >>= 1;
    B = (B * B) % M;
  }
  return R;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long a, b;
  cin >> a >> b;
  long long sum = a + b;
  cout << sum;
}
