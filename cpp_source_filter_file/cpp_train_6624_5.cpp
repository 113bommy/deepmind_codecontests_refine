#include <bits/stdc++.h>
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = mod1 + 2;
const int e = 10;
string s;
long long h1[1000000], h2[1000000];
long long e_pow1[1000000], e_pow2[1000000];
long long roll(long long h, int e, int val, int mod) {
  h *= e;
  if (h >= mod) h %= mod;
  h += val;
  if (h >= mod) h %= mod;
  return h;
}
long long subtract(long long a, long long b, int mod) {
  if (b >= mod) b %= mod;
  if (a < b) a += mod;
  a -= b;
  if (a >= mod) a %= mod;
  return a;
}
bool check(int p1, int p2) {
  int a = p1 + 1;
  int c = s.size() - p2 - 1;
  int b = p2 - p1;
  if (a < 1 || b < 1 || c < 1) return false;
  if (c < a || c < b) return false;
  if (b > 1 && s[p1 + 1] == '0') return false;
  if (c > 1 && s[p2 + 1] == '0') return false;
  long long a1 = h1[p1];
  long long a2 = h2[p1];
  long long b1 = subtract(h1[p2], roll(a1, e_pow1[b], 0, mod1), mod1);
  long long b2 = subtract(h2[p2], roll(a2, e_pow2[b], 0, mod2), mod2);
  long long c1 = subtract(
      h1[s.size() - 1], roll(h1[p2], e_pow1[s.size() - 1 - p2], 0, mod1), mod1);
  long long c2 = subtract(
      h2[s.size() - 1], roll(h2[p2], e_pow2[s.size() - 1 - p2], 0, mod2), mod2);
  if (c1 == (b1 + a1) % mod1 && c2 == (b2 + a2) % mod2) return true;
  return false;
}
void print(int p1, int p2) {
  for (int i = 0; i < s.size(); i++) {
    cout << s[i];
    if (i == p1) cout << "+";
    if (i == p2) cout << "=";
  }
}
int main() {
  int i;
  int p1, p2;
  cin >> s;
  e_pow1[0] = e_pow2[0] = 1;
  h1[0] = h2[0] = s[0] - '0';
  for (i = 1; i < s.size(); i++) {
    e_pow1[i] = roll(e_pow1[i - 1], e, 0, mod1);
    e_pow2[i] = roll(e_pow2[i - 1], e, 0, mod2);
    h1[i] = roll(h1[i - 1], e, s[i] - '0', mod1);
    h2[i] = roll(h2[i - 1], e, s[i] - '0', mod2);
  }
  for (i = 1; i < s.size() - 1; i++) {
    p2 = s.size() - i - 1;
    p1 = i;
    if (check(p1, p2)) {
      print(p1, p2);
      return 0;
    }
    p1 = i - 1;
    if (check(p1, p2)) {
      print(p1, p2);
      return 0;
    }
    p1 = p2 - i;
    if (check(p1, p2)) {
      print(p1, p2);
      return 0;
    }
    p1 = p2 - i + 1;
    if (check(p1, p2)) {
      print(p1, p2);
      return 0;
    }
  }
  return 0;
}
