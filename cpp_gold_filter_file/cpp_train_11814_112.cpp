#include <bits/stdc++.h>
using namespace std;
int main() {
  int w, l;
  cin >> w >> l;
  if ((w * l) % 2) {
    cout << ((w * l) - 1) / 2;
  } else {
    cout << (w * l) / 2;
  }
}
