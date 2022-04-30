#include <bits/stdc++.h>

using namespace std;
const int MAX = 100001;

int isPrime[MAX];
vector<int> visit(3'000'001, 0);

bool canInsert(int value)
{
    if (visit[value])
    {
        return false;
    }

    if (value >= 0 && value <= 3'000'001)
    {
        return true;
    }

    return false;
}

void vectorInit()
{
    for (int i = 0; i < 3'000'001; i++)
    {
        visit[i] = 0;
    }
}

bool isInnerAndPrime(int A, int B, int value)
{
    if (value < A || value > B)
    {
        return false;
    }

    return isPrime[value];
}

void precalc()
{
    fill(isPrime, isPrime + MAX, 1);
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i * i < 100001; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= 100001; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    precalc();

    int T;
    cin >> T;
    while (T--)
    {
        int N, A, B;
        cin >> N >> A >> B;
        vectorInit();

        queue<pair<int, int>> q;
        q.push({N, 0});
        visit[N] = true;
        int answer = -1;
        int current = N;

        while (!q.empty())
        {
            int here = q.front().first;
            int count = q.front().second;
            q.pop();

            if (isInnerAndPrime(A, B, here))
            {
                answer = count;
                current = here;
                break;
            }

            int v[4] = {
                here / 2,
                here / 3,
                here + 1,
                here - 1};

            for (int a : v)
            {
                if (canInsert(a))
                {
                    q.push({a, count + 1});
                    visit[a] = 1;
                }
            }
        }

        cout << answer << '\n';
    }

    return 0;
}