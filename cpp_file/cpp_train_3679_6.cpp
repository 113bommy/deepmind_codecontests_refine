#include <bits/stdc++.h>
using namespace std;
vector<int> prefix_func(string s) {
  int N = s.length();
  vector<int> pr(N);
  for (int i = 1; i < N; i++) {
    int j = pr[i - 1];
    while (j > 0 && s[i] != s[j]) j = pr[j - 1];
    if (s[i] == s[j]) ++j;
    pr[i] = j;
  }
  return pr;
}
vector<vector<int>> prefix_aut(string s) {
  s += '#';
  int N = s.length();
  vector<int> pr = prefix_func(s);
  vector<vector<int>> aut(N, vector<int>(2));
  for (int i = 0; i < N; i++) {
    for (char c = 0; c < 2; c++) {
      if (i > 0 && 'a' + c != s[i])
        aut[i][c] = aut[pr[i - 1]][c];
      else
        aut[i][c] = i + ('a' + c == s[i]);
    }
  }
  return aut;
}
const unsigned long long MODULE = 1000000007;
unsigned long long matrix[100][4];
int main() {
  unsigned long long k;
  int M;
  cin >> k >> M;
  for (int m = 0; m < M; m++) {
    string s;
    cin >> s;
    int n = s.length();
    vector<vector<int>> aut = prefix_aut(s);
    vector<vector<int>> G(max(3ULL, min(k + 1, 4ULL * n)), vector<int>(n + 1));
    vector<vector<int>> K(max(3ULL, min(k + 1, 4ULL * n)), vector<int>(n + 1));
    for (int i = 0; i < n + 1; i++) {
      G[0][i] = i;
      G[1][i] = aut[i][0];
      G[2][i] = aut[i][1];
      K[0][i] = 0;
      K[1][i] = (aut[i][0] == n);
      K[2][i] = (aut[i][1] == n);
    }
    int l1 = 1;
    int l2 = 1;
    int l3 = 1;
    int i;
    for (i = 3; i <= k && l2 < n; i++) {
      for (int j = 0; j < n + 1; j++) {
        G[i][j] = G[i - 2][G[i - 1][j]];
        K[i][j] = (K[i - 1][j] + K[i - 2][G[i - 1][j]]) % MODULE;
      }
      l1 = l2;
      l2 = l3;
      l3 = l2 + l1;
    }
    if (i > k)
      cout << K[k][0] << endl;
    else {
      unsigned long long matr[4] = {1, 0, 0, 1};
      matrix[0][0] = matrix[0][1] = matrix[0][2] = 1;
      matrix[0][3] = 0;
      int left = k - i;
      int j = 0;
      while (left > 0) {
        if (j > 0) {
          matrix[j][0] = (matrix[j - 1][0] * matrix[j - 1][0] +
                          matrix[j - 1][1] * matrix[j - 1][2]) %
                         MODULE;
          matrix[j][1] = (matrix[j - 1][0] * matrix[j - 1][1] +
                          matrix[j - 1][1] * matrix[j - 1][3]) %
                         MODULE;
          matrix[j][2] = (matrix[j - 1][2] * matrix[j - 1][0] +
                          matrix[j - 1][3] * matrix[j - 1][2]) %
                         MODULE;
          matrix[j][3] = (matrix[j - 1][2] * matrix[j - 1][1] +
                          matrix[j - 1][3] * matrix[j - 1][3]) %
                         MODULE;
        }
        if (left & 1) {
          unsigned long long newmatr[4] = {
              (matr[0] * matrix[j][0] + matr[1] * matrix[j][2]) % MODULE,
              (matr[0] * matrix[j][1] + matr[1] * matrix[j][3]) % MODULE,
              (matr[2] * matrix[j][0] + matr[3] * matrix[j][2]) % MODULE,
              (matr[2] * matrix[j][1] + matr[3] * matrix[j][3]) % MODULE};
          matr[0] = newmatr[0];
          matr[1] = newmatr[1];
          matr[2] = newmatr[2];
          matr[3] = newmatr[3];
        }
        left >>= 1;
        j++;
      }
      int c1 = K[i - 2][0];
      int c2 = K[i - 1][0];
      int d12 = (MODULE + K[i - 1][G[i - 2][0]] - K[i - 1][0]) % MODULE;
      int d22 = (MODULE + K[i - 1][G[i - 1][0]] - K[i - 1][0]) % MODULE;
      int d21 = (MODULE + K[i - 2][G[i - 1][0]] - K[i - 2][0]) % MODULE;
      unsigned long long result = (d21 + c1 + c2) * matr[0] + c2 * matr[2];
      if ((k - i) & 1) {
        result += d12 * matr[0];
        result += d22 * (MODULE + matr[1] - 1);
      } else {
        result += d12 * (MODULE + matr[0] - 1);
        result += d22 * matr[1];
      }
      cout << result % MODULE << endl;
    }
  }
}
