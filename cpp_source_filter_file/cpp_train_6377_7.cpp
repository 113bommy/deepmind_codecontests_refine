#include <bits/stdc++.h>
using namespace std;
const int maxn = 200 * 1001;
const int infty = 10001 * 1000;
char A[maxn];
int B[maxn], P[maxn], S[maxn];
int main() {
  scanf("%s", A);
  int n = strlen(A);
  for (int i = 0; i < n; i++)
    if (tolower(A[i]) == 'a' || tolower(A[i]) == 'e' || tolower(A[i]) == 'i' ||
        tolower(A[i]) == 'o' || tolower(A[i]) == 'u')
      B[i + 1] = -1;
    else
      B[i + 1] = 2;
  P[0] = 0;
  for (int i = 1; i <= n; i++) P[i] = P[i - 1] + B[i];
  S[n + 1] = -infty;
  for (int i = n; i >= 1; i--) S[i] = max(S[i + 1], P[i]);
  int a = 0;
  int b = 0;
  int k = 0;
  int prev = infty;
  while (a < n) {
    b = max(b, a);
    while (b <= n && S[b + 1] >= S[a]) b++;
    k = max(k, b - a);
    prev = P[a];
    while (a < n && P[a] >= prev) a++;
  }
  int r = 0;
  for (int i = 0; i + k <= n; i++)
    if (P[i + k] >= P[i]) r++;
  printf(k ? "%d %d\n" : "No solution", k, r);
}
