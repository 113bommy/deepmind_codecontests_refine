#include <bits/stdc++.h>
using namespace std;
const string ODD = "Stannis";
const string EVEN = "Daenerys";
void setup() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(15);
}
int N, K;
int odd = 0, even = 0;
int main() {
  setup();
  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    int v;
    cin >> v;
    if (v & 1)
      odd++;
    else
      even++;
  }
  if (N == K) {
    cout << (odd & 1 ? ODD : EVEN) << endl;
    return 0;
  }
  int lp = (N - K) & 1;
  int opm = (N - K) / 2;
  if (lp) {
    bool can_win = false;
    if (opm >= even && !(K & 1)) can_win = true;
    if (opm >= odd) can_win = true;
    cout << (can_win ? EVEN : ODD) << endl;
  } else {
    bool can_win = false;
    if (opm >= even && (K & 1)) can_win = true;
    cout << (can_win ? ODD : EVEN) << endl;
  }
}
