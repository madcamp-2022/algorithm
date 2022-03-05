#include<bits/stdc++.h>
using namespace std;

int m, n;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};

int a[101][101];

struct Robot{
	
	int id, y, x, dir;
	
	Robot(int _id, int _y, int _x, char _dir){
		id = _id; y = _y; x = _x;
		if(_dir == 'E') dir = 0;
		else if(_dir == 'S') dir = 1;
		else if(_dir == 'W') dir = 2;
		else if(_dir == 'N') dir = 3;
		a[y][x] = id;
	};
	
	bool go(char op){
		if(op == 'L') dir = (dir+3)%4;
		else if(op == 'R') dir = (dir+1)%4;
		else if(op == 'F') {
			int yy = y + dy[dir];
			int xx = x + dx[dir];
			if(yy<1||xx<1||yy>n||xx>m) {
				cout << "Robot " << id << " crashes into the wall";
				return 0;
			}
			if(a[yy][xx]){
				cout << "Robot " << id << " crashes into robot " << a[yy][xx];
				return 0;
			}
			a[y][x] = 0;
			a[yy][xx] = id;
			y = yy;
			x = xx;
		}
		return 1;
	}
} *robots[110];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> m >> n;
	int t, q;
	cin >> t >> q;
	for(int i=1;i<=t;i++){
		int x, y;
		char dir;
		cin >> x >> y >> dir;
		robots[i] = new Robot(i,y,x,dir);
	}
	while(q--){
		int id, x;
		char op;
		cin >> id >> op >> x;
		while(x--) if(!robots[id]->go(op)) return 0;
	}
	cout << "OK";
}
