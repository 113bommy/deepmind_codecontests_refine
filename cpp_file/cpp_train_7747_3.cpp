#include <bits/stdc++.h>
using namespace std;
double PI = acos(-1);
double EPS = 1e-7;
int INF = 1000000000;
int MOD = 1000000007;
int MAXINT = 2147483647;
long long INFLL = 1000000000000000000LL;
long long MAXLL = 9223372036854775807LL;
int mx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int my[8] = {0, 0, -1, 1, -1, 1, -1, 1};
int n[3];
int m[3];
int tot;
vector<int> adj[3][200005];
vector<int> adj3[3][200005];
vector<int> adj2[3][200005];
long long dp[3][200005][8];
map<int, pair<int, long long> > dp2[3][200005];
int sz[3][200005];
long long maxi[3];
void traverse(int id, int k, int par) {
  sz[id][k] = 1;
  for (int(a) = (0); (a) <= ((int)adj[id][k].size() - 1); (a)++) {
    if (adj[id][k][a] == par) continue;
    adj3[id][k].push_back(adj[id][k][a]);
    traverse(id, adj[id][k][a], k);
    sz[id][k] += sz[id][adj[id][k][a]];
  }
}
void rebuild(int id, int k) {
  int ls = k;
  for (int(a) = (0); (a) <= ((int)adj3[id][k].size() - 1); (a)++) {
    int v = adj3[id][k][a];
    adj2[id][ls].push_back(v);
    rebuild(id, v);
    adj2[id][ls].push_back(++m[id]);
    ls = m[id];
  }
}
pair<int, long long> precalc(int id, int k, int par) {
  if (dp2[id][k].count(par)) return dp2[id][k][par];
  pair<int, long long> &ret = dp2[id][k][par];
  ret.first = 1;
  for (int(a) = (0); (a) <= ((int)adj[id][k].size() - 1); (a)++) {
    if (adj[id][k][a] == par) continue;
    ret.first += precalc(id, adj[id][k][a], k).first;
    ret.second += precalc(id, adj[id][k][a], k).second;
  }
  ret.second += ret.first * (tot - ret.first);
  return ret;
}
pair<int, long long> calc(int id, int k, int par) {
  if (dp2[id][k].count(par)) return dp2[id][k][par];
  pair<int, long long> &ret = dp2[id][k][par];
  if (par) {
    pair<int, long long> tmp = calc(id, k, 0);
    tmp.second -= tmp.first * (tot - tmp.first);
    tmp.first -= calc(id, par, k).first;
    tmp.second -= calc(id, par, k).second;
    tmp.second += tmp.first * (tot - tmp.first);
    ret = tmp;
  } else {
    ret.first = 1;
    for (int(a) = (0); (a) <= ((int)adj[id][k].size() - 1); (a)++) {
      if (adj[id][k][a] == par) continue;
      ret.first += calc(id, adj[id][k][a], k).first;
      ret.second += calc(id, adj[id][k][a], k).second;
    }
    ret.second += ret.first * (tot - ret.first);
  }
  return ret;
}
long long go(int id, int k, int mask) {
  if (dp[id][k][mask] != -1) return dp[id][k][mask];
  long long &ret = dp[id][k][mask];
  int sze = sz[id][k];
  for (int(a) = (0); (a) <= (2); (a)++) {
    if (mask & (1 << a)) sze += n[a];
  }
  ret = 0;
  if (n[id] >= k) ret = (long long)sze * (long long)(tot - sze);
  vector<int> child;
  for (int(a) = (0); (a) <= ((int)adj2[id][k].size() - 1); (a)++) {
    child.push_back(adj2[id][k][a]);
  }
  if ((int)child.size() == 0) {
    for (int(a) = (0); (a) <= (2); (a)++) {
      if (mask & (1 << a)) ret += maxi[a];
    }
  }
  if ((int)child.size() == 1) {
    long long maks = 0;
    for (int(mask2) = (0); (mask2) <= ((1 << 3) - 1); (mask2)++) {
      if ((mask2 & mask) == mask2) {
        int mask3 = mask ^ mask2;
        long long cur = 0;
        for (int(a) = (0); (a) <= (2); (a)++) {
          if (mask2 & (1 << a)) cur += maxi[a];
        }
        (maks) = max((maks), (cur + go(id, child[0], mask3)));
      }
    }
    ret += maks;
  }
  if ((int)child.size() == 2) {
    long long maks = 0;
    for (int(mask2) = (0); (mask2) <= ((1 << 3) - 1); (mask2)++) {
      if ((mask2 & mask) == mask2) {
        int res = mask ^ mask2;
        for (int(mask3) = (0); (mask3) <= ((1 << 3) - 1); (mask3)++) {
          if ((mask3 & res) == mask3) {
            int mask4 = res ^ mask3;
            long long cur = 0;
            for (int(a) = (0); (a) <= (2); (a)++) {
              if (mask2 & (1 << a)) cur += maxi[a];
            }
            (maks) = max((maks), (cur + go(id, child[0], mask3) +
                                  go(id, child[1], mask4)));
          }
        }
      }
    }
    ret += maks;
  }
  return ret;
}
int val[3][200005];
pair<int, int> cl(int id, int u) {
  pair<int, int> lol = make_pair(val[id][u], 0);
  for (int(a) = (0); (a) <= ((int)adj3[id][u].size() - 1); (a)++) {
    pair<int, int> tmp = cl(id, adj3[id][u][a]);
    lol.first += tmp.first;
    lol.second += tmp.second;
  }
  lol.second += (lol.first) * (tot - lol.first);
  return lol;
}
int main() {
  for (int(a) = (0); (a) <= (2); (a)++) scanf("%d", &n[a]);
  tot = n[0] + n[1] + n[2];
  m[0] = n[0];
  m[1] = n[1];
  m[2] = n[2];
  for (int(a) = (0); (a) <= (2); (a)++) {
    for (int(b) = (1); (b) <= (n[a] - 1); (b)++) {
      int u, v;
      scanf("%d%d", &u, &v);
      adj[a][u].push_back(v);
      adj[a][v].push_back(u);
    }
  }
  int root = 1;
  for (int(a) = (0); (a) <= (2); (a)++) {
    traverse(a, root, 0);
    rebuild(a, root);
    precalc(a, 1, 0);
    for (int(b) = (1); (b) <= (n[a]); (b)++) {
      (maxi[a]) = max((maxi[a]), (calc(a, b, 0).second));
    }
  }
  memset(dp, -1, sizeof(dp));
  long long maks = 0;
  for (int(a) = (0); (a) <= (2); (a)++) {
    (maks) = max((maks), (go(a, 1, 7 ^ (1 << a))));
  }
  cout << maks << endl;
}
