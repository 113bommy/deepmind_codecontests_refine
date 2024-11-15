#include <bits/stdc++.h>
using namespace std;
struct data {
  int x, y, val, minVal, rMin;
  data(int X, int Y) {
    x = X;
    y = Y;
    val = 0;
    minVal = 1e9;
    rMin = 1e9;
  }
};
vector<data> a[int(1e5 + 100)];
int Small, n, m, p;
bool cmp(data x, data y) { return x.val < y.val; }
bool cmp2(data x, data y) { return x.x < y.x; }
int dist(data x, data y) { return abs(x.x - y.x) + abs(x.y - y.y); }
int main() {
  cin >> n >> m >> p;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      int x;
      scanf("%d", &x);
      a[x].push_back(data(i, j));
    }
  Small = 1e9;
  for (int i = 0; i < a[1].size(); i++) {
    a[1][i].val = a[1][i].x + a[1][i].y - 2;
    a[1][i].rMin = a[1][i].val;
    a[1][i].minVal = a[1][i].val;
    Small = min(Small, a[1][i].val);
  }
  sort(a[1].begin(), a[1].end(), cmp);
  for (int i = 1; i < a[1].size(); i++)
    a[1][i].minVal = min(a[1][i - 1].minVal, a[1][i].val);
  for (int i = int(a[1].size()) - 2; i >= 0; i--)
    a[1][i].rMin = min(a[1][i + 1].rMin, a[1][i].val);
  int l = max(0, int(a[1].size()) - n - m);
  int x = a[1].size() - 1;
  while (a[1][x].val - Small > n + m) {
    l++;
    x--;
  }
  sort(a[1].begin(), a[1].begin() + int(a[1].size()) - l, cmp2);
  for (int i = 2; i <= p; i++) {
    Small = 1e9;
    for (int j = 0; j < a[i].size(); j++) {
      int tmp = 1e9;
      for (int k = 0; k < a[i - 1].size() - l; k++)
        tmp = min(tmp, dist(a[i][j], a[i - 1][k]) + a[i - 1][k].val);
      Small = min(Small, tmp);
      a[i][j].val = tmp;
    }
    l = max(0, int(a[i].size()) - n - m);
    sort(a[i].begin(), a[i].end(), cmp);
    a[i][0].minVal = a[i][0].val;
    a[i][a[i].size() - 1].rMin = a[i][a[i].size() - 1].val;
    int x = a[i].size() - l - 1;
    while (a[i][x].val - Small > n + m) {
      l++;
      x--;
    }
    sort(a[i].begin(), a[i].begin() + int(a[i].size()) - l, cmp2);
  }
  int ans = Small;
  cout << ans;
}
