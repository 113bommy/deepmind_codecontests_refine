#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:128777216")
const int null = 0;
using namespace std;
template <class T>
int size(const T &a) {
  return int(a.size());
}
template <class T>
T abs(const T &a) {
  return (a < 0 ? -a : a);
}
template <class T>
T sqr(const T &a) {
  return a * a;
}
const int max_n = 2001;
int a[max_n][max_n];
typedef bool bool2d[max_n][max_n];
bool2d was, was2, was3;
int n, m;
struct Pos {
  int r, c;
  void init(int r, int c) {
    this->r = r;
    this->c = c;
  }
} q[max_n * max_n], q1[max_n * max_n], q2[max_n * max_n];
void bfs(int i, int j, Pos *q, bool2d &was, int &u) {
  q[0].init(i, j);
  was[i][j] = true;
  u = 1;
  for (int d = 0; d < u; d++) {
    int i = q[d].r, j = q[d].c;
    for (int di = -1; di <= 1; di++) {
      for (int dj = -1; dj <= 1; dj++) {
        int r = i + di, c = j + dj;
        if (r >= 0 && c >= 0 && r < n && c < m) {
          if (!was[r][c]) {
            q[u++].init(r, c);
            was[r][c] = true;
          }
        }
      }
    }
  }
}
int bfs2(int i, int j, int dist) {
  q2[0].init(i, j);
  was2[i][j] = true;
  int u = 1;
  for (int i = 0, d = 0; i < dist; i++) {
    int cu = u;
    for (; d < cu; d++) {
      int i = q2[d].r, j = q2[d].c;
      for (int di = -1; di <= 1; di++) {
        for (int dj = -1; dj <= 1; dj++) {
          int r = i + di, c = j + dj;
          if (r >= 0 && c >= 0 && r < n && c < m) {
            if (!was2[r][c]) {
              if (u == 90) {
                for (int i = 0; i < u; i++) {
                  was2[q2[i].r][q2[i].c] = false;
                }
                return 1;
              }
              q2[u++].init(r, c);
              was2[r][c] = true;
            }
          }
        }
      }
    }
  }
  for (int i = 0; i < u; i++) {
    was2[q2[i].r][q2[i].c] = false;
  }
  return 0;
}
vector<int> res;
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &a[i][j]);
      if (!a[i][j]) {
        was[i][j] = was2[i][j] = was3[i][j] = true;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] && !was[i][j]) {
        int u;
        bfs(i, j, q, was, u);
        for (int i = 0; i < u; i++) {
          int r = q[i].r, c = q[i].c;
          if (bfs2(r, c, 10)) {
            was3[r][c] = true;
          }
        }
        int cur = 0;
        for (int i = 0; i < u; i++) {
          int r = q[i].r, c = q[i].c;
          if (!was3[r][c]) {
            int q = 0;
            bfs(r, c, q1, was3, q);
            cur++;
          }
        }
        res.push_back(cur);
      }
    }
  }
  printf("%d\n", res.size());
  sort(res.begin(), res.end());
  for (int i = 0; i < res.size(); i++) {
    printf("%d ", res[i]);
  }
  return 0;
}
