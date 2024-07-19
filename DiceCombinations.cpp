#include <bits/stdc++.h>
using namespace std;
int MOD = 1e9 + 7;
long long int solve(long long int n, long long int dp[])
{
    if (n == 0)
        return 1;
    long long int ans = 0;
    if (dp[n] != -1)
        return dp[n];
    for (int i = 1; i <= min(6ll, n); i++)
    {
        if (dp[n - i] == -1)
            dp[n - i] = solve(n - i, dp);
        ans = (ans % MOD + dp[n - i] % MOD) % MOD;
    }
    return dp[n] = ans;
}
int main()
{
    long long int n;
    cin >> n;
    long long int dp[n + 1];
    memset(dp, -1ll, sizeof(dp));
    dp[0] = 1;
    cout << solve(n, dp);
}