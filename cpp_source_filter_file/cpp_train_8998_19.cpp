#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  while (a && b) {
    if (a > b)
      a %= b;
    else
      b %= a;
  }
  return a + b;
}
const int N = 2000000;
const int nn = 2000;
long long l, r, b[N], c[N], n, a[N], x, k, m, z, e[nn][nn];
double d[N];
pair<long long, long long> p;
pair<string, string> S;
pair<char, char> C;
vector<long long> V;
unordered_map<long long, long long> mp;
string s, t;
char ch, cc;
bool flag = false;
stack<long long> st;
int main() {
  cin >> s;
  n = s.size();
  s = (n < 2 ? '0' + s : s);
  n = s.size();
  cout << (((s[n - 1] - '0') * 10 + s[n] - '0') % 4 ? 0 : 4);
  return 0;
}
