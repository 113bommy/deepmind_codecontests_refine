#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; t = i++) {
    int a, b;
    cin >> a >> b;
    cout << (23 - a) * 60 + (60 - b) << endl;
  }
}
