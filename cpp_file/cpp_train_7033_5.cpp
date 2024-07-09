#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int arr[n + 1];
  for (int i = 1; i <= n; i++) cin >> arr[i];
  int sum = m, x;
  for (int i = 0; i < m; i++) {
    cin >> x;
    sum += x;
  }
  for (int i = sum; i <= n; i++)
    if (arr[i]) {
      cout << i;
      return 0;
    }
  cout << -1;
}
