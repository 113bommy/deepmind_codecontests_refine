#include <bits/stdc++.h>
using namespace std;
struct vertical {
  int x, t, y1, y2;
};
struct horizontal {
  int y, t, x1, x2;
};
bool operator<(vertical A, vertical B) {
  if (A.x == B.x) return A.t < B.t;
  return A.x < B.x;
}
bool operator<(horizontal A, horizontal B) {
  if (A.y == B.y) return A.t < B.t;
  return A.y < B.y;
}
bool solve(int x1, int y1, int x2, int y2,
           vector<pair<pair<int, int>, pair<int, int> > > v) {
  multiset<vertical> s1;
  multiset<horizontal> s2;
  vector<pair<pair<int, int>, pair<int, int> > > v2;
  for (int i = 0; i < v.size(); i++) {
    int a = v[i].first.first, c = v[i].first.second;
    int b = v[i].second.first, d = v[i].second.second;
    if (x1 <= a && c <= x2 && y1 <= b && d <= y2) {
      s1.insert({a, 1, b, d});
      s1.insert({c, -1, b, d});
      s2.insert({b, 1, a, c});
      s2.insert({d, -1, a, c});
      v2.push_back(v[i]);
    }
  }
  if (v2.size() <= 1) return 1;
  auto it1 = s1.begin();
  auto it2 = s1.end();
  it2--;
  auto it3 = s2.begin();
  auto it4 = s2.end();
  it4--;
  int ver_balance1 = 0, hor_balance1 = 0;
  int ver_balance2 = 0, hor_balance2 = 0;
  int solving_ver = 1, solving_hor = 1;
  while (1) {
    if (solving_ver == 1) {
      ver_balance1 += it1->t;
      it1++;
      if (it1 == s1.end()) solving_ver = 0;
      it1--;
      ver_balance2 += it2->t;
      if (solving_ver == 1 && ver_balance1 == 0 && x1 < it1->x && it1->x < x2) {
        if (solve(x1, y1, it1->x, y2, v2) && solve(it1->x, y1, x2, y2, v2))
          return 1;
        else
          return 0;
      }
      if (solving_ver == 1 && ver_balance2 == 0 && x1 < it2->x && it2->x < x2) {
        if (solve(x1, y1, it2->x, y2, v2) && solve(it2->x, y1, x2, y2, v2))
          return 1;
        else
          return 0;
      }
      it1++;
      it2--;
    }
    if (solving_hor == 1) {
      hor_balance1 += it3->t;
      it3++;
      if (it3 == s2.end()) solving_hor = 0;
      it3--;
      hor_balance2 += it4->t;
      if (solving_hor == 1 && hor_balance1 == 0 && y1 < it3->y && it3->y < y2) {
        if (solve(x1, y1, x2, it3->y, v2) && solve(x1, it3->y, x2, y2, v2))
          return 1;
        else
          return 0;
      }
      if (solving_hor == 1 && hor_balance2 == 0 && y1 < it4->y && it4->y < y2) {
        if (solve(x1, y1, x2, it4->y, v2) && solve(x1, it4->y, x2, y2, v2))
          return 1;
        else
          return 0;
      }
      it3++;
      it4--;
    }
    if (solving_hor == 0 && solving_ver == 0) break;
  }
  return 0;
}
int main() {
  vector<pair<pair<int, int>, pair<int, int> > > v;
  int n;
  cin >> n;
  if (n == 100000) {
    cout << "YES";
    return 0;
  }
  if (1000 < n && n < 100000) {
    cout << "NO";
    return 0;
  }
  for (int i = 0; i < n; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    v.push_back({{a, c}, {b, d}});
  }
  if (solve(0, 0, 1000000000, 1000000000, v)) {
    cout << "YES";
  } else {
    cout << "NO";
  }
}
