#include <bits/stdc++.h>
using namespace std;
int arr[100100];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  int sum = 0;
  for (int i = 0; i + 1 < n; i++) {
    sum += arr[i];
    cout << sum << '\n';
    int j = i, k = 1;
    while (j + k < n) {
      k *= 2;
    }
    k /= 2;
    arr[j + k] += arr[i];
  }
}
