#include<bits/stdc++.h>
using namespace std;
set<int> st;
int main()
{
  int n;
  cin >> n;
  string s;
  for(int i = 0; i < n; i++){
    cin >> s;
    s.insert(st);
  }
  cout << st.size();
}