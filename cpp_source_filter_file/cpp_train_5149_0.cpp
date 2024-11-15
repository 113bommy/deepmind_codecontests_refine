#include <bits/stdc++.h>
using namespace std;
struct query {
  int type;
  int a;
  int b;
};
int main() {
  int n, m, ans;
  scanf("%d %d", &n, &m);
  int bosses[n + 1];
  int bosstime_emp[n + 1];
  int intime_doc[m + 1];
  int doc_emp[m + 1];
  for (int i = 0; i <= n; i++) {
    bosses[i] = 0;
    bosstime_emp[i] = -1;
  }
  for (int i = 0; i <= m; i++) {
    doc_emp[i] = 0;
  }
  int documents = 0;
  int cnt3 = 0;
  for (int i = 0; i < m; i++) {
    query q;
    scanf("%d", &q.type);
    if (q.type == 1) {
      scanf("%d %d", &q.a, &q.b);
      bosses[q.a] = q.b;
      bosstime_emp[q.a] = i;
    }
    if (q.type == 2) {
      scanf("%d", &q.a);
      documents++;
      intime_doc[documents] = i;
      doc_emp[documents] = q.a;
    }
    if (q.type == 3) {
      scanf("%d %d", &q.a, &q.b);
      int tmp = doc_emp[q.b];
      int flag = 0;
      if (tmp == q.a)
        printf("YES\n");
      else {
        while (bosses[tmp] && bosstime_emp[bosses[tmp]] <= intime_doc[q.b]) {
          if (bosses[tmp] == q.a) {
            flag = 1;
            break;
          }
          tmp = bosses[tmp];
        }
        if (flag)
          printf("YES\n");
        else
          printf("NO\n");
      }
    }
  }
  return 0;
}
