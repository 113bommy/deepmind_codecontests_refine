#include <bits/stdc++.h>
using namespace std;
int x, y;
vector<string> Res;
bool flag;
bool _min(vector<string> A, vector<string> B) {
  for (int i = 0; i < A.size(); i++) {
    if (A[i] == B[i]) continue;
    if (A[i] < B[i]) return true;
    return false;
  }
  return false;
}
bool validate(vector<string> V) {
  if (V[0].size() >= V[3].size()) return false;
  if (V[5].size() >= V[3].size()) return false;
  if (V[1].size() >= V[2].size()) return false;
  if (V[4].size() >= V[2].size()) return false;
  if (V[3].size() - V[0].size() + 1 != V[5].size()) return false;
  if (V[2].size() - V[1].size() + 1 != V[4].size()) return false;
  if (V[0][V[0].size() - 1] != V[2][0]) return false;
  if (V[0][0] != V[1][0]) return false;
  if (V[1][V[1].size() - 1] != V[3][0]) return false;
  if (V[2][V[1].size() - 1] != V[3][V[0].size() - 1]) return false;
  if (V[3][V[3].size() - 1] != V[4][0]) return false;
  if (V[4][V[4].size() - 1] != V[5][V[5].size() - 1]) return false;
  if (V[2][V[2].size() - 1] != V[5][0]) return false;
  char MM[V[2].size()][V[3].size()];
  for (int i = 0; i < V[2].size(); i++)
    for (int j = 0; j < V[3].size(); j++) MM[i][j] = '.';
  for (int i = 0; i < V[0].size(); i++) MM[0][i] = V[0][i];
  for (int i = 0; i < V[1].size(); i++) MM[i][0] = V[1][i];
  for (int i = 0; i < V[2].size(); i++) MM[i][V[0].size() - 1] = V[2][i];
  for (int i = 0; i < V[3].size(); i++) MM[V[1].size() - 1][i] = V[3][i];
  for (int i = 0; i < V[5].size(); i++)
    MM[V[2].size() - 1][V[0].size() + i - 1] = V[5][i];
  for (int i = 0; i < V[4].size(); i++)
    MM[V[1].size() + i - 1][V[3].size() - 1] = V[4][i];
  vector<string> M;
  for (int i = 0; i < V[2].size(); i++) {
    string cad = "";
    for (int j = 0; j < V[3].size(); j++) cad += MM[i][j];
    M.push_back(cad);
  }
  if (!flag) {
    x = V[2].size();
    y = V[3].size();
    Res = M;
    flag = true;
  } else if (_min(M, Res)) {
    Res = M;
    x = V[2].size();
    y = V[3].size();
  }
  return true;
}
void print(vector<string> V) {
  for (int i = 0; i < V.size(); i++) cout << V[i] << "\n";
}
int main() {
  vector<string> V(6);
  for (int i = 0; i < 6; i++) cin >> V[i];
  sort(V.begin(), V.end());
  x = 200;
  y = 200;
  int r = 0;
  flag = false;
  do {
    validate(V);
  } while (next_permutation(V.begin(), V.end()));
  if (x == 200)
    printf("Impossible\n");
  else
    print(Res);
  return 0;
}
