#include <bits/stdc++.h>
using namespace std;
int a[51];
long long c[51][51];
double dp[51][51][51];
bool state[51][51][51];
double cal(int stu, int room, int mval) {
  if (state[stu][room][mval]) return dp[stu][room][mval];
  state[stu][room][mval] = true;
  double &ret = dp[stu][room][mval];
  if (!stu) return ret = mval;
  if (!room) return ret = 0.0;
  for (int i = 0; i <= stu; i++) {
    int rval = i / a[room] + (i % a[room] != 0);
    ret += 1.0 * c[i][stu] * pow(1.0 / room, i) *
           pow(1.0 - 1.0 / room, stu - i) *
           cal(stu - i, room - 1, max(mval, rval));
  }
  return ret;
}
int main() {
  int n, m, i;
  for (i = 1; i <= 50; i++) c[0][i] = c[i][i] = 1;
  for (i = 2; i <= 20; i++)
    for (n = 1; n < i; n++) c[n][i] = c[n - 1][i - 1] + c[n][i - 1];
  scanf("%d %d", &n, &m);
  for (i = 1; i <= m; i++) scanf("%d", a + i);
  printf("%.20lf", cal(n, m, 0));
  return 0;
}
