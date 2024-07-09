#include <bits/stdc++.h>
using namespace std;
int dx[100000], dy[100000];
int x[10010], y[10010];
int main2(int N) {
  int i, j;
  for (i = 0; i * i < 100000; i++)
    for (j = 0; i * i + j * j < 100000; j++) {
      dx[i * i + j * j] = i;
      dy[i * i + j * j] = j;
    }
  int c = 0, xsum = 0, ysum = 0;
  for (i = 2;; i++)
    if (dx[i] != 0 || dy[i] != 0) {
      x[c] = dx[i];
      y[c] = dy[i];
      xsum += dx[i];
      ysum += dy[i];
      c++;
      if (c == N) break;
    }
  if (xsum % 2 != ysum % 2) y[0] = 0;
  if (xsum % 2 != 0)
    for ((i) = 0; (i) < (int)(N); (i)++)
      if (x[i] % 2 != y[i] % 2) {
        swap(x[i], y[i]);
        break;
      }
  while (1) {
    int X = 0, Y = 0;
    for (i = N - 1; i >= 0; i--) {
      if (X > 0) x[i] = -x[i];
      X += x[i];
      if (Y > 0) y[i] = -y[i];
      Y += y[i];
    }
    if (X == 0 && Y == 0) break;
    for ((i) = 0; (i) < (int)(N); (i)++) {
      x[i] = abs(x[i]);
      y[i] = abs(y[i]);
    }
    while (1) {
      int r = rand() % N;
      if (x[r] % 2 == y[r] % 2) {
        swap(x[r], y[r]);
        break;
      }
    }
  }
  vector<pair<double, int> > v;
  for ((i) = 0; (i) < (int)(N); (i)++) {
    double theta = atan2(y[i], x[i]);
    v.push_back(make_pair(theta, i));
  }
  sort(v.begin(), v.end());
  printf("YES\n");
  xsum = 0;
  ysum = 0;
  for ((i) = 0; (i) < (int)(N); (i)++) {
    printf("%d %d\n", xsum, ysum);
    int id = v[i].second;
    xsum += x[id];
    ysum += y[id];
  }
  return 0;
}
int main(void) {
  int N;
  cin >> N;
  main2(N);
  return 0;
}
