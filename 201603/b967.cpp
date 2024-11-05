#include<bits/stdc++.h>
using namespace std;

const int MaxN = 1e5 + 5;

vector<int> G[MaxN];
vector<vector<int>> dis(2, vector<int>(MaxN, -1));
int s, ans;

void dfs(int pt, int a){
	for(int &i:G[pt]){
		if(dis[a][i] == -1){
			dis[a][i] = dis[a][pt] + 1;
			dfs(i, a);
		}
	}
}

int main(){
	
	int n;cin>>n;
	for(int i=1;i<n;i++){
		int a, b;cin>>a>>b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	dis[0][0] = 0;
	dfs(0, 0);

	// for(int i=0;i<n;i++) cout<<dis[0][i]<<" ";
	// cout<<"\n";

	s = 0;
	for(int i=0;i<n;i++)
		if(dis[0][s] < dis[0][i])
			s = i;
	
	// cout<<"s : "<<s<<"\n";

	ans = 0;
	dis[1][s] = 0;
	dfs(s, 1);

	// for(int i=0;i<n;i++) cout<<dis[1][i]<<" ";
	// cout<<"\n";

	for(int i=0;i<n;i++) ans = max(ans, dis[1][i]);

	cout<<ans<<"\n";

	return 0;
}
