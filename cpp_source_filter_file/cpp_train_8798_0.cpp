#include <bits/stdc++.h>
using namespace std;
int n, i;
map<string, int> mymap;
string str[200000];
int main() {
  cin >> n;
  for (i = 0; i < n; i++) cin >> str[i];
  for (i = n; i >= 0; i--)
    if (mymap[str[i]] == 0) {
      mymap[str[i]] = 1;
      cout << str[i];
    }
}
