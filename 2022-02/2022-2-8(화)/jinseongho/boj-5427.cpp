#include <iostream>
#include <queue>

using namespace std;
using pii = pair<int, int>;
using piii = pair<pii, int>;
using piiiii = pair<pair<pii,pii>,int>;
int W, H;
string map[1001];
queue<piii> fires;
queue<piiiii> person;
int dy[4] = {0,-1,0,1};
int dx[4] = {1,0,-1,0};
int bfs(){
	int dep = 0;
	while(!fires.empty() || !person.empty()){
			
		if((fires.empty() || fires.front().second != dep) && (person.empty() || person.front().second != dep)){dep++; }
		
		while(!person.empty() && person.front().second == dep){
			piiiii temp = person.front(); person.pop();
			int y = temp.first.first.first;
			int x = temp.first.first.second;
			int pre_y = temp.first.second.first;
			int pre_x = temp.first.second.second;
			int depth = temp.second;
			if((pre_y != -1 && pre_x != -1 && map[pre_y][pre_x] == '*'))continue;
			if(y == -1 || y == H || x == W || x == -1)return depth;
			if(map[y][x] == '*' || map[y][x] == '#' || map[y][x] == '@')continue;
		
			map[y][x] = '@';
			
			for(int i = 0; i < 4; i++){
				int ty = dy[i]+y;
				int tx = dx[i]+x;

				person.push({{{ty,tx},{y,x}},depth+1});
			}
		}
		
		while(!fires.empty() && fires.front().second == dep){
			piii temp = fires.front(); fires.pop();
			int y = temp.first.first;
			int x = temp.first.second;
			int depth = temp.second;
			
			if(y == -1 || y == H || x == W || x == -1 || map[y][x] == '#' || map[y][x] == '*')continue;
			
			map[y][x] = '*';
			for(int i = 0; i < 4; i++){
				int ty = dy[i]+y;
				int tx = dx[i]+x;
				fires.push({{ty,tx},depth+1});
			}
			
		}
		
	}
	
	return -1;
}

int main() {
	
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	int T;
	cin >> T;
	
	while(T--){
		queue<piii> t1;
		queue<piiiii> t2;
		fires = t1;
		person = t2;
		
		cin >> W >> H;
		
		for(int i = 0; i < H; i++){
			cin >> map[i];
			for(int j = 0; j < W; j++){
				if(map[i][j] == '@'){person.push({{{i,j},{-1,-1}},0}); map[i][j] = '.';}
				if(map[i][j] == '*'){fires.push({{i,j},0}); map[i][j] = '.';}
			}
		}
		
		int flag = bfs();
		
		if(flag == -1){
			cout << "IMPOSSIBLE" << '\n';
		}
		else{
			cout << flag << '\n';
		}
		
	}
	
}