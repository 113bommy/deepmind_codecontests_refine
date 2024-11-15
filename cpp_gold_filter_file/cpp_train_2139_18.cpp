#include <bits/stdc++.h>
using namespace std;
int Ti, Td, Tr, Te;
char S[4004], T[4004];
int DP[4004 + 4][4004 + 4];
int last_in_S[26];
int last_in_T[26];
int edit_distance() {
  int N = strlen(S + 1);
  int M = strlen(T + 1);
  for (int i = 1; i <= N; ++i) {
    DP[i][0] = Td * i;
  }
  for (int j = 1; j <= M; ++j) {
    DP[0][j] = Ti * j;
  }
  DP[0][0] = 0;
  memset(last_in_S, 0, sizeof(last_in_S));
  for (int i = 1; i <= N; ++i) {
    memset(last_in_T, 0, sizeof(last_in_T));
    for (int j = 1; j <= M; ++j) {
      DP[i][j] = 0x3f3f3f3f;
      if (S[i] == T[j]) {
        DP[i][j] = DP[i - 1][j - 1];
      } else {
        DP[i][j] = min(DP[i][j], DP[i - 1][j - 1] + Tr);
        DP[i][j] = min(DP[i][j], DP[i - 1][j] + Td);
        DP[i][j] = min(DP[i][j], DP[i][j - 1] + Ti);
        int p1 = last_in_S[T[j] - 'a'];
        int p2 = last_in_T[S[i] - 'a'];
        if (p1 > 0 && p2 > 0) {
          DP[i][j] = min(DP[i][j], DP[p1 - 1][p2 - 1] + Te + Td * (i - p1 - 1) +
                                       Ti * (j - p2 - 1));
        }
      }
      last_in_T[T[j] - 'a'] = j;
    }
    last_in_S[S[i] - 'a'] = i;
  }
  return DP[N][M];
}
int main(int argc, char* argv[]) {
  scanf("%d %d %d %d", &Ti, &Td, &Tr, &Te);
  scanf("%s", S + 1);
  scanf("%s", T + 1);
  int res = edit_distance();
  printf("%d\n", res);
  return 0;
}
