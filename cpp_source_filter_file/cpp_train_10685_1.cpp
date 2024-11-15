#include <bits/stdc++.h>
using namespace std;
int N, K, V;
vector<int> dp[5050];
int A[5050];
int S;
int did[5050];
void solve() {
  int i, j, k, l, r, x, y;
  string s;
  cin >> N >> K >> V;
  dp[0].push_back(0);
  for (i = 1; i <= N; i++) {
    cin >> A[i];
    S += A[i];
    for (j = 0; j < (K); j++)
      if (dp[j].size() && dp[(j + A[i]) % K].empty()) {
        if (dp[j].back() != i) {
          dp[(j + A[i]) % K] = dp[j];
          dp[(j + A[i]) % K].push_back(i);
        }
      }
  }
  if (S >= V && ((S - V) % K == 0 || V % K == 0)) {
    vector<vector<int>> LV;
    for (i = 2; i <= N; i++) {
      int movs = (A[i] + K - 1) / K;
      if (movs) LV.push_back({movs, i, 1});
    }
    if (V % K == 0) {
      if (V) LV.push_back({V / K, 1, 2});
    } else {
      if ((S - V) / K) LV.push_back({(S - V) / K, 1, 2});
    }
    (void)printf("YES\n");
    for (auto& v : LV) (void)printf("%d %d %d\n", v[0], v[1], v[2]);
    return;
  }
  if (S < V || dp[V % K].empty()) return (void)printf("NO\n");
  (void)printf("YES\n");
  int S2 = 0;
  if (dp[V % K].size() >= 2) {
    S2 = A[dp[V % K][1]];
    did[dp[V % K][1]] = 1;
    for (i = 2; i < dp[V % K].size(); i++) {
      x = A[dp[V % K][i]];
      S += x;
      if ((x + K - 1) / K > 0)
        (void)printf("%d %d %d\n", (x + K - 1) / K, dp[V % K][i], dp[V % K][1]);
      did[dp[V % K][i]] = 1;
    }
  }
  int first = -1;
  for (i = 1; i <= N; i++)
    if (did[i] == 0) {
      if (first == -1) {
        first = i;
      } else {
        if ((A[i] + K - 1) / K > 0)
          (void)printf("%d %d %d\n", (A[i] + K - 1) / K, i, first);
      }
    }
  if (S2 < V) {
    (void)printf("%d %d %d\n", (V - S2) / K, first, dp[V % K][1]);
  } else if (S2 > V) {
    (void)printf("%d %d %d\n", (S2 - V) / K, dp[V % K][1], first);
  }
}
int main(int argc, char** argv) {
  string s;
  int i;
  if (argc == 1) ios::sync_with_stdio(false), cin.tie(0);
  for (i = 0; i < (argc - 1); i++) s += argv[i + 1], s += '\n';
  for (i = 0; i < (s.size()); i++) ungetc(s[s.size() - 1 - i], stdin);
  cout.tie(0);
  solve();
  return 0;
}
