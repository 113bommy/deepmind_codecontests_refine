#include <bits/stdc++.h>
using namespace std;
void solve(int x, int y, int z) {
  if (y - x == 3 || x - y == 9) {
    if (z - y == 4 || y - z == 8) {
      cout << "minor";
      exit(0);
    }
  }
  if (y - x == 4 || x - y == 8) {
    if (z - y == 3 || y - z == 9) {
      cout << "major";
      exit(0);
    }
  }
}
int main() {
  map<string, int> M;
  M["C"] = 1;
  M["C#"] = 2;
  M["D"] = 3;
  M["D#"] = 4;
  M["E"] = 5;
  M["F"] = 6;
  M["F#"] = 7;
  M["G"] = 8;
  M["G#"] = 9;
  M["A"] = 10;
  M["B"] = 11;
  M["H"] = 12;
  string a, b, c;
  cin >> a >> b >> c;
  int x = M[a], y = M[b], z = M[c];
  solve(x, y, z);
  solve(x, z, y);
  solve(y, x, z);
  solve(y, z, x);
  solve(z, x, y);
  solve(z, y, z);
  cout << "strange";
  return 0;
}
