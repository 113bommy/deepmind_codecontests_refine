#include <bits/stdc++.h>
using namespace std;
int n, ans = 0x3f3f3f3f, dis[1000015];
bool gkp[1000015];
vector<int> a, p, e[1000015];
queue<int> q;
int check(int x) {
  for (int i = 2; i * i <= x; ++i) {
    if (x % i) continue;
    int cnt = 0;
    while (x % i == 0) {
      cnt++;
      x /= i;
    }
    if (cnt % 2 == 1) x *= i;
  }
  return x;
}
void bfs(int x) {
  for (int i = 0; i < p.size(); ++i) dis[p[i]] = 0x3f3f3f3f, gkp[p[i]] = 0;
  while (!q.empty()) q.pop();
  q.push(x);
  gkp[x] = 1;
  dis[x] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    gkp[u] = 0;
    for (int i = 0; i < e[u].size(); ++i) {
      int v = e[u][i];
      if (dis[v] > dis[u] + 1) {
        dis[v] = dis[u] + 1;
        q.push(v);
        gkp[v] = 1;
      } else if (gkp[v])
        ans = min(ans, dis[u] + dis[v] + 1);
    }
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    int temp;
    scanf("%d", &temp);
    a.push_back(check(temp));
  }
  sort(a.begin(), a.end());
  if (a[0] == 1) {
    puts("1");
    return 0;
  }
  a.erase(unique(a.begin(), a.end()), a.end());
  if (a.size() < n) {
    puts("2");
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    int cur[2];
    cur[0] = i;
    cur[1] = -1;
    for (int j = 2; j * j <= a[i]; ++j) {
      if (a[i] % j) continue;
      cur[0] = j;
      if ((a[i] / j) != 1) cur[1] = a[i] / j;
      break;
    }
    if (cur[1] == -1) cur[1] = 1;
    p.push_back(cur[0]);
    p.push_back(cur[1]);
    e[cur[0]].push_back(cur[1]);
    e[cur[1]].push_back(cur[0]);
  }
  sort(p.begin(), p.end());
  p.erase(unique(p.begin(), p.end()), p.end());
  for (int i = 1; i <= 1000; ++i) {
    if (e[i].empty()) continue;
    bfs(i);
  }
  if (ans == 0x3f3f3f3f)
    printf("-1");
  else
    printf("%d", ans);
  return 0;
}
