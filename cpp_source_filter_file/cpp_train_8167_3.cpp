#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t, sum = 1, flag = 0;
  cin >> n >> t;
  int a[n];
  for (int i = 0; i < n - 1; i++) {
    cin >> a[i];
  }
  while (sum < (t)) {
    sum = sum + a[sum];
  }
  if (sum == (t - 1)) {
    cout << "YES";
  } else
    cout << "NO";
}
