#include <bits/stdc++.h>
using namespace std;
int b[6][6];
int main() {
  int a[30];
  char ch[10];
  int sum = 0;
  int max;
  b[1][6] = 1;
  b[2][5] = 1;
  b[2][3] = 2;
  b[2][4] = 2;
  b[3][2] = 6;
  b[3][3] = 3;
  b[3][4] = 2;
  b[4][3] = 5;
  b[4][2] = 8;
  b[5][2] = 15;
  b[6][1] = 30;
  memset(a, 0, sizeof(a));
  scanf("%s", ch);
  for (int i = 0; i < 6; i++) a[ch[i] - 'A']++;
  max = 0;
  for (int i = 0; i < 26; i++)
    if (a[i] != 0) {
      sum++;
      if (a[i] > max) max = a[i];
    }
  printf("%d\n", b[sum][max]);
  return 0;
}
