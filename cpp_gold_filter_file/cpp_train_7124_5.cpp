#include <bits/stdc++.h>
using namespace std;
template <class C>
void mini(C& a4, C b4) {
  a4 = min(a4, b4);
}
template <class C>
void maxi(C& a4, C b4) {
  a4 = max(a4, b4);
}
template <class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> pair) {
  return out << "(" << pair.X << ", " << pair.Y << ")";
}
const long double kEps = 1e-7;
long double sq(long double a) { return a * a; }
int main() {
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  int n, d;
  cin >> n >> d;
  ;
  vector<pair<long double, int> > inters;
  long double PI = acos(0) * 2;
  for (int i = (1); i <= (n); ++i) {
    int x, y, r;
    cin >> x >> y >> r;
    ;
    long double dis = sqrt(sq(x) + sq(y));
    int least_mult = int((dis - r - kEps) / d) * d;
    int greatest_mult = int((dis + r + kEps) / d) * (d + 1);
    long double ang = atan2(y, x);
    for (int R1 = least_mult; R1 <= greatest_mult; R1 += d) {
      if (abs(dis - R1) > r || R1 <= 0) {
        continue;
      }
      long double R2 = r;
      long double diff = (sq(R1) - sq(R2)) / dis;
      long double a = (dis + diff) / 2;
      long double width = acos(a / R1);
      pair<long double, long double> inter1 =
          make_pair(ang - width - kEps, ang + width + kEps);
      pair<long double, long double> inter2 =
          make_pair(inter1.first - 2 * PI, inter1.first - 2 * PI);
      pair<long double, long double> inter3 =
          make_pair(inter1.first + 2 * PI, inter1.first + 2 * PI);
      vector<pair<long double, long double> > vec;
      vec.push_back(inter1);
      vec.push_back(inter2);
      vec.push_back(inter3);
      for (auto p : vec) {
        inters.push_back(make_pair(p.first, 1));
        inters.push_back(make_pair(p.second, -1));
      }
    }
  }
  sort((inters).begin(), (inters).end());
  int acc = 0;
  int res = 0;
  for (auto p : inters) {
    acc += p.second;
    maxi(res, acc);
  }
  cout << res << endl;
  return 0;
}
