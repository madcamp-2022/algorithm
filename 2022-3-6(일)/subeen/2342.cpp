#include<bits/stdc++.h>
using namespace std;
int d1[5][5], d2[5][5];
int dist(int i, int j){
	if(j<i) swap(i,j);
	if(i==0) return 2;
	else if(j-i==2) return 4;
	else if(j==i) return 1;
	else return 3;
}
int main(){
	ios_base::sync_with_stdio(0);
	for(int i=0;i<5;i++) for(int j=0;j<5;j++) d1[i][j] = 1e9;
	d1[0][0] = 0;
	while(1){
		int t;
		cin >> t;
		if(!t) break;
		for(int i=0;i<5;i++) for(int j=0;j<5;j++) d2[i][j] = 1e9;
		for(int i=0;i<5;i++) for(int j=0;j<5;j++) if(t!=j) d2[t][j] = min(d2[t][j], d1[i][j] + dist(i,t));
		for(int i=0;i<5;i++) for(int j=0;j<5;j++) if(i!=t) d2[i][t] = min(d2[i][t], d1[i][j] + dist(j,t));
		swap(d1,d2);
	}
	int ans = 1e9;
	for(int i=0;i<5;i++) for(int j=0;j<5;j++) ans = min(ans, d1[i][j]);
	cout << ans;
}
