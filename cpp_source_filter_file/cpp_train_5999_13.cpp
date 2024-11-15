#include <bits/stdc++.h>
using namespace std;
long long readi() {
  long long input = 0;
  char c = ' ';
  while (c < '-') {
    c = getchar();
  }
  bool negative = false;
  if (c == '-') {
    negative = true;
    c = getchar();
  }
  while (c >= '0') {
    input = 10 * input + (c - '0');
    c = getchar();
  }
  if (negative) {
    input = -input;
  }
  return input;
}
void printi(long long output) {
  if (output == 0) {
    putchar('0');
    return;
  }
  if (output < 0) {
    putchar('-');
    output = -output;
  }
  int aout[20];
  int ilen = 0;
  while (output) {
    aout[ilen] = ((output % 10));
    output /= 10;
    ilen++;
  }
  for (int i = ilen - 1; i >= 0; i--) {
    putchar(aout[i] + '0');
  }
  return;
}
string reads() {
  string input = "";
  char c = ' ';
  while (c <= ' ') {
    c = getchar();
  }
  while (c > ' ') {
    input += c;
    c = getchar();
  }
  return input;
}
void prints(string output) {
  for (int i = 0; i < output.length(); i++) {
    putchar(output[i]);
  }
  return;
}
long long getrand() {
  long long rand1 = (rand() % 536870912);
  long long rand2 = (rand() % 536870912);
  return (rand1 * 536870912ll + rand2);
}
int N;
int arr[1000010];
int ans;
int32_t main() {
  srand(time(NULL));
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  ios_base::sync_with_stdio(false);
  if (fopen("cf859a.in", "r")) {
    freopen("cf859a.in", "r", stdin);
  }
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + N);
  arr[0] = 0;
  for (int i = 1; i <= N; i++) {
    ans += (arr[i] - arr[i - 1] - 1);
  }
  ans -= (25 - N);
  ans = max(ans, 0);
  cout << ans << '\n';
  return 0;
}
