#include <bits/stdc++.h>
#pragma warning(disable : 4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;
int IT_MAX = 1 << 18;
int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const long long LL_INF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);
const double ERR = 1e-10;
const int MX = 100005;
const int MM = 1000000007;
int BC[2][MX], AA[2][MX];
int main() {
  string A, B;
  cin >> A >> B;
  int N = A.size(), M = B.size();
  for (int i = 1; i <= N; i++) {
    BC[0][i] = A[i - 1] != 'A' ? 1 : 0;
    if (A[i - 1] == 'A')
      AA[0][i] = AA[0][i - 1] + 1;
    else
      AA[0][i] = 0;
  }
  for (int i = 1; i <= M; i++) {
    BC[1][i] = B[i - 1] != 'A' ? 1 : 0;
    if (B[i - 1] == 'A')
      AA[1][i] = AA[1][i - 1] + 1;
    else
      AA[1][i] = 0;
  }
  for (int t = 0; t < 2; t++) {
    for (int i = 1; i <= max(N, M); i++) BC[t][i] += BC[t][i - 1];
  }
  int Q;
  scanf("%d", &Q);
  for (int i = 1; i <= Q; i++) {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    int p = BC[0][b] - BC[0][a - 1];
    int q = BC[1][d] - BC[1][c - 1];
    int x = min(b - a + 1, AA[0][b]);
    int y = min(d - c + 1, AA[1][d]);
    int ans = 0;
    if (p == q)
      ans = x >= y && (x - y) % 3 == 0;
    else if (p < q && (q - p) % 2 == 0)
      ans = y <= (p ? x : x - 1);
    printf("%d", ans);
  }
  printf("\n");
}
