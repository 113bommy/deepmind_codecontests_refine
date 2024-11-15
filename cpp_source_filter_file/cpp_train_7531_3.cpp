#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int gcd[4002][4002];
int main() {
  long long w, h, ww, hh, i, j, k, kk, t, tot;
  long long ans;
  cin >> w >> h;
  for (i = 0; i <= w; i++)
    for (j = 0; j <= h; j++)
      if (i && j)
        gcd[i][j] = (i > j ? gcd[i - j][j] : gcd[i][j - i]);
      else
        gcd[i][j] = i + j;
  tot = (w + 1) * (h + 1);
  ans = tot * (tot - 1) % mod * (tot - 2) % mod;
  if (w >= 2) {
    ww = (w + 1) * w * (w - 1);
    ans = ((ans - ww * (h + 1)) % mod + mod) % mod;
  }
  if (h >= 2) {
    hh = (h + 1) * h * (h - 1);
    ans = ((ans - hh * (w + 1)) % mod + mod) % mod;
  }
  for (i = 1; i <= h; i++)
    for (j = 1; j <= w; j++) {
      k = gcd[i][j];
      t = (h - i + 1) * (w - j + 1);
      if (k >= 2) {
        kk = 6 * (k - 1);
        ans = ((ans - 2 * kk * t) % mod + mod) % mod;
      }
      t = 0;
      k = (h - i + 1) * (w - j + 1);
      if (i * j % 2 == 0)
        t += (i / 2) * (j / 2) * 4;
      else
        t += ((i - 1) * (j - 1) - (i / 2) * (j / 2)) * 4;
      if (i % 2 == 1 && j % 2 == 1) {
        t += 2 * (j - 1) + 2 * (i - 1);
        t += 2 * (((i + 1) / 2) * ((j + 1) / 2) +
                  (i + 1 - (i + 1) / 2) * (j + 1 - (j + 1) / 2));
      }
      if (i % 2 == 0 && j % 2 == 1) {
        t += 2 * (((i + 1) / 2) * (j + 1));
      }
      if (i % 2 == 1 && j % 2 == 0) {
        t += 2 * (((j + 1) / 2) * (i + 1));
      }
      ans = ((ans - (6 * k * t % mod)) % mod + mod) % mod;
    }
  cout << ans << endl;
  return 0;
}
