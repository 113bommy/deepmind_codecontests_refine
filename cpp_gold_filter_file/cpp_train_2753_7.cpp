#include <bits/stdc++.h>
using namespace std;
vector<string> lst1;
vector<string> lst2;
inline char calM(const string &s) {
  char m = 1;
  for (int i = 0; i < s.length(); i++) {
    m = max(m, (char)(s[i] + 1));
  }
  return m;
}
void printCase(const string &s) {
  int i, j;
  char m;
  for (i = 0, m = '0'; i < s.length(); i++) {
    m = max(m, s[i]);
  }
  char ch;
  bool firstSet = true;
  ;
  bool firstNumber;
  for (ch = '0'; ch <= m; ch++) {
    if (firstSet) {
      firstSet = false;
    } else {
      printf(",");
    }
    printf("{");
    firstNumber = true;
    for (i = 0; i < s.length(); i++) {
      if (s[i] == ch) {
        if (!firstNumber) {
          printf(",");
        } else {
          firstNumber = false;
        }
        printf("%d", i + 1);
      }
    }
    printf("}");
  }
  printf("\n");
}
int main() {
  int n, i, j, m;
  char ch;
  scanf("%d", &n);
  vector<string> *pPreList;
  vector<string> *pCurList;
  pPreList = &lst1;
  pCurList = &lst2;
  pCurList->push_back("0");
  for (j = 2; j <= n; j++) {
    swap(pPreList, pCurList);
    pCurList->clear();
    string tmp;
    for (i = 0; i < pPreList->size(); i++) {
      tmp = (*pPreList)[i];
      m = calM(tmp);
      if ((i & 1) == 0) {
        pCurList->push_back(tmp + '0');
        for (ch = m; ch >= '1'; ch--) {
          pCurList->push_back(tmp + ch);
        }
      } else {
        for (ch = '1'; ch <= m; ch++) {
          pCurList->push_back(tmp + ch);
        }
        pCurList->push_back(tmp + '0');
      }
    }
  }
  printf("%d\n", pCurList->size());
  for (i = 0; i < pCurList->size(); i++) {
    printCase((*pCurList)[i]);
  }
  return 0;
}
