#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string s;
    ll k;
    cin>>s>>k;
    int i=0;
    while (i<s.size()-1&&i<k-1&&s[i]=='1')
        i++;
    cout<<s[i]<<endl;
    return 0;
}