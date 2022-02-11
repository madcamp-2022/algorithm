#include <bits/stdc++.h>

using namespace std;

vector<int> v[101];

bool flag = true;

int visited[101];

void f(int start){
    visited[start] = 2;
    for(int i = 0; i < v[start].size(); i++){
        int next = v[start][i];

        if(!visited[next]){
            f(next);
        }

        if(visited[next] == 2){
            flag = false;
        }
    }
    visited[start] = 1;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int N;
    cin >> N;

    for(int i = 1; i < N; i++){
        int m;
        cin >> m;
        while(m--){
            int a;
            cin >> a;
            v[i].push_back(a);
        }
    }

    f(1);

    cout << (flag ? "NO " : "") << "CYCLE";
}