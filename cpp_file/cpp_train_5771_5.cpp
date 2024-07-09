#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
inline bool mina(A &x, B y) {
  return (x > y) ? (x = y, 1) : 0;
}
template <typename A, typename B>
inline bool maxa(A &x, B y) {
  return (x < y) ? (x = y, 1) : 0;
}
int N, K;
pair<int, int> P[(200005)];
int A[(200005)];
int B[(200005)];
long long sol = 1LL << 60;
void check(int n0) {
  if (n0 > N) return;
  priority_queue<int, vector<int>, greater<int>> Q;
  int a = 0;
  int b = 0;
  int r = 0;
  for (int _b = (N), i = (0); i < _b; ++i) {
    if (P[i].first == n0 - 1 || P[i].first == n0) {
      A[a++] = P[i].second;
      ++r;
    } else {
      B[b++] = P[i].second;
      if (P[i].first > n0) ++r;
    }
  }
  sort(A, A + a, greater<int>());
  sort(B, B + b, greater<int>());
  long long res = 0;
  int n = 0;
  while (b > 0 && n < n0) {
    res += B[--b];
    ++n;
  }
  while (n < n0) {
    res += A[--a];
    --r;
    ++n;
  }
  if (r <= K) mina(sol, res);
  while (a > 0) {
    res += A[--a] - B[b++];
    --r;
    if (r <= K) mina(sol, res);
  }
}
int main() {
  cin >> N >> K;
  for (int _b = (N), i = (0); i < _b; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    P[i] = pair<int, int>(a, b);
  }
  --K;
  sort(P, P + N, greater<pair<int, int>>());
  if (P[K].first > N) {
    printf("-1\n");
    return 0;
  }
  check(P[K].first);
  check(P[K].first + 1);
  check(P[K].first + 2);
  cout << sol << endl;
  return 0;
}
