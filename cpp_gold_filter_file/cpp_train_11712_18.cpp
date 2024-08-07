#include <bits/stdc++.h>
const int N = 1010;
const int inf = 0x3f3f3f3f;
using namespace std;
int n, m;
long long cnt[N][N];
char s[N][N];
long long getsum(int a, int b) { return 1ll * a * b * (a + b + 2ll) / 2ll; }
struct data {
  int x, y;
  data() {}
  data(int x, int y) : x(x), y(y) {}
} da[N];
bool cmpx(const data &a, const data &b) { return a.x < b.x; }
bool cmpy(const data &a, const data &b) { return a.y < b.y; }
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> s[i][j];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      cnt[i][j] = getsum(i - 1, j - 1) + getsum(i - 1, m - j) +
                  getsum(n - i, j - 1) + getsum(n - i, m - j) +
                  i * (i - 1) / 2 + (j - 1) * j / 2 +
                  (n - i) * (n - i + 1) / 2 + (m - j) * (m - j + 1) / 2;
    }
  int k = 0;
  long long sum = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (s[i][j] == 'X')
        sum -= cnt[i][j], da[k++] = data(i, j);
      else
        sum += cnt[i][j];
  sort(da, da + k, cmpx);
  for (int i = 0; i < k; i++) {
    long long t = m - da[i].y;
    for (int j = i + 1; j < k; j++) {
      if (da[j].x - 1 != da[j - 1].x) break;
      if (da[j].y < da[j - 1].y) break;
      t += m - da[j].y;
    }
    for (int j = i - 1; j >= 0; j--) {
      if (da[j].x + 1 != da[j + 1].x) break;
      if (da[j].y < da[j + 1].y) break;
      t += m - da[j].y;
    }
    sum += t * 4 * (da[i].y - 1);
  }
  sort(da, da + k, cmpy);
  for (int i = 0; i < k; i++) {
    long long t = n - da[i].x;
    for (int j = i + 1; j < k; j++) {
      if (da[j].y - 1 != da[j - 1].y) break;
      if (da[j].x < da[j - 1].x) break;
      t += n - da[j].x;
    }
    for (int j = i - 1; j >= 0; j--) {
      if (da[j].y + 1 != da[j + 1].y) break;
      if (da[j].x < da[j + 1].x) break;
      t += n - da[j].x;
    }
    sum += t * 4 * (da[i].x - 1);
  }
  for (int i = 0; i < k; i++)
    for (int j = i + 1; j < k; j++)
      sum += 2 * fabs(da[i].x - da[j].x) + 2 * fabs(da[i].y - da[j].y);
  printf("%.12f\n", 1.0 * sum / (n * m - k) / (n * m - k));
  return 0;
}
