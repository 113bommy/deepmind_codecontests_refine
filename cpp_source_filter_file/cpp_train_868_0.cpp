#include <bits/stdc++.h>
using namespace std;
int sec[300006], l, r, Y, M, D, H, Mi, S;
int n, m, hi[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char in[5000006];
int main() {
  l = r = 0;
  for (int i = 1; i <= 12; i++) hi[i] += hi[i - 1];
  scanf("%d %d\n", &n, &m);
  while (scanf("%d-%d-%d %d:%d:%d:", &Y, &M, &D, &H, &Mi, &S)) {
    cin.getline(in, 5000006);
    sec[r] =
        S + Mi * 60 + H * 60 * 60 + D * 24 * 60 * 60 + hi[M - 1] * 24 * 60 * 60;
    r++;
    while (l < r && sec[r - 1] - sec[l] >= n) l++;
    if ((r - l) >= m) {
      printf("2012-%02d-%02d %02d:%02d:%02d\n", M, D, H, Mi, S);
      return 0;
    }
  }
  printf("-1\n");
  return 0;
}
