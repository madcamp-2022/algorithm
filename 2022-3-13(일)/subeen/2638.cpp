#include<bits/stdc++.h>
using namespace std;
int n, m, a[101][101], b[101][101], d[101][101];
int dx[4] = {1,0,-1,0}; 
int dy[4] = {0,1,0,-1};

void dfs(int y, int x){
	if(d[y][x]) return;
	d[y][x] = 1;
	for(int i=0;i<4;i++){
		int yy = y + dy[i];
		int xx = x + dx[i];
		if(yy<0||xx<0||yy>=n||xx>=m||a[yy][xx]||d[yy][xx]) continue;
		dfs(yy,xx);
	}
}

bool f(){
	bool ret = 0;
	memset(d,0,sizeof(d));
	dfs(0,0);
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) {
		if(a[i][j] == 1) {
			int sum = 0;
			for(int k=0;k<4;k++) sum += d[i+dy[k]][j+dx[k]];
			ret |= (b[i][j] = sum < 2);
		} else b[i][j] = 0;
	}
	swap(a,b);
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	bool no = 1;
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) {
		cin >> a[i][j];
		if(a[i][j]) no = 0;
	}
	if(no) {
		cout << "0";
		return 0;
	}
	for(int i=1;i<=n*m;i++) if(!f()) {
		cout << i;
		return 0;
	}
}
