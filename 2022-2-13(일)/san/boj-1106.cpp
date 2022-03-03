#include <cmath>
#include <iostream>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int ads[20][2];
int sum[1001];
int C, N;

// ! 답지 보고 품
int dp(int customer) {
    if (customer <= 0)
        return 0;
    else if (sum[customer] > 0)
        return sum[customer];

    int minimum = 100000;
    for (int i = 0; i < N; ++i) {
        minimum = min(minimum, dp(customer - ads[i][1]) + ads[i][0]);
    }
    sum[customer] = minimum;

    return minimum;
}

int main() {
    fastio;

    cin >> C >> N;
    for (int i = 0; i < N; ++i) {
        cin >> ads[i][0] >> ads[i][1];
    }

    cout << dp(C) << endl;
}
