#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-5;
const int oo = 0x3f3f3f3f;
template <class T>
inline void checkmin(T &a, T b) {
  if (b < a) a = b;
}
template <class T>
inline void checkmax(T &a, T b) {
  if (b > a) a = b;
}
template <class T>
inline T sqr(T x) {
  return x * x;
}
template <class T>
inline T lowbit(T n) {
  return (n ^ (n - 1)) & n;
}
template <class T>
inline int countbit(T n) {
  return (n == 0) ? 0 : (1 + countbit(n & (n - 1)));
}
template <class T>
inline T gcd(T a, T b) {
  T c;
  while (a != 0) {
    c = a;
    a = b % a;
    b = c;
  }
  return b;
}
template <class T>
inline T mabs(T a) {
  if (a < 0)
    return -a;
  else
    return a;
}
typedef vector<int> VI;
typedef vector<VI> VII;
typedef vector<string> VS;
#pragma comment(linker, "/STACK:36777216")
int TEST_TO;
int TEST_FROM;
const long long MAXM = (long long)1LL * 1e16 + 11;
inline long long doit(long long n) {
  long long res = 0LL;
  for (long long k = 2LL; k * k * k <= n; k++) res += n / (1LL * k * k * k);
  return res;
}
inline int solve(int testnum) {
  long long m;
  scanf("%I64d", &m);
  long long lo = 0, hi = MAXM;
  while (lo + 1LL < hi) {
    long long mid = (lo + hi) / 2;
    if (doit(mid) >= m)
      hi = mid;
    else
      lo = mid;
  }
  if (doit(hi) == m)
    printf("%I64d\n", hi);
  else
    printf("-1\n");
  return 0;
}
int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  int t = 1;
  if (argc > 1) t = atoi(argv[1]);
  TEST_FROM = 1;
  TEST_TO = t;
  for (int _t = (1); _t < int(t + 1); _t++) {
    int ret = solve(_t);
    if (ret == -1) break;
  }
  return 0;
}
