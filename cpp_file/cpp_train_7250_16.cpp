#include <bits/stdc++.h>
using namespace std;
int a[100];
string command[100];
string ex(int id) {
  string ans = "eax";
  ans[1] += id;
  return ans;
}
bool dfs(int MAX, int pos, int N) {
  int i, j, k;
  if (a[pos] > N) return false;
  if (pos == MAX) {
    if (a[pos] != N) return false;
    cout << MAX << endl;
    for ((i) = 0; (i) < (int)(MAX); (i)++) cout << command[i] << endl;
    return true;
  }
  for ((i) = 0; (i) < (int)(pos + 1); (i)++)
    for (k = 1; k <= 8; k *= 2) {
      a[pos + 1] = a[i] * k;
      if (a[pos + 1] > N) continue;
      if (pos + 1 == MAX && a[pos + 1] != N) continue;
      command[pos] =
          "lea " + ex(pos + 1) + ", [" + (char)('0' + k) + "*" + ex(i) + "]";
      if (dfs(MAX, pos + 1, N)) return true;
    }
  for ((i) = 0; (i) < (int)(pos + 1); (i)++)
    for ((j) = 0; (j) < (int)(pos + 1); (j)++)
      for (k = 1; k <= 8; k *= 2) {
        a[pos + 1] = a[i] * k + a[j];
        if (a[pos + 1] > N) continue;
        if (pos + 1 == MAX && a[pos + 1] != N) continue;
        command[pos] = "lea " + ex(pos + 1) + ", [" + ex(j) + " + " +
                       (char)('0' + k) + "*" + ex(i) + "]";
        if (dfs(MAX, pos + 1, N)) return true;
      }
}
int main(void) {
  int N, i;
  cin >> N;
  a[0] = 1;
  for (i = 0;; i++)
    if (dfs(i, 0, N)) break;
  return 0;
}
