#include <bits/stdc++.h>
const int N = 100010;
const int inf = 0x3f3f3f3f;
using namespace std;
int a[101][101];
int main() {
  int n;
  scanf("%d", &n);
  int l = 1;
  int ret = 1;
  while ((ret + 1) * ret / 2 <= n) ret++;
  for (int i = 1; i <= ret; i++)
    for (int j = i; j <= ret; j++) a[j + 1][i] = a[i][j] = l++;
  printf("%d\n", ret);
  for (int i = 1; i <= ret; i++, puts(""))
    for (int j = 1; j < ret; j++) printf("%d ", a[i][j]);
  return 0;
}
