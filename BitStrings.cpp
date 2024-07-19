#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;
long long int solve(long long int n)
{
    if (n == 0)
        return 1;
    long long int ans = solve(n / 2);
    ans = (ans % mod * ans % mod) % mod;
    if (n & 1)
        ans = (ans % mod * 2 % mod) % mod;
    return ans;
}
int main()
{
    long long int n;
    cin >> n;
    cout << solve(n);
}