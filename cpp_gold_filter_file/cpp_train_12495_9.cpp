#include<iostream>
using namespace std;

int main(){
	int n,m,l,A[100][100],B[100][100];
	long long int C[100][100]={};
	cin>>n>>m>>l;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>A[i][j];
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<l;j++){
			cin>>B[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int k=0;k<m;k++){
			for(int j=0;j<l;j++){
				C[i][j]+=A[i][k]*B[k][j];
			}
			
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<l;j++){
			cout<<C[i][j];
			if(j!=l-1)cout<<" ";
		}
		cout<<endl;
	}
}
