#include<bits/stdc++.h>
using namespace std;

const int32_t MaxRC = 10 + 5;

int32_t B[2][MaxRC][MaxRC];
int32_t r, c, m;
int32_t t = 0;

int32_t main(){
	
	cin>>r>>c>>m;
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			cin>>B[t][i][j];
	int32_t op[m];
	for(int i=0;i<m;i++) cin>>op[i];
	/*
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++)
			cout<<B[t][i][j]<<" ";
		cout<<"\n";
	}
	cout<<"\n";
	*/
	for(int k=m-1;k>=0;k--){
		if(op[k]){
			for(int i=0;i<r;i++)
				for(int j=0;j<c;j++)
					B[(t == 0)][i][j] = B[t][r - 1 - i][j];
			t = (t == 0);
		}else{
			for(int i=0;i<c;i++)
				for(int j=0;j<r;j++)
					B[(t == 0)][i][j] = B[t][j][c - 1 - i];
			swap(r, c);
			t = (t == 0);
		}
	}

	cout<<r<<" "<<c<<"\n";
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++)
			cout<<B[t][i][j]<<(j != c - 1 ? " " : "");
		cout<<"\n";
	}

	return 0;
}
