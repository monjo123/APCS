#include<bits/stdc++.h>
using namespace std;

int main(){

	int32_t n; cin>>n;
	int32_t score[n];
	for(auto &i:score) cin>>i;
	
	sort(score, score+n);
	
	int32_t maxf = -1, minp = 101;
	for(auto &i:score){
		cout<<i<<" ";
		if(i < 60) maxf = max(maxf, i);
		else minp = min(minp, i);
	}
	cout<<"\n";
	cout<<(maxf == -1 ? "best case" : to_string(maxf))<<"\n";
	cout<<(minp == 101 ? "worst case" : to_string(minp))<<"\n";


	return 0;
}
