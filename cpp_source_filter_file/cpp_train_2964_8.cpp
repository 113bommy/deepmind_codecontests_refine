#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000;
int n;
vector<pair<int, int> > edge[200000];
bool onCircle[maxn];
bool vis[maxn];
long long down[maxn];
long long up[maxn];
int cnt[maxn];
int dis[maxn * 3];
int circle[maxn * 3];
int num[maxn * 3];
int m;
int findCircle(int u, int pre) {
  if (vis[u]) return u;
  vis[u] = true;
  for (vector<pair<int, int> >::iterator it = edge[u].begin();
       it != edge[u].end(); it++) {
    int v = it->first;
    if (v == pre) continue;
    int t = findCircle(v, u);
    if (t != -1) {
      circle[m] = v;
      dis[m++] = it->second;
      onCircle[v] = true;
      return t == u ? -1 : t;
    }
  }
  return -1;
}
void godown(int u, int pre) {
  for (vector<pair<int, int> >::iterator it = edge[u].begin();
       it != edge[u].end(); it++) {
    int v = it->first;
    if (v == pre || onCircle[v]) continue;
    godown(v, u);
    cnt[u] += cnt[v];
    down[u] += cnt[v] * it->second + down[u];
  }
}
void goup(int u, int pre) {
  for (vector<pair<int, int> >::iterator it = edge[u].begin();
       it != edge[u].end(); it++) {
    int v = it->first;
    if (v == pre || onCircle[v]) continue;
    up[v] = up[u] + down[u] - down[v] + (n - 2 * cnt[v]) * it->second;
    godown(v, u);
  }
}
void calcCircle() {
  long long tots = 0;
  for (int i = 0; i < m; i++) {
    tots += down[circle[i]];
    num[i] = num[i + m] = num[i + m + m] = cnt[circle[i]];
    circle[i + m] = circle[i + m + m] = circle[i];
    dis[i + m] = dis[i + m + m] = dis[i];
  }
  int leftd = 0, rightd = 0;
  int leftc = 0, rightc = 0;
  long long lefts = 0, rights = 0;
  int l = m, r = m, it = m;
  int T = m - 1;
  while (T--) {
    if (leftd + dis[l - 1] <= rightd + dis[r]) {
      l--;
      leftd += dis[l];
      leftc += num[l];
      lefts += num[l] * leftd;
    } else {
      rightd += dis[r];
      rightc += num[r + 1];
      rights += num[r + 1] * rightd;
      r++;
    }
  }
  up[circle[it]] = lefts + rights + tots - down[circle[it]];
  T = m - 1;
  while (T--) {
    leftc += num[it];
    leftd += dis[it];
    lefts += dis[it] * leftc;
    rights -= dis[it] * rightc;
    rightc -= num[it + 1];
    rightd -= dis[it];
    it++;
    while (leftd > rightd + dis[r]) {
      lefts -= num[l] * leftd;
      leftd -= dis[l];
      leftc -= num[l];
      l++;
      rightd += dis[r];
      rightc += num[r + 1];
      rights += num[r + 1] * rightd;
      r++;
    }
    up[circle[it]] = lefts + rights + tots - down[circle[it]];
  }
}
void init() {
  for (int i = 0; i < n; i++) {
    edge[i].clear();
    vis[i] = false;
    onCircle[i] = false;
    cnt[i] = 1;
    down[i] = up[i] = 0;
  }
  m = 0;
}
void input() {
  for (int i = 0; i < n; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    a--, b--;
    edge[a].push_back(make_pair(b, c));
    edge[b].push_back(make_pair(a, c));
  }
}
int main() {
  while (~scanf("%d", &n)) {
    init();
    input();
    findCircle(0, -1);
    for (int i = 0; i < m; i++) {
      godown(circle[i], -1);
    }
    calcCircle();
    for (int i = 0; i < m; i++) {
      goup(circle[i], -1);
    }
    for (int i = 0; i < n; i++) {
      printf("%I64d%c", up[i] + down[i], i == n - 1 ? '\n' : ' ');
    }
  }
  return 0;
}
