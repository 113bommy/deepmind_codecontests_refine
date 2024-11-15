#include <bits/stdc++.h>
using namespace std;
const int N = 251;
const int M = 2e5 + 5;
const int star = 16;
const int MOD = 1e9 + 7;
int nxt[26][M], dp[N][N][N][3];
int get(int i, int j, int k, int l) {
  int go = -1;
  if (l == 0) {
    for (int ll = 0; ll < 3; ll++)
      if (dp[i - 1][j][k][ll] != -1) {
        if (go == -1)
          go = dp[i - 1][j][k][ll];
        else
          go = min(go, dp[i - 1][j][k][ll]);
      }
  } else if (l == 1) {
    for (int ll = 0; ll < 3; ll++)
      if (dp[i][j - 1][k][ll] != -1) {
        if (go == -1)
          go = dp[i][j - 1][k][ll];
        else
          go = min(go, dp[i][j - 1][k][ll]);
      }
  } else {
    for (int ll = 0; ll < 3; ll++)
      if (dp[i][j][k - 1][ll] != -1) {
        if (go == -1)
          go = dp[i][j][k - 1][ll];
        else
          go = min(go, dp[i][j][k - 1][ll]);
      }
  }
  return go;
}
int main() {
  int n, q, i, j, k, l, a, b, c;
  cin >> n >> q;
  string s, A = "", B = "", C = "";
  cin >> s;
  a = b = c = 0;
  for (i = n - 1; i >= 0; i--) {
    for (j = 0; j < 26; j++) {
      nxt[j][i] = -1;
      if (s[i] - 'a' == j) {
        nxt[j][i] = i + 1;
      } else if (i < n - 1)
        nxt[j][i] = nxt[j][i + 1];
    }
  }
  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++)
      for (k = 0; k < N; k++)
        for (l = 0; l < 3; l++) dp[i][j][k][l] = -1;
  dp[0][0][0][0] = dp[0][0][0][1] = dp[0][0][0][2] = 0;
  while (q--) {
    char type, add;
    int rel;
    cin >> type;
    if (type == '+') {
      cin >> rel >> add;
      int al, bl, cl, ah, bh, ch;
      if (rel == 1) {
        a++;
        al = a;
        ah = a;
        bl = 0;
        bh = b;
        cl = 0;
        ch = c;
        A += add;
      } else if (rel == 2) {
        b++;
        al = 0;
        ah = a;
        bl = b;
        bh = b;
        cl = 0;
        ch = c;
        B += add;
      } else {
        c++;
        al = 0;
        ah = a;
        bl = 0;
        bh = b;
        cl = c;
        ch = c;
        C += add;
      }
      for (i = al; i <= ah; i++)
        for (j = bl; j <= bh; j++)
          for (k = cl; k <= ch; k++) {
            dp[i][j][k][0] = dp[i][j][k][1] = dp[i][j][k][2] = -1;
            int go;
            if (i > 0) {
              go = get(i, j, k, 0);
              if (go != -1 && go < n) dp[i][j][k][0] = nxt[A[i - 1] - 'a'][go];
            }
            if (j > 0) {
              go = get(i, j, k, 1);
              if (go != -1 && go < n) dp[i][j][k][1] = nxt[B[j - 1] - 'a'][go];
            }
            if (k > 0) {
              go = get(i, j, k, 2);
              if (go != -1 && go < n) dp[i][j][k][2] = nxt[C[k - 1] - 'a'][go];
            }
          }
    } else {
      cin >> rel;
      if (rel == 1) {
        a--;
        A.pop_back();
      } else if (rel == 2) {
        b--;
        B.pop_back();
      } else {
        c--;
        C.pop_back();
      }
    }
    if (dp[a][b][c][0] != -1 || dp[a][b][c][1] != -1 || dp[a][b][c][2] != -1) {
      cout << "YES\n";
    } else
      cout << "NO\n";
  }
  return 0;
}
