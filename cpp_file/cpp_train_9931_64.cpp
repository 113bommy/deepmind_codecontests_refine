#include <bits/stdc++.h>
using namespace std;
int found, N, M, nr, d[1609][1609], ap[1609][1609], cnt[10009];
char sir[4009];
bool a[1609][1609];
int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
queue<pair<int, int> > cc;
void fill(int i, int j) {
  if (i < 1 || i > N || j < 1 || j > M || ap[i][j] == -1 || ap[i][j] > 0)
    return;
  ap[i][j] = nr;
  for (int k = 0; k < 4; k++) fill(i + dx[k], j + dy[k]);
}
void fill2(int i, int j) {
  if (ap[i][j] > 0) {
    found = ap[i][j];
    return;
  }
  if (i < 1 || i > N || j < 1 || j > M || ap[i][j] != -1 || a[i][j] == 0)
    return;
  ap[i][j] = -2;
  for (int k = 0; k < 8; k++) fill2(i + dx[k], j + dy[k]);
}
int main() {
  scanf("%d %d\n", &N, &M);
  for (int i = 1; i <= N; i++) {
    gets(sir);
    for (int j = 1; j <= M; j++) {
      a[i][j] = sir[j * 2 - 2] - '0', d[i][j] = 10000;
      if (a[i][j] == 0) cc.push(make_pair(i, j)), d[i][j] = 0;
    }
  }
  while (!cc.empty()) {
    pair<int, int> curr = cc.front();
    cc.pop();
    for (int k = 0; k < 4; k++) {
      int x = curr.first + dx[k], y = curr.second + dy[k];
      if (d[x][y] > d[curr.first][curr.second] + 1) {
        d[x][y] = d[curr.first][curr.second] + 1;
        cc.push(make_pair(x, y));
      }
    }
  }
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++)
      if (d[i][j] > 4)
        cc.push(make_pair(i, j)), d[i][j] = 0;
      else
        d[i][j] = 10000;
  while (!cc.empty()) {
    pair<int, int> curr = cc.front();
    cc.pop();
    for (int k = 0; k < 4; k++) {
      int x = curr.first + dx[k], y = curr.second + dy[k];
      if (d[x][y] > d[curr.first][curr.second] + 1) {
        d[x][y] = d[curr.first][curr.second] + 1;
        if (d[x][y] <= 6) cc.push(make_pair(x, y));
      }
    }
  }
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++)
      if (d[i][j] >= 10000) ap[i][j] = -1;
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++)
      if (ap[i][j] == 0) nr++, fill(i, j);
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++)
      if (ap[i][j] == -1 && a[i][j] == 1) {
        found = 0, fill2(i, j);
        cnt[found]++;
      }
  sort(cnt + 1, cnt + nr + 1);
  printf("%d\n", nr);
  for (int i = 1; i <= nr; i++) printf("%d ", cnt[i]);
  printf("\n");
  return 0;
}
