#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  int mex = 1;
  for (int i = 0; i < n; i++) {
    if (arr[i] >= (mex)) {
      mex++;
      continue;
    }
  }
  cout << mex;
  return 0;
}
