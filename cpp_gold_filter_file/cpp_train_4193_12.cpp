#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    int n, m;
    cin >> n >> m;
    int count = 0;
    for (int i = 0; i < n; ++i) {
      string s1;
      cin >> s1;
      if (i != n - 1) {
        if (s1[m - 1] == 'R') count++;
      } else {
        for (int j = 0; j < m - 1; ++j) {
          if (s1[j] == 'D') count++;
        }
      }
    }
    cout << count << "\n";
  }
}
