#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  vector<int> A;
  for (int i = 0; i < n; i++) {
    int e;
    scanf("%d", &e);
    A.push_back(e);
  }
  sort(A.begin(), A.end());
  if (A[n] != A[n - 1]) {
    printf("YES");
  } else {
    printf("NO");
  }
}
