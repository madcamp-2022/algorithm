#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int n, m;
bool vis[51][51];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
string t[50];

int bfs(int y, int x){
	if(t[y][x] == 'W') return 0;
	queue< pair< pii, int > > q;
	q.push({{y,x},0});
	memset(vis,0,sizeof(vis));
	int ret = 0;
	while(!q.empty()){
		int y = q.front().first.first;
		int x = q.front().first.second;
		int dist = q.front().second;
		ret = max(ret, dist);
		q.pop();
		if(vis[y][x]) continue;
 		vis[y][x] = 1;
		for(int i=0;i<4;i++){
			int yy = y + dy[i];
			int xx = x + dx[i];
			if(yy<0||xx<0||yy>=n||xx>=m||t[yy][xx]=='W'||vis[yy][xx]) continue;
			q.push({{yy,xx}, dist+1});
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for(int i=0;i<n;i++) cin >> t[i];
	int ans = 0;
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) ans = max(ans, bfs(i,j));
	cout << ans;
}
