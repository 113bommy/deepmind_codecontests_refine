#include <bits/stdc++.h>
using namespace std;
void read(int &x) {
  int v = 0, f = 1;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = v * 10 + c - '0';
  while (isdigit(c = getchar())) v = v * 10 + c - '0';
  x = v * f;
}
void read(long long &x) {
  long long v = 0ll, f = 1ll;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = v * 10 + c - '0';
  while (isdigit(c = getchar())) v = v * 10 + c - '0';
  x = v * f;
}
void readc(char &x) {
  char c;
  while ((c = getchar()) == ' ')
    ;
  x = c;
}
void writes(string s) { puts(s.c_str()); }
void writeln() { writes(""); }
void writei(int x) {
  if (x < 0) {
    putchar('-');
    x = abs(x);
  }
  if (!x) putchar('0');
  char a[25];
  int top = 0;
  while (x) {
    a[++top] = (x % 10) + '0';
    x /= 10;
  }
  while (top) {
    putchar(a[top]);
    top--;
  }
}
void writell(long long x) {
  if (x < 0) {
    putchar('-');
    x = abs(x);
  }
  if (!x) putchar('0');
  char a[25];
  int top = 0;
  while (x) {
    a[++top] = (x % 10) + '0';
    x /= 10;
  }
  while (top) {
    putchar(a[top]);
    top--;
  }
}
inline long long inc(int &x) { return ++x; }
inline long long inc(long long &x) { return ++x; }
inline long long inc(int &x, long long y) { return x += y; }
inline long long inc(long long &x, long long y) { return x += y; }
inline double inc(double &x, double y) { return x += y; }
inline long long dec(int &x) { return --x; }
inline long long dec(long long &x) { return --x; }
inline long long dec(int &x, long long y) { return x -= y; }
inline long long dec(long long &x, long long y) { return x -= y; }
inline double dec(double &x, double y) { return x -= y; }
inline long long mul(int &x) { return x = ((long long)x) * x; }
inline long long mul(long long &x) { return x = x * x; }
inline long long mul(int &x, long long y) { return x *= y; }
inline long long mul(long long &x, long long y) { return x *= y; }
inline double mul(double &x, double y) { return x *= y; }
inline long long divi(const int &x) {
  long long ans, l, r, mid;
  ans = 0;
  l = 0;
  r = 0x3fffffff;
  while (l < r) {
    mid = (l + r) / 2;
    if (mid * mid <= x) {
      ans = mid;
      l = mid + 1;
    } else
      r = mid;
  }
  return ans;
}
inline long long divi(const long long &x) {
  long long ans, l, r, mid;
  ans = 0;
  l = 0;
  r = 0x3fffffff;
  while (l < r) {
    mid = (l + r) / 2;
    if (mid * mid <= x) {
      ans = mid;
      l = mid + 1;
    } else
      r = mid;
  }
  return ans;
}
inline long long divi(int &x, long long y) { return x /= y; }
inline long long divi(long long &x, long long y) { return x /= y; }
inline double divi(double &x, double y) { return x /= y; }
inline long long mod(int &x, long long y) { return x %= y; }
inline long long mod(long long &x, long long y) { return x %= y; }
int n, m, i, j, dis[21777], cnt, x, y, z, op, typ[5005], bel[5005], l[21777],
    r[21777], s = 0, t = 21775;
vector<pair<pair<int, int>, int> > v;
struct ed {
  int fr, y, c, re, id;
} e[380005];
vector<int> bi[21777];
void init() {
  int i;
  cnt = 0;
  for (i = 1; i <= n; i++) bi[i].clear();
}
bool bfs(int st, int ed) {
  int i;
  queue<int> qx;
  memset(dis, -1, sizeof(dis));
  dis[st] = 0;
  qx.push(st);
  while (!qx.empty()) {
    int x = qx.front();
    qx.pop();
    for (i = 0; i < bi[x].size(); i++) {
      if (e[bi[x][i]].y != st && e[bi[x][i]].c > 0 &&
          dis[e[bi[x][i]].y] == -1) {
        dis[e[bi[x][i]].y] = dis[x] + 1;
        qx.push(e[bi[x][i]].y);
      }
    }
  }
  if (dis[ed] == -1) return 0;
  return 1;
}
int dfs(int x, int ed, int flw) {
  if (x == ed) {
    return flw;
  }
  int i, res = 0;
  for (i = 0; i < bi[x].size(); i++) {
    if (dis[x] + 1 == dis[e[bi[x][i]].y] && e[bi[x][i]].c > 0) {
      int t = dfs(e[bi[x][i]].y, ed, min(e[bi[x][i]].c, flw));
      e[bi[x][i]].c -= t;
      e[e[bi[x][i]].re].c += t;
      flw -= t;
      res += t;
      if (flw < 1) break;
    }
  }
  if (res == 0) dis[x] = -123456;
  return res;
}
int maxflow(int st, int ed) {
  int ans = 0;
  while (bfs(st, ed)) ans += dfs(st, ed, 0x22222222);
  return ans;
}
void add(int x, int y, int sz, int id = 0) {
  cnt += 2;
  e[cnt - 1] = {x, y, sz, cnt, id};
  e[cnt] = {y, x, 0, cnt - 1, id};
  bi[x].push_back(cnt - 1);
  bi[y].push_back(cnt);
}
void build(int x, int le, int ri) {
  l[x] = le;
  r[x] = ri;
  if (le == ri) return;
  add(x + n, x * 2 + n, 10000);
  add(x + n, x * 2 + 1 + n, 10000);
  build(x * 2, le, (le + ri) / 2);
  build(x * 2 + 1, (le + ri) / 2 + 1, ri);
}
void upd(int fr, int x, int le, int ri) {
  if (l[x] > ri || r[x] < le) return;
  if (l[x] >= le && r[x] <= ri) {
    add(fr, x + n, 1);
    return;
  }
  upd(fr, x * 2, le, ri);
  upd(fr, x * 2 + 1, le, ri);
}
bool cmp(pair<pair<int, int>, int> x, pair<pair<int, int>, int> y) {
  return make_pair(make_pair(x.first.second, x.first.first), x.second) <
         make_pair(make_pair(y.first.second, y.first.first), y.second);
}
int main() {
  ios_base::sync_with_stdio(false);
  ;
  cin >> n >> m;
  build(1, 1, 8192);
  if ((1) <= ((n)))
    for (((i)) = (1); ((i)) <= ((n)); ((i))++) {
      cin >> op;
      typ[i] = op;
      if (op == 0) {
        cin >> x;
        while (x--) {
          cin >> y;
          add(i, 8191 + y + n, 1);
        }
      }
      if (op == 1) {
        cin >> x >> y;
        upd(i, 1, x, y);
        v.push_back(make_pair(make_pair(y, x), i));
      }
      if (op == 2) {
        cin >> x >> y >> z;
        add(i, 8191 + x + n, 1);
        add(i, 8191 + y + n, 1);
        add(i, 8191 + z + n, 1);
      }
    }
  stable_sort((v).begin(), (v).end(), cmp);
  for (i = 1; i <= n; i++) {
    if (typ[i] == 2) add(s, i, 2);
  }
  for (i = 1; i <= n; i++) {
    if (typ[i] != 2) add(s, i, 1);
  }
  for (i = 1; i <= m; i++) add(i + 8191 + n, t, 1);
  cout << maxflow(s, t) << endl;
  for (i = 1; i <= m; i++) {
    for (__typeof((bi[i + n + 8191]).begin()) it = (bi[i + n + 8191]).begin();
         it != (bi[i + n + 8191]).end(); it++) {
      if (e[*it].y != t && e[*it].c > 0) {
        bel[i] = e[*it].y;
      }
    }
  }
  set<pair<pair<int, int>, int> > s;
  int pnt = 0;
  for (i = 1; i <= m; i++) {
    if (bel[i] > n || typ[bel[i]] == 1) {
      while (pnt < v.size() && v[pnt].first.second <= i) s.insert(v[pnt++]);
      while (!s.empty() && s.begin()->first.first < i) s.erase(s.begin());
      bel[i] = 0;
      if (!s.empty()) {
        bel[i] = s.begin()->second;
        s.erase(s.begin());
      }
    }
  }
  if ((1) <= ((m)))
    for (((i)) = (1); ((i)) <= ((m)); ((i))++)
      if (bel[i]) cout << bel[i] << ' ' << i << endl;
  return 0;
}
