#include <bits/stdc++.h>
using namespace std;
int arr1[10001], arr2[10001];
int main() {
  int c = 0, n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> arr1[i];
    if (arr2[arr1[i]] == 0) c++;
    arr2[arr1[i]]++;
  }
  if (c == 1) {
    cout << "Exemplary pages.";
    return 0;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if ((arr1[i] + arr1[j]) % 2 == 0 &&
          arr2[(arr1[i] + arr1[j]) / 2] == n - 2 && arr1[i] > arr1[j]) {
        cout << arr1[i] - (arr1[i] + arr1[j]) / 2 << " ml. from cup #" << j
             << " to cup #" << i << '.';
        return 0;
      }
  cout << "Unrecoverable configuration.";
}
