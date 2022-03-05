#include<bits/stdc++.h>
using namespace std;
int n, m, k, a[51][51], b[51][51], r[10], c[10], s[10];
typedef pair<int,int> pii;

void rotate(int r, int c, int s){
	vector<pii> v;
	for(int j=c-s;j<c+s;j++) v.push_back({r-s,j});
	for(int i=r-s;i<r+s;i++) v.push_back({i,c+s});
	for(int j=c+s;j>c-s;j--) v.push_back({r+s,j});
	for(int i=r+s;i>r-s;i--) v.push_back({i,c-s});
	int t = a[r-s+1][c-s];
	for(int i=v.size()-2;i>=0;i--){
		a[v[i+1].first][v[i+1].second] = a[v[i].first][v[i].second];
	}
	a[v[0].first][v[0].second] = t;
}

void rotate_all(int r, int c, int s){
	for(int i=1;i<=s;i++) rotate(r,c,i);
}

int norm(){
	int ret = 1e9;
	for(int i=1;i<=n;i++){
		int sum = 0;
		for(int j=1;j<=m;j++) sum += a[i][j];
		ret = min(ret, sum);
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) {
		cin >> a[i][j];
		b[i][j] = a[i][j];
	}
	for(int i=0;i<k;i++) cin >> r[i] >> c[i] >> s[i];
	vector<int> v;
	for(int i=0;i<k;i++) v.push_back(i);
	int ans = 1e9;
	do {
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) a[i][j] = b[i][j];
		for(int i=0;i<k;i++) rotate_all(r[v[i]], c[v[i]], s[v[i]]);
		ans = min(ans, norm());
	} while(next_permutation(v.begin(), v.end()));
	cout << ans;
}
