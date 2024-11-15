#include <bits/stdc++.h>
const int N = 505;
int firstEdge[N], nextEdge[N * 2], pointTo[N * 2], weight[N * 2];
short f[N][N][N];
int tmp[N][N], best[N][N], totEdge;
void addEdge(int from, int to, int wi) {
  weight[totEdge] = wi;
  pointTo[totEdge] = to;
  nextEdge[totEdge] = firstEdge[from];
  firstEdge[from] = totEdge++;
}
int n, son[N], x;
int totBlack, dis[N][N], col[N];
inline void checkmin(int &x, int y) {
  if (x == -1 || y < x) x = y;
}
void dfs(int u, int fa) {
  son[u] = 1;
  std::vector<int> children;
  for (int e = firstEdge[u]; e != -1; e = nextEdge[e]) {
    if (pointTo[e] != fa) {
      dfs(pointTo[e], u);
      son[u] += son[pointTo[e]];
      children.push_back(pointTo[e]);
    }
  }
  int sz = (int)children.size();
  for (int who = 0; who < n; who++) {
    if (dis[u][who] > x) continue;
    for (int i = 0; i <= sz + 1; i++) {
      for (int j = 0; j <= sz + 1; j++) {
        tmp[i][j] = -1;
      }
    }
    tmp[0][0] = 0;
    tmp[0][1] = 0;
    int totSon = 1;
    for (int i = 0; i < sz; i++) {
      int child = children[i];
      for (int j = 0; j <= totSon && j <= totBlack; j++) {
        for (int k = 0; k <= son[child] && k + j <= totBlack; k++) {
          if (tmp[i][j] != -1) {
            if (f[child][k][who] != -1) {
              checkmin(tmp[i + 1][j + k], tmp[i][j] + f[child][k][who]);
            }
            if (best[child][k] != -1) {
              checkmin(tmp[i + 1][j + k], tmp[i][j] + best[child][k]);
            }
          }
        }
      }
      totSon += son[child];
    }
    for (int i = 0; i <= son[u]; i++) {
      f[u][i][who] = tmp[sz][i];
    }
  }
  for (int i = 0; i <= son[u] && i < totBlack; i++) {
    best[u][i + 1] = -1;
    for (int who = 0; who < n; who++) {
      if (f[u][i][who] != -1)
        checkmin(best[u][i + 1], f[u][i][who] + (col[who] != 1));
    }
  }
}
void bfs(int s) {
  std::queue<int> Q;
  static bool vis[N];
  memset(vis, false, sizeof(vis));
  static int d[N];
  Q.push(s);
  vis[s] = true;
  d[s] = 0;
  while (!Q.empty()) {
    int fr = Q.front();
    Q.pop();
    for (int e = firstEdge[fr]; e != -1; e = nextEdge[e]) {
      if (!vis[pointTo[e]]) {
        vis[pointTo[e]] = true;
        d[pointTo[e]] = dis[s][pointTo[e]] = std::min(d[fr] + weight[e], x + 1);
        Q.push(pointTo[e]);
      }
    }
  }
}
int main() {
  scanf("%d%d", &n, &x);
  for (int i = 0; i < n; i++) {
    scanf("%d", &col[i]);
    totBlack += col[i];
  }
  memset(firstEdge, -1, sizeof(firstEdge));
  memset(best, -1, sizeof(best));
  memset(f, -1, sizeof(f));
  for (int i = 1, a, b, c; i < n; i++) {
    scanf("%d%d%d", &a, &b, &c);
    a--;
    b--;
    addEdge(a, b, c);
    addEdge(b, a, c);
  }
  for (int i = 0; i < n; i++) {
    bfs(i);
  }
  dfs(0, -1);
  printf("%d\n", best[0][totBlack]);
  return 0;
}
