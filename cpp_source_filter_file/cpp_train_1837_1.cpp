#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void amin(T &x, const T &y) {
  if (y < x) x = y;
}
template <class T>
inline void amax(T &x, const T &y) {
  if (x < y) x = y;
}
template <class Iter>
void rprintf(const char *fmt, Iter begin, Iter end) {
  for (bool sp = 0; begin != end; ++begin) {
    if (sp)
      putchar(' ');
    else
      sp = true;
    printf(fmt, *begin);
  }
  putchar('\n');
}
struct Data {
  long long val;
  long long cnt;
  long long z;
  Data(long long val_, long long cnt_, long long z_) {
    val = val_;
    cnt = cnt_;
    z = z_;
  }
  bool operator<(const Data &y) const { return val < y.val; }
};
long long N, M, R, K;
void MAIN() {
  scanf("%lld%lld%lld%lld", &N, &M, &R, &K);
  if (N > M) swap(N, M);
  priority_queue<Data> Q;
  if (2 * R <= N) {
    Q.emplace(R * R, (N - 2 * R) * (M - 2 * R), -1);
    Q.emplace(R * R, (N - 2 * R) * 2 + (M - 2 * R) * 2, R);
    for (long long i = 1; i <= R; i++) {
      Q.emplace(i * R, 4, R);
    }
  } else if (2 * R <= M) {
    Q.emplace(R * (N - R + 1), (M - 2 * R) * (2 * R - N), -1);
    Q.emplace(R * (N - R), (M - 2 * R) * 2, R);
    Q.emplace((N - R + 1) * R, (2 * R - N) * 2, N - R + 1);
    for (long long i = 1; i <= R; i++) {
      Q.emplace(i * (N - R), 4, i);
    }
  } else {
    Q.emplace((N - R + 1) * (M - R + 1), (2 * R - N) * (2 * R - M), -1);
    Q.emplace((M - R) * (N - R + 1), (N - R + 1) * 2, N - R + 1);
    Q.emplace((N - R) * (M - R + 1), (M - R + 1) * 2, M - R + 1);
    for (long long i = 1; i <= M - R; i++) {
      Q.emplace(i * (N - R), 4, i);
    }
  }
  long long sum = 0;
  while (K) {
    Data d = Q.top();
    Q.pop();
    if (d.cnt <= 0) continue;
    long long g = min(K, d.cnt);
    sum += g * d.val;
    K -= g;
    if (d.z >= 1 && d.val > d.z) {
      d.val -= d.z;
      Q.push(d);
    }
  }
  double base = (N - R + 1) * (M - R + 1);
  printf("%.12f\n", (double)sum / base);
}
int main() {
  int TC = 1;
  for (int tc = 0, tc_len = (TC); tc < tc_len; ++tc) MAIN();
  return 0;
}
