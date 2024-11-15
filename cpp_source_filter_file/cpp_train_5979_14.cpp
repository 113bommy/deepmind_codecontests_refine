#include <bits/stdc++.h>
using namespace std;
const int LMAX = 100000001;
const int NMAX = 50010;
int vertical[NMAX], vertical_points[NMAX][2];
int horizontal[NMAX], horizontal_points[NMAX][2];
int n, m;
int get_y(const pair<int, int>& a) {
  if (a.second == 1)
    return horizontal[a.first];
  else
    return vertical_points[a.first][a.second];
}
bool cmp_points(const pair<int, int>& a, const pair<int, int>& b) {
  int y1 = get_y(a), y2 = get_y(b);
  if (y1 != y2) return y1 < y2;
  if (a.second != b.second) return a.second < b.second;
  if (a.second == 1)
    return horizontal_points[a.first][0] < horizontal_points[b.first][0];
  return vertical[a.first] < vertical[b.first];
}
bool make_plus(int k) {
  cerr << "make_plus " << k << endl;
  vector<pair<int, int> > points;
  for (int i = 0; i < n; i++) {
    vertical_points[i][0] += k;
    vertical_points[i][1] -= k;
    if (vertical_points[i][1] >= vertical_points[i][0]) {
      points.push_back(make_pair(i, 0));
      points.push_back(make_pair(i, 2));
    }
  }
  for (int i = 0; i < m; i++) {
    horizontal_points[i][0] += k;
    horizontal_points[i][1] -= k;
    if (horizontal_points[i][1] >= horizontal_points[i][0]) {
      points.push_back(make_pair(i, 1));
    }
  }
  sort(points.begin(), points.end(), cmp_points);
  set<int> vertical_lines;
  bool intersect = false;
  for (vector<pair<int, int> >::iterator it = points.begin();
       it != points.end(); it++) {
    cerr << it->first << " " << it->second << endl;
    if (it->second == 0) {
      cerr << "add vertical line " << vertical[it->first] << endl;
      vertical_lines.insert(vertical[it->first]);
    } else if (it->second == 2) {
      cerr << "remove vertical line " << vertical[it->first] << endl;
      vertical_lines.erase(vertical[it->first]);
    } else {
      int x1 = horizontal_points[it->first][0],
          x2 = horizontal_points[it->first][1];
      cerr << "test if intersects " << x1 << "," << x2 << endl;
      set<int>::iterator pos = vertical_lines.lower_bound(x1);
      if (pos != vertical_lines.end()) {
        intersect = (*pos) <= x2;
        if (intersect) break;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    vertical_points[i][0] -= k;
    vertical_points[i][1] += k;
  }
  for (int i = 0; i < m; i++) {
    horizontal_points[i][0] -= k;
    horizontal_points[i][1] += k;
  }
  return intersect;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int x, y, l;
    cin >> x >> y >> l;
    vertical[i] = x;
    vertical_points[i][0] = y;
    vertical_points[i][1] = y + l;
  }
  for (int i = 0; i < m; i++) {
    int x, y, l;
    cin >> x >> y >> l;
    horizontal[i] = y;
    horizontal_points[i][0] = x;
    horizontal_points[i][1] = x + l;
  }
  int l = 0, r = LMAX;
  while (l + 1 < r) {
    int k = (r + l) / 2;
    if (make_plus(k)) {
      l = k;
    } else {
      r = k;
    }
  }
  cout << l << endl;
  return 0;
}
