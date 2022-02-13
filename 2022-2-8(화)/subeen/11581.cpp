#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> v[110];
bool vis[110], fin[110];
bool f(int cur){
    if(vis[cur]) return fin[cur];
    vis[cur] = 1;
    bool ret = 1;
    for(int nxt:v[cur]) ret&=f(nxt);
    fin[cur] = 1;
    return ret; 
}
int main(){
    cin >> n;
    for(int i=1;i<n;i++){
        int j,t;
        cin >> t;
        while(t--){
            cin >> j;
            v[i].push_back(j);
        }
    }
    if(f(1)) cout << "NO ";
    cout << "CYCLE";
}