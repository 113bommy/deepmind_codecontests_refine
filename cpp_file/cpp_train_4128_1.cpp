#include <bits/stdc++.h>
using namespace std;
long long n, resp, sum, num, loga;
int main() {
  scanf("%l64d", &n);
  for (long long i = n; i >= 1; i--) {
    for (long long j = i; j >= 1; j--) {
      num = 0;
      sum = i ^ j;
      while (sum) {
        loga = log2(sum);
        sum -= (1 << loga);
        num += (1 << loga);
      }
      if (num > j) continue;
      if (i + j > num && i + num > j && j + num > i) resp++;
    }
  }
  printf("%I64d", resp);
  return 0;
}
