#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 1; i < n; i++) cin >> a[i];
  int check = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == 1) check = 1;
  }
  if (check == 1)
    cout << -1;
  else
    cout << 1;
  return 0;
}
