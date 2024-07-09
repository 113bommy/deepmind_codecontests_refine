#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, city = 1;
  bool count;
  cin >> n;
  int* time;
  time = new int[n];
  for (i = 0; i < n; i++) cin >> time[i];
  int t = time[0];
  for (i = 0; i < n; i++) {
    if (time[i] == t && i > 0) count = true;
    if (time[i] < t) {
      t = time[i];
      city = i + 1;
      count = false;
    }
  }
  if (count)
    cout << "Still Rozdil";
  else
    cout << city;
}
