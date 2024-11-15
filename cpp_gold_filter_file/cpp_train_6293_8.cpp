#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, M, K;
  vector<long double> p2(1, 1.0), p3(1, 1.0), logfact(1, 0.0);
  for (int i = 1; i < 1000; i++) p2.push_back(p2.back() * 2);
  for (int i = 1; i < 1000; i++) p3.push_back(p3.back() * 3);
  for (int i = 1; i < 110000; i++) logfact.push_back(logfact.back() + log(i));
  while (cin >> N >> M >> K) {
    long double ret = 0.0;
    for (int nc = 0; nc <= N; nc++)
      for (int nr = 0; nr <= N; nr++) {
        int sel = nc * N + (N - nc) * nr;
        int nsel = N * N - sel;
        if (sel > K) continue;
        long double sc = 1.0;
        long double v = 0.0;
        v += logfact[K] - logfact[K - sel];
        v += logfact[M - sel] - logfact[M - sel - nsel];
        v += logfact[N] - logfact[N - nr] - logfact[nr];
        v += logfact[N] - logfact[N - nc] - logfact[nc];
        v -= logfact[M] - logfact[M - N * N];
        ret += exp(v) * sc;
      }
    if (ret > 1e99) ret = 1e99;
    printf("%.15lf\n", (double)ret);
  }
}
