#include <bits/stdc++.h>
int arr[100005];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans += arr[i];
    int j = 0;
    while (i + (1 << j) < n) j++;
    --j;
    arr[i + (1 << j)] += arr[i];
    printf("%I64d\n", ans);
  }
}
