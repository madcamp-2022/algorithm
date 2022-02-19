#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    long long n, k;
    cin >> n >> k;
    long long plus = 2;
    if(n == 5 || n == 1){
        plus = 1;
    }

    long long answer = (k / plus) * 8 + ((k % plus) == 1 ? 9 - n : n - 1);
    cout << answer;
}