#include <bits/stdc++.h>
using namespace std;
struct stuff {
  int id, D, X;
} tmp;
int L, B, F, N, t1, t2, a, M;
vector<stuff> V;
bool flag;
int main() {
  scanf("%d%d%d%d", &L, &B, &F, &N);
  tmp.D = -B;
  V.push_back(tmp);
  tmp.D = L + F;
  V.push_back(tmp);
  for (int z = 1; z <= N; ++z) {
    scanf("%d%d", &a, &tmp.X);
    tmp.id = z;
    if (a == 1) {
      flag = 0;
      for (int i = 0; i < V.size() - 1; ++i) {
        if (V[i + 1].D - (F + tmp.X + B + V[i].X + V[i].D) >= 0) {
          ++i;
          tmp.D = V[i - 1].D + V[i - 1].X + B;
          printf("%d\n", tmp.D);
          V.insert(V.begin() + i, tmp);
          flag = 1;
          break;
        }
      }
      if (!flag) printf("-1\n");
    } else {
      for (int i = 1; i < V.size(); ++i) {
        if (V[i].id == tmp.X) {
          V.erase(V.begin() + i);
          break;
        }
      }
    }
  }
}
