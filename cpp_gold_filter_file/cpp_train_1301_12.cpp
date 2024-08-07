#include <bits/stdc++.h>
using namespace std;
struct package {
  int diff;
  int skill;
};
bool comp(package a, package b) { return (a.diff < b.diff); }
int main() {
  int n, k, a;
  cin >> n >> k;
  vector<package> v;
  package p;
  for (int i = 0; i < n; i++) {
    cin >> a;
    p.skill = a;
    p.diff = (10 - (a % 10));
    v.push_back(p);
  }
  sort(v.begin(), v.end(), comp);
  int xtra = 0, ans = 0;
  for (int i = 0; i < n; i++) {
    int need = v[i].diff;
    if (k >= need) {
      if (v[i].skill + need <= 100) {
        v[i].skill += need;
        k -= need;
      }
    }
    xtra += (100 - v[i].skill);
    ans += (v[i].skill / 10);
  }
  ans += min(xtra, k) / 10;
  cout << ans << endl;
  return 0;
}
