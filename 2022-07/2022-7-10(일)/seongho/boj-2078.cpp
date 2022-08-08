#include <bits/stdc++.h>

using namespace std;

int main()
{
    int l = 0;
    int r = 0;

    int a, b;
    cin >> a >> b;

    while (!(a == 1 && b == 1))
    {
        if (a < b)
        {
            int diff = b - a;
            int count = diff / a + (diff % a != 0);
            b -= count * a;
            r += count;
        }
        else if (a > b)
        {
            int diff = a - b;
            int count = diff / b + (diff % b != 0);
            a -= count * b;
            l += count;
        }
    }

    cout << l << ' ' << r;
}