#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int Arr[5][3]={0,};
	int N;
	cin >> N;
	scanf("%d %d %d", &Arr[0][0], &Arr[0][1],&Arr[0][2]);
	for(int i = 0; i < 3; i++){
		Arr[3][i]=Arr[0][i];
		Arr[4][i]=987654321;
	}
	
	for(int i = 1; i < N; i++){
		
		cin >> Arr[1][0] >> Arr[1][1] >> Arr[1][2];
		
		for(int j = 0; j < 3; j++){
			
			for(int k = -1; k <= 1; k++){
				if(j+k<0)continue;
				if(Arr[2][j+k] < Arr[0][j]+Arr[1][j+k])Arr[2][j+k] = Arr[0][j]+Arr[1][j+k];
				if(Arr[4][j+k] > Arr[3][j]+Arr[1][j+k])Arr[4][j+k] = Arr[3][j]+Arr[1][j+k];
			}
		
		}
		
		for(int j = 0; j < 3; j++){
			Arr[0][j]=Arr[2][j];
			Arr[3][j]=Arr[4][j];
			Arr[4][j]=987654321;
		}
		
	}
	int ans1= 0,ans2 = 987654321;
	for(int i = 0; i < 3; i++){
		ans1 = max(ans1, Arr[0][i]);
		ans2 = min(ans2,Arr[3][i]);
	}
	cout << ans1 << " " << ans2;
	
}