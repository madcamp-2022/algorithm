#include <bits/stdc++.h>

using namespace std;

vector<int> v;
int dp[1001][31][2];

int T, W;

int f(int a, int w, int c){
    
    if(a == T){
        return 0;
    }

    int& ret = dp[a][w][c];

    if(ret != -1){
        return ret;
    }

    ret = ((c+1) == v[a]) + max(f(a+1, w, c), w > 0 ? f(a+1, w-1, (c + 1) % 2) : 0);
    return ret;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> T >> W;

    for(int i = 0; i < T; i++){
        int a;
        cin >> a;
        v.push_back(a);
    }

    for(int i = 0; i < 1001; i++){
        for(int j = 0; j < 31; j++){
            dp[i][j][0] = dp[i][j][1] = -1;
        }
    }

    cout << max(f(0, W, 0), W > 0 ? f(0, W-1, 1) : 0);
}