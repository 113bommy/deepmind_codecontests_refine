#include <bits/stdc++.h>
using namespace std;
int t, n, i, T, p[10], ans, k;
char S[1000];
int main() {
  scanf("%d", &t);
  scanf("%s", S);
  n = strlen(S);
  for (i = 0; i < n; i++)
    if (S[i] == '5')
      p[2]++;
    else if (S[i] == '9')
      p[6]++;
    else
      p[S[i] - '0']++;
  while (true) {
    T = t;
    while (T) {
      if (T % 10 == 5)
        k = 2;
      else if (T % 10 == 9)
        k = 6;
      else
        k = T % 10;
      if (!p[k]) {
        printf("%d\n", ans);
        return 0;
      }
      p[k]--;
      T /= 10;
    }
    ans++;
  }
}
