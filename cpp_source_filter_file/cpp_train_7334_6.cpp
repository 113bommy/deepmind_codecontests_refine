#include <bits/stdc++.h>
using namespace std;
int a[1000];
int b[1000];
char name[1000][250];
int pos[1000];
int h[1000];
int v1[1000] = {0};
int v2[1000] = {0};
int ff[1000];
int n, m, k;
int f(int x) {
  if (ff[x] != x && ff[x])
    ff[x] = f(ff[x]);
  else
    ff[x] = x;
  return ff[x];
}
void join(int a, int b) { ff[f(a)] = f(b); }
void r(int* v) {
  memset(ff, 0, sizeof(ff));
  bool flag = true;
  while (flag) {
    flag = false;
    for (int i = 1; i <= m; i++) {
      if (v[i] == 0 & (f(a[i]) == f(pos[i]) || f(b[i]) == f(pos[i]))) {
        join(a[i], b[i]);
        v[i] = flag = true;
      }
    }
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= m; i++) scanf("%d%d", &a[i], &b[i]);
  for (int i = 0; i < k; i++) {
    scanf("%s", name[i]);
    scanf("%d", &h[i]);
    int y;
    scanf("%d", &y);
    for (int j = 0; j < y; j++) {
      int z;
      scanf("%d", &z);
      pos[z] = h[i];
    }
  }
  r(v1);
  bool rez = true;
  char s[100];
  for (int j = 0; j < k; j++) {
    scanf("%s", s);
    for (int i = 0; i < k; i++)
      if (strcmp(s, name[i]) == 0) {
        int x;
        scanf("%d", &x);
        if (f(x) != f(h[i])) rez = false;
        h[i] = x;
        int y;
        scanf("%d", &y);
        for (int j = 0; j < y; j++) {
          int z;
          scanf("%d", &z);
          if (f(pos[z]) != f(h[i])) rez = false;
          pos[z] = h[i];
        }
      }
  }
  r(v2);
  for (int i = 1; i <= m; i++)
    if (v1[i] != v2[i]) rez = false;
  if (rez)
    printf("YES");
  else
    printf("NO");
}
