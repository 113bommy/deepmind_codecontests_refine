#include <bits/stdc++.h>
using namespace std;
string a[16], b[16], c[16];
int r[6];
map<string, int> Map;
string str[5];
int cnt;
int x, y;
int aa[6], bb[6], cc[6];
bool vis[4][4];
const string tr = "BERLAND";
int op, rt;
bool cmp(int i, int j) {
  if (aa[i] != aa[j]) return aa[i] > aa[j];
  if (bb[i] != bb[j]) return bb[i] > bb[j];
  if (cc[i] != cc[j]) return cc[i] > cc[j];
  return str[i] < str[j];
}
int main() {
  int i, j;
  cnt = 0;
  for (i = 0; i < 5; i++) {
    cin >> a[i] >> b[i] >> c[i];
    x = c[i][0] - '0';
    y = c[i][2] - '0';
    if (Map.find(a[i]) == Map.end()) str[cnt] = a[i], Map[a[i]] = cnt++;
    if (Map.find(b[i]) == Map.end()) str[cnt] = b[i], Map[b[i]] = cnt++;
    int ta = Map[a[i]], tb = Map[b[i]];
    if (x > y) aa[ta] += 3;
    if (x == y) aa[ta] += 1, aa[tb] += 1;
    if (x < y) aa[tb] += 3;
    bb[ta] += x - y, bb[tb] += y - x;
    cc[ta] += x, cc[tb] += y;
    vis[ta][tb] = vis[tb][ta] = 1;
  }
  rt = Map[tr];
  for (int i = 0; i < 4; i++) {
    if (i != rt && !vis[rt][i]) {
      op = i;
      break;
    }
  }
  int xx = -1, yy;
  aa[rt] += 3;
  for (i = 0; i < 10; i++)
    for (j = 0; j < i; j++) {
      for (int k = 0; k < 4; k++) r[k] = k;
      bb[rt] += i - j, bb[op] += j - i;
      cc[rt] += i, cc[op] += j;
      sort(r, r + 4, cmp);
      if ((r[0] == rt || r[1] == rt) &&
          (xx == -1 || (i - j < xx - yy || (i - j == xx - yy && j < yy))))
        xx = i, yy = j;
      bb[rt] -= i - j, bb[op] -= j - i;
      cc[rt] -= i, cc[op] -= j;
    }
  if (xx != -1)
    cout << xx << ":" << yy << endl;
  else
    cout << "IMPOSSIBLE" << endl;
}
