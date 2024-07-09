#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, l;
  cin >> k >> l;
  int x = 1;
  while (pow(k, x) <= l) x++;
  if (pow(k, x - 1) == l)
    cout << "YES" << endl << x - 2;
  else
    cout << "NO";
}
