#include <bits/stdc++.h>
using namespace std;
int main() {
  int fin;
  int x = 0;
  int a, b, c, d, r;
  int ar[1000];
  int arb[1000];
  d = 0;
  cin >> a;
  for (int i = 0; i < a; i++) {
    cin >> ar[i] >> arb[i];
  }
  cin >> r;
  for (int i = 0; i < a; i++) {
    if (arb[i] > r) d++;
  }
  cout << d;
  cin >> fin;
}
