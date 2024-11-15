#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void scan(int& a) { scanf("%d", &a); }
void scan(long long& a) { scanf("%lld", &a); }
template <class T>
void scan(T& a) {
  cin >> a;
}
template <class T>
void scan(vector<T>& vec) {
  for (auto&& it : vec) scan(it);
}
void in() {}
template <class Head, class... Tail>
void in(Head& head, Tail&... tail) {
  scan(head);
  in(tail...);
}
void print(const int& a) { printf("%d", a); }
void print(const long long& a) { printf("%lld", a); }
void print(const double& a) { printf("%.15lf", a); }
template <class T>
void print(const T& a) {
  cout << a;
}
template <class T>
void print(const vector<T>& vec) {
  if (vec.empty()) return;
  print(vec[0]);
  for (auto it = vec.begin(); ++it != vec.end();) {
    putchar(' ');
    print(*it);
  }
}
void out() { putchar('\n'); }
template <class T>
void out(const T& t) {
  print(t);
  putchar('\n');
}
template <class Head, class... Tail>
void out(const Head& head, const Tail&... tail) {
  print(head);
  putchar(' ');
  out(tail...);
}
template <class T>
void dprint(const T& a) {
  cerr << a;
}
template <class T>
void dprint(const vector<T>& vec) {
  if (vec.empty()) return;
  cerr << vec[0];
  for (auto it = vec.begin(); ++it != vec.end();) {
    cerr << " " << *it;
  }
}
void debug() { cerr << endl; }
template <class T>
void debug(const T& t) {
  dprint(t);
  cerr << endl;
}
template <class Head, class... Tail>
void debug(const Head& head, const Tail&... tail) {
  dprint(head);
  cerr << " ";
  debug(tail...);
}
int main() {
  int n;
  string a, b;
  int test;
  scanf("%d", &test);
  while (test--) {
    in(n, a, b);
    vector<int> ope;
    int f = 0, r = n - 1, rev = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (rev % 2 == 0) {
        if (a[r] != b[i]) {
          if (a[f] == b[i]) {
            ope.push_back(1);
            if (a[f] == '1')
              a[f] = '0';
            else
              a[f] = '1';
          }
          if (a[f] != b[i]) {
            ope.push_back(i + 1);
            rev++;
            f++;
          }
        } else {
          r--;
        }
      } else {
        if (a[f] == b[i]) {
          if (a[r] != b[i]) {
            ope.push_back(1);
            if (a[r] == '1')
              a[r] = '0';
            else
              a[r] = '1';
          }
          if (a[r] == b[i]) {
            ope.push_back(i + 1);
            rev++;
            r--;
          }
        } else {
          f++;
        }
      }
    }
    out(ope.size(), ope);
  }
}
