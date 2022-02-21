#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int N, M, visit[101];
vector<int> adjlist[101];
int bfs(int n){
	
	queue<pair<int, int>> q;
	fill(visit, visit+101, 0);
	
	q.push({n,0});
	visit[n] = 1;
	int ret = 0;
	while(!q.empty()){
		pair<int, int> temp = q.front(); q.pop();
		ret += temp.second;
		for(int i = 0; i < adjlist[temp.first].size(); i++){
			int num = adjlist[temp.first][i];
			if(!visit[num]){
				visit[num] = 1;
				q.push({num, temp.second+1});
			}
		}
		
	}
	
	return ret;
}


int main(){
	cin >> N >> M;
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	for(int i = 0; i < M; i++){
		int a, b;
		cin >> a >> b;
		adjlist[a].push_back(b);
		adjlist[b].push_back(a);
	}
	
	int mi = 987654321;
	int ans =987654321;
	for(int i = 1; i <= N; i++){
		int temp = bfs(i);
		if(temp < mi){
			mi = temp;
			ans = i;
		}
	}
	
	cout << ans;
}