#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, ar[105], s[105], a, b;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &ar[i]);
  s[0] = 0;
  for (int i = 1; i <= n; i++) s[i] = s[i - 1] + ar[i];
  scanf("%d%d", &a, &b);
  printf("%d\n",
         min(abs(s[b - 1] - s[a - 1]), s[n] - abs(s[b - 1] - s[a - 1])));
  return 0;
}
