#include<bits/stdc++.h>
using namespace std;
char c[10010];
int k;
void solve(){
	cin >> c >> k;
	int n = strlen(c);
	deque<int> dq[26];
	int mx = -1, mn = 1e9;
	for(int i=0;i<n;i++){
		int idx = c[i]-'a';
		dq[idx].push_back(i);
		while(dq[idx].size() > k) dq[idx].pop_front(); 
		if(dq[idx].size() == k){
			mx = max(mx, dq[idx].back()-dq[idx].front()+1);
			mn = min(mn, dq[idx].back()-dq[idx].front()+1);
		}
	}
	if(mx == -1) cout << "-1\n";
	else cout << mn << " " << mx << "\n";
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
}
