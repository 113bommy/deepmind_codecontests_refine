#include <bits/stdc++.h>
using namespace std;
int a1, b1, c1, a2, b2, c2;
int main() {
  cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
  if (!a1 && !b1 && c1 || !a2 && !b2 && c2) return puts("0"), 0;
  if (a1 * b2 != a2 * b1) return puts("1"), 0;
  if (a1 * b2 == a2 * b1 && c1 * a2 == c2 * a1) return puts("-1"), 0;
  return puts("0"), 0;
}
