#include <bits/stdc++.h>

using namespace std;

vector<long long> dp(100'001, -1);
vector<long long> v;
int n;

long long f(int idx){
    if(idx == n){
        return 0;
    }

    long long& ret = dp[idx];

    if(ret != -1){
        return ret;
    }

    ret = 0;
    ret = f(idx+1) + v[idx];
    if(idx + 1 < n){
        ret = max(ret, f(idx+2) + (v[idx] * v[idx+1]));
    }
    return ret;
}


int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    cout << f(0);
}