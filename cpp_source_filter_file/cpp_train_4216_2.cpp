#include <bits/stdc++.h>
using namespace std;
long long prms[78] = {
    1500000001, 1500000041, 1500000043, 1500000059, 1500000077, 1500000079,
    1500000101, 1500000107, 1500000113, 1500000167, 1500000233, 1500000283,
    1500000301, 1500000373, 1500000377, 1500000409, 1500000419, 1500000427,
    1500000449, 1500000473, 1500000511, 1500000527, 1500000529, 1500000563,
    1500000577, 1500000587, 1500000613, 1500000617, 1500000701, 1500000707,
    1500000713, 1500000721, 1500000739, 1500000743, 1500000767, 1500000773,
    1500000779, 1500000787, 1500000823, 1500000829, 1500000839, 1500000851,
    1500000857, 1500000871, 1500000877, 1500000893, 1500000917, 1500000973,
    1500001003, 1500001033, 1500001043, 1500001049, 1500001117, 1500001213,
    1500001231, 1500001241, 1500001271, 1500001291, 1500001319, 1500001333,
    1500001337, 1500001343, 1500001367, 1500001369, 1500001387, 1500001397,
    1500001411, 1500001421, 1500001439, 1500001453, 1500001457, 1500001507,
    1500001543, 1500001549, 1500001553, 1500001577, 1500001661, 1500001673};
long long hsh1[1000111];
long long hsh2[1000111];
long long mlt;
char s[1000111];
bool good[1000111];
int n, m;
long long MOD = 1000000007LL;
int main() {
  scanf("%d%d", &n, &m);
  scanf("%s", s);
  int size = 0;
  for (; s[size] != '\0'; size++)
    ;
  size--;
  memset(good, 1, sizeof(good));
  for (int j = 0; j < 78; j++) {
    for (int i = 0; i <= size; i++) {
      if (i > 0) {
        long long tmp = s[i] - 'a';
        hsh1[i] = (hsh1[i - 1] * 26L + tmp) % prms[j];
      } else {
        hsh1[i] = s[i] - 'a';
      }
    }
    for (int i = size; i >= 0; i--) {
      if (i < size) {
        mlt *= 26L;
        mlt %= prms[j];
        long long tmp = s[i] - 'a';
        tmp *= mlt;
        tmp %= prms[j];
        hsh2[i] = (tmp + hsh2[i + 1]) % prms[j];
      } else {
        mlt = 1;
        hsh2[i] = s[i] - 'a';
      }
      if (hsh2[i] != hsh1[size - i]) {
        good[i] = 0;
      }
    }
  }
  int lst = -1;
  int sm = 0;
  int nw;
  for (int i = 1; i <= m; i++) {
    scanf("%d", &nw);
    if (nw > lst + size && lst != -1) {
      sm += nw - (lst + size);
    } else if (lst == -1) {
      sm += nw - 1;
    }
    if (nw <= lst + size && lst != -1) {
      int ps = nw - lst;
      if (!good[ps]) {
        sm = -1;
        break;
      }
    }
    lst = nw;
    if (i == m) {
      sm += n - (nw + size);
    }
  }
  if (m == 0) sm = n;
  long long res = 1;
  if (sm == -1) {
    printf("0\n");
  } else {
    for (int i = 1; i <= sm; i++) {
      res *= 26LL;
      res %= 1000000007LL;
    }
    printf("%I64d\n", res);
  }
}
