#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n;
  cin >> n;
  long long int x[n][2];
  long long int y[n][2];
  long long int xx[n][2], yy[n][2];
  long long int xxx[n][2], yyy[n][2];
  long long int maxx = -10000000000, minx = 10000000000;
  long long int maxy = -10000000000, miny = 10000000000;
  for (long long int i = 0; i < n; i++) {
    cin >> x[i][0];
    cin >> y[i][0];
    cin >> x[i][1];
    cin >> y[i][1];
    if (x[i][0] > maxx) {
      maxx = x[i][0];
      xx[i][0] = maxx;
    } else
      xx[i][0] = xx[i - 1][0];
    if (x[i][1] < minx) {
      minx = x[i][1];
      xx[i][1] = minx;
    } else
      xx[i][1] = xx[i - 1][1];
    if (y[i][0] > maxy) {
      maxy = y[i][0];
      yy[i][0] = maxy;
    } else
      yy[i][0] = yy[i - 1][0];
    if (y[i][1] < miny) {
      miny = y[i][1];
      yy[i][1] = miny;
    } else
      yy[i][1] = yy[i - 1][1];
  }
  maxx = -10000000000, minx = 10000000000;
  maxy = -10000000000, miny = 10000000000;
  for (long long int i = n - 1; i >= 0; i--) {
    if (x[i][0] > maxx) {
      maxx = x[i][0];
      xxx[i][0] = maxx;
    } else
      xxx[i][0] = xxx[i + 1][0];
    if (x[i][1] < minx) {
      minx = x[i][1];
      xxx[i][1] = minx;
    } else
      xxx[i][1] = xxx[i + 1][1];
    if (y[i][0] > maxy) {
      maxy = y[i][0];
      yyy[i][0] = maxy;
    } else
      yyy[i][0] = yyy[i + 1][0];
    if (y[i][1] < miny) {
      miny = y[i][1];
      yyy[i][1] = miny;
    } else
      yyy[i][1] = yyy[i + 1][1];
  }
  for (long long int i = 0; i < n; i++) {
    if (i == 0) {
      if (xxx[1][1] - xxx[1][0] >= 0 && yyy[1][1] - yyy[1][0] >= 0) {
        cout << xxx[1][1] << " " << yyy[1][1];
        return 0;
      }
    } else if (i == n - 1) {
      if (xx[n - 2][1] - xx[n - 2][0] >= 0 &&
          yy[n - 2][1] - yy[n - 2][0] >= 0) {
        cout << xx[n - 2][1] << " " << yy[n - 2][1];
        return 0;
      }
    } else {
      long long int mxx = max(xx[i - 1][0], xxx[i + 1][0]),
                    mnx = min(xx[i - 1][1], xxx[i + 1][1]);
      long long int mxy = max(yy[i - 1][0], yyy[i + 1][0]),
                    mny = min(yy[i - 1][1], yyy[i + 1][1]);
      if (mnx - mxx >= 0 && mny - mxy >= 0) {
        cout << mnx << " " << mny;
        return 0;
      }
    }
  }
  return 0;
}
