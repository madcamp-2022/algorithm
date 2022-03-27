#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int n, m, k, a[100010], b[100010], d[100010];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k;
	for(int i=1;i<=n;i++) {
		cin >> a[i];
		d[i] = d[i-1] + a[i];
	}
	vector<pii> v;
	for(int i=0;i<k;i++) cin >> b[i];
	b[k] = n+1;
	for(int i=0;i<k;i++) {
		v.push_back({d[b[i]-1]-d[b[i+1]-1], b[i]});
	}
	sort(v.begin(), v.end());
	vector<int> ans;
	for(int i=0;i<m;i++) ans.push_back(v[i].second);
	sort(ans.begin(), ans.end());
	for(int x:ans) cout << x << "\n";
}
