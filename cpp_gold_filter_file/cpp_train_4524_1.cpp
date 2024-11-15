#include <bits/stdc++.h>
using namespace std;
struct point {
  double x, y;
  point() {}
  point(double x, double y) : x(x), y(y) {}
  void in() { scanf("%lf%lf", &x, &y); }
};
inline point operator-(const point &a, const point &b) {
  return (point(a.x - b.x, a.y - b.y));
}
inline point operator*(const point &a, double b) {
  return (point(a.x * b, a.y * b));
}
inline point operator/(const point &a, double b) {
  return (point(a.x / b, a.y / b));
}
inline int sign(double x, double eps = 1e-8) {
  return (x < -eps ? -1 : x > eps);
}
inline bool operator<(const point &a, const point &b) {
  return (sign(a.x - b.x) < 0 || sign(a.x - b.x) == 0 && sign(a.y - b.y) < 0);
}
inline bool operator==(const point &a, const point &b) {
  return (sign(a.x - b.x) == 0 && sign(a.y - b.y) == 0);
}
inline double dot(const point &a, const point &b) {
  return (a.x * b.x + a.y * b.y);
}
inline double det(const point &a, const point &b) {
  return (a.x * b.y - a.y * b.x);
}
inline double sqr(double x) { return (x * x); }
inline double dist(const point &a, const point &b) {
  return (sqrt(sqr(a.x - b.x) + sqr(a.y - b.y)));
}
inline bool parellel(const point &a, const point &b, const point &c,
                     const point &d) {
  return (sign(det(a - b, c - d)) == 0);
}
inline point intersect(const point &a, const point &b, const point &c,
                       const point &d) {
  double s1 = det(b - a, c - a);
  double s2 = det(b - a, d - a);
  return ((c * s2 - d * s1) / (s2 - s1));
}
inline bool online(const point &p, const point &a, const point &b) {
  return (sign(det(p - a, p - b)) == 0 && sign(dot(p - a, p - b)) <= 0);
}
inline bool inPolygon(const point &p, const vector<point> ps) {
  int n = ps.size(), cnt = 0;
  for (int i = 0; i < n; i++) {
    point a = ps[i], b = ps[(i + 1) % n];
    if (online(p, a, b)) return (false);
    int t0 = sign(det(a - p, b - p));
    int t1 = sign(a.y - p.y);
    int t2 = sign(b.y - p.y);
    cnt += t0 > 0 && t1 <= 0 && t2 > 0;
    cnt -= t0 < 0 && t2 <= 0 && t1 > 0;
  }
  return (cnt != 0);
}
point pa[110], pb[110];
vector<point> p;
set<pair<int, int> > S;
int W, H, tot, b[100010], a[2000010][2], __next__[200010];
bool vis[200010];
vector<point> poly[20010];
vector<pair<double, point> > buffer;
double polyReal[20010], polyArea[20010];
map<pair<int, int>, int> M;
map<string, int> color;
inline bool onBoard(const point &p) {
  return (sign(p.x) == 0 || sign(p.y) == 0 || sign(p.x - W) == 0 ||
          sign(p.y - H) == 0);
}
inline void addedge(int x, int y) {
  if (S.count(make_pair(x, y))) return;
  S.insert(make_pair(x, y));
  a[++tot][0] = y, a[tot][1] = b[x], b[x] = tot;
}
double ans[100010];
int polyCnt, kind[100010];
string name[100010];
inline int __hash__(const string &s) {
  if (!color.count(s)) {
    int now = color.size() + 1;
    name[now] = s;
    color[s] = now;
  }
  return (color[s]);
}
inline void addpoint(int id, const string &s, double area) {
  kind[id] = __hash__(s);
  ans[id] = area;
}
inline void add(int x, int y) {
  a[++tot][0] = y, a[tot][1] = b[x], b[x] = tot;
  a[++tot][0] = x, a[tot][1] = b[y], b[y] = tot;
}
int edge;
int get(const point &P) {
  int now = lower_bound(p.begin(), p.end(), P) - p.begin();
  if (now < p.size() && P == p[now]) return (now + 1);
  for (map<pair<int, int>, int>::iterator k = M.begin(); k != M.end(); k++) {
    int x = k->first.first, y = k->first.second;
    if (online(P, p[x], p[y])) return (k->second);
  }
  double mi = 1e100;
  int k = -1;
  for (int j = 1; j <= polyCnt; j++)
    if (polyReal[j] < mi && inPolygon(P, poly[j])) {
      mi = polyReal[j];
      k = j;
    }
  return (k + edge);
}
queue<int> Q;
void bfs(const point &p, string s) {
  int S = get(p), id = __hash__(s);
  if (kind[S] == id) return;
  Q.push(S);
  int origin = kind[S];
  kind[S] = id;
  while (!Q.empty()) {
    int x = Q.front();
    Q.pop();
    for (int i = b[x]; i; i = a[i][1]) {
      int y = a[i][0];
      if (kind[y] == origin) {
        kind[y] = id;
        Q.push(y);
      }
    }
  }
}
map<int, double> final;
int main() {
  scanf("%d%d", &W, &H);
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) pa[i].in(), pb[i].in();
  pa[n + 1] = point(0, 0), pb[n + 1] = point(W, 0);
  pa[n + 2] = point(0, 0), pb[n + 2] = point(0, H);
  pa[n + 3] = point(W, H), pb[n + 3] = point(W, 0);
  pa[n + 4] = point(W, H), pb[n + 4] = point(0, H);
  n += 4;
  for (int i = 1; i <= n; i++) {
    p.push_back(pa[i]);
    p.push_back(pb[i]);
    for (int j = i + 1; j <= n; j++) {
      if (parellel(pa[i], pb[i], pa[j], pb[j])) continue;
      point P = intersect(pa[i], pb[i], pa[j], pb[j]);
      if (online(P, pa[i], pb[i]) && online(P, pa[j], pb[j])) p.push_back(P);
    }
  }
  sort(p.begin(), p.end());
  p.erase(unique(p.begin(), p.end()), p.end());
  tot = 1;
  for (int i = 1; i <= n; i++) {
    vector<pair<double, int> > lq;
    for (int j = 0; j < p.size(); j++)
      if (online(p[j], pa[i], pb[i]))
        lq.push_back(make_pair(dist(p[j], pa[i]), j));
    sort(lq.begin(), lq.end());
    for (int j = 1; j < lq.size(); j++) {
      int x = lq[j - 1].second, y = lq[j].second;
      addedge(x, y);
      addedge(y, x);
    }
  }
  for (int i = 0; i < p.size(); i++) {
    vector<pair<double, int> > lq;
    for (int j = b[i]; j; j = a[j][1]) {
      int x = a[j][0];
      lq.push_back(make_pair(atan2(p[x].y - p[i].y, p[x].x - p[i].x), j));
    }
    sort(lq.begin(), lq.end());
    for (int j = 0; j < lq.size(); j++)
      __next__[lq[(j + 1) % lq.size()].second ^ 1] = lq[j].second;
  }
  polyCnt = 0;
  for (int i = 2; i <= tot; i++)
    if (!vis[i]) {
      double area = 0;
      vector<point> lq;
      for (int j = i; !vis[j]; j = __next__[j]) {
        area += det(p[a[j ^ 1][0]], p[a[j][0]]);
        vis[j] = true;
        lq.push_back(p[a[j][0]]);
      }
      if (sign(area) > 0) {
        poly[++polyCnt] = lq;
        polyArea[polyCnt] = area;
        polyReal[polyCnt] = area;
      }
      if (sign(area) <= 0) buffer.push_back(make_pair(area, p[a[i][0]]));
    }
  __hash__("____lq____");
  __hash__("black");
  __hash__("white");
  tot = 0;
  memset(b, 0, sizeof(b));
  for (int i = 0; i < p.size(); i++)
    addpoint(i + 1, onBoard(p[i]) ? "____lq____" : "black", 0);
  edge = p.size();
  for (set<pair<int, int> >::iterator k = S.begin(); k != S.end(); k++) {
    int x = k->first, y = k->second;
    if (x > y) continue;
    M[make_pair(x, y)] = ++edge;
    addpoint(edge, onBoard(p[x]) && onBoard(p[y]) ? "____lq____" : "black", 0);
    add(edge, x + 1);
    add(edge, y + 1);
  }
  for (int i = 0; i < buffer.size(); i++) {
    double mi = 1e100;
    int k = -1;
    for (int j = 1; j <= polyCnt; j++)
      if (polyReal[j] < mi && inPolygon(buffer[i].second, poly[j])) {
        mi = polyReal[j];
        k = j;
      }
    if (k != -1) {
      polyArea[k] += buffer[i].first;
      add(edge + k,
          lower_bound(p.begin(), p.end(), buffer[i].second) - p.begin() + 1);
    }
  }
  for (int i = 1; i <= polyCnt; i++) {
    addpoint(edge + i, "white", polyArea[i] / 2);
    int x = lower_bound(p.begin(), p.end(), poly[i][0]) - p.begin();
    int y = lower_bound(p.begin(), p.end(), poly[i][1]) - p.begin();
    add(edge + i, M[make_pair(min(x, y), max(x, y))]);
  }
  int Q;
  scanf("%d", &Q);
  while (Q--) {
    point now;
    now.in();
    char buf[100];
    scanf("%s", buf);
    bfs(now, buf);
  }
  for (int i = 1; i <= edge + polyCnt; i++) final[kind[i]] += ans[i];
  for (map<int, double>::iterator k = final.begin(); k != final.end(); k++) {
    if (k->first == 1) continue;
    printf("%s %.10f\n", name[k->first].c_str(), k->second);
  }
  return (0);
}
