#include <bits/stdc++.h>
using namespace std;

int main() 
{
	string s; cin>>s;
	int one=0,zero=0;
	for(char c: s)
	{
		if(c=='1')
		{
			one++
		}
		else
		{
			zero++;
		}
	}
	cout<<min(one,zero)*2;
	


}