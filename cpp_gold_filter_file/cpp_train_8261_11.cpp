#include <bits/stdc++.h>
using namespace std;
const int Mod = 1000000009;
int z[2][35][35][35][35], u[2][35][35][35][35];
int us, p[4], up[4], np[4];
int n, h;
int main() {
  scanf("%d%d", &n, &h);
  z[1][0][0][0][0] = 1;
  us++;
  u[1][0][0][0][0] = us;
  for (int i = 1; i <= n; i++) {
    int now = i % 2;
    int nxt = 1 - now;
    int nus = us + 1;
    for (p[0] = 0; p[0] <= h; p[0]++) {
      for (p[1] = p[0]; p[1] <= h; p[1]++) {
        for (p[2] = p[1]; p[2] <= h; p[2]++) {
          for (p[3] = p[2]; p[3] <= h; p[3]++) {
            if (u[now][p[0]][p[1]][p[2]][p[3]] == us &&
                z[now][p[0]][p[1]][p[2]][p[3]]) {
              for (int i = 0; i < 4; i++) {
                up[i] = min(h, p[i] + 1);
              }
              for (int i = 0; i < 4; i++) {
                memcpy(np, up, sizeof(up));
                if (p[i] < h) {
                  np[i] = 0;
                  for (int j = i; j > 0 && np[j] < np[j - 1]; j--) {
                    swap(np[j], np[j - 1]);
                  }
                }
                if (u[nxt][np[0]][np[1]][np[2]][np[3]] != nus) {
                  u[nxt][np[0]][np[1]][np[2]][np[3]] = nus;
                  z[nxt][np[0]][np[1]][np[2]][np[3]] = 0;
                }
                z[nxt][np[0]][np[1]][np[2]][np[3]] +=
                    z[now][p[0]][p[1]][p[2]][p[3]];
                if (z[nxt][np[0]][np[1]][np[2]][np[3]] >= Mod) {
                  z[nxt][np[0]][np[1]][np[2]][np[3]] -= Mod;
                }
              }
            }
          }
        }
      }
    }
    us++;
  }
  int ans = 0;
  int now = (n + 1) % 2;
  for (p[0] = 0; p[0] < h; p[0]++) {
    for (p[1] = p[0]; p[1] <= h; p[1]++) {
      for (p[2] = p[1]; p[2] <= h; p[2]++) {
        for (p[3] = p[2]; p[3] <= h; p[3]++) {
          if (u[now][p[0]][p[1]][p[2]][p[3]] == us) {
            ans += z[now][p[0]][p[1]][p[2]][p[3]];
            ans %= Mod;
          }
        }
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
