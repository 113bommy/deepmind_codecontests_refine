#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n + 5];
  set<int> s;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] != 0) {
      s.insert(a[i]);
    }
  }
  cout << s.size();
}
