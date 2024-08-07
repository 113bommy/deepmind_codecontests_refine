#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
string print_iterable(T1 begin_iter, T2 end_iter, int counter) {
  bool done_something = false;
  stringstream res;
  res << "[";
  for (; begin_iter != end_iter and counter; ++begin_iter) {
    done_something = true;
    counter--;
    res << *begin_iter << ", ";
  }
  string str = res.str();
  if (done_something) {
    str.pop_back();
    str.pop_back();
  }
  str += "]";
  return str;
}
vector<int> SortIndex(int size, std::function<bool(int, int)> compare) {
  vector<int> ord(size);
  for (int i = 0; i < size; i++) ord[i] = i;
  sort(ord.begin(), ord.end(), compare);
  return ord;
}
template <typename T>
bool MinPlace(T& a, const T& b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
bool MaxPlace(T& a, const T& b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <typename Container>
int SZ(const Container& S) {
  return S.size();
}
template <typename S, typename T>
ostream& operator<<(ostream& out, const pair<S, T>& p) {
  out << "{" << p.first << ", " << p.second << "}";
  return out;
}
template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v) {
  out << "[";
  for (int i = 0; i < (int)v.size(); i++) {
    out << v[i];
    if (i != (int)v.size() - 1) out << ", ";
  }
  out << "]";
  return out;
}
const int MAXN = 1000010;
const long long mod = 998244353;
long long fact[MAXN];
long long invfact[MAXN];
long long Inverse(long long n, long long m) {
  n %= m;
  if (n <= 1) return n;
  return m - ((m * Inverse(m, n) - 1) / n);
}
long long modpow(long long a, long long e) {
  if (e == 0) return 1;
  if (e % 2) return (a * modpow((a * a) % mod, e / 2)) % mod;
  return modpow((a * a) % mod, e / 2);
}
long long binom(long long a, long long b) {
  return (fact[a] * (invfact[b] * invfact[a - b]) % mod) % mod;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  fact[0] = 1;
  invfact[0] = 1;
  for (long long i = 1; i < MAXN; i++) {
    fact[i] = (fact[i - 1] * i) % mod;
    invfact[i] = Inverse(fact[i], mod);
  }
  long long N;
  cin >> N;
  long long x = Inverse(3, mod);
  long long ris1 = -2ll * modpow(3, N * N);
  long long c = 1 - modpow(x, N - 1);
  ris1 *= modpow(c, N) - 1;
  ris1 %= mod;
  long long ris2 = 0;
  for (long long i = 1; i <= N; i++) {
    long long curr = binom(N, i) * modpow(x, N * i);
    curr %= mod;
    if (i % 2) curr = -curr;
    long long w = 1 - modpow(x, N - i);
    curr *= modpow(w, N) - 1;
    curr %= mod;
    ris2 += curr;
  }
  ris2 %= mod;
  ris2 *= -modpow(3, N * N + 1);
  ris2 %= mod;
  long long res = ris1 + ris2;
  res %= mod;
  res += mod;
  res %= mod;
  cout << res << endl;
}
