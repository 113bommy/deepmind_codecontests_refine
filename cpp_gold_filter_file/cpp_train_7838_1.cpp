#include <bits/stdc++.h>
using namespace std;
;
int main() {
  int k, s = 0, i;
  cin >> k;
  int a[12];
  for (int i = 0; i < 12; i++) cin >> a[i];
  sort(a, a + 12);
  for (i = 11; i >= 0; i--) {
    if (s >= k)
      break;
    else
      s += a[i];
  }
  if (s >= k)
    cout << (11 - i);
  else
    cout << -1;
  return 0;
}
