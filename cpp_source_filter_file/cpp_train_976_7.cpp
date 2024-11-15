#include <bits/stdc++.h>
using namespace std;
const int Asize = 1000;
int A[Asize][Asize] = {{0}};
void func(int x, int y) {
  if (A[x][y] < 4) return;
  int a = A[x][y] / 4;
  A[x][y] %= 4;
  A[x - 1][y] += a;
  func(x - 1, y);
  A[x][y - 1] += a;
  func(x, y - 1);
  A[x][y + 1] += a;
  func(x, y + 1);
  A[x + 1][y] += a;
  func(x + 1, y);
}
int main(void) {
  int t;
  cin >> A[Asize / 2][Asize / 2] >> t;
  func(Asize / 2, Asize / 2);
  for (int i = 0; i < t; i++) {
    int x, y;
    cin >> x >> y;
    if (x < -Asize / 2 || x > Asize / 2 || y < -Asize / 2 || y > Asize / 2)
      cout << 9 << endl;
    else
      cout << A[Asize / 2 + x][Asize / 2 + y] << endl;
  }
  return 0;
}
