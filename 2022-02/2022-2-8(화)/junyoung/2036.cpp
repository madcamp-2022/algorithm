#include <bits/stdc++.h>
using namespace std;

long long int N, t;
long long int ANS = 0;
long long int zero = 0;
vector<long long int> positive;
vector<long long int> negative;

int main(void) {
    cin >> N;
    for (long long int i = 0; i < N; i++) {
        cin >> t;
        if (t > 0) positive.push_back(t);
        else if (t < 0) negative.push_back(t);
        else zero++;
    }
    
    sort(positive.begin(), positive.end());
    sort(negative.begin(), negative.end(), greater<long long int>());
    
    if (positive.size()) {
        long long int top = 0;
        while(!positive.empty()) {
            if (top == 0) { top = positive.back(); }
            else {
                if (top == 1 || positive.back() == 1) {
                    ANS += (top + positive.back());
                }
                else {
                    ANS += top * positive.back();
                }
                top = 0;
            }
            positive.pop_back();
        }
        if (top != 0) ANS += top;
    }
    
    if (negative.size()) {
        long long int top = 0;
        while(!negative.empty()) {
            if (top == 0) { top = negative.back(); }
            else {
                ANS += top * negative.back();
                top = 0;
            }
            negative.pop_back();
        }
        if (top != 0 && zero == 0) ANS += top;
    }
    
    cout << ANS;
    return 0;
}
