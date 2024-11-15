#include <bits/stdc++.h>
const double inf = 1e20;
using namespace std;
vector<int> G[3 * 100005];
map<string, int> name;
pair<int, int> cnt[3 * 100005];
int tot, n, m, x[100005];
int getid(string &s) {
  int len = (int)s.length();
  int c = 0;
  for (int i = 0; i < len; i++) {
    s[i] = tolower(s[i]);
    if (s[i] == 'r') c++;
  }
  if (name.find(s) != name.end()) {
    return name[s];
  } else {
    cnt[tot] = make_pair(c, len);
    return name[s] = tot++;
  }
}
bool cmp(int x, int y) { return cnt[x] < cnt[y]; }
string a, b;
priority_queue<int> que;
bool inq[3 * 100005];
int tt[3 * 100005];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a, x[i] = getid(a);
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    int ca = getid(a);
    int cb = getid(b);
    G[cb].push_back(ca);
  }
  for (int i = 0; i < tot; i++) tt[i] = i;
  sort(tt, tt + tot, cmp);
  for (int i = 0; i < tot; i++) {
    if (inq[tt[i]]) continue;
    que.push(tt[i]);
    inq[tt[i]] = 1;
    while (!que.empty()) {
      int v = que.top();
      que.pop();
      for (int i = 0; i < G[v].size(); i++)
        if (!inq[G[v][i]])
          cnt[G[v][i]] = cnt[v], que.push(G[v][i]), inq[G[v][i]] = 1;
    }
  }
  int r = 0, t1 = 0;
  for (int i = 0; i < n; i++) r += cnt[x[i]].first, t1 += cnt[x[i]].second;
  cout << r << " " << t1 << endl;
  return 0;
}
