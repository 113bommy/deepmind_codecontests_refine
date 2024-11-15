#include <bits/stdc++.h>
using namespace std;
int N, Q;
int A[202020];
vector<int> cand3[202020];
vector<int> cand4[202020];
vector<pair<int, int>> U, D;
set<int> US, DS;
set<int> S;
int mo[202020], le[202020];
void solve() {
  int i, j, k, l, r, x, y;
  string s;
  scanf("%d%d", &N, &Q);
  vector<pair<int, int>> V;
  for (i = 0; i < (N); i++) {
    scanf("%d", &A[i]);
    V.push_back({A[i], i});
  }
  sort((V.begin()), (V.end()));
  for (i = 0; i < (2); i++) {
    set<int> S;
    S.insert(-1);
    S.insert(N);
    for (x = 0; x < (N); x++) {
      for (y = x; y < N && V[y].first == V[x].first; y++) {
        int t = V[y].second;
        int R = *S.lower_bound(t);
        int L = *prev(S.lower_bound(t));
        if (L >= 0 && R < N && (cand3[R].empty() || cand3[R][0] < L))
          cand3[R] = {L, t, R};
      }
      for (y = x; y < N && V[y].first == V[x].first; y++) {
        S.insert(V[y].second);
      }
      x = y - 1;
    }
    reverse((V.begin()), (V.end()));
  }
  U.push_back({1 << 30, N});
  D.push_back({-(1 << 30), N});
  US.insert(N);
  DS.insert(N);
  S.insert(N);
  vector<int> W;
  for (i = N - 1; i >= 0; i--) {
    while (U.back().first < A[i]) {
      if (DS.count(U.back().second) == 0) S.insert(U.back().second);
      US.erase(U.back().second);
      U.pop_back();
    }
    while (D.back().first >= A[i]) {
      if (US.count(D.back().second) == 0) S.insert(D.back().second);
      DS.erase(D.back().second);
      D.pop_back();
    }
    if (A[i] == U.back().first)
      mo[i] = mo[U.back().second];
    else
      mo[i] = U.back().second;
    if (A[i] == D.back().first)
      le[i] = le[D.back().second];
    else
      le[i] = D.back().second;
    y = *S.lower_bound(max(mo[i], le[i]));
    U.push_back({A[i], i});
    D.push_back({A[i], i});
    US.insert(i);
    DS.insert(i);
    if (A[i] == A[i + 1]) continue;
    if (y < N && cand4[y].empty()) {
      x = *prev(US.lower_bound(y));
      j = *prev(DS.lower_bound(y));
      if (x > i && j > i && x < y && j < y)
        cand4[y] = {i, min(x, j), max(x, j), y};
    }
  }
  vector<int> ok3 = {-1, -1, -1}, ok4 = {-1, -1, -1, -1};
  for (i = 0; i < (N); i++) {
    if (cand3[i].size()) ok3 = max(ok3, cand3[i]);
    cand3[i] = ok3;
    if (cand4[i].size()) ok4 = max(ok4, cand4[i]);
    cand4[i] = ok4;
  }
  for (i = 0; i < (Q); i++) {
    int L, R;
    scanf("%d%d", &L, &R);
    L--;
    R--;
    if (cand4[R][0] >= L) {
      cout << 4 << endl;
      cout << cand4[R][0] + 1 << " " << cand4[R][1] + 1 << " "
           << cand4[R][2] + 1 << " " << cand4[R][3] + 1 << endl;
    } else if (cand3[R][0] >= L) {
      cout << 3 << endl;
      cout << cand3[R][0] + 1 << " " << cand3[R][1] + 1 << " "
           << cand3[R][2] + 1 << endl;
    } else {
      cout << 0 << endl;
      cout << endl;
    }
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
