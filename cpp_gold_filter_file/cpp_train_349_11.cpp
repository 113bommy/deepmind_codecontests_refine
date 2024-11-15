#include <bits/stdc++.h>
using namespace std;
int hashu[505][505];
int ar[501][501];
int xline[250001], yline[250001], fline[250001];
int main() {
  int n, m, a, b;
  cin >> n >> m;
  memset(ar, 0, sizeof(ar));
  memset(hashu, -1, sizeof(hashu));
  for (int i = 0; i < m; ++i) {
    cin >> a >> b;
    ar[a][++ar[a][0]] = b;
    ar[b][++ar[b][0]] = a;
  }
  int fin = 0, l = 1, r = 1;
  xline[l] = 1, yline[l] = n;
  hashu[1][n] = 0;
  while (l <= r) {
    int nowx = xline[l];
    int nowy = yline[l];
    for (int x = 1; x <= ar[nowx][0]; ++x) {
      for (int y = 1; y <= ar[nowy][0]; ++y) {
        int nex = ar[nowx][x], ney = ar[nowy][y];
        if (hashu[nex][ney] == -1 && nex != ney) {
          ++r;
          hashu[nex][ney] = hashu[nowx][nowy] + 1;
          xline[r] = nex;
          yline[r] = ney;
          fline[r] = l;
          if (xline[r] == n && yline[r] == 1) fin = r;
        }
      }
    }
    if (fin) break;
    ++l;
  }
  cout << hashu[n][1] << endl;
  if (hashu[n][1] == 0) {
    cout << l << " " << r << endl;
  }
  if (hashu[n][1] == -1) return 0;
  int now = fin;
  while (true) {
    cout << yline[now] << " ";
    if (now == 1) break;
    now = fline[now];
  }
  now = fin;
  cout << endl;
  while (true) {
    cout << xline[now] << " ";
    if (now == 1) break;
    now = fline[now];
  }
  cout << endl;
}
