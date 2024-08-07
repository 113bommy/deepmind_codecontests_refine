#include <bits/stdc++.h>
using namespace std;
const int NMAX = 200010;
int p[NMAX], s[NMAX];
long long e[NMAX];
int n, k;
bool comp_e(int a, int b) { return e[a] < e[b]; }
long long test(int P, int Q) {
  cerr << "Q=" << Q << " P=" << P << endl;
  int always = max(0, P - 2);
  int ss = 0;
  for (int i = 0; i <= always; i++) {
    ss += s[i];
  }
  cerr << "ss=" << ss << endl;
  vector<int> if_win, others;
  for (int i = 0; i < n; i++) {
    if ((p[i] == P) || (p[i] == P - 1)) {
      if_win.push_back(i);
    } else {
      others.push_back(i);
    }
  }
  sort(if_win.begin(), if_win.end(), comp_e);
  long long result = 0;
  int count = 0;
  for (int i = 0; (i < Q - ss) && (i < if_win.size()); i++) {
    result += e[if_win[i]];
    count++;
  }
  cerr << "result=" << result << endl;
  for (int i = max(0, Q - ss); i < if_win.size(); i++) {
    others.push_back(if_win[i]);
  }
  sort(others.begin(), others.end(), comp_e);
  vector<int>::iterator it = others.begin();
  while (count < P) {
    result += e[*it];
    count++;
    it++;
  }
  cerr << "result2=" << result << endl;
  return result;
}
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> p[i] >> e[i];
    s[p[i]]++;
  }
  int Q = n - (k - 1);
  int P = 0;
  for (int ss = s[0]; P <= n; P++, ss += s[P]) {
    if (ss >= Q) {
      break;
    }
  }
  if (P > n) {
    cout << (-1) << endl;
  } else {
    long long res = test(P, Q);
    if (P + 1 <= n) {
      res = min(res, test(P + 1, Q));
    }
    if (P + 2 <= n) {
      res = min(res, test(P + 2, Q));
    }
    cout << res << endl;
  }
  return 0;
}
