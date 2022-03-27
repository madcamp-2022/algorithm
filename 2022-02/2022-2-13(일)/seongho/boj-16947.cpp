#include <bits/stdc++.h>

using namespace std;

vector<int> adj[3001];
vector<int> temp(3001, 0);
int cur = 0;
stack<int> s;
int f(int before, int start){
    s.push(start);
    int mi = temp[start] = ++cur;
    for(int i = 0; i < adj[start].size(); i++){
        int next = adj[start][i];
        if(next == before)continue;
        if(temp[next]){
            mi = min(temp[next], mi);
        } else {
            mi = min(f(start, next), mi);
        }
    }

    if(temp[start] == mi){
        while(s.top() != start){
            temp[s.top()] = temp[start];
            s.pop();
        }
        s.pop();
    }

    return mi;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    f(0, 1);

    map<int,int> m;
    int circleNum = 0;

    for(int i = 1; i <= n; i++){
        m[temp[i]]++;
        if(m[temp[i]] > 1){
            circleNum = temp[i];
            break;
        }
    }

    for(int i = 1; i <= n; i++){
        if(circleNum == temp[i]){
            cout << 0 << ' ';
            continue;
        }

        queue<pair<int,int>> q;
        q.push({i, 0});
        vector<int> visited(3001,0);
        visited[i] = true;

        while(!q.empty()){
            int here = q.front().first; 
            int cost = q.front().second;
            q.pop();
            if(temp[here] == circleNum){
                cout << cost << ' ';
                break;
            }

            for(int i = 0; i < adj[here].size(); i++){
                int next = adj[here][i];
                if(!visited[next]){
                    visited[next] = true;
                    q.push({next, cost + 1});
                }
            }
        }
    }

}