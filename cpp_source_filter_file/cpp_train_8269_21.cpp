#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, c = 1;
  cin >> n;
  int arr[n], arr2[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i] >> arr2[i];
    if (arr[i] != arr2[i]) {
      c++;
    }
  }
  if (c > 1)
    cout << "Happy Alex" << c;
  else
    cout << "Poor Alex";
  return 0;
}
