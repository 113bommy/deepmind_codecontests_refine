#include <bits/stdc++.h>
using namespace std;
int n, a1 = 0, a2, b[303];
void print() {
  for (int i = b[0]; i >= 1; i--) cout << b[i];
  cout << endl;
}
void add(int s) {
  for (int i = 1; s; i++) {
    while (b[i] < 9 && s > 0) b[i]++, s--;
    if (!s) b[0] = max(b[0], i);
  }
}
void sub(int s) {
  for (int i = 1;; i++) {
    b[0] = max(b[0], i);
    if (b[i] != 9 && s > 0) {
      b[i]++, s--;
      add(s);
      break;
    }
    s += b[i], b[i] = 0;
  }
}
void calc(int s) {
  if (s > 0)
    add(s);
  else
    sub(s);
  print();
}
int main() {
  cin >> n;
  while (n--) {
    cin >> a2;
    calc(a2 - a1);
    a1 = a2;
  }
}
