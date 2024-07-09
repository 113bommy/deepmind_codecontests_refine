#include <bits/stdc++.h>
using namespace std;
int b[30], c[30];
int a[4][4], j;
int n, sum, sum1;
int s[30];
int d[30], r[30];
void get(int num) {
  if (num == 2 * n && s[0] != s[1]) return;
  if (num == 3 * n && s[0] != s[2]) return;
  if (num == 4 * n && s[0] != s[3]) return;
  if (num == (n - 1) * n + 2 && d[0] != d[1]) return;
  if (num == (n - 1) * n + 3 && d[0] != d[2]) return;
  if (num == (n - 1) * n + 4 && d[0] != d[3]) return;
  if (num == n * n) {
    sum = 0;
    sum1 = 0;
    for (int i = 0; i < n; i++) sum1 += a[i][i];
    for (int i = 0; i < n; i++) sum += a[n - 1 - i][i];
    if (sum != sum1) return;
    cout << sum << endl;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) cout << a[i][j] << " ";
      cout << endl;
    }
    exit(0);
  }
  for (int i = 0; i <= j; i++)
    if (c[i]) {
      c[i]--;
      a[num / n][num % n] = r[i];
      s[num / n] += r[i];
      d[num % n] += r[i];
      get(num + 1);
      s[num / n] -= r[i];
      d[num % n] -= r[i];
      c[i]++;
    }
}
int main(void) {
  cin >> n;
  for (int i = 0; i < n * n; i++) cin >> b[i];
  sort(b, b + n * n);
  j = 0;
  c[0] = 1;
  r[0] = b[0];
  for (int i = 1; i < n * n; i++)
    if (b[i] == b[i - 1])
      c[j]++;
    else {
      j++;
      r[j] = b[i];
      c[j]++;
    }
  get(0);
  return 0;
}
