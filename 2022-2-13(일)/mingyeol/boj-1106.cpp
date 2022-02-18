#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int arr[21][1001];
int cost[2][21];

int main(void) {
    int c, n;
    scanf("%d %d", &c, &n);
    for(int i=1; i<=n; i++)
        scanf("%d %d", &cost[0][i], &cost[1][i]);
    
    for(int j=1; j<=c; j++) 
        arr[0][j] = INT_MAX;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=c; j++) {
            if(j < cost[1][i]) {
                arr[i][j] = min(arr[i-1][j], arr[i][0] + cost[0][i]);
            } else {
                arr[i][j] = min(arr[i-1][j], arr[i][j - cost[1][i]] + cost[0][i]);
            }
        }
    }

    printf("%d", arr[n][c]);
    return 0;
}