#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  double a, b, r;
  cin >> a >> b >> r;
  if (a / 2 >= r && b / 2 >= r) {
    cout << "First";
  } else {
    cout << "Second";
  }
}
