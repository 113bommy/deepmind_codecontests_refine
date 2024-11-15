#include <bits/stdc++.h>
using namespace std;
int main() {
  int x;
  scanf("%d", &x);
  vector<int> luck;
  for (int i = 1; i <= 8; i++) {
    for (int j = 0; j <= i; j++) {
      int four = i - j;
      int seven = j;
      string s;
      while (four--) s += "4";
      while (seven--) s += "7";
      do {
        luck.push_back(atoi(s.c_str()));
      } while (next_permutation(s.begin(), s.end()));
    }
  }
  sort(luck.begin(), luck.end());
  printf("%d\n",
         (int)(upper_bound(luck.begin(), luck.end(), x) - luck.begin()));
  return 0;
}
