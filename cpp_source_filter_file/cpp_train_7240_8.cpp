#include <bits/stdc++.h>
using namespace std;
int a[100500];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n - 1; i++) cout << a[i] - a[i + 1] << ' ';
  cout << a[n - 1] << endl;
  return 0;
}
