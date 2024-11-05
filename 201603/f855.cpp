#include<bits/stdc++.h>
#define l first
#define r second
using namespace std;

const int MaxN = 10000 + 5;

pair<int, int> lines[MaxN];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;cin>>n;
	for(int i=0;i<n;i++) cin>>lines[i].l>>lines[i].r;

	sort(lines, lines+n);
	
	int ans = 0;
	for(int i=0;i<n;i++){
		int l = lines[i].l, r = lines[i].r;
		while(i + 1 < n && r >= lines[i+1].l) r = max(r, lines[++i].r);
		ans += r - l;
	}
	
	cout<<ans<<"\n";

	return 0;
}
