#include <bits/stdc++.h>
int n;
long long f[100000][2];
using namespace std;
char a[1000], b[1000];
int main() {
  scanf("%s", a);
  scanf("%s", b);
  int len = strlen(a);
  if (strncmp(a, b, len) == 0)
    f[0][0] = 1;
  else
    f[0][1] = 1;
  int x = 0;
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < len; j++)
      if (a[(i + j) % len] != b[j]) goto out;
    ++x;
  out:;
  }
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    f[i + 1][0] = (x * f[i][1] + (x - 1) * f[i][0]) % 1000000007;
    f[i + 1][1] = ((len - 1 - x) * f[i][1] % 1000000007 +
                   (len - x) * f[i][0] % 1000000007) %
                  1000000007;
  }
  printf("%lld", f[n][0]);
}
