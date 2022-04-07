#include<bits/stdc++.h>
using namespace std;
int n, k, d[100010];

vector<int> v;
int main(){
	cin >> n >> k;
	memset(d,-1,sizeof(d));
	d[0] = 0;
	for(int i=0;i<n;i++){
		int t1, t2;
		cin >> t1 >> t2;
		for(int i=k;i-t1>=0;i--) if(d[i-t1] != -1) d[i] = max(d[i], d[i-t1] + t2);
	}
	int ans = 0;
	for(int i=0;i<=k;i++) ans = max(ans, d[i]);
	cout << ans;
}
