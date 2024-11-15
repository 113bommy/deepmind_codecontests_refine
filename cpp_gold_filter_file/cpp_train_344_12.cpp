#include <bits/stdc++.h>
using namespace std;
int n, m;
string a, b;
int cnt[30];
string cur = "";
void find(int pos, bool eq) {
  if (pos == min(n, m)) {
    if (cur > b || n > m) {
      while (1) {
        char cc = 0;
        for (char c = 'a'; c <= 'z'; ++c) {
          if (cnt[c - 'a']) {
            --cnt[c - 'a'];
            cc = c;
            break;
          }
        }
        if (!cc) {
          break;
        }
        cur += cc;
      }
      cout << cur;
      exit(0);
    }
    return;
  }
  for (char c = eq ? b[pos] : 'a'; c <= 'z'; ++c) {
    if (cnt[c - 'a']) {
      cur += c;
      --cnt[c - 'a'];
      find(pos + 1, eq && c == b[pos]);
      ++cnt[c - 'a'];
      cur.erase((int)cur.size() - 1);
    }
  }
}
int main() {
  cin >> a >> b;
  n = (int)a.size();
  m = (int)b.size();
  for (int i = 0; i < (int)a.size(); ++i) {
    ++cnt[a[i] - 'a'];
  }
  find(0, 1);
  cout << -1;
  return 0;
}
