#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n;
vector<int> v[3010];
int prv[3010], cost[3010][3010], start, d[3010];
bool vis[3010], flag;

bool dfs(int cur){
	if(vis[cur]){
		start = cur;
		cost[cur][prv[cur]] = cost[prv[cur]][cur] = 0;
		for(int i=prv[cur]; i!=cur; i=prv[i]){
			cost[i][prv[i]] = cost[prv[i]][i] = 0;
		}
		return 1;
	}
	vis[cur] = 1;
	for(int nxt:v[cur]){
		if(nxt == prv[cur]) continue;
		prv[nxt] = cur;
		if(dfs(nxt)) return 1;
	}
	return 0;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++) d[i] = 1e9;
	for(int i=0;i<n;i++){
		int t1, t2;
		cin >> t1 >> t2;
		v[t1].push_back(t2);
		v[t2].push_back(t1);
		cost[t1][t2] = cost[t2][t1] = 1;
	}
	dfs(1);
	priority_queue< pii > pq;
	d[start] = 0;
	pq.push({0, start});
	while(!pq.empty()){
		int dis = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if(dis > d[cur]) continue;
		
		for(int nxt:v[cur]){
			if(dis + cost[cur][nxt] < d[nxt]){
				d[nxt] = dis + cost[cur][nxt];
				pq.push({-d[nxt], nxt});
			}
		}
	}
	
	for(int i=1;i<=n;i++) cout << d[i] << " ";
	
}
