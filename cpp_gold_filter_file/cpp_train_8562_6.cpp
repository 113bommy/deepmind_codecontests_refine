#include <bits/stdc++.h>
using namespace std;
int main() {
  char arr1[101];
  cin >> arr1;
  int len = 1;
  int x = 0;
  for (int i = 0; i < strlen(arr1); i++) {
    if (len == 5) {
      x++;
      len = 1;
      i++;
      if (i == strlen(arr1)) break;
    }
    if (arr1[i] == arr1[i + 1]) {
      len++;
    }
    if (arr1[i] != arr1[i + 1]) {
      x++;
      len = 1;
    }
  }
  cout << x;
  return 0;
}
