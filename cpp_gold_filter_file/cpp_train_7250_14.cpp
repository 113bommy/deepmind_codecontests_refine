#include <bits/stdc++.h>
using namespace std;
int target = 0;
int best = 8;
int op1[10];
int op2[10];
int op3[10];
int bop1[10];
int bop2[10];
int bop3[10];
int nr[100];
int N;
void go(int lvl) {
  if (lvl >= best) return;
  for (int i = 0; i < N; ++i)
    if (nr[i] == target && lvl < best) {
      best = lvl;
      memcpy(bop1, op1, sizeof(int) * lvl);
      memcpy(bop2, op2, sizeof(int) * lvl);
      memcpy(bop3, op3, sizeof(int) * lvl);
      return;
    }
  if (lvl >= best - 1) return;
  int n = N;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      for (int k = 1; k <= 8; k *= 2) {
        nr[N++] = nr[i] + nr[j] * k;
        op1[lvl] = i;
        op2[lvl] = k;
        op3[lvl] = j;
        go(lvl + 1);
        --N;
      }
}
int main() {
  nr[0] = 1;
  nr[1] = 0;
  N = 2;
  cin >> target;
  go(0);
  cout << best << '\n';
  for (int lvl = 0; lvl < best; ++lvl) {
    cout << "lea e" << (char)('a' + lvl + 2) << "x, [e";
    cout << (char)('a' + bop1[lvl]) << "x + " << bop2[lvl] << "*e"
         << (char)('a' + bop3[lvl]) << "x]\n";
  }
  return 0;
}
