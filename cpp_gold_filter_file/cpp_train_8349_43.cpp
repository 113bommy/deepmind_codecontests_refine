#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int h, m;
    cin >> h >> m;
    cout << (23 - h) * 60 + 60 - m << endl;
  }
  return 0;
}
