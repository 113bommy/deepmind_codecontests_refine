#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, kl, cd, p, nl, np, aux;
  cin >> n >> kl >> aux;
  kl *= aux;
  cin >> cd >> aux >> p >> nl >> np;
  cd *= aux;
  aux = min((kl / nl), min(cd, p / np));
  aux /= n;
  cout << aux << endl;
  return 0;
}
