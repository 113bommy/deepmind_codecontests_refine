#include <bits/stdc++.h>
using namespace std;
char a[1000010], b[1000010];
int pre[1000010];
int main() {
  int n;
  scanf("%d%s%s", &n, a + 1, b + 1);
  n--;
  for (int i = 1; i <= n; i++)
    if (a[i] == 'N')
      a[i] = 'S';
    else if (a[i] == 'E')
      a[i] = 'W';
    else if (a[i] == 'W')
      a[i] = 'E';
    else
      a[i] = 'N';
  for (int i = 1; i <= n / 2; i++) swap(a[i], a[n + 1 - i]);
  pre[1] = 0;
  int k = 0;
  for (int i = 2; i <= n; i++) {
    while (k && a[k + 1] != a[i]) k = pre[k];
    if (a[k + 1] == a[i]) k++;
    pre[i] = k;
  }
  k = 0;
  for (int i = 1; i <= n; i++) {
    while (k && a[k + 1] != b[i]) k = pre[k];
    if (a[k + 1] == b[i]) k++;
  }
  if (k)
    puts("NO");
  else
    puts("YES");
  return 0;
}
