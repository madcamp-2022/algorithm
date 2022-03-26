#include <bits/stdc++.h>

using namespace std;

int dp[2][3][3];
map<char, int> m;
map<int, string> temp;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    stack<char> st;

    string s;
    cin >> s;

    for(int i = 0; i < s.size(); i++){
        st.push(s[i]);

        if(st.size() >= 4){
            char d = st.top(); st.pop();
            char c = st.top(); st.pop();
            char b = st.top(); st.pop();
            char a = st.top(); st.pop();

            if(a == 'P' && b == 'P' && c == 'A' && d == 'P'){
                st.push('P');
            } else {
                st.push(a);
                st.push(b);
                st.push(c);
                st.push(d);
            }
        }
    } 

    if(st.size() == 1 && st.top() == 'P'){
        cout << "PPAP";
    } else {
        cout << "NP";
    }
}