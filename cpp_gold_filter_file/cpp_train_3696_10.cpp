#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
const int INF = 2147483647;
struct point {
  int x, t;
  point(int cx = 0, int ct = 0) {
    x = cx;
    t = ct;
  }
  bool operator<(const point &rhs) const { return x < rhs.x; }
} P[maxn];
int D[4][maxn], num[4];
int dp[maxn][3];
int e, s, n, m;
int bitlook1(int x, int *C, int n) {
  int L = 0, R = n - 1, ans = -1;
  while (L <= R) {
    int mid = (L + R) >> 1;
    int id = C[mid];
    if (P[id].x >= x) {
      ans = mid;
      R = mid - 1;
    } else {
      L = mid + 1;
    }
  }
  return ans;
}
void cmp(int &A, int &B, int &V, int C, int D, int DV) {
  if (A >= C) {
    if (A == C) {
      if (B < D) return;
      if (B > D) {
        B = D;
        V = DV;
      } else {
        V = min(V, DV);
      }
    } else {
      A = C;
      B = D;
      V = DV;
    }
  }
}
void solve1(int id) {
  int loc = P[id].x;
  int d1 = bitlook1(loc + 1, D[1], num[1]);
  int d2 = bitlook1(loc + 1, D[2], num[2]);
  int d3 = bitlook1(loc + 1, D[3], num[3]);
  if (d3 != -1) d3 = D[3][d3];
  if (d2 != -1) d2 = D[2][d2];
  if (d1 != -1) d1 = D[1][d1];
  if (d3 != -1 && P[d3].x <= loc + s) {
    int cp1 = dp[d3][1] + P[d3].x - loc;
    int cp2 = dp[d3][2];
    cmp(dp[id][1], dp[id][2], dp[id][0], cp1, cp2, P[d3].x - loc);
  }
  if (d2 != -1 && P[d2].x <= loc + s) {
    int cp1 = dp[d2][1] + P[d2].x - loc;
    int cp2 = dp[d2][2];
    cmp(dp[id][1], dp[id][2], dp[id][0], cp1, cp2, P[d2].x - loc);
  }
  if (d1 != -1 && P[d1].x <= loc + s) {
    int cp1 = dp[d1][1] + P[d1].x - loc;
    int cp2 = dp[d1][2];
    cmp(dp[id][1], dp[id][2], dp[id][0], cp1, cp2, P[d1].x - loc);
  }
}
int bitlook2(int x, int *C, int n) {
  int L = 0, R = n - 1, ans = -1;
  while (L <= R) {
    int mid = (L + R) >> 1;
    int id = C[mid];
    if (P[id].x <= x) {
      ans = mid;
      L = mid + 1;
    } else {
      R = mid - 1;
    }
  }
  return ans;
}
void solve2(int id) {
  int loc = P[id].x;
  int d1 = bitlook2(loc + s, D[1], num[1]);
  int d2 = bitlook1(loc + 1, D[2], num[2]);
  int d3 = bitlook1(loc + 1, D[3], num[3]);
  if (d3 != -1) d3 = D[3][d3];
  if (d2 != -1) d2 = D[2][d2];
  if (d1 != -1) d1 = D[1][d1];
  if (d3 != -1 && P[d3].x <= loc + s) {
    int cp1 = dp[d3][1];
    int cp2 = dp[d3][2] + P[d3].x - loc;
    cmp(dp[id][1], dp[id][2], dp[id][0], cp1, cp2, P[d3].x - loc);
  }
  if (d2 != -1 && P[d2].x <= loc + s) {
    int cp1 = dp[d2][1];
    int cp2 = dp[d2][2] + P[d2].x - loc;
    cmp(dp[id][1], dp[id][2], dp[id][0], cp1, cp2, P[d3].x - loc);
  }
  if (d1 != -1 && P[d1].x > loc) {
    int cp0 = s;
    int lit = s - (P[d1].x - loc);
    int cp1 = dp[d1][1] - min(lit, dp[d1][0]);
    int cp2 = dp[d1][2] + cp0;
    cmp(dp[id][1], dp[id][2], dp[id][0], cp1, cp2, cp0);
  }
}
void solve3(int id) {
  int loc = P[id].x;
  int d1 = bitlook2(loc + s, D[1], num[1]);
  int d2 = bitlook2(loc + s, D[2], num[2]);
  int d3 = bitlook1(loc + 1, D[3], num[3]);
  if (d3 != -1) d3 = D[3][d3];
  if (d2 != -1) d2 = D[2][d2];
  if (d1 != -1) d1 = D[1][d1];
  if (d3 != -1 && P[d3].x <= loc + s) {
    cmp(dp[id][1], dp[id][2], dp[id][0], dp[d3][1], dp[d3][2], 0);
  }
  if (d2 != -1 && P[d2].x > loc) {
    int lit = s - (P[d2].x - loc);
    int cp1 = dp[d2][1];
    int cp2 = dp[d2][2] - min(dp[d2][0], lit);
    cmp(dp[id][1], dp[id][2], dp[id][0], cp1, cp2, 0);
  }
  if (d1 != -1 && P[d1].x > loc) {
    int lit = s - (P[d1].x - loc);
    int cp1 = dp[d1][1] - min(dp[d1][0], lit);
    int cp2 = dp[d1][2];
    cmp(dp[id][1], dp[id][2], dp[id][0], cp1, cp2, 0);
  }
}
void solve4(int loc, int &S1, int &S2) {
  int k;
  int d1 = bitlook2(loc + s, D[1], num[1]);
  int d2 = bitlook2(loc + s, D[2], num[2]);
  int d3 = bitlook1(loc + 1, D[3], num[3]);
  if (d3 != -1) d3 = D[3][d3];
  if (d2 != -1) d2 = D[2][d2];
  if (d1 != -1) d1 = D[1][d1];
  if (d3 != -1 && P[d3].x <= loc + s && dp[d3][1] != INF) {
    cmp(S1, S2, k, dp[d3][1], dp[d3][2], 0);
  }
  if (d2 != -1 && P[d2].x > loc && dp[d2][1] != INF) {
    int lit = s - (P[d2].x - loc);
    int cp1 = dp[d2][1];
    int cp2 = dp[d2][2] - min(dp[d2][0], lit);
    cmp(S1, S2, k, cp1, cp2, 0);
  }
  if (d1 != -1 && P[d1].x > loc && dp[d1][1] != INF) {
    int lit = s - (P[d1].x - loc);
    int cp1 = dp[d1][1] - min(dp[d1][0], lit);
    int cp2 = dp[d1][2];
    cmp(S1, S2, k, cp1, cp2, 0);
  }
}
int main() {
  while (scanf("%d%d%d%d", &e, &s, &n, &m) == 4) {
    num[0] = num[1] = num[2] = num[3] = 0;
    int k = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d%d", &P[k].t, &P[k].x);
      if (P[k].x < e) k++;
    }
    n = k;
    sort(P, P + n);
    if (P[n - 1].x != e) {
      P[n] = point(e, 3);
      n++;
    }
    for (int i = 0; i < n; i++)
      if (P[i].t == 1)
        D[1][num[1]++] = i;
      else if (P[i].t == 2)
        D[2][num[2]++] = i;
      else
        D[3][num[3]++] = i;
    dp[n - 1][0] = dp[n - 1][1] = dp[n - 1][2] = 0;
    for (int i = n - 2; i >= 0; i--) dp[i][0] = dp[i][1] = dp[i][2] = INF;
    for (int i = n - 2; i >= 0; i--) {
      if (P[i].t == 1)
        solve1(i);
      else if (P[i].t == 2)
        solve2(i);
      else
        solve3(i);
      if (dp[i][1] == INF) break;
    }
    for (int i = 0; i < m; i++) {
      int S1 = INF, S2 = INF;
      int loc;
      scanf("%d", &loc);
      solve4(loc, S1, S2);
      if (S1 == INF) {
        printf("-1 -1\n");
      } else {
        printf("%d %d\n", S1, S2);
      }
    }
  }
  return 0;
}
