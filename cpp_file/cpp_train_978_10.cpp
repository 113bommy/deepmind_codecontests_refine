#include <bits/stdc++.h>
using namespace std;
const int Maxn = 1e6 + 5;
long long gcd(long long a, long long b) {
  long long t;
  while (b) {
    t = a % b;
    a = b;
    b = t;
  }
  return a;
}
int n;
long long A[Maxn];
map<long long, int> fact;
int main() {
  srand(time(NULL));
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lld", &A[i]);
  long long ans = 1;
  int rep = 14;
  while (rep--) {
    int rnd = (rand() * RAND_MAX + rand()) % n + 1;
    fact.clear();
    for (int i = 1; i <= n; i++) {
      long long t = gcd(A[i], A[rnd]);
      if (!fact.count(t))
        fact[t] = 1;
      else
        fact[t]++;
    }
    map<long long, int>::iterator it = fact.end();
    do {
      it--;
      int cnt = 0;
      if (it->first <= ans) continue;
      for (map<long long, int>::iterator it1 = it;
           it1 != fact.end() && cnt << 1 < n; it1++)
        if (it1->first % it->first == 0) cnt += it1->second;
      if (cnt << 1 >= n) ans = it->first;
    } while (it != fact.begin());
  }
  printf("%lld\n", ans);
}
