#include <bits/stdc++.h>
int mat[1000][1000], n, end, snc, syc;
int main() {
  FILE *in = fopen("hobbit.in", "r");
  scanf("%d", &n);
  while (snc <= n) {
    end++;
    snc += end;
  }
  snc -= end;
  end--;
  for (int r = 0; r < end; r++) {
    for (int i = r; i < end; i++) {
      mat[r][i] = syc + 1;
      mat[i + 1][r] = syc + 1;
      syc++;
    }
  }
  printf("%d\n", end);
  for (int i = 0; i <= end; i++, printf("\n"))
    for (int j = 0; j < end; j++) printf("%d ", mat[i][j]);
  getchar();
}
