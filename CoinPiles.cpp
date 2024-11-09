#include <bits/stdc++.h>
using namespace std;
// int solve(int a, int b, vector<vector<int>> &dp)
// {
//     if (a < 0 || b < 0)
//         return 0;
//     if (dp[a][b] != -1)
//         return dp[a][b];
//     int op1 = 0, op2 = 0;
//     if (a - 2 >= 0 && b - 1 >= 0)
//         if (dp[a - 2][b - 1] == -1)
//             op1 = solve(a - 2, b - 1, dp), dp[a - 2][b - 1] = op1;
//         else
//             op1 = dp[a - 2][b - 1];
//     if (a - 1 >= 0 && b - 2 >= 0)
//         if (dp[a - 1][b - 2] == -1)
//             op2 = solve(a - 1, b - 2, dp), dp[a - 1][b - 2] = op2;
//         else
//             op2 = dp[a - 1][b - 2];
//     return dp[a][b] = op1 || op2;
// }
int main()
{
    /*
        a  b
        x  2x
        2x x
        x x && x%3 == 0
    */
    long long int t, a, b;
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        // vector<vector<int>> dp(a + 1, vector<int>(b + 1, -1));
        // dp[0][0] = 1;
        // for (int i = 1; i <= a; i++)
        //     dp[a][0] = 0;
        // for (int i = 1; i <= b; i++)
        //     dp[0][b] = 0;
        // cout << (solve(a, b, dp) ? "YES" : "NO") << endl;

        if(a == 2*b || b == 2*a || (a==b && a%3==0))
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
    }
}