#include <bits/stdc++.h>
using namespace std;
long long n, h, i, j, indx, a[100][100];
int main() {
  cin >> n >> h;
  for (indx = 1; indx <= n; indx++) {
    a[0][indx - 1] = 1;
    for (i = 1; i <= n; i++)
      for (j = 0; j < i; j++)
        a[i][indx] += a[j][indx - 1] * a[i - 1 - j][indx - 1];
  }
  cout << a[n][n] - a[n][h - 1];
}
