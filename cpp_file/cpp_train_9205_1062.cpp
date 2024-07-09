#include <bits/stdc++.h>
const double pi = 3.1415926535897932384626433832795;
double EPS = 10e-6;
const int INF = 2000000000;
#pragma comment(linker, "/stack:1500000000")
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
using namespace std;
void ifd() {}
void tme() {}
long long a, b;
int main() {
  ifd();
  cin >> a >> b;
  cout << a + b << "\n";
  tme();
  return 0;
}
