#include <bits/stdc++.h>
using namespace std;
int sp[1100000];
int k;
bool verif(int x);
int main() {
  int n, c;
  ios_base::sync_with_stdio(0);
  cin >> n >> k;
  while (n--) {
    cin >> c;
    sp[c]++;
  }
  for (int i(1); i < 1100000; i++) sp[i] += sp[i - 1];
  for (int i(1000000); i >= 1; i--) {
    if (verif(i)) {
      cout << i;
      return 0;
    }
  }
  return 0;
}
bool verif(int x) {
  if (x == 3) cout << "";
  if (sp[x - 1]) return 0;
  if (x <= k) return true;
  bool posibil(1);
  for (int i(2 * x); i < 1100000; i += x) {
    if (sp[i - 1] - sp[i - x + k]) posibil = 0;
  }
  return posibil;
}
