#include <bits/stdc++.h>
using namespace std;
int R, C, K;
char B[504][504];
int vis[504][504];
int dr[] = {-1, 0, 0, 1};
int dc[] = {0, -1, 1, 0};
int KK;
void dfs(int r, int c) {
  if (r < 0 || r >= R || c < 0 || c >= C) return;
  if (B[r][c] != '.' || vis[r][c]) return;
  vis[r][c] = true;
  for (int j = 0; j < 4; ++j) {
    dfs(r + dr[j], c + dc[j]);
  }
  if (KK >= 0) {
    B[r][c] = 'X';
    --KK;
  }
}
int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> R >> C >> K;
  for (int r = 0; r < R; ++r) cin >> B[r];
  int sr = -1, sc = -1;
  for (int r = 0; r < R; ++r) {
    for (int c = 0; c < C; ++c)
      if (B[r][c] == '.') {
        sr = r, sc = c;
        break;
      }
    if (sr >= 0) break;
  }
  KK = K;
  dfs(sr, sc);
  for (int r = 0; r < R; ++r) cout << B[r] << endl;
  return 0;
}
