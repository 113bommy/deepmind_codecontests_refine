#include <bits/stdc++.h>
enum { WHITE, GREY, BLACK };
using namespace std;
long long int inf = 1e18;
template <class T>
T gcd(T a, T b) {
  return b == 0 ? a : gcd(b, a % b);
}
template <typename T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
template <typename T>
T last_bit(T n) {
  return n & 1;
}
template <class T>
T big_mod(T n, T p, T m) {
  if (p == 0) return (T)1;
  T x = big_mod(n, p / 2, m);
  x = (x * x) % m;
  if (p & 1) x = (x * n) % m;
  return x;
}
template <class T>
T modInv(T a, T m) {
  T x, y;
  extgcd(a, m, x, y);
  x %= m;
  while (x < 0) {
    x += m;
  }
  return x;
}
template <class T>
T extgcd(T a, T b, T& x, T& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  } else {
    int g = extgcd(b, a % b, y, x);
    y -= a / b * x;
    return g;
  }
}
template <class T>
T multiplication(T n, T p, T m) {
  if (p == 0) return (T)0;
  T x = multiplication(n, p / 2, m);
  x = (x + x) % m;
  if (p & 1) x = (x + n) % m;
  return x;
}
template <class T>
T my_pow(T n, T p) {
  if (p == 0) return 1;
  T x = my_pow(n, p / 2);
  x = (x * x);
  if (p & 1) x = (x * n);
  return x;
}
template <class T>
double getdist(T a, T b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
template <class T>
T extract(string s, T ret) {
  stringstream ss(s);
  ss >> ret;
  return ret;
}
template <class T>
string tostring(T n) {
  stringstream ss;
  ss << n;
  return ss.str();
}
template <class T>
T Mod(T n, T m) {
  return (n % m + m) % m;
}
template <class T>
T MIN3(T a, T b, T c) {
  return min(a, min(b, c));
}
template <class T>
T MAX3(T a, T b, T c) {
  return max(a, max(b, c));
}
template <class T>
void print_vector(T& v) {
  int sz = v.size();
  if (sz) cout << v[0];
  for (int i = 1; i < sz; i++) cout << ' ' << v[i];
  cout << "\n";
}
bool isVowel(char ch) {
  ch = toupper(ch);
  if (ch == 'A' || ch == 'U' || ch == 'I' || ch == 'O' || ch == 'E')
    return true;
  return false;
}
bool isConsonant(char ch) {
  if (isalpha(ch) && !isVowel(ch)) return true;
  return false;
}
template <class R>
R Josephus(R n, R k) {
  R ans = 1;
  for (R i = 2; i <= n; i++) ans = (ans + k - 1) % i + 1;
  return ans;
}
template <class R>
R toitent_Phi2(R a) {
  R result = a;
  for (R i = 2; i * i <= a; i++) {
    if (a % i == 0) result = result - result / i;
    while (a % i == 0) a = a / i;
  }
  if (a > 1) result = result - result / a;
  return result;
}
template <typename T>
T Angle(T x1, T y1, T x2, T y2) {
  return atan(double(y1 - y2) / double(x1 - x2));
}
string s;
long long int a[5009], b[5009];
int main() {
  cin.sync_with_stdio(false);
  cin.tie();
  ;
  long long int T, t;
  long long int i, j, k;
  long long int n, m, q;
  cin >> s;
  string p = "x" + s + "x";
  long long int cnta = 0;
  long long int cntb = 0;
  for (i = 0; i < p.size(); i++) {
    if (p[i] == 'a')
      cnta++;
    else if (p[i] == 'b')
      cntb++;
    a[i] = cnta;
    b[i] = cntb;
  }
  long long int ans = 0;
  long long int sz = p.size();
  for (i = 1; i < sz; i++) {
    long long int x = a[i] - a[0];
    for (j = i + 1; j < sz; j++) {
      long long int y = b[j] - b[i];
      long long int z = a[sz - 1] - a[j];
      ans = max(ans, x + y + z);
    }
  }
  cout << ans << "\n";
  return 0;
}
