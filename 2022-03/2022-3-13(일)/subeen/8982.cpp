#include<bits/stdc++.h>
using namespace std;
int n, k, h[5010], w[5010], d[5010];
map<int,int> m;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	int t;
	cin >> t >> t;
	for(int i=0;i<n/2-1;i++){
		int x1, x2, y;
		cin >> x1 >> y >> x2 >> y;
		m[x1] = i;
		h[i] = y;
		w[i] = x2 - x1;
	}
	cin >> t >> t;
	n = n/2-1;
	cin >> k;
	for(int i=0;i<k;i++){
		int x1, x2, y;
		cin >> x1 >> y >> x2 >> y;
		int idx = m[x1];
		int now = h[idx];
		for(int i=idx;i<n;i++){
			now = min(now, h[i]);
			d[i] = max(d[i], now);
		}
		now = h[idx];
		for(int i=idx;i>=0;i--){
			now = min(now, h[i]);
			d[i] = max(d[i], now);
		}
	}
	int ans = 0;
	for(int i=0;i<n;i++) ans += (h[i]-d[i])*w[i];
	cout << ans;
}
