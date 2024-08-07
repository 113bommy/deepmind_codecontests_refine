#include <bits/stdc++.h>
using namespace std;
int N;
int a[100005];
int cnt[100005];
int check[100005];
int main() {
  long long ans = 0;
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    scanf("%d", &a[i]);
    cnt[a[i]]++;
  }
  int odd = 0;
  for (int i = 0; i <= N; ++i) {
    if (cnt[i] % 2) ++odd;
  }
  if (odd > 1) {
    printf("0\n");
    return 0;
  }
  int start = -1;
  for (int i = 0; i < N; ++i) {
    if (a[i] != a[N - i - 1]) {
      start = i;
      break;
    }
    cnt[a[i]] -= 2;
  }
  if (start == -1) {
    cout << (1LL * N * (N + 1) / 2LL) << endl;
    return 0;
  }
  for (int i = 0; i <= 100000; ++i) check[i] = 0;
  int ret = 0;
  for (int i = start; i <= N - start - 1; ++i) {
    check[a[i]]++;
    if (check[a[i]] * 2 > cnt[a[i]]) {
      if (i < N - i - 1) break;
      if (cnt[a[i]] % 2 == 0 && i == N - i - 1) break;
      if (a[i] != a[N - i - 1]) break;
    }
    ++ret;
  }
  for (int i = 0; i <= N; ++i) check[i] = 0;
  for (int i = N - start - 1; i >= 0; --i) {
    check[a[i]]++;
    if (check[a[i]] * 2 > cnt[a[i]]) {
      if (i > N - i - 1) break;
      if (cnt[a[i]] % 2 == 0 && i == N - i - 1) break;
      if (a[i] != a[N - i - 1]) break;
    }
    ++ret;
  }
  ans += 1LL * ret * (start + 1);
  ans += 1LL * (start + 1) * (start + 1);
  cout << ans << endl;
  return 0;
}
