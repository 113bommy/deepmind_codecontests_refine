#include <bits/stdc++.h>
using namespace std;
int main() {
  int HomeColorsArrCount[100000];
  int AwayColors[100000];
  int n, x, i;
  memset(HomeColorsArrCount, 0, 100000 * sizeof(int));
  memset(AwayColors, 0, 100000 * sizeof(int));
  cin >> n;
  for (i = 0; i < n; ++i) {
    cin >> x >> AwayColors[i];
    HomeColorsArrCount[x] = HomeColorsArrCount[x] + 1;
  }
  int nHomeMatchesCount = (n - 1);
  int nTotalMatchesCount = (nHomeMatchesCount << 1);
  for (i = 0; i < n; ++i) {
    cout << (nHomeMatchesCount + HomeColorsArrCount[AwayColors[i]]) << " "
         << nTotalMatchesCount -
                (nHomeMatchesCount + HomeColorsArrCount[AwayColors[i]])
         << endl;
  }
  return 0;
}
