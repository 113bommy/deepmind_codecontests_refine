#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, c = 0, x;
  int max, min;
  cin >> n >> m >> min >> max;
  for (int i = 0; i < m; i++) {
    cin >> x;
    if (x > min && x < max) c++;
    if (x < min && x > max) return cout << "Incorrect", 0;
  }
  if (c + 2 <= n)
    cout << "Correct";
  else
    cout << "Incorrect";
  return 0;
}
