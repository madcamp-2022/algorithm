#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool desc(int a, int b) { return a > b; }

long long iterate_vec(vector<int> *v) {
    vector<int>::iterator iter;
    int temp;
    long long sum = 0;

    for (iter = v->begin(); iter != v->end(); iter++) {
        temp = *iter;
        if (++iter != v->end()) {
            sum += (long long)temp * (*iter);
        } else {
            sum += temp;
            break;
        }
    }

    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, num;
    long long sum = 0;
    vector<int> negatives, positives;
    cin >> n;
    while (n--) {
        cin >> num;
        if (num > 1) {
            positives.push_back(num);
        } else if (num == 1) {
            // 1은 곱하면 -1 손해
            sum += 1;
        } else {
            // 0은 negative로 보내서 음수 상쇄되게
            negatives.push_back(num);
        }
    }

    sort(negatives.begin(), negatives.end());
    sort(positives.begin(), positives.end(), desc);

    sum += iterate_vec(&negatives);
    sum += iterate_vec(&positives);

    cout << sum << endl;
}
