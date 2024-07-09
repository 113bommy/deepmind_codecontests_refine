#include <bits/stdc++.h>
using namespace std;
bool judge(char s[3]) {
  if (s[0] == 'A' && s[1] == 'T' && s[2] == 'K')
    return 1;
  else
    return 0;
}
long long Max(long long a, long long b) {
  if (a > b)
    return a;
  else
    return b;
}
int main() {
  int n, m, i, p, q, x, j;
  long long maxn = 0, mmaxn = 0, s1 = 0, s2 = 0, s3 = 0;
  int a[101], d[101], b[101];
  cin >> n >> m;
  char s[3];
  for (i = 0, p = 0, q = 0; i < n; i++) {
    scanf("%s", &s);
    scanf("%d", &x);
    if (judge(s)) {
      a[p++] = x;
      s1 += x;
    } else {
      d[q++] = x;
      s2 += x;
    }
  }
  for (i = 0; i < m; i++) {
    scanf("%d", &b[i]);
    s3 += b[i];
  }
  sort(a, a + p);
  sort(d, d + q);
  sort(b, b + m);
  for (i = m - 1, j = 0; i >= 0 && j < p; i--) {
    if (b[i] >= a[j]) {
      maxn += b[i] - a[j];
      j++;
    }
  }
  if (s1 + s2 < s3) {
    int r;
    int rr = 0;
    for (r = 0; r < q; r++) {
      for (j = 0; j < m; j++) {
        if (b[j] > d[r]) {
          ++rr;
          s3 -= b[j];
          b[j] = 10000;
          sort(b, b + m);
          --m;
          break;
        }
      }
    }
    for (i = 0, j = 0; i < m && j < p; i++) {
      if (b[i] >= a[j]) {
        mmaxn += b[i] - a[j];
        j++;
        s3 -= b[i];
      }
    }
    if (j == p && rr == q) {
      mmaxn += s3;
    }
  }
  maxn = Max(maxn, mmaxn);
  cout << maxn << endl;
  return 0;
}
