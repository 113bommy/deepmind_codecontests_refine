#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, l, r, c;
  cin >> n;
  int arr[200021];
  int x, i, j;
  for (int i = 0; i < n; ++i) cin >> arr[i];
  vector<int> MIN(n + 1);
  MIN[n] = 2000000000;
  for (int i = n - 1; i >= 0; --i)
    if (arr[i] < MIN[i + 1])
      MIN[i] = arr[i];
    else
      MIN[i] = arr[i + 1];
  for (int i = 0; i < n; ++i) {
    l = i;
    r = n;
    while (l + 1 < r) {
      c = (l + r) / 2;
      if (MIN[c] < arr[i])
        l = c;
      else
        r = c;
    }
    if (MIN[r] < arr[i]) l = r;
    cout << l - i - 1 << " ";
  }
  return 0;
}
