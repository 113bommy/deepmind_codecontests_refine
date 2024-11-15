#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const long long inf = 1e9 + 5;
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
  int n, p, idx = -1;
  bool ch = 0;
  string s;
  char c, mx;
  cin >> n >> p >> s;
  mx = 'a' + p - 1;
  for (int i = n - 1; i >= 0; i--) {
    c = s[i];
    bool bad;
    for (char j = c + 1; j <= mx; j++) {
      bad = 0;
      if (i - 1 >= 0 && s[i - 1] == j) bad = 1;
      if (i - 2 >= 0 && s[i - 2] == j) bad = 1;
      string bs = s;
      bs[i] = j;
      for (int k = i + 1; k < n; k++) {
        char tmp = 'a';
        while ((k - 1 >= 0 && bs[k - 1] == tmp) ||
               (k - 2 >= 0 && bs[k - 2] == tmp))
          tmp++;
        if (tmp > mx) {
          bad = 1;
          break;
        }
        bs[k] = tmp;
      }
      if (!bad) {
        idx = 1;
        s = bs;
        break;
      }
    }
    if (idx != -1) break;
  }
  if (idx == -1) {
    cout << "NO" << endl;
    return 0;
  }
  cout << s << endl;
  return 0;
}
