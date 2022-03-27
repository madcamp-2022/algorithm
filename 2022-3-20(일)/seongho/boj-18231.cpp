#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> adjlist[2001];
int check[2001];
int destoryed[2001];
vector<int> ans;
int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);

	cin >> N >> M;
	for(int i = 0; i < M; i++){
		int a, b;
		cin >> a >> b;
		adjlist[a].push_back(b);
		adjlist[b].push_back(a);
	}
	int T;
	cin >> T;
	while(T--){
		int b;
		cin >> b;
		destoryed[b] = 1;
	}

	for(int i = 1; i <= N; i++){
		bool flag = true;
		if(destoryed[i] == 0)continue;
		for(int j = 0; j < adjlist[i].size(); j++){
			int next = adjlist[i][j];
			if(destoryed[next] == 0){
				flag = false;
				break;
			}
		}
		if(flag){ans.push_back(i);
		check[i] = 1;
		for(int j = 0; j < adjlist[i].size(); j++){
			check[adjlist[i][j]] = 1;
		}
		}
	}
	

	
	int c = true;
	for(int i = 1; i <= N; i++){
		c &= (check[i] == destoryed[i]);
	}
	
	if(c){
		cout << ans.size() << '\n';
		for(int i = 0; i < ans.size(); i++){
			cout << ans[i] << " ";
		}
	}
	else{
		cout << -1;
	}
}
	