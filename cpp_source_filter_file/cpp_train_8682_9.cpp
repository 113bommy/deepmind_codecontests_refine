#include <bits/stdc++.h>
using namespace std;
vector<int> children[50000];
int daddy[50000];
int N, R1, R2;
void dfs(int n, int d) {
  if (daddy[n]) return;
  daddy[n] = d;
  for (int i = 0; i < children[n].size(); i++) dfs(children[n][i], n);
}
int main() {
  scanf("%d %d %d", &N, &R1, &R2);
  for (int i = 0; i < N; i++) {
    if (i == R1 - 1) continue;
    int a;
    scanf("%d", &a);
    children[a - 1].push_back(i);
    children[i].push_back(a - 1);
  }
  dfs(R2 - 1, -1);
  for (int i = 0; i < N; i++)
    if (daddy[i] != -1) printf("%d ", daddy[i] + 1);
  printf("\n");
}
