#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <memory.h>
#include <math.h>
#include <algorithm>
using namespace std;
int n, m;
string str1, str2;
int recv(int s1, int s2)
{
	if (s1 == n || s2 == m)
	{
		return 0;
	}
	int &ret = dp[s1][s2];
	if (~ret)
		return ret;
	ret = 0;
	if (str1[s1] == str2[s2])
	{
		ret = 1 + recv(s1 + 1, s2 + 1);
	}
	else
	{
		ret = max(recv(s1, s2 + 1), recv(s1 + 1, s2));
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(dp, -1, sizeof(dp));
	cin >> str1 >> str2;
	n = str1.length();
	m = str2.length();
	cout << n + m - recv(0, 0);
}