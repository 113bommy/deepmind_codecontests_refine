#include <bits/stdc++.h>
int a;
int d[109];
int b[109][109];
int main() {
  scanf("%d", &a);
  for (int i = 0; i < a; i++)
    for (int j = 0; j < a; j++) scanf("%d", &b[i][j]);
  for (int i = 0; i < a; i++)
    for (int j = 0; j < a; j++)
      if (i != j) d[i] = (d[i] | b[i][j]);
  for (int i = 0; i < a; i++) printf("%d", d[i]);
}
