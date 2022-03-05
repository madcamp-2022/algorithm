#include <bits/stdc++.h>
using namespace std;

int N, K, L, R, X;
vector<long long int> arr;

int main(void) {
    cin >> N >> K;
    arr = vector<long long int>(N);
    for (int i = 0; i < N; i++) { cin >> arr[i]; }
    
    sort(arr.begin(), arr.end());
    
    for (int i = 3; i <= K + 2; i++) {
        cin >> L >> R >> X;
        for (int j = L - 1; j < R; j++) {
            arr[j] += X;
        }
        if (X < 0 && arr[max(0, L - 1)] < arr[max(0, L - 2)]) {
            sort(arr.begin(), arr.end());
        }
        else if (X > 0 && arr[min(N - 1, R - 1)] > arr[min(N - 1, R)]) {
            sort(arr.begin(), arr.end());
        }
    }
    for (auto &n: arr) {
        cout << n << " ";
    }
    return 0;
}
