#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, count = 0;
  int a[100010] = {0}, b[100010] = {0}, d[100010] = {0}, ans[100010],
      check[100010] = {0};
  cin >> n;
  for (i = 1; i <= n; i++) cin >> a[i];
  for (i = 1; i <= n; i++) {
    cin >> b[i];
    d[i] = a[i] - b[i] + d[i - 1];
  }
  int mn = d[1];
  for (i = 1; i <= n; i++)
    if (mn > d[i]) mn = d[i];
  for (i = 0; i < n; i++) {
    mn -= (a[i] - b[i]);
    if (mn >= 0) {
      ans[count] = i + 1;
      count++;
      check[i + 1] = 1;
    }
  }
  memset(d, 0, sizeof(d));
  b[0] = b[n];
  for (i = n; i > 0; i--) {
    d[i] = a[i] - b[i - 1] + d[i + 1];
  }
  mn = d[1];
  for (i = 1; i <= n; i++)
    if (mn > d[i]) mn = d[i];
  if (mn >= 0 && check[n] == 0) {
    ans[count] = n;
    count++;
    check[n] = 1;
  }
  for (i = n; i > 1; i--) {
    mn -= (a[i] - b[i - 1]);
    if (mn >= 0) {
      if (check[i - 1] == 0) {
        ans[count] = i - 1;
        check[i - 1] = 1;
        count++;
      }
    }
  }
  sort(ans, ans + count);
  cout << count << endl;
  for (i = 0; i < count; i++) cout << ans[i] << "  ";
}
