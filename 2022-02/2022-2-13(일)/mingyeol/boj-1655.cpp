#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void) {
    int n, c;
    priority_queue<int, vector<int>, less<int>> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2;
    
    scanf("%d", &n);
    pq1.push(-10001);
    pq2.push(10001);
    for(int i=0; i<n; i++) {
        scanf("%d", &c);
        if(c < pq2.top()) pq1.push(c);
        else pq2.push(c);
        
        if(pq1.size() < pq2.size()) {
            pq1.push(pq2.top());
            pq2.pop();
        }
        if(pq1.size() > pq2.size() + 1) {
            pq2.push(pq1.top());
            pq1.pop();
        }
        
        printf("%d\n", pq1.top());
    }

    return 0;
}