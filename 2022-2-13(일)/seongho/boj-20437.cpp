#include <bits/stdc++.h>

using namespace std;


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int T;
    cin >> T;

    while(T--){
        string s;
        int w;
        cin >> s >> w;

        vector<vector<int>> v(26);

        for(int i = 0; i < s.length(); i++){
            v[s[i] - 'a'].push_back(i);
        }

        int answer = 987654321;
        int answer2 = 0;
        for(int i = 0; i < 26; i++){
            int sSize = s.length();
            int sz = v[i].size();

            for(int j = 0; j + w <= sz; j++){
                answer = min(answer, v[i][j+w-1] - v[i][j] + 1);
                answer2 = max(answer2, v[i][j+w-1] - v[i][j] + 1);
            }
        }
        if(answer == 987654321){
            cout << -1 << '\n';
        } else {
            cout << answer << " " << answer2 << '\n';
        }
    }   

}