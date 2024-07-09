#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int res = 0, w = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9')
    ch == '-' ? w = -1, ch = getchar() : ch = getchar();
  while (ch >= '0' && ch <= '9') {
    res = res * 10 + ch - '0';
    ch = getchar();
  }
  return w * res;
}
const int N = 10;
int id[N], score[N];
int T, n, flag[N];
char s[20005];
set<int> minpos;
void check(int op) {
  for (register int i = 1; i <= 4; ++i) score[i] = 0;
  for (register int i = 1; i <= n; ++i) {
    if (s[i] == 'G')
      ++score[1];
    else if (s[i] == 'H')
      ++score[2];
    else if (s[i] == 'R')
      ++score[3];
    else if (s[i] == 'S')
      ++score[4];
    else {
      int minn = 0x3f3f3f3f;
      minpos.clear();
      for (register int j = 1; j <= 4; ++j) {
        if (score[j] < minn) {
          minpos.clear();
          minpos.insert(j);
          minn = score[j];
        } else if (score[j] == minn)
          minpos.insert(j);
      }
      if (!op) {
        for (register int j = 1; j <= 4; ++j)
          if (minpos.count(id[j])) {
            ++score[id[j]];
            break;
          }
      } else {
        while (1) {
          int t = rand() % 4 + 1;
          if (minpos.count(t)) {
            ++score[t];
            break;
          }
        }
      }
    }
  }
  int minn = 0x3f3f3f3f, tot, now[N];
  for (register int i = 1; i <= 4; ++i) {
    if (score[i] < minn) {
      tot = 0;
      now[++tot] = i;
      minn = score[i];
    } else if (score[i] == minn)
      now[++tot] = i;
  }
  for (register int i = 1; i <= tot; ++i) flag[now[i]] = 1;
}
int main() {
  srand(time(0));
  n = read();
  scanf("%s", s + 1);
  memset(flag, 0, sizeof(flag));
  for (register int i = 1; i <= 4; ++i) id[i] = i;
  check(0);
  while (next_permutation(id + 1, id + 4 + 1)) check(0);
  for (register int i = 1; i <= 300; ++i) check(1);
  if (flag[1]) printf("Gryffindor\n");
  if (flag[2]) printf("Hufflepuff\n");
  if (flag[3]) printf("Ravenclaw\n");
  if (flag[4]) printf("Slytherin\n");
  return 0;
}
