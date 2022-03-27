#include "iostream"
#include "stdlib.h"
#include "vector"
#include "algorithm"

using namespace std;
long long island[130000];
vector<int> vertex[130000];

long long dfs(int i) {
    long long ret = island[i];
    for (int v: vertex[i]) {
        ret += dfs(v);
    }

    return max(ret, 0ll);
}

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;

    for (int i = 2; i < N+1; i++) {
        char t; long long a, p;
        cin >> t >> a >> p;
        vertex[p].push_back(i);
        island[i] = a;
        if (t == 'W') {
            island[i] = -island[i];
        }
    }

    cout  << dfs(1) << endl;
    return 0;
}
