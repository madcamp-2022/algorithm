#include <bits/stdc++.h>

using namespace std;

long long dp[65][10];

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    for(int i = 0; i < 10; i++){
        dp[1][i] = 1;
    }

    for(int i = 2; i < 65; i++){

        for(int j = 0; j < 10; j++){
            long long sum = 0;
            for(int k = j; k < 10; k++){
                sum += dp[i-1][k];
            }
            dp[i][j] = sum;
        }
    }

    int T;
    cin >> T;

    while(T--){
        int temp;
        cin >> temp;
        long long answer = 0;
        for(int i = 0; i < 10; i++){
            answer += dp[temp][i];
        }
        cout << answer << '\n';
    }

}