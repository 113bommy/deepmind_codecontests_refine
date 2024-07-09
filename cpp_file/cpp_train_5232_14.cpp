#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n];
    vector<pair<int, int> > pv;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      pv.push_back(make_pair(arr[i], i));
    }
    sort(pv.begin(), pv.end());
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      int cnt2 = 1;
      int prev = pv[i].second;
      for (int j = i + 1; j < n; j++) {
        if (pv[j].second > prev) {
          prev = pv[j].second;
          cnt2++;
          i = j;
        } else {
          break;
        }
      }
      cnt = max(cnt, cnt2);
    }
    cout << (n - cnt) << endl;
  }
  return 0;
}
