#include <bits/stdc++.h>
using namespace std;
struct debugger {
  template <typename T>
  debugger& operator,(const T& v) {
    cerr << v << " ";
    return *this;
  }
} dbg;
int main() {
  int r1, r2, c1, c2, d1, d2;
  cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;
  vector<int> sums{r1, c1, d1, d2, c2, r2};
  for (int c = 1; c < 10; c++)
    for (int d = 1; d < 10; d++)
      for (int e = 1; e < 10; e++)
        for (int f = 1; f < 10; f++) {
          vector<int> vec{c, d, e, f};
          set<int> s(vec.begin(), vec.end());
          if (s.size() == 4) {
            int i = 0;
            for (int g = 0; g < 4; g++)
              for (int h = g + 1; h < 4; h++)
                if (vec[g] + vec[h] != sums[i++]) goto fail;
            cout << c << ' ' << d << endl << e << ' ' << f << endl;
            return 0;
          fail:;
          }
        }
  cout << "-1\n";
  return 0;
}
