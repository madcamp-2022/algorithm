#include <bits/stdc++.h>

using namespace std;

int arr[40001];

vector<int> primes;

void preCalc(){
    arr[1] = 0;
    arr[2] = 1;

    for(int i = 3; i < 40001; i++){
        arr[i] = 1;
    }

    for(int i = 2; i < 40001; i++){
        if(arr[i]){
            for(int j = i * i; j < 40001; j += i){
                arr[j] = 0;
            }
        }
    }

    for(int i = 2; i < 40001; i++){
        if(arr[i]){
            primes.push_back(i);
        }
    }
}

int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(0);

    preCalc();

    int N;
    cin >> N;

    vector<int> dp(40001);
    dp[0] = 1;

    for(int i = 1; i < primes.size() + 1; i++){
        for(int j = 0; j <= N; j++){
            int current = primes[i - 1];
            if(j - current >= 0){
                dp[j] += dp[j-current];
                dp[j] %= 123'456'789;
            }
        }
    }
    cout << dp[N]<< ' ';
}