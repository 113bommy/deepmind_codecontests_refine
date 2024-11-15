#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9;
const int R = 405;
struct edge {
  int u, v;
};
struct Element {
  int u, v;
  int col;
  bool in_independent_set = false;
  int independent_set_position;
  Element(int _u, int _v, int _col) { u = _u, v = _v, col = _col; }
};
vector<int> independent_set;
vector<Element> ground_set;
struct DSU {
  int f[R];
  void init(int n) {
    for (int i = 0; i < (n); ++i) f[i] = i;
  }
  int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
  void unite(int x, int y) { f[find(x)] = find(y); }
  bool same(int x, int y) { return find(x) == find(y); }
};
DSU dsu, dsu_wo[R];
int cntc = 0, cntg = 0;
bool dsu_oracle(int inserted) {
  auto &e = ground_set[inserted];
  return !dsu.same(e.u, e.v);
}
bool dsu_oracle(int inserted, int removed) {
  int wi = ground_set[removed].independent_set_position;
  auto &e = ground_set[inserted];
  return !dsu_wo[wi].same(e.u, e.v);
}
void prepare_dsu_oracle(int flag) {
  dsu.init(cntg);
  if (flag) {
    for (int i = 0; i < ((int)(independent_set).size()); ++i)
      dsu_wo[i].init(cntg);
  }
  for (int i = 0; i < ((int)(independent_set).size()); ++i) {
    int eid = independent_set[i];
    auto e = ground_set[independent_set[i]];
    dsu.unite(e.u, e.v);
    if (flag) {
      for (int j = 0; j < ((int)(independent_set).size()); ++j)
        if (i != j) {
          dsu_wo[j].unite(ground_set[eid].u, ground_set[eid].v);
        }
    }
  }
}
int cnt[R];
bool choice_oracle(int ins) {
  ins = ground_set[ins].col;
  return cnt[ins] < 2;
}
bool choice_oracle(int ins, int rem) {
  ins = ground_set[ins].col;
  rem = ground_set[rem].col;
  return ins == rem || cnt[ins] < 2;
}
void prepare_choice_oracle(int flag) {
  for (int c = 0; c < (cntc); ++c) cnt[c] = 0;
  for (auto &t : independent_set) cnt[ground_set[t].col]++;
}
bool augment(int flag) {
  prepare_dsu_oracle(flag);
  prepare_choice_oracle(flag);
  vector<int> par((int)(ground_set).size(), INF);
  int lst = -1;
  if (!flag) {
    for (int i = 0; i < ((int)(ground_set).size()); ++i) {
      if (!ground_set[i].in_independent_set && choice_oracle(i) &&
          dsu_oracle(i)) {
        par[i] = -1;
        lst = i;
      }
    }
  } else {
    queue<int> q;
    for (int i = 0; i < ((int)(ground_set).size()); ++i) {
      if (!ground_set[i].in_independent_set && choice_oracle(i)) {
        par[i] = -1;
        q.push(i);
      }
    }
    while ((int)(q).size()) {
      int cur = q.front();
      q.pop();
      if (ground_set[cur].in_independent_set) {
        for (int to = 0; to < ((int)(ground_set).size()); ++to)
          if (par[to] == INF && !ground_set[to].in_independent_set) {
            if (!choice_oracle(to, cur)) continue;
            par[to] = cur;
            q.push(to);
          }
      } else {
        if (dsu_oracle(cur)) {
          lst = cur;
          break;
        }
        for (auto &to : independent_set)
          if (par[to] == INF) {
            if (!dsu_oracle(cur, to)) continue;
            par[to] = cur;
            q.push(to);
          }
      }
    }
  }
  if (lst == -1) return false;
  do {
    ground_set[lst].in_independent_set ^= true;
    lst = par[lst];
  } while (lst != -1);
  independent_set.clear();
  for (int i = 0; i < ((int)(ground_set).size()); ++i)
    if (ground_set[i].in_independent_set) {
      ground_set[i].independent_set_position = (int)(independent_set).size();
      independent_set.push_back(i);
    }
  return true;
}
string str[22];
string ans[45];
int n, m;
int dx[] = {0, 0, -1, 1}, dy[] = {1, -1, 0, 0};
bool in_bound(int i, int j) { return i >= 0 && i < n && j >= 0 && j < m; }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    ground_set.clear();
    independent_set.clear();
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> str[i];
    cntc = 0, cntg = n * m;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if ((i + j) % 2 == 0 && !(i == 0 && j == 0) && str[i][j] != 'X') {
          for (int d = 0; d < 4; d++) {
            int ni = i + dx[d], nj = j + dy[d];
            if (in_bound(ni, nj) && str[ni][nj] != 'X') {
              ground_set.push_back(Element(i * m + j, ni * m + nj, cntc));
            }
          }
          cntc++;
        }
      }
    }
    while (true) {
      if (!augment(1)) break;
    }
    if (independent_set.size() != cntc * 2) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    for (int i = 0; i < 2 * n - 1; i++) {
      ans[i].resize(2 * m - 1, ' ');
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) ans[2 * i][2 * j] = str[i][j];
    }
    for (auto e : independent_set) {
      int i1 = ground_set[e].u / m, j1 = ground_set[e].u % m;
      int i2 = ground_set[e].v / m, j2 = ground_set[e].v % m;
      ans[i1 + i2][j1 + j2] = 'O';
    }
    prepare_dsu_oracle(0);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (str[i][j] == 'X') continue;
        for (int d = 0; d < 4; d++) {
          int ni = i + dx[d], nj = j + dy[d];
          if (in_bound(ni, nj) && str[ni][nj] != 'X') {
            if (!dsu.same(i * m + j, ni * m + nj)) {
              dsu.unite(i * m + j, ni * m + nj);
              ans[i + ni][j + nj] = 'O';
            }
          }
        }
      }
    }
    for (int i = 0; i < 2 * n - 1; i++) cout << ans[i] << '\n';
  }
}
