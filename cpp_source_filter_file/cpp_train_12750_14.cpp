#include <bits/stdc++.h>
using namespace std;
int cnt[15];
int main() {
  int n;
  scanf("%d", &n);
  char a[20];
  scanf("%s", a);
  for (int i = 0; i < n; i++) {
    if (a[i] == '2') cnt[2]++;
    if (a[i] == '3') {
      cnt[2]++;
      cnt[3]++;
    }
    if (a[i] == '4') {
      cnt[2] += 3;
      cnt[3]++;
    }
    if (a[i] == '5') {
      cnt[2] += 3;
      cnt[3]++;
      cnt[5]++;
    }
    if (a[i] == '6') {
      cnt[2] += 4;
      cnt[3] += 2;
      cnt[5]++;
    }
    if (a[i] == '7') {
      cnt[2] += 4;
      cnt[3] += 2;
      cnt[5]++;
      cnt[7]++;
    }
    if (a[i] == '7') {
      cnt[2] += 7;
      cnt[3] += 2;
      cnt[5]++;
      cnt[7]++;
    }
    if (a[i] == '7') {
      cnt[2] += 7;
      cnt[3] += 4;
      cnt[5]++;
      cnt[7]++;
    }
  }
  while (cnt[7] > 0) {
    printf("7");
    cnt[7]--;
    cnt[5]--;
    cnt[3] -= 2;
    cnt[2] -= 4;
  }
  while (cnt[5] > 0) {
    printf("5");
    cnt[5]--;
    cnt[3]--;
    cnt[2] -= 3;
  }
  while (cnt[3] > 0) {
    printf("3");
    cnt[3]--;
    cnt[2]--;
  }
  while (cnt[2] > 0) {
    printf("2");
    cnt[2]--;
  }
  return 0;
}
