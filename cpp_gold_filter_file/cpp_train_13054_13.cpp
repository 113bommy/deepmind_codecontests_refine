#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
const int p = 10000;
int k, m, xval;
set<int> res;
void solve(int value, int remain) {
  if (remain == 0) {
    int dif = abs(k - abs(value));
    if (dif < p) {
      if (res.size() < m) res.insert(dif * p + xval);
      if (res.size() < m) res.insert(p * xval + dif);
    }
    return;
  }
  solve(value + remain % 10, remain / 10);
  solve(value - remain % 10, remain / 10);
  solve(value * (remain % 10), remain / 10);
}
int main() {
  cin >> k >> m;
  for (int i = 0; i < p; i++) {
    xval = i;
    solve(i % 10, i / 10);
  }
  for (set<int>::iterator i = res.begin(); i != res.end(); i++)
    printf("%08d\n", *i);
  return 0;
}
