#include <bits/stdc++.h>
using namespace std;
int main() {
  string a;
  cin >> a;
  int n = a.size();
  for (int i = 1; i < n - 1; i++) {
    if (a[i] == a[i - 1]) {
      for (int j = 'a'; j <= 'z'; j++) {
        if (a[i - 1] != j && a[i + 1] != j) {
          a[i] = j;
          break;
        }
      }
    }
  }
  cout << a << endl;
}
