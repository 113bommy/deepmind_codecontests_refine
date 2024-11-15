#include <bits/stdc++.h>
using namespace std;
pair<int, int> A[100000];
int B[100000];
int C[100000];
int main() {
  int N;
  cin >> N;
  int M = (N + 2) / 3;
  for (int i = 0; i < N; i++) {
    A[i].second = i;
    cin >> A[i].first;
  }
  sort(A, A + N);
  for (int i = 0; i < M; i++) {
    B[A[i].second] = 0;
    C[A[i].second] = A[i].first;
  }
  for (int i = M; i < 2 * M; i++) {
    B[A[i].second] = A[i].first;
    C[A[i].second] = 0;
  }
  for (int i = 2 * M; i < N; i++) {
    int dx = N - i - 1;
    B[A[i].second] = dx;
    C[A[i].second] = A[i].first - dx;
  }
  cout << "YES" << endl;
  for (int i = 0; i < N; i++) {
    if (i) cout << ' ';
    cout << B[i];
  }
  cout << endl;
  for (int i = 0; i < N; i++) {
    if (i) cout << ' ';
    cout << C[i];
  }
  cout << endl;
  return 0;
}
