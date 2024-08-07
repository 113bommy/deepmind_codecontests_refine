#include <bits/stdc++.h>
using namespace std;
void mySwap(int &a, int &b) {
  a ^= b;
  b ^= a;
  a ^= b;
}
void mySort(int *array, int n) {
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n - i - 1; j++)
      if (array[j] > array[j + 1]) mySwap(array[j], array[j + 1]);
  }
}
int main() {
  int n, k;
  cin >> n >> k;
  if (k > n) {
    cout << -1 << endl;
    return 0;
  }
  int i;
  int data[n];
  for (i = 0; i < n; i++) cin >> data[i];
  mySort(data, n);
  cout << 0 << ' ' << data[n - k] << endl;
  return 0;
}
