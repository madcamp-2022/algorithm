#include <bits/stdc++.h>

using namespace std;
const int sz = 123'457;
vector<int> v[sz];
int s[sz];
int w[sz];

int f(int idx){
    int ret = 0;

    for(int i = 0; i < v[idx].size(); i++){
        ret += f(v[idx][i]);
    }

    return ret - w[idx] + s[idx];
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int N;
    cin >> N;

    for(int i = 2; i <= N; i++){
        char c;
        int a, b;
        cin >> a >> b;
        v[b].push_back(i);

        if(c == 'S'){
            s[i] = a;
        } else {
            w[i] = a;
        }
    }

    cout << f(1);
}