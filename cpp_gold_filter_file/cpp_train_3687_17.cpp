#include <bits/stdc++.h>
using namespace std;
int main() {
  int i = 0, n, m = 0, k, t, arr[1000000];
  cin >> n >> k;
  for (; i < n; i++) {
    cin >> t;
    arr[i % k] += t;
  }
  for (i = 1; i < k; i++) {
    if (arr[i] < arr[m]) m = i;
  }
  cout << m + 1;
}
