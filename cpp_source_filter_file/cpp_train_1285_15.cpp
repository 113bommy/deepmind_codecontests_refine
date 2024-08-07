#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const long long inf = 1e18 + 5;
const long long MX = 303030;
int cox[4] = {1, -1, 0, 0};
int coy[4] = {0, 0, 1, -1};
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
long long leastbit(long long a) { return a & (-a); }
long long C(int a, int b) {
  long long res = 1;
  for (int i = 0; i < b; i++) res = res * (a - i) / (i + 1);
  return res;
}
long long powmod(long long a, long long b) {
  if (b == 0) return 1;
  long long cnt = powmod(a, b / 2);
  (cnt *= cnt) %= mod;
  if (b & 1) {
    (cnt *= a) %= mod;
  }
  return cnt;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long k, b, n, t, num = 1;
  cin >> k >> b >> n >> t;
  while (num < t) {
    num = num * k + b;
    n--;
  }
  cout << max(0ll, n + 1) << endl;
  return 0;
}
