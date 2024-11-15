#include <bits/stdc++.h>
using namespace std;
int nBlue, nRed;
int xBlue[2001], yBlue[2001];
int xRed[2001], yRed[2001];
struct segment {
  int minX, maxX, minY, maxY;
  bool haveCommonPoint(segment that) {
    if (minX > that.maxX) return false;
    if (maxX < that.minX) return false;
    if (minY > that.maxY) return false;
    if (maxY < that.minY) return false;
    return true;
  }
  void unionIt(segment that) {
    minX = min(minX, that.minX);
    maxX = max(maxX, that.maxX);
    minY = min(minY, that.minY);
    maxY = max(maxY, that.maxY);
  }
} blues[2001], reds[2001];
int nBlueGood, nRedGood;
segment blueGood[2001], redGood[2001];
bool unions[2001][2001];
bool compareXY(segment a, segment b) {
  if (a.minX == b.minX) return a.minY < b.minY;
  return a.minX < b.minX;
}
bool compareYX(segment a, segment b) {
  if (a.minY == b.minY) return a.minX < b.minX;
  return a.minY < b.minY;
}
bool check(int d) {
  for (int i = 1; i <= nBlue; i++) {
    blues[i].minX = blues[i].maxX = xBlue[i];
    blues[i].minY = yBlue[i] - 2 * d;
    blues[i].maxY = yBlue[i] + 2 * d;
  }
  sort(blues + 1, blues + nBlue, compareXY);
  nBlueGood = 0;
  for (int i = 1; i <= nBlue; i++)
    if (nBlueGood == 0 ||
        blueGood[nBlueGood].haveCommonPoint(blues[i]) == false)
      blueGood[++nBlueGood] = blues[i];
    else
      blueGood[nBlueGood].unionIt(blues[i]);
  for (int i = 1; i <= nRed; i++) {
    reds[i].minY = reds[i].maxY = yRed[i];
    reds[i].minX = xRed[i] - 2 * d;
    reds[i].maxX = xRed[i] + 2 * d;
  }
  sort(reds + 1, reds + nRed, compareYX);
  nRedGood = 0;
  for (int i = 1; i <= nRed; i++)
    if (nRedGood == 0 || redGood[nRedGood].haveCommonPoint(reds[i]) == false)
      redGood[++nRedGood] = reds[i];
    else
      redGood[nRedGood].unionIt(reds[i]);
  memset(unions, 0, sizeof(unions));
  for (int i = 1; i <= nRedGood; i++) {
    vector<int> touchedBlues;
    for (int j = 1; j <= nBlueGood; j++)
      if (redGood[i].haveCommonPoint(blueGood[j])) touchedBlues.push_back(j);
    for (int j = 0; j < touchedBlues.size(); j++)
      for (int k = j + 1; k < touchedBlues.size(); k++) {
        int a = touchedBlues[j];
        int b = touchedBlues[k];
        if (unions[a][b] || unions[b][a]) return true;
        unions[a][b] = true;
        unions[b][a] = true;
      }
  }
  return false;
}
int MAIN() {
  cin >> nBlue >> nRed;
  for (int i = 1; i <= nBlue; i++) {
    int x, y;
    cin >> x >> y;
    xBlue[i] = x + y;
    yBlue[i] = x - y;
  }
  for (int i = 1; i <= nRed; i++) {
    int x, y;
    cin >> x >> y;
    xRed[i] = x + y;
    yRed[i] = x - y;
  }
  int L = 0, R = 10000000, M;
  if (check(R) == false)
    cout << "Poor Sereja!" << endl;
  else {
    while (R - L > 1) {
      M = (L + R) / 2;
      if (check(M) == true)
        R = M;
      else
        L = M;
    }
    cout << R << endl;
  }
  return 0;
}
int main() {
  ios ::sync_with_stdio(false);
  cout << fixed << setprecision(16);
  return MAIN();
}
