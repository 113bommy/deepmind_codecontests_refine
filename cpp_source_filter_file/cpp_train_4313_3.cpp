#include <bits/stdc++.h>
using namespace std;
int N, K, K1, K2, nr, a[300009], lft[300009], rgt[300009];
double ans, put[209];
pair<int, int> v[300009];
set<int> S;
int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) scanf("%d", &a[i]), v[i] = make_pair(-a[i], i);
  put[0] = 1.0;
  for (int i = 1; i <= 102; i++) put[i] = put[i - 1] / 2.0;
  sort(v + 1, v + N + 1), K = 33;
  for (int I = 1; I <= N; I++) {
    int i = v[I].second;
    S.insert(i);
    set<int>::iterator it = S.find(i), it1, it2;
    it1 = it, it2 = it, K1 = K2 = K, lft[0] = rgt[0] = i;
    for (int j = 1; j <= K; j++) {
      if (it1 == S.begin()) {
        K1 = j - 1;
        break;
      }
      it1--, lft[j] = *it1;
    }
    for (int j = 1; j <= K; j++) {
      if (++it2 == S.end()) {
        K2 = j - 1;
        break;
      }
      rgt[j] = *it2;
    }
    lft[K1 + 1] = 0, rgt[K2 + 1] = N + 1;
    for (int j1 = 0; j1 <= K1; j1++)
      for (int j2 = 0; j2 <= K2; j2++)
        ans = (double)ans + (double)a[i] * put[j1 + j2 + 1] *
                                (rgt[j2 + 1] - rgt[j2]) *
                                (lft[j1] - lft[j1 + 1]);
  }
  ans = (double)ans / N;
  ans = (double)ans / N;
  printf("%.15f\n", ans);
  return 0;
}
