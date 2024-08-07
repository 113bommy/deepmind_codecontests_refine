#include <bits/stdc++.h>
using namespace std;
int a[510000];
int n;
bool Dif(int pos) {
  for (int i = 0; i < n; i++) {
    if (i == pos) continue;
    int next1 = i + 1;
    if (next1 == pos) next1++;
    if (next1 >= n) continue;
    if (a[i] == 0 && a[next1] != 0) return false;
    int next2 = next1 + 1;
    if (next2 == pos) next2++;
    if (next2 >= n) break;
    if (a[next1] * a[next1] == a[next2] * a[i])
      continue;
    else
      return false;
  }
  return true;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  int pos = -1;
  if (a[0] == 0 && a[1] != 0) pos = 0;
  for (int i = 1; i < n - 1 && pos == -1; i++)
    if (a[i] * a[i] != a[i - 1] * a[i + 1] || (a[i] == 0 && a[i + 1] != 0)) {
      pos = i - 1;
      break;
    }
  if (pos == -1) {
    puts("0");
    return 0;
  }
  for (int i = 0; i < 3; i++)
    if (Dif(pos + i) == true) {
      puts("1");
      return 0;
    }
  puts("2");
  return 0;
}
