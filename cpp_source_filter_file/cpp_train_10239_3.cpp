#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
int ar[MAXN];
long long sol[MAXN][2], sag[MAXN][2];
int main() {
  int n;
  scanf(" %d", &n);
  n--;
  for (int i = 1; i <= n; i++) scanf(" %d", ar + i);
  for (int i = 1; i <= n; i++) {
    if (ar[i] != 1) sol[i + 1][0] = sol[i][0] + ar[i] - ar[i] % 2;
    sol[i + 1][1] = sol[i][1] + ar[i] - (1 - ar[i] % 2);
    sol[i + 1][1] = max(sol[i + 1][1], sol[i + 1][0]);
  }
  for (int i = n; i >= 1; i--) {
    if (ar[i] != 1) sag[i][0] = sag[i - 1][0] + ar[i] - ar[i] % 2;
    sag[i][1] = sag[i - 1][1] + ar[i] - (1 - ar[i] % 2);
    sag[i][1] = max(sag[i][1], sag[i][0]);
  }
  n++;
  long long res = 0;
  for (int i = 1; i <= n; i++)
    res = max(res, sol[i][1] + sag[i][0]),
    res = max(res, sol[i][0] + sag[i][1]);
  cout << res << endl;
  return 0;
}
