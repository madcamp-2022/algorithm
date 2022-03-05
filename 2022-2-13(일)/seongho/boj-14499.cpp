#include <bits/stdc++.h>

using namespace std;

int N, M, sy, sx, Q, m[20][20];
int dice[7];
int dice_value[7];
int dy[5] = {-1,0,0,-1,1};
int dx[5] = {-1,1,-1,0,0};

void change(int f){
	if(f == 1){
		int temp = dice[1];
		dice[1] = dice[3];
		dice[3] = dice[6];
		dice[6] = dice[4];
		dice[4] = temp;
	}
	else if(f == 2){
		int temp = dice[1];
		dice[1] = dice[4];
		dice[4] = dice[6];
		dice[6] = dice[3];
		dice[3] = temp;
	}
	else if(f == 3){
		int temp = dice[5];
		dice[5] = dice[1];
		dice[1] = dice[2];
		dice[2] = dice[6];
		dice[6] = temp;
	}
	else if(f == 4){
		int temp = dice[5];
		dice[5] = dice[6];
		dice[6] = dice[2];
		dice[2] = dice[1];
		dice[1] = temp;
	}
	else{
		return;
	}
}

void print(){
	
	cout << "  " << dice[2] << '\n';
	cout << dice[4] << " " << dice[1] << " " << dice[3] << '\n';
	cout << "  " << dice[5] << '\n'<< "  " << dice[6] << '\n';
	cout << '\n';
}

void pirnt1(){
	cout << "  " << dice_value[dice[2]] << '\n';
	cout << dice_value[dice[4]] << " " << dice_value[dice[1]] << " " << dice_value[dice[3]] << '\n';
	cout << "  " << dice_value[dice[5]] << '\n'<< "  " << dice_value[dice[6]] << '\n';
	cout << '\n';
}

bool check(int y, int x){
	return y >= 0 && y < N && x >= 0 && x < M;
}

int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	
	for(int i = 1; i <= 6; i++)dice[i] = i;

	cin >> N >> M >> sy >> sx >> Q;
	
	/*print();
	for(int i = 1; i <= 4; i++){
		change(i);
		print();
	}
	*/

	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> m[i][j];
		}
	}

	while(Q--){
		int a;
		cin >> a;

		if(check(sy + dy[a], sx + dx[a])){
			sy += dy[a];
			sx += dx[a];
			//pirnt1();
			change(a);
			
			if(m[sy][sx] == 0){
				m[sy][sx] = dice_value[dice[1]];
			}	
			else{
				dice_value[dice[1]] = m[sy][sx];
				m[sy][sx] = 0;
			}

			cout << dice_value[dice[6]] << '\n';
		}					
	}
	/*
	print();
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cout << m[i][j] << " ";
		}
		cout << '\n';
	}*/
}