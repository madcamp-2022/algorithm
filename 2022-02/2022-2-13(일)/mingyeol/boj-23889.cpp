#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int sand[100000], rock[100000];
vector<pair<int,int>> dif;
vector<int> ans;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

int main(void) {
    int n, m, k, idx=0, sum=0;
    scanf("%d %d %d", &n, &m, &k);
    for(int i=0; i<n; i++) scanf("%d", sand+i);
    for(int i=0; i<k; i++) scanf("%d", rock+i);

    for(int i=rock[0]-1; i<n; i++) {
        if(i == rock[idx+1]-1) {
            dif.push_back(make_pair(sum, rock[idx++]));
            sum = 0;
        }
        sum += sand[i];
    }
    dif.push_back(make_pair(sum, rock[idx]));

    sort(dif.begin(), dif.end(), cmp);
    for(int i=0; i<m; i++) ans.push_back(dif[i].second);

    sort(ans.begin(), ans.end());
    for(int i : ans) printf("%d\n", i);

    return 0;
}