#include <bits/stdc++.h>
using namespace std;
const int maxn = 6;
int In[maxn];
int l[maxn][maxn];
int h[maxn][maxn];
int a[maxn][maxn];
int n, ans;
void dfs(int s, int t, int sum) {
  if (t == n) {
    if (s != n - 2 && In[s] != 0) return;
    s++;
    t = s + 1;
  }
  if (s == n - 1) {
    if (ans < sum) ans = sum;
    return;
  }
  for (int i = l[s][t]; i <= h[s][t]; i++) {
    if (In[s] < i) continue;
    In[s] -= i;
    In[t] += i;
    dfs(s, t + 1, sum + (i ? a[s][t] : 0) + i * i);
    In[t] -= i;
    In[s] += i;
  }
}
int main() {
  scanf("%d", &n);
  int m = n * (n - 1) / 2;
  int minf = 0, maxf = 0;
  while (m--) {
    int s, f;
    scanf("%d%d", &s, &f);
    s--, f--;
    scanf("%d%d", &l[s][f], &h[s][f]);
    scanf("%d", &a[s][f]);
    if (s == 0) {
      minf += l[s][f];
      maxf += h[s][f];
    }
  }
  ans = -1;
  memset(In, 0, sizeof(In));
  for (int i = minf; i <= maxf; i++) {
    In[0] = i;
    dfs(0, 1, 0);
    if (ans != -1) break;
  }
  if (ans == -1) In[0] = -1;
  printf("%d %d\n", In[0], ans);
  return 0;
}
