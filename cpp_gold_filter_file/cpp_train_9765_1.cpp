#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

int main(){
 int N;
 cin >> N;
 map<string,int> mp;
 string s;
 uint64_t count = 0;

 for(int i=0;i<N;i++){
   cin >> s;
   sort(s.begin(),s.end());
   count += mp[s];
   mp[s]++;
  }

cout << count;
}