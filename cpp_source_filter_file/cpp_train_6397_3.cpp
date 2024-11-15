#include <bits/stdc++.h>
using namespace std;
const long long inf = 1000000007;
const int maxn = 101000 * 2;
int cnt, tal;
int f[maxn], len[maxn], nex[maxn][26];
void add(int c, int m) {
  len[++cnt] = m;
  int p = tal;
  for (; p != -1 && !nex[p][c]; p = f[p]) nex[p][c] = cnt;
  tal = cnt;
  if (p == -1)
    f[tal] = 0;
  else {
    if (len[nex[p][c]] == len[p] + 1)
      f[tal] = nex[p][c];
    else {
      len[++cnt] = len[p] + 1;
      int tmp = nex[p][c];
      f[cnt] = f[tmp];
      for (int i = 0; i < 26; ++i) nex[cnt][i] = nex[tmp][i];
      f[tal] = f[tmp] = cnt;
      for (; p != -1 && nex[p][c] == tmp; p = f[p]) nex[p][c] = cnt;
    }
  }
}
vector<pair<int, int> > vec[maxn];
void down(const string &s, int k) {
  for (int i = 0, length = s.length(), pos = 0, slen = 0; i < length; ++i) {
    int ii = s[i] - 'a';
    while (pos && !nex[pos][ii]) {
      pos = f[pos];
      slen = len[pos];
    }
    pos = nex[pos][ii];
    slen += (pos > 0);
    vec[pos].push_back(make_pair(slen, k));
  }
}
long long num[maxn], cc[maxn][3];
void up(int slen, int pos, int k, long long c) {
  cc[pos][k] = (cc[pos][k] + c) % inf;
  num[slen] =
      (num[slen] + cc[pos][(k + 1) % 3] * cc[pos][(k + 2) % 3] % inf * c) % inf;
}
int r[maxn];
bool cmp(const int &i, const int &j) { return len[i] < len[j]; }
int main() {
  string a, b, c;
  cin >> a >> b >> c;
  if (a.length() > b.length()) swap(a, b);
  if (a.length() > b.length()) swap(a, b);
  tal = cnt = 0;
  f[0] = -1;
  len[0] = 0;
  for (int i = 0; i < 26; ++i) nex[0][i] = 0;
  for (int i = 0; i < a.length(); ++i) add(a[i] - 'a', i + 1);
  down(a, 0);
  down(b, 1);
  down(c, 2);
  for (int i = 1; i <= cnt; ++i) r[i] = i;
  sort(r + 1, r + 1 + cnt, cmp);
  for (int ii = cnt; ii > 0; --ii) {
    int i = r[ii];
    sort(vec[i].begin(), vec[i].end());
    for (int j = vec[i].size(); j > 0; --j)
      up(vec[i][j - 1].first, i, vec[i][j - 1].second, 1);
    int fa = f[i];
    num[len[fa]] =
        ((num[len[fa]] - cc[i][0] * cc[i][1] % inf * cc[i][2]) % inf + inf) %
        inf;
    up(len[fa], fa, 0, cc[i][0]);
    up(len[fa], fa, 1, cc[i][1]);
    up(len[fa], fa, 2, cc[i][2]);
  }
  for (int i = a.length(); i > 0; --i) num[i - 1] = (num[i - 1] + num[i]) % inf;
  for (int i = 1; i <= a.length(); ++i) cout << num[i] << " ";
  cout << endl;
  return 0;
}
