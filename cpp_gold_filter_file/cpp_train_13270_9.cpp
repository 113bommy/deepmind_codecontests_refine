#include <bits/stdc++.h>
using namespace std;
const int MAXN = 23;
const int INF = 1 << 30;
const int stepx[4] = {0, 0, 1, -1};
const int stepy[4] = {1, -1, 0, 0};
struct person {
  int x, y;
  long long speed;
};
struct edge {
  int from, to, cap, flow;
};
int n, m, male, female;
vector<person> males;
vector<person> females;
vector<edge> edges;
vector<int> net[10 * MAXN * MAXN];
queue<person> Q;
queue<int> netQ;
int nets, netm, netr1[10 * MAXN * MAXN], netr2[10 * MAXN * MAXN], netf, nett;
int maps[MAXN][MAXN];
int visit[MAXN][MAXN];
int netvisit[10 * MAXN * MAXN];
int dis[10 * MAXN * MAXN];
int cur[10 * MAXN * MAXN];
int netbfs() {
  memset(netvisit, 0, sizeof(netvisit));
  netQ.push(nets);
  dis[nets] = 0;
  netvisit[nets] = 1;
  while (!netQ.empty()) {
    int x = netQ.front();
    netQ.pop();
    for (int i = 0; i < net[x].size(); i++) {
      edge e = edges[net[x][i]];
      if (!netvisit[e.to] && e.cap > e.flow) {
        netvisit[e.to] = true;
        dis[e.to] = dis[x] + 1;
        netQ.push(e.to);
      }
    }
  }
  return netvisit[nett];
}
int netdfs(int x, int a) {
  if (x == nett || a == 0) return a;
  int flow = 0, f;
  for (int &i = cur[x]; i < net[x].size(); i++) {
    edge &e = edges[net[x][i]];
    if (dis[x] + 1 == dis[e.to] &&
        (f = netdfs(e.to, min(a, e.cap - e.flow))) > 0) {
      e.flow += f;
      edges[net[x][i] ^ 1].flow -= f;
      flow += f;
      a -= f;
      if (a == 0) break;
    }
  }
  return flow;
}
int addedge(int a, int b, int c) {
  edges.push_back((edge){a, b, c, 0});
  edges.push_back((edge){b, a, 0, 0});
  int temp = edges.size();
  net[a].push_back(temp - 2);
  net[b].push_back(temp - 1);
  return 0;
}
int bfsinit(int a, int b, long long c) {
  memset(visit, 0, sizeof(visit));
  Q.push((person){a, b, c});
  visit[a][b] = 1;
  return 0;
}
int pd(person in) {
  if (in.x < 1 || in.x > n || in.y < 1 || in.y > m || visit[in.x][in.y] ||
      maps[in.x][in.y] == 1)
    return 0;
  visit[in.x][in.y] = 1;
  return 1;
}
int bfs(int a, int b, int c, int d, long long e, long long f) {
  bfsinit(a, b, e);
  while (!Q.empty()) {
    person tempa = Q.front();
    Q.pop();
    if (d == 0)
      addedge(netm + c - 1, netr1[tempa.x] + tempa.y - 1, 1);
    else
      addedge(netr2[tempa.x] + tempa.y - 1, netf + c - 1, 1);
    if (tempa.speed >= f)
      for (int i = 0; i < 4; i++) {
        person tempb =
            (person){tempa.x + stepx[i], tempa.y + stepy[i], tempa.speed - f};
        if (!pd(tempb)) continue;
        Q.push(tempb);
      }
  }
  return 0;
}
int judgeinit(long long in) {
  edges.clear();
  for (int i = 0; i <= nett; i++) net[i].clear();
  for (int i = 1; i <= males.size(); i++) {
    addedge(nets, netm + i - 1, 1);
    bfs(males[i - 1].x, males[i - 1].y, i, 0, in, males[i - 1].speed);
  }
  for (int i = 1; i <= females.size(); i++) {
    addedge(netf + i - 1, nett, 1);
    bfs(females[i - 1].x, females[i - 1].y, i, 1, in, females[i - 1].speed);
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) addedge(netr1[i] + j - 1, netr2[i] + j - 1, 1);
  return 0;
}
int judge(long long in) {
  judgeinit(in);
  int flow = 0;
  while (netbfs()) {
    memset(cur, 0, sizeof(cur));
    flow += netdfs(nets, INF);
  }
  if (flow == females.size())
    return 1;
  else
    return 0;
}
int read() {
  while (true) {
    int tempc = getchar();
    if (tempc == '.')
      return 0;
    else if (tempc == '#')
      return 1;
  }
}
int init() {
  scanf("%d%d%d%d", &n, &m, &male, &female);
  if (abs(male - female) != 1) {
    printf("-1\n");
    return 1;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) maps[i][j] = read();
  {
    int tempa, tempb, tempc;
    scanf("%d%d%d", &tempa, &tempb, &tempc);
    if (male > female)
      females.push_back((person){tempa, tempb, tempc});
    else
      males.push_back((person){tempa, tempb, tempc});
  }
  for (int i = 1; i <= male; i++) {
    int tempa, tempb, tempc;
    scanf("%d%d%d", &tempa, &tempb, &tempc);
    males.push_back((person){tempa, tempb, tempc});
  }
  for (int i = 1; i <= female; i++) {
    int tempa, tempb, tempc;
    scanf("%d%d%d", &tempa, &tempb, &tempc);
    females.push_back((person){tempa, tempb, tempc});
  }
  nets = 0;
  netm = 1;
  for (int i = 1; i <= n; i++) netr1[i] = males.size() + m * (i - 1) + 1;
  for (int i = 1; i <= n; i++)
    netr2[i] = males.size() + n * m + m * (i - 1) + 1;
  netf = males.size() + 2 * n * m + 1;
  nett = males.size() + 2 * n * m + females.size() + 1;
  return 0;
}
int solve() {
  long long head = 0, tail = 500e9;
  int flag = 0;
  while (head < tail) {
    long long mid = (head + tail) >> 1;
    if (judge(mid)) {
      tail = mid;
      flag = 1;
    } else
      head = mid + 1;
  }
  if (flag)
    cout << head << endl;
  else
    printf("-1\n");
  return 0;
}
int main(void) {
  if (init()) return 0;
  solve();
  return 0;
}
