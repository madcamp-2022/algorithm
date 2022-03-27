#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int N;

bool cmp(int i, int j){
	return abs(i) < abs(j);
}

int main(){
	cin >> N;
	
	vector<int> Arr(N);
	
	for(int i = 0; i < N; i++){
		cin >> Arr[i];
	}
	
	sort(Arr.begin(),Arr.end(),cmp);
	
	int ans1, ans2;
	int ret = 2000000001;
	for(int i = 0; i < N-1; i++){
		if(abs(ret) > abs(Arr[i]+Arr[i+1])){ret = abs(Arr[i]+Arr[i+1]); ans1 = Arr[i]; ans2 = Arr[i+1];}
	}
	
	if(ans1 > ans2){
		int temp = ans1;
		ans1 = ans2;
		ans2 = temp;
	}
	
	cout << ans1 <<" "<< ans2;
}
	