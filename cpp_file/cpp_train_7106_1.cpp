#include <bits/stdc++.h>
using namespace std;
bool sortinrev(const pair<long long, long long> &a,
               const pair<long long, long long> &b) {
  return (a.first > b.first);
}
unsigned long long fac(unsigned long long n, long long x) {
  long long res = 1, i;
  for (i = 2; i <= n; i++) {
    res *= i;
    res %= x;
  }
  return res % x;
}
long long powM(long long x, long long y, long long m) {
  long long ans = 1, r = 1;
  x %= m;
  while (r > 0 && r <= y) {
    if (r & y) {
      ans *= x;
      ans %= m;
    }
    r <<= 1;
    x *= x;
    x %= m;
  }
  return ans;
}
bool isSubseq(vector<long long> v, vector<long long> w) {
  long long x = v.size(), y = w.size();
  long long j, i;
  for (j = 0, i = 0; i < x && j < y; i++) {
    if (w[j] == v[i]) {
      j++;
    }
  }
  if (j < y) {
    return 0;
  } else {
    return 1;
  }
}
bool opp(long long x, long long y) { return ((x ^ y) < 0); }
bool isPowerOfTwo(long long x) { return (x && !(x & (x - 1))); }
bool isPrime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
long long gcd(long long v, long long b) {
  if (b == 0) return v;
  return gcd(b, v % b);
}
long long maxSubArraySum(long long v[], long long size) {
  long long max_so_far = v[0];
  long long curr_max = v[0];
  for (long long i = 1; i < size; i++) {
    curr_max = max(v[i], curr_max + v[i]);
    max_so_far = max(max_so_far, curr_max);
  }
  return max_so_far;
}
long long sum(long long n) {
  long long v = 0;
  while (n != 0) {
    v += (n % 10);
    n /= 10;
  }
  return v;
}
void ans() {
  long long n, m;
  cin >> n >> m;
  long long a[n], b[m];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (long long i = 0; i < m; i++) {
    cin >> b[i];
  }
  vector<long long> v;
  for (long long i = 0; i < n; i++) {
    long long x = INT_MAX;
    for (long long j = 0; j < m; j++) {
      x = min(x, a[i] & b[j]);
    }
    v.push_back(x);
  }
  sort(v.begin(), v.end(), greater<long long>());
  long long c = v[0];
  for (long long i = 0; i < n; i++) {
    long long x = INT_MAX;
    for (long long j = 0; j < m; j++) {
      long long r = a[i] & b[j];
      x = min(x, c | r);
    }
    c |= x;
  }
  cout << c;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ans();
  return 0;
}
