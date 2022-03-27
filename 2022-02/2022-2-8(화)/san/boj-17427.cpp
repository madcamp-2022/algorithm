#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastio;

    int N;
    long sum = 0;

    cin >> N;
    for (long n = 1; n <= N; n++) {
        // n appears N / n times as divisor between 1~N
        sum += n * (N / n);
    }

    cout << sum << endl;
}
