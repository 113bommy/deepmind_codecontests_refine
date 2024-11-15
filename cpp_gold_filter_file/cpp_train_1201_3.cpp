#include <bits/stdc++.h>
using namespace std;
int h, q;
map<int, double> sum, ec;
char task[20];
double f(int x, double best) {
  if (sum[x] <= best)
    return best;
  else {
    return 0.5 * f(x * 2, max(best, sum[x * 2 + 1] + ec[x])) +
           0.5 * f(x * 2 + 1, max(best, sum[x * 2] + ec[x]));
  }
}
int main() {
  while (scanf("%d%d", &h, &q) != EOF) {
    ec.clear();
    sum.clear();
    for (int t = 0; t < q; t++) {
      scanf("%s", task);
      if (strcmp(task, "add") == 0) {
        int v, e;
        scanf("%d%d", &v, &e);
        ec[v] += e;
        while (v) {
          sum[v] += e;
          v /= 2;
        }
      } else {
        printf("%.8lf\n", f(1, 0));
      }
    }
  }
  return 0;
}
