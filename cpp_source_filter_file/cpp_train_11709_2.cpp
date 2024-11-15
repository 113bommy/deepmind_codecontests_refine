#include <bits/stdc++.h>
using namespace std;
int n;
bitset<2000> a[3000];
bitset<2000> lookup[3000];
vector<pair<int, int> > basis;
bitset<2000> parse(string s) {
  bitset<2000> ans;
  reverse(s.begin(), s.end());
  int m = (int)s.size();
  vector<int> chunk((m + 7) / 8);
  for (int i = m - 1; i >= 0; i--) {
    s[i] -= '0';
    chunk[i / 8] *= 10;
    chunk[i / 8] += s[i];
  }
  m = (m + 7) / 8;
  int cur = 0;
  while (m > 0) {
    ans[cur] = chunk[0] & 1;
    chunk[0] -= chunk[0] & 1;
    int car = 0;
    for (int i = m - 1; i >= 0; i--) {
      chunk[i] += car;
      car = (chunk[i] & 1) ? 100000000 : 0;
      chunk[i] >>= 2;
    }
    cur++;
    if (chunk[m - 1] == 0) m--;
  }
  return ans;
}
bool insert(int x) {
  for (int i = 0; i < (int)basis.size(); i++) {
    if (a[x][basis[i].first]) {
      a[x] ^= a[basis[i].second];
      lookup[x] ^= lookup[basis[i].second];
    }
  }
  if (a[x].count()) {
    int sm = 2000;
    for (int i = 0; i < 2000; i++) {
      if (a[x][i]) {
        sm = i;
        break;
      }
    }
    basis.push_back(make_pair(sm, x));
    int m = (int)basis.size() - 1;
    while (m >= 1 && basis[m] < basis[m - 1]) {
      swap(basis[m], basis[m - 1]);
    }
    return false;
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    a[i] = parse(s);
    lookup[i][i] = 1;
    if (insert(i)) {
      vector<int> ans;
      for (int j = 0; j < i; j++) {
        if (lookup[i][j]) {
          ans.push_back(j);
        }
      }
      printf("%d", (int)ans.size());
      for (int j = 0; j < (int)ans.size(); j++) {
        printf(" %d", ans[j]);
      }
      printf("\n");
    } else
      printf("0\n");
  }
}
