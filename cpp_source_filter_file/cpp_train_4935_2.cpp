#include <bits/stdc++.h>
using namespace std;
const int BSE = 131;
int pl, sl, k;
unsigned int hap[1000005], has[205];
char p[1000005], s[205], ans[2005], cur[2005];
int main() {
  char c;
  while ((c = getchar()) != '\n') p[pl++] = c;
  while ((c = getchar()) != '\n') s[sl++] = c;
  scanf("%d", &k);
  for (int i = pl - 1; i >= 0; i--)
    hap[i] = (i + k < pl ? hap[i + k] : 0) * BSE + p[i] - 32;
  for (int i = 1; i <= k && i <= sl; i++) {
    for (int j = sl - 1; j >= 0; j--)
      has[j] = (j + i < sl ? has[j + i] : 0) * BSE + s[j] - 32;
    int now = i - 1;
    for (int j = k - 1; j >= 0; j--)
      if (now >= 0 && hap[j] == has[now])
        cur[j] = '1', now--;
      else
        cur[j] = '0';
    if (now < 0 && (!ans[0] || strcmp(cur, ans) < 0)) strcpy(ans, cur);
  }
  if (!ans[0])
    puts("0");
  else
    puts(ans);
}
