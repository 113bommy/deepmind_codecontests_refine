#include <bits/stdc++.h>
using namespace std;
int cnt[100001];
int a[100001];
int n;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    cnt[a[i]]++;
  }
  for (int i = 2; i <= n; i++)
    if (cnt[i] > cnt[i - 1]) {
      printf("-1\n");
      return 0;
    }
  printf("%d\n", cnt[1]);
  for (int i = 0; i < n; i++) {
    if (i) printf(" ");
    printf("%d", cnt[a[i]]--);
  }
  return 0;
}
