#include <bits/stdc++.h>
using namespace std;
int n, i, j, p[1000], q[1000];
bool ha[10000];
string a[10000], b[10000];
int main() {
  cin >> n;
  for (i = 1; i <= n; i++) cin >> a[i], p[a[i][0]]++;
  for (i = 1; i <= n; i++) cin >> b[i], q[b[i][0]]++;
  sort(a + 1, a + 1 + n);
  sort(b + 1, b + 1 + n);
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++)
      if (!ha[j] && ((a[i][0] == b[j][0]) ||
                     (p[a[i][0]] > q[a[i][0]] && p[b[j][0]] < q[b[j][0]]))) {
        ha[j] = true;
        p[a[i][0]]--;
        q[b[j][0]]--;
        if (i != n)
          cout << a[i] << ' ' << b[j] << ", ";
        else
          cout << a[i] << ' ' << b[j];
        break;
      }
}
