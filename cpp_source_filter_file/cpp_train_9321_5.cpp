#include <bits/stdc++.h>
using namespace std;
string OS[5], outp[5];
int P[255];
int N;
char S[11000];
int j, k, Min, sz, len;
int G[5];
int O[5];
int Ans[5];
int main() {
  srand(time(0));
  scanf("%d\n", &N);
  gets(S + 1);
  len = strlen(S + 1);
  P['G'] = 1;
  OS[1] = "Gryffindor";
  P['H'] = 2;
  OS[2] = "Hufflepuff";
  P['R'] = 3;
  OS[3] = "Ravenclaw";
  P['S'] = 4;
  OS[4] = "Slytherin";
  for (int i = 1; i <= 10; i++) {
    G[1] = G[2] = G[3] = G[4] = 0;
    for (j = 1; j <= len; j++)
      if (S[j] != '?')
        G[P[int(S[j])]]++;
      else {
        Min = 100000;
        sz = 0;
        for (k = 1; k <= 4; k++)
          if (G[k] < Min)
            Min = G[k], O[sz = 1] = k;
          else if (G[k] == Min)
            O[++sz] = k;
        G[O[(rand() % sz) + 1]]++;
      }
    Min = 100000;
    sz = 0;
    for (k = 1; k <= 4; k++)
      if (G[k] < Min)
        Min = G[k], O[sz = 1] = k;
      else if (G[k] == Min)
        O[++sz] = k;
    for (int i = 1; i <= sz; i++) Ans[O[i]] = 1;
  }
  sz = 0;
  for (int i = 1; i <= 4; i++)
    if (Ans[i]) outp[++sz] = OS[i];
  for (int i = 1; i <= sz; i++) cout << outp[i] << endl;
}
