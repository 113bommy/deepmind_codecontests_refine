#include <bits/stdc++.h>
using namespace std;
int p = 1, n, j, a[105];
char c;
int main() {
  a[j++] = 1;
  while (cin >> c && c != '=') {
    if (c == '-') p--, a[j++] = -1;
    if (c == '+') p++, a[j++] = 1;
  }
  cin >> n;
  for (int i = 0; i < j; i++) {
    if (a[i] > 0)
      while (p < n && a[i] < n) a[i]++, p++;
    else
      while (p > n && a[i] < 0 && a[i] > -n) a[i]--, p--;
  }
  if (p != n) {
    cout << "Impossible" << endl;
    return 0;
  }
  cout << "Possible" << endl;
  cout << a[0] << " ";
  for (int i = 1; i < j; i++)
    if (a[i] < 0)
      cout << "- " << -a[i];
    else
      cout << "+ " << a[i];
  cout << "= " << n;
}
