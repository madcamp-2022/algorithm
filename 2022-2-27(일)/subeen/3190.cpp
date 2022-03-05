#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int dir = 0;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};

int n, a[110][110];
char s[10010];
deque<pii> dq;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	int k;
	cin >> k;
	while(k--){
		int y, x;
		cin >> y >> x;
		a[y][x] = 2;
	}
	int l;
	cin >> l;
	while(l--){
		int t;
		char c;
		cin >> t >> c;
		s[t] = c;
	}
	a[1][1] = 1;
	dq.push_back({1,1});
	
	for(int i=0;i<=10000;i++){
		if(s[i] == 'L') dir = (dir+1)%4;
		if(s[i] == 'D') dir = (dir+3)%4;
		int y = dq.front().first;
		int x = dq.front().second;
		int yy = y + dy[dir];
		int xx = x + dx[dir];
		if(yy<1||xx<1||yy>n||xx>n||a[yy][xx]==1){
			cout << i+1;
			return 0;
		}
		if(a[yy][xx] != 2){
			a[dq.back().first][dq.back().second] = 0;
			dq.pop_back();
		}
		a[yy][xx] = 1;
		dq.push_front({yy,xx});
	}
}
