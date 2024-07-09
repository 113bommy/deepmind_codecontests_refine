#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2099;
const int MAXK = 800009;
const long long inf = 1000000000000000999ll;
const double pi = acos(-1.0);
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
int n;
char image[MAXN][MAXN];
char visited[MAXN][MAXN];
int circleNumber, squareNumber;
bool valid(int first, int second) {
  if (first < 0 || second < 0) return 0;
  if (first >= n || second >= n) return 0;
  return 1;
}
void dfs(short first, short second, vector<pair<short, short> >& pixel) {
  if (visited[first][second]) return;
  visited[first][second] = 1;
  pixel.push_back(make_pair(first, second));
  for (int k = 0; k < 4; k++) {
    int nx = first + dx[k];
    int ny = second + dy[k];
    if (!valid(nx, ny) || visited[nx][ny]) continue;
    if (image[nx][ny]) dfs(nx, ny, pixel);
  }
}
int getType(vector<pair<short, short> >& pixel) {
  int sumx = 0;
  int sumy = 0;
  int maxx = 0;
  int maxy = 0;
  int s = pixel.size();
  for (pair<short, short> p : pixel) {
    sumx += p.first;
    sumy += p.second;
    maxx = max(maxx, int(p.first));
    maxy = max(maxy, int(p.second));
  }
  sumx /= s;
  sumy /= s;
  int r1 = maxx - sumx;
  int r2 = maxx - sumx;
  if (abs(r1 - r2) > 5) return 1;
  if (fabs(r1 * r1 * pi - s) > 30)
    return 1;
  else
    return 0;
}
int main() {
  scanf("%d\n", &n);
  for (int i = 0, _n = (n); i < _n; i++) {
    for (int j = 0, _n = (n); j < _n; j++) {
      scanf("%c ", &image[i][j]);
      image[i][j] -= '0';
    }
    scanf("\n");
  }
  vector<pair<short, short> > pixel;
  for (int i = 0, _n = (n); i < _n; i++) {
    for (int j = 0, _n = (n); j < _n; j++) {
      if (!visited[i][j] && image[i][j]) {
        pixel.clear();
        dfs(i, j, pixel);
        if (pixel.size() < 40) continue;
        int t = getType(pixel);
        if (t == 0)
          circleNumber++;
        else
          squareNumber++;
      }
    }
  }
  printf("%d %d\n", circleNumber, squareNumber);
  return 0;
}
