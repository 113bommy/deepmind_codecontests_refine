#include <bits/stdc++.h>
using namespace std;
const int N = 100 * 1000 + 5;
int slo[N];
int ile[N], tmp[N];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", slo + i);
  for (int i = 0; i < n; i++) ile[slo[i]]++;
  int niep = 0;
  for (int i = 1; i <= n; i++)
    if (ile[i] % 2) niep++;
  if (niep > 1) {
    printf("0\n");
    return 0;
  }
  niep = 0;
  for (int i = 1; i <= n; i++)
    if (ile[i] % 2) niep = i;
  int d = 0;
  while (d < n / 2 && slo[d] == slo[n - d - 1]) d++;
  if (d == n / 2) {
    printf("%lld\n", n * (long long)(n - 1));
    return 0;
  }
  int x = n - 1;
  while (x >= (n + 1) / 2) {
    if (++tmp[slo[x]] > ile[slo[x]] / 2) break;
    x--;
  }
  if (x == (n + 1) / 2 - 1) {
    if (niep && slo[x] == niep) x--;
    if (niep == 0 || x < n / 2)
      while (x >= 0 && slo[x] == slo[n - 1 - x]) x--;
  }
  long long int wynik = 0;
  wynik = (d + 1) * (long long)(n - x);
  for (int i = 1; i <= n; i++) tmp[i] = 0;
  x = 0;
  while (x < n / 2) {
    if (++tmp[slo[x]] > ile[slo[x]] / 2) break;
    x++;
  }
  if (x == n / 2) {
    if (niep && slo[x] == niep) x++;
    if (niep == 0 || x > n / 2)
      while (x < n && slo[x] == slo[n - 1 - x]) x++;
  }
  wynik += (d + 1) * (long long)(x + 1);
  wynik -= (d + 1) * (long long)(d + 1);
  printf("%lld\n", wynik);
}
