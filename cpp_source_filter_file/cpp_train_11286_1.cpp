#include <bits/stdc++.h>
using namespace std;
int n, a[300005], ans[300005], max_val = -1, l, r, size = 0;
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    l = i, r = i;
    while (l && a[l - 1] % a[i] == 0) l--;
    while (r < n - 1 && a[r + 1] % a[i] == 0) r++;
    i = r + 1;
    if (r - l < max_val) continue;
    if (r - l > max_val) max_val = r - l, size = 0;
    ans[size++] = l + 1;
  }
  cout << size << " " << max_val << "\n";
  for (int i = 0; i < size; i++) cout << ans[i] << " ";
  return 0;
}
