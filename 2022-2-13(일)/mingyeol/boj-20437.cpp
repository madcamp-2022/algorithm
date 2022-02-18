#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int cnt[26];
int arr[26][10001];

int main(void) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t, k, amin, amax;
    string w;
    cin >> t;

    for(int i=0; i<t; i++) {
        for(int j=0; j<26; j++) cnt[j] = 0;
        amax = 0;
        amin = INT_MAX;
        cin >> w >> k; // -97
        
        for(int j=0; j<w.length(); j++) {
            arr[w[j]-97][++cnt[w[j]-97]] = j;
            if(cnt[w[j]-97] >= k) {
                int len = j - arr[w[j]-97][cnt[w[j]-97] - k + 1] + 1;
                amin = min(amin, len);
                amax = max(amax, len);
            }
        }
        
        if(!amax) cout << -1 << endl;
        else cout << amin << " " << amax << endl;
    }

    return 0;
}