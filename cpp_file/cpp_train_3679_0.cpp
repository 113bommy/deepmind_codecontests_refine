#include <bits/stdc++.h>
using namespace std;
vector<bool> bittify(const char *s) {
  int n = strlen(s);
  vector<bool> bits;
  bits.reserve(n);
  for (int i = 0; i < (n); ++i) bits.push_back(s[i] == 'b');
  return bits;
}
void multiply(long long a[2][2], long long b[2][2]) {
  long long c[2][2] = {0LL};
  for (int i = 0; i < (2); ++i)
    for (int j = 0; j < (2); ++j)
      for (int k = 0; k < (2); ++k)
        c[i][j] = (c[i][j] + (a[i][k] * b[k][j]) % 1000000007) % 1000000007;
  for (int i = 0; i < (2); ++i)
    for (int j = 0; j < (2); ++j) a[i][j] = c[i][j];
}
map<long long, long long> fibcache;
long long fibonacci(const long long &n) {
  if (n <= 0)
    return 0LL;
  else if (n <= 2)
    return 1LL;
  else if (fibcache.find(n) != fibcache.end())
    return fibcache[n];
  else {
    long long f[2][2] = {{1LL, 1LL}, {1LL, 0LL}};
    long long x[2][2] = {{1LL, 0LL}, {0LL, 1LL}};
    long long nn = n - 1LL, m = 0;
    for (int i = 62; i >= 0; --i) {
      m <<= 1;
      multiply(x, x);
      if (m) fibcache[m + 1] = x[0][0];
      if (nn & (1LL << i)) {
        m |= 1LL;
        multiply(x, f);
        fibcache[m + 1] = x[0][0];
      }
    }
    return x[0][0];
  }
}
void replace(const vector<bool> &b, vector<bool> &b1, vector<bool> &b2) {
  b1.clear();
  b2.clear();
  int n = b.size(), two = false;
  int zeros = 0, ones = 0;
  for (int i = 0; i < (n); ++i) {
    if (b[i])
      ++ones, zeros = 0;
    else
      ++zeros, ones = 0;
    if (ones >= 3 || zeros >= 2) return;
  }
  for (int i = 0; i < (n); ++i) {
    if (b[i]) {
      if (i < n - 1) {
        if (b[i + 1])
          b1.push_back(0);
        else
          b1.push_back(1), ++i;
      } else
        b1.push_back(0), two = true;
    } else
      b1.push_back(1);
  }
  if (two) {
    b2 = b1;
    b2[b1.size() - 1] = 1;
  }
}
char *str(const vector<bool> &b) {
  char *s = new char[b.size() + 1];
  memset(s, 0, (b.size() + 1) * sizeof(char));
  for (int i = 0; i < (b.size()); ++i) s[i] = b[i] ? 'b' : 'a';
  return s;
}
inline bool operator<(const vector<bool> &a, const vector<bool> &b) {
  if (a.size() != b.size()) return a.size() < b.size();
  for (int i = 0; i < (a.size()); ++i)
    if (a[i] != b[i]) return a[i] < b[i];
  return false;
}
map<pair<vector<bool>, int>, long long> calccache;
long long calculate(const vector<bool> &b, const int &k) {
  if (k < 1 || b.empty())
    return 0LL;
  else if (b.size() == 1) {
    if (b[0])
      return fibonacci(k - 1);
    else
      return fibonacci(k - 2) + (k == 1);
  } else {
    pair<vector<bool>, int> id(b, k);
    if (calccache.find(id) != calccache.end())
      return calccache[id];
    else {
      vector<bool> b1, b2;
      replace(b, b1, b2);
      long long r1 = calculate(b1, k - 1);
      long long r2 = calculate(b2, k - 1);
      return calccache[id] = (r1 + r2) % 1000000007;
    }
  }
}
int main() {
  int k, m;
  char str[100000 + 2];
  for (scanf("%d%d", &k, &m); m--;) {
    scanf("%s", str);
    vector<bool> bitstr = bittify(str);
    long long ans = calculate(bitstr, k);
    printf("%I64d\n", ans);
  }
  return 0;
}
