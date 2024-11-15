#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10007;
int bCnt[MAXN];
int cnt[MAXN];
int main() {
  for (int i = 0; i < MAXN; ++i) {
    bCnt[i] = __builtin_popcount(i);
  }
  int n, k;
  cin >> n >> k;
  int b;
  for (int i = 0; i < n; ++i) {
    cin >> b;
    cnt[b]++;
  }
  long long res = 0;
  for (int i = 0; i < MAXN; ++i) {
    for (int j = i; j < MAXN; ++j) {
      if (cnt[i] > 0 && cnt[j] > 0 && bCnt[i ^ j] == k) {
        if (i == j) {
          res += 1LL * cnt[i] * (cnt[i] - 1) / 2;
        } else {
          res += 1LL * cnt[i] * cnt[j];
        }
      }
    }
  }
  cout << res;
  return 0;
}
