#include <bits/stdc++.h>
using namespace std;
int k, x = 3, y = 4, z = 5, i, j;
bool g[100][100];
string s = "NY";
void G(int a, int b) { g[a][b] = g[b][a] = true; }
int main() {
  for (cin >> k, G(0, 3), G(0, 4); k; G(x, x + 3), G(x, y + 3), G(y, y + 3),
                                      G(y, x + 3), G(z, z + 3), x += 3, y += 3,
                                      z += 3, k /= 2)
    if (k & 1) G(y, z);
  for (G(1, z), cout << "100\n" << endl; i < 100; cout << "\n", i++)
    for (j = 0; j < 100; cout << s[g[i][j++]])
      ;
}
