#include <bits/stdc++.h>
using namespace std;
long long max(long long a, long long b) {
  if (a > b) return a;
  return b;
}
long long factors(long long n) {
  long long k = sqrt(n), ans = 0;
  for (long long i = 1; i * i < n; ++i)
    if (!(n % i)) ans += 2;
  if (k * k == n) ++ans;
  return ans;
}
vector<long long> pFactors(long long n) {
  vector<long long> v;
  if (n % 2 == 0) {
    v.push_back(2);
    n /= 2;
  }
  for (long long j = 3; j * j <= n; j += 2)
    if (n % j == 0) {
      v.push_back(j);
      n /= j;
    }
  if (n > 1) v.push_back(n);
  return v;
}
long long maxNum(long long n) {
  long long k = n;
  while (k * n <= 1000000000) k *= n;
  return k;
}
bool sieve[632];
vector<int> primes;
void solve() {
  long long cur = 1, n = 1, x;
  for (auto i : {2, 5, 7, 11, 13, 17, 19, 23, 29, 31, 53, 59, 61, 67}) cur *= i;
  cout << "? " << cur << endl;
  cin >> x;
  n *= x;
  cur = 1;
  for (auto i : {37, 41, 43, 47, 71, 73, 79, 83, 89, 107}) cur *= i;
  cout << "? " << cur << endl;
  cin >> x;
  n *= x;
  cur = 1;
  for (auto i : {97, 101, 103, 109, 113, 127, 673, 677}) cur *= i;
  cout << "? " << cur << endl;
  cin >> x;
  n *= x;
  cur = 1;
  for (auto i : {131, 137, 139, 149, 151, 157, 163, 167}) cur *= i;
  cout << "? " << cur << endl;
  cin >> x;
  n *= x;
  cur = 1;
  for (auto i : {173, 179, 181, 191, 653, 659, 661}) cur *= i;
  cout << "? " << cur << endl;
  cin >> x;
  n *= x;
  cur = 1;
  for (auto i : {193, 197, 199, 211, 641, 643, 647}) cur *= i;
  cout << "? " << cur << endl;
  cin >> x;
  n *= x;
  cur = 1;
  for (int i = 0; i < 7; ++i) cur *= primes[i];
  cout << "? " << cur << endl;
  cin >> x;
  n *= x;
  cur = 1;
  for (int i = 7; i < 14; ++i) cur *= primes[i];
  cout << "? " << cur << endl;
  cin >> x;
  n *= x;
  cur = 1;
  for (int i = 14; i < 20; ++i) cur *= primes[i];
  cout << "? " << cur * 3 << endl;
  cin >> x;
  n *= x;
  cur = 1;
  for (int i = 20; i < 26; ++i) cur *= primes[i];
  cout << "? " << cur << endl;
  cin >> x;
  n *= x;
  cur = 1;
  for (int i = 26; i < 32; ++i) cur *= primes[i];
  cout << "? " << cur << endl;
  cin >> x;
  n *= x;
  cur = 1;
  for (int i = 32; i < 38; ++i) cur *= primes[i];
  cout << "? " << cur << endl;
  cin >> x;
  n *= x;
  cur = 1;
  for (int i = 38; i < 44; ++i) cur *= primes[i];
  cout << "? " << cur << endl;
  cin >> x;
  n *= x;
  cur = 1;
  for (int i = 44; i < 50; ++i) cur *= primes[i];
  cout << "? " << cur << endl;
  cin >> x;
  n *= x;
  cur = 1;
  for (int i = 50; i < 56; ++i) cur *= primes[i];
  cout << "? " << cur << endl;
  cin >> x;
  n *= x;
  cur = 1;
  for (int i = 56; i < 62; ++i) cur *= primes[i];
  cout << "? " << cur << endl;
  cin >> x;
  n *= x;
  cur = 1;
  for (int i = 62; i < 68; ++i) cur *= primes[i];
  cout << "? " << cur << endl;
  cin >> x;
  n *= x;
  cur = 1;
  vector<long long> primeF = pFactors(n);
  n = 1;
  cur = (int)(primeF).size();
  for (int i = 1; i < cur; i += 2) {
    cout << "? " << maxNum(primeF[i - 1]) * maxNum(primeF[i]) << endl;
    cin >> x;
    n *= x;
  }
  if (cur % 2) {
    cout << "? " << maxNum(primeF[cur - 1]) << endl;
    cin >> x;
    n *= x;
  }
  n = factors(n);
  cout << "! " << max(n + 7, 2 * n) << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 2; i < 632; ++i)
    if (!sieve[i]) {
      if (i > 211) primes.push_back(i);
      for (int j = i * 2; j < 632; j += i) sieve[j] = 1;
    }
  int n;
  cin >> n;
  while (n--) solve();
  return 0;
}
