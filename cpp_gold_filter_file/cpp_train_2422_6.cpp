#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > s, v;
int main(void) {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    int a, h, l, r;
    scanf("%d%d%d%d", &a, &h, &l, &r);
    if (l) {
      s.push_back(make_pair(a - h, l));
      s.push_back(make_pair(a, -l));
    }
    if (r) {
      s.push_back(make_pair(a + 1, r));
      s.push_back(make_pair(a + h + 1, -r));
    }
  }
  for (int i = 0; i < m; i++) {
    int b, z;
    scanf("%d%d", &b, &z);
    v.push_back(make_pair(b, z));
  }
  sort(s.begin(), s.end());
  sort(v.begin(), v.end());
  double ans = 0;
  int zcnt = 0;
  int ccnt[105] = {};
  for (int i = 0, j = 0; j < (int)v.size(); j++) {
    while (i < (int)s.size() && s[i].first <= v[j].first) {
      if (s[i].second < 0) {
        if (s[i].second != -100)
          --ccnt[100 + s[i].second];
        else
          --zcnt;
      } else {
        if (s[i].second != 100)
          ++ccnt[100 - s[i].second];
        else
          ++zcnt;
      }
      ++i;
    }
    if (zcnt == 0) {
      double p = 1.0;
      for (int k = 1; k < 100; k++) p *= pow((double)k / 100., ccnt[k]);
      ans += p * v[j].second;
    }
  }
  printf("%.9f\n", ans);
  return 0;
}
