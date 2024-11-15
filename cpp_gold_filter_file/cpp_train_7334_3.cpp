#include <bits/stdc++.h>
using namespace std;
int fat[12000], fatt[12000];
inline int fnd(int x) {
  if (fat[x] == x) return x;
  return fat[x] = fnd(fat[x]);
}
inline int fndd(int x) {
  if (fatt[x] == x) return x;
  return fatt[x] = fndd(fatt[x]);
}
string str;
map<string, int> mp;
int x1, x2, x3, n, m, kp, edge[1200][2], key[1200][1200], keyy[1200][1200],
    pos[1200], keypos[1200], poss[1200];
int main() {
  cin >> n >> m >> kp;
  for (int i = 1; i <= n; i++) {
    fat[i] = i;
    fatt[i] = i;
  }
  for (int i = 1; i <= m; i++) {
    cin >> edge[i][0] >> edge[i][1];
  }
  for (int i = 1; i <= kp; i++) {
    cin >> str;
    mp[str] = i;
    cin >> pos[i] >> key[i][0];
    for (int j = 1; j <= key[i][0]; j++) {
      cin >> key[i][j];
      keypos[key[i][j]] = pos[i];
    }
  }
  for (int i = 1; i <= kp; i++) {
    for (int j = 1; j <= kp; j++) {
      for (int k = 1; k <= key[j][0]; k++) {
        x1 = edge[key[j][k]][0];
        x2 = edge[key[j][k]][1];
        if (fnd(x1) == fnd(pos[j]) || fnd(x2) == fnd(pos[j]))
          fat[fnd(x1)] = fnd(x2);
      }
    }
  }
  for (int i = 1; i <= kp; i++) {
    cin >> str;
    x1 = mp[str];
    cin >> x2;
    if (fnd(x2) != fnd(pos[x1])) {
      printf("NO");
      return 0;
    }
    poss[i] = x2;
    cin >> keyy[i][0];
    for (int j = 1; j <= keyy[i][0]; j++) {
      cin >> keyy[i][j];
      if (fnd(keypos[keyy[i][j]]) != fnd(pos[x1])) {
        printf("NO");
        return 0;
      }
    }
  }
  for (int i = 1; i <= kp; i++) {
    for (int j = 1; j <= kp; j++) {
      for (int k = 1; k <= keyy[j][0]; k++) {
        x1 = edge[keyy[j][k]][0];
        x2 = edge[keyy[j][k]][1];
        if (fndd(x1) == fndd(poss[j]) || fndd(x2) == fndd(poss[j]))
          fatt[fndd(x1)] = fndd(x2);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (fnd(i) == fnd(j)) {
        if (fndd(i) != fndd(j)) {
          printf("NO");
          return 0;
        }
      } else {
        if (fndd(i) == fndd(j)) {
          printf("NO");
          return 0;
        }
      }
    }
  }
  printf("YES");
  return 0;
}
