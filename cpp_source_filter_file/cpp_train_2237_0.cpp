#include <bits/stdc++.h>
using namespace std;
string pic[30];
int N, M;
string encode(int i0, int j0, int i1, int j1) {
  string res, s1;
  s1.reserve((i1 - i0) * (j1 - j0));
  for (int i = i0; i < i1; i++) {
    for (int j = j0; j < j1; j++) s1 += pic[i][j];
    s1 += '|';
  }
  res = s1;
  s1.clear();
  for (int j = j1 - 1; j >= j0; j--) {
    for (int i = i0; i < i1; i++) s1 += pic[i][j];
    s1 += '|';
  }
  res = min(res, s1);
  s1.clear();
  for (int i = i1 - 1; i >= i0; i--) {
    for (int j = j1 - 1; j >= j0; j--) s1 += pic[i][j];
    s1 += '{';
  }
  res = min(res, s1);
  s1.clear();
  for (int j = j0; j < j1; j++) {
    for (int i = i1 - 1; i >= i0; i--) s1 += pic[i][j];
    s1 += '|';
  }
  res = min(res, s1);
  return res;
}
bool good(int n, int m) {
  set<string> seen;
  for (int i = 0; i < N; i += n)
    for (int j = 0; j < M; j += m) {
      string s = encode(i, j, i + n, j + m);
      if (seen.count(s)) return false;
      seen.insert(s);
    }
  return true;
}
int main() {
  cin >> N >> M;
  for (int i = 0; i < N; i++) cin >> pic[i];
  int cnt = 0;
  pair<int, int> best = make_pair(N, M);
  for (int n = 1; n <= N; n++)
    if (N % n == 0)
      for (int m = 1; m <= M; m++)
        if (M % m == 0 && good(n, m)) {
          cnt++;
          if (n * m < best.first * best.second ||
              n * m == best.first * best.second && n < best.first)
            best = make_pair(n, m);
        }
  cout << cnt << endl;
  cout << best.first << " " << best.second << endl;
}
