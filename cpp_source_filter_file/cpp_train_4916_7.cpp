#include <bits/stdc++.h>
using namespace std;
const int N = 5050;
int sieve[N];
int primes[N];
int pcount;
int rev[1000];
int f[N][1000];
int pre[N][1000];
int nxt[N];
int w[N];
int amt[N];
int dst[N];
int good[N];
void setup() {
  for (int i = 0; i < N; ++i) {
    good[i] = 1;
  }
  for (int i = 2; i < N; ++i) {
    if (sieve[i] == 0) {
      primes[++pcount] = i;
      rev[i] = pcount;
      for (int j = i * i; j < N; j += i) {
        if (!sieve[j]) {
          sieve[j] = i;
        }
      }
      sieve[i] = i;
    }
  }
  for (int i = 2; i < N; ++i) {
    int q = i;
    int lst = -1;
    while (q > 1) {
      ++f[i][rev[sieve[q]]];
      lst = q;
      q /= sieve[q];
    }
    nxt[i] = max(nxt[i - 1], rev[lst]);
    for (int j = 1; j <= pcount; ++j) {
      pre[i][j] = pre[i - 1][j] + f[i][j];
      dst[i] += pre[i][j];
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  setup();
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    ++w[x];
  }
  long long cur = 0;
  for (int i = 1; i < N; ++i) {
    cur += (long long)w[i] * dst[i];
    if (w[i]) {
    }
  }
  long long ans = cur;
  int q = pcount;
  while (q) {
    memset(amt, 0, sizeof amt);
    for (int i = 1; i < N; ++i) {
      if (good[i]) {
        amt[nxt[i]] += w[i];
      }
    }
    pair<long long, long long> best(0, -1);
    for (int i = 1; i <= q; ++i) {
      best = max(best, pair<long long, long long>(amt[i], i));
    }
    cur += n - 2 * best.first;
    ans = min(ans, cur);
    if (best.first == 0) break;
    if (best.first * 2 < n) break;
    q = best.second;
    for (int i = 0; i < N; ++i) {
      if (nxt[i] != best.second) {
        good[i] = 0;
      } else if (nxt[i] == best.second && good[i]) {
        --pre[i][best.second];
        int j = best.second;
        while (j && pre[i][j] == 0) --j;
        nxt[i] = j;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
