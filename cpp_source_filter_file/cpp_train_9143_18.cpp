#include <bits/stdc++.h>
using namespace std;
int main() {
  int A, B, C, D;
  cin >> A >> B >> C >> D;
  cout << max(0, min(B, D) - min(A, C)) << endl;
}
