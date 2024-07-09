#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:167177216")
using namespace std;
const int MAX = 2147483647;
const int MAXN = 200100;
const long long MOD = 1000000000 + 7;
vector<int> a;
int readij(int i) {
  cin >> a[i];
  return 1;
}
int reader(int i, int n) {
  int res = (i < n * n) ? readij(i) : 0;
  return res ? reader(i + 1, n) : 0;
}
int calc(int k, int i, int j, int n) {
  a[i * n + j] = min(a[i * n + j], a[i * n + k] + a[k * n + j]);
  return 1;
}
int filler(int i, int n) {
  int res = (i < n * n * n) ? calc(i / n / n, (i / n) % n, i % n, n) : 0;
  return res ? filler(i + 1, n) : 0;
}
int maxi = 0;
int maximize(int i) {
  maxi = max(maxi, a[i]);
  return 1;
}
int solver(int i, int n) {
  int res = (i < n * n) ? maximize(i) : 0;
  return res ? solver(i + 1, n) : 0;
}
int main(int argc, char* argv[]) {
  int n;
  cin >> n;
  a.resize(n * n);
  reader(0, n);
  filler(0, n);
  solver(0, n);
  cout << maxi;
  return 0;
}
