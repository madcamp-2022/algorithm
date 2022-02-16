#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> Hotel;
int C, N;
vector<Hotel> hotelList;
vector<vector<int>> dp;
int main(void) {
    cin >> C >> N;
    hotelList = vector<Hotel>(N + 1);
    dp = vector<vector<int>>(N + 1, vector<int>(C * 2 + 1, INT_MAX / 2));
    for (int i = 1; i <= N; i++) {
        cin >> hotelList[i].second >> hotelList[i].first;
    }
    sort(hotelList.begin(), hotelList.end());
    int ans = INT_MAX;
    for (int i = 1; i <= N; i++) {
        int currentCost = hotelList[i].second;
        int currentCustomer = hotelList[i].first;
        for (int j = 1; j <= C * 2; j++) {
            int sameOrGreater = (j / currentCustomer) * currentCost;
            if (j % currentCustomer) sameOrGreater += currentCost;
            if (sameOrGreater == 0) sameOrGreater = currentCost;
            
            if (j >= currentCustomer) {
                dp[i][j] = min({dp[i - 1][j - currentCustomer] + currentCost,
                                dp[i][j - currentCustomer] + currentCost,
                                dp[i - 1][j],
                                sameOrGreater
                });
            }
            else {
                dp[i][j] = min({dp[i - 1][j],
                                sameOrGreater
                });
            }
            if (j >= C) ans = min(ans, dp[i][j]);
        }
    }
    cout << ans;
}
