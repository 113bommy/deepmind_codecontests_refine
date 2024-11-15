#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000000;
int dig[MAXN + 1];
int dis[10][MAXN + 1], num[10][MAXN + 1];
int main() {
  for (int i = 0; i <= MAXN; ++i) {
    dig[i] = 0;
    for (int j = i; j; j /= 10) dig[i] = max(dig[i], j % 10);
  }
  for (int i = 1; i < 10; ++i) {
    for (int j = 0; j < i; ++j) {
      dis[i][j] = 1;
      num[i][j] = j - i;
    }
    for (int j = i; j <= MAXN; ++j) {
      int maxs = dig[j];
      dis[i][j] = dis[i][j - maxs] + 1;
      num[i][j] = num[i][j - maxs];
    }
  }
  long long n;
  scanf("%I64d", &n);
  long long ret = 0;
  while (1) {
    int pre = n / MAXN;
    if (!pre) {
      while (n) {
        ++ret;
        n -= dig[n];
      }
      printf("%I64d\n", ret);
      return 0;
    }
    ret += dis[dig[pre]][n % MAXN];
    n = n / MAXN * MAXN + num[dig[pre]][n % MAXN];
  }
  return 0;
}
