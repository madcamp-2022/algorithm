#include <bits/stdc++.h>

using namespace std;

vector<int> dp(1001, -1);
int arr[1001];
int n;

int f(int s){
    if(s >= n){
        return 0;
    }
    int& ret = dp[s];
    if(ret != -1){
        return ret;
    }

    ret = 0;
    int mi = arr[s];
    int ma = arr[s];

    for(int i = s; i < n; i++){
        mi = min(arr[i], mi);
        ma = max(arr[i], ma);
        ret = max(ret, (ma - mi) + f(i+1));
    }

    return ret;
}


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << f(0);

}