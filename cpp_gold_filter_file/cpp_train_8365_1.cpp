#include <bits/stdc++.h>
using namespace std;
const int p[11] = {0, 25, 18, 15, 12, 10, 8, 6, 4, 2, 1};
int t, n;
vector<int> v[55];
map<string, int> mp;
string name[55];
int main() {
  scanf("%d", &t);
  for (int i = 0; i < t; ++i) {
    scanf("%d", &n);
    for (int j = 1; j <= n; ++j) {
      char s[100];
      scanf("%s", s);
      if (!mp.count(s)) {
        int k = mp.size();
        mp[s] = k;
        name[k] = s;
        v[k].resize(55, 0);
      }
      int k = mp[s];
      ++v[k][j];
      if (j <= 10) v[k][0] += p[j];
    }
  }
  int imax = 0;
  for (int i = 1; i < mp.size(); ++i) {
    if (v[i] > v[imax]) {
      imax = i;
    }
  }
  puts(name[imax].c_str());
  for (int i = 0; i < mp.size(); ++i) {
    swap(v[i][0], v[i][1]);
  }
  imax = 0;
  for (int i = 1; i < mp.size(); ++i) {
    if (v[i] > v[imax]) {
      imax = i;
    }
  }
  puts(name[imax].c_str());
}
