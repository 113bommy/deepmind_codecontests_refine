#include <bits/stdc++.h>
using namespace std;
long long l, r;
inline long long find(int x) {
  if (x < 3) return 0;
  long long j = 0;
  long long now = x;
  for (; now > 1;) {
    j++;
    now /= 2LL;
  }
  long long line = (1LL << j) - 1LL;
  long long ans = find(line);
  j++;
  for (int i = 1; i <= j - 1; i++) {
    if (!(j % i)) {
      long long tmp = 0;
      for (int k = 0; k <= j / i - 1; k++)
        tmp += 1LL << (long long)((long long)k * i);
      if (tmp > x) continue;
      ans = ans + (x / tmp) - find(x / tmp);
      ans = ans - (line / tmp) + find(line / tmp);
    }
  }
  return ans;
}
int main() {
  scanf("%I64d%I64d", &l, &r);
  printf("%I64d\n", find(r) - find(l - 1));
}
