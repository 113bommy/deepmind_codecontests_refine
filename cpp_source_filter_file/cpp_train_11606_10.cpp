#include <bits/stdc++.h>
using namespace std;
int a, arr[10][10];
int main() {
  cin >> a;
  for (int i = 0; i <= a; i++) {
    for (int j = 0; j <= a; j++) {
      if (i == 0) {
        arr[j][i] = 1;
      } else if (j == 0) {
        arr[j][i] = 1;
      } else {
        arr[j][i] = arr[i - 1][j] + arr[i][j - 1];
      }
    }
  }
  cout << arr[a - 1][a - 1];
}
