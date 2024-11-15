#include <bits/stdc++.h>
using namespace std;
int n, b, pnum, pri[30001], t;
long long quickpow(long long x, int y) {
  long long ret = 1;
  for (; y; y >>= 1, x = x * x % n)
    if (y & 1) ret = ret * x % n;
  return ret;
}
bool check(int x) {
  for (int i = 1; i <= pnum; i++)
    if (quickpow(x, (n - 1) / pri[i]) == 1) return false;
  return true;
}
int main() {
  cin >> n >> b;
  --b;
  if (n == 1) return printf("%d\n", b > 1 ? b : -1), 0;
  t = (++n) - 1;
  for (int i = 2; i * i <= t; i++)
    if (t % i == 0) {
      pri[++pnum] = i;
      while (t % i == 0) t /= i;
    }
  if (t > 1) pri[++pnum] = t;
  for (int i = 2; i * i <= n; i++)
    if (n % i == 0) return puts("-1"), 0;
  for (; b > 1; --b)
    if (b % n != 0 && check(b)) return printf("%d\n", b), 0;
  puts("-1");
}
