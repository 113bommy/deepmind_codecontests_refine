#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) {
  int x1, x2, y1, y2;
  map<pair<int, int>, int> M;
  int countX = 0, countY = 0;
  for (int i = 0; i < 4; i++) {
    cin >> x1 >> y1 >> x2 >> y2;
    if ((x1 == x2) && (y1 != y2)) countY++;
    if ((y1 == y2) && (x1 != x2)) countX++;
    M[make_pair(x1, y1)]++;
    M[make_pair(x2, y2)]++;
  }
  bool flag = ((countX == 2) && (countY == 2)) ? true : false;
  map<pair<int, int>, int>::iterator itM;
  for (itM = M.begin(); itM != M.end(); itM++)
    if (flag &= (itM->second == 2) ? true : false)
      continue;
    else
      break;
  cout << ((flag) ? "YES" : "NO");
  return (0);
}
