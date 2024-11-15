#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
std::istream& operator>>(std::istream& i, pair<T, U>& p) {
  i >> p.first >> p.second;
  return i;
}
template <typename T>
std::istream& operator>>(std::istream& i, vector<T>& t) {
  for (auto& v : t) {
    i >> v;
  }
  return i;
}
template <typename T, typename U>
std::ostream& operator<<(std::ostream& o, const pair<T, U>& p) {
  o << p.first << ' ' << p.second;
  return o;
}
template <typename T>
std::ostream& operator<<(std::ostream& o, const vector<T>& t) {
  if (t.empty()) o << '\n';
  for (size_t i = 0; i < t.size(); ++i) {
    o << t[i] << " \n"[i == t.size() - 1];
  }
  return o;
}
template <typename T>
using minheap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using maxheap = priority_queue<T, vector<T>, less<T>>;
template <typename T>
bool in(T a, T b, T c) {
  return a <= b && b < c;
}
unsigned int logceil(int first) {
  return 8 * sizeof(int) - __builtin_clz(first);
}
namespace std {
template <typename T, typename U>
struct hash<pair<T, U>> {
  hash<T> t;
  hash<U> u;
  size_t operator()(const pair<T, U>& p) const {
    return t(p.first) ^ (u(p.second) << 7);
  }
};
}  // namespace std
template <typename T, typename F>
T bsh(T l, T h, const F& f) {
  T r = -1, m;
  while (l <= h) {
    m = (l + h) / 2;
    if (f(m)) {
      l = m + 1;
      r = m;
    } else {
      h = m - 1;
    }
  }
  return r;
}
template <typename F>
double bshd(double l, double h, const F& f, double p = 1e-9) {
  unsigned int r = 3 + (unsigned int)log2((h - l) / p);
  while (r--) {
    double m = (l + h) / 2;
    if (f(m)) {
      l = m;
    } else {
      h = m;
    }
  }
  return (l + h) / 2;
}
template <typename T, typename F>
T bsl(T l, T h, const F& f) {
  T r = -1, m;
  while (l <= h) {
    m = (l + h) / 2;
    if (f(m)) {
      h = m - 1;
      r = m;
    } else {
      l = m + 1;
    }
  }
  return r;
}
template <typename F>
double bsld(double l, double h, const F& f, double p = 1e-9) {
  unsigned int r = 3 + (unsigned int)log2((h - l) / p);
  while (r--) {
    double m = (l + h) / 2;
    if (f(m)) {
      h = m;
    } else {
      l = m;
    }
  }
  return (l + h) / 2;
}
template <typename T>
T gcd(T a, T b) {
  if (a < b) swap(a, b);
  return b ? gcd(b, a % b) : a;
}
template <typename T>
class vector2 : public vector<vector<T>> {
 public:
  vector2() {}
  vector2(size_t a, size_t b, T t = T())
      : vector<vector<T>>(a, vector<T>(b, t)) {}
};
template <typename T>
class vector3 : public vector<vector2<T>> {
 public:
  vector3() {}
  vector3(size_t a, size_t b, size_t c, T t = T())
      : vector<vector2<T>>(a, vector2<T>(b, c, t)) {}
};
template <typename T>
class vector4 : public vector<vector3<T>> {
 public:
  vector4() {}
  vector4(size_t a, size_t b, size_t c, size_t d, T t = T())
      : vector<vector3<T>>(a, vector3<T>(b, c, d, t)) {}
};
template <typename T>
class vector5 : public vector<vector4<T>> {
 public:
  vector5() {}
  vector5(size_t a, size_t b, size_t c, size_t d, size_t e, T t = T())
      : vector<vector4<T>>(a, vector4<T>(b, c, d, e, t)) {}
};
class TaskD {
 public:
  void solve(istream& cin, ostream& cout) {
    string S, T;
    cin >> S >> T;
    auto runs = [](const string& S) {
      int i = 0, r = 0;
      while (i < S.size()) {
        char z = S[i];
        while (i < S.size() && S[i] == z) ++i;
        ++r;
      }
      return r;
    };
    vector<std::pair<int, int>> Ans;
    int best = 1e9;
    auto adv = [](int& i, int& s, const string& S) {
      if (i == S.size()) return;
      char z = S[i];
      while (i < S.size() && S[i] == z) {
        ++i;
        ++s;
      }
    };
    auto advRuns = [&](string& S, int runs) {
      int i = 0;
      while (i < S.size() && runs > 0) {
        char z = S[i];
        while (i < S.size() && S[i] == z) ++i;
        --runs;
      }
      return i;
    };
    auto solve = [&](int r1, int r2, int w) {
      vector<std::pair<int, int>> Cur;
      int s = 0, t = 0;
      int i = advRuns(S, r1);
      int j = advRuns(T, r2);
      if (i != 0 || j != 0) {
        Cur.push_back({i, j});
      }
      string A = T.substr(0, j) + S.substr(i);
      string B = S.substr(0, i) + T.substr(j);
      i = 0, j = 0;
      if (A[0] == B[0]) {
        if (w) {
          adv(i, s, A);
        } else {
          adv(j, t, B);
        }
        Cur.push_back({i, j});
        swap(s, t);
      }
      while (i < A.size() || j < B.size()) {
        adv(i, s, A);
        adv(j, t, B);
        if (i >= A.size() && j >= B.size()) break;
        Cur.push_back({s, t});
        swap(t, s);
      }
      if (Cur.size() < best) {
        Ans = Cur;
        best = Cur.size();
      }
    };
    int r1 = runs(S);
    int r2 = runs(T);
    int q = 4;
    for (int w = 0; w < 2; ++w) {
      for (int z = max(0, (r1 - r2) / 2 - q); z <= min(r1, (r1 - r2) / 2 + q);
           ++z) {
        solve(z, 0, w);
        solve(z, 1, w);
      }
      for (int z = max(0, (r2 - r1) / 2 - q); z <= min(r2, (r2 - r1) / 2 + q);
           ++z) {
        solve(0, z, w);
        solve(1, z, w);
      }
    }
    cout << Ans.size() << '\n';
    for (auto ans : Ans) cout << ans << '\n';
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  TaskD solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}
